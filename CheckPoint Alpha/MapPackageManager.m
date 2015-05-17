//
//  MapPackageManager.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "MapPackageManager.h"

#import "SKManager.h"
#import <SKMaps/SKMaps.h>
#import <SKMaps/SKRoutingService.h>

#import "DataManager.h"
#import "WSError.h"

NSString *const MapDataModificationsNotification    = @"MapDataModificationsNotification";
NSString *const WWanNetworkNotification             = @"WWanNetworkNotification";
NSString *const DownloadFailureNotification         = @"DownloadFailNotification";

@interface MapPackageManager ()

@property (strong, nonatomic) NSString *currentCountryCode;
@property (strong, nonatomic) UIProgressView *currentProgressBar;

@end

@implementation MapPackageManager

static MapPackageManager *shared = nil;

+ (MapPackageManager *)sharedInstance
{
    @synchronized (self) {
        if (shared == nil) {
            shared = [[self alloc] init];
        }
    }
    
    return shared;
}

- (BOOL)isPackageInstalled:(NSString *)productId
{
    NSInteger lastDotPos = [productId rangeOfString:@"." options:NSBackwardsSearch].location;
    NSString *countryCode = [[productId substringWithRange:NSMakeRange(lastDotPos + 1, productId.length - lastDotPos - 1)] uppercaseString];
    NSArray *mapPackages = [[[[SKManager sharedInstance] offlinePackageManager] installedOfflineMapPackages] valueForKeyPath:@"@distinctUnionOfObjects.name"];
    return [mapPackages containsObject:countryCode];
}

- (BOOL)hasMapPackageDeletedForCountryCode:(NSString *)countryCode
{
    return [[[SKManager sharedInstance] offlinePackageManager] deleteOfflineMapPackageNamed:countryCode];
}

#pragma mark - Download Map method

- (void)downloadMap:(NSString *)countryCode withProgressBar:(UIProgressView *)progressBar
{
    self.currentCountryCode = countryCode;
    self.currentProgressBar = progressBar;
    [self downloadMapPathForCountryCode:countryCode];
}

- (void)downloadMapPathForCountryCode:(NSString *)countryCode
{
    NSString *urlPath = [[@"https://nyon-test.de/ebikeconnect/api/" stringByAppendingString:@"maps"] stringByAppendingFormat:@"/%@", countryCode];
    [[DataManager sharedInstance] getDataFromServerWithPath:urlPath withBlock:^(id responseObject, WSError *error) {
        if (error) {
            DLog(@"***ERROR*** %ld - %@ ",(long)[error code], [error message]);
        } else if (responseObject) {
            [self downloadZipMapAtPackagePath
             :(responseObject[@"paths"])[@"SKM_file"] withCountryCode:countryCode];
        }
    }];
}

//Request for the zip file
- (void)downloadZipMapAtPackagePath:(NSString *)packagePath withCountryCode:(NSString *)countryCode
{
    DLog(@"Package path to make a request for zip file: %@", packagePath);
    //Make a request for the zip file
    [[DataManager sharedInstance] fetchMapPachageZipFromServerWithPath:packagePath withProgressBar:self.currentProgressBar withBlock:^(id responseObject, WSError *error) {
        if (error) {
            DLog(@"Download Request Falied with status code: %ld, %@", (long)[error code], [error message]);
        } else if (responseObject) {
            DLog(@"Download complet...good to go!!! Unzipe it!");
            NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
            NSString *documentsDirectory = paths[0];
            //Install map
            //In documents must be a .skm file that will be cut and passed into SKMaps
            [self installMapPackage:countryCode atPath:documentsDirectory];
        }
    }];
}

// Installs the .skm file, cuts and pastes the .skm file from Documents folder to SKMaps
- (void)installMapPackage:(NSString *)countryCode atPath:(NSString *)mapPathToFolder
{
    DLog(@"Install map %@ from the folder path %@", countryCode, mapPathToFolder);
    BOOL downloadState = [[[SKManager sharedInstance] offlinePackageManager] addOfflineMapPackageNamed:countryCode inContainingFolderPath:mapPathToFolder];
    // Adding/downloading the map failed by returning FALSE, success by returning TRUE
    if (!downloadState) {
        [[NSNotificationCenter defaultCenter] postNotificationName:DownloadFailureNotification object:countryCode userInfo:nil];
    } else {
        [[NSNotificationCenter defaultCenter] postNotificationName:MapDataModificationsNotification object:countryCode userInfo:nil];
    }
}

@end
