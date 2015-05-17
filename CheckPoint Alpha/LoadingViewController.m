//
//  LoadingViewController.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "LoadingViewController.h"

#import "WSUserAPIManager.h"
#import "MapPackageManager.h"
#import "NSObject+PerformBlockAfterDelay.h"
#import "UserManager.h"

#define DELAY 2

@interface LoadingViewController ()

@end

@implementation LoadingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"is de installed: %d", [[MapPackageManager sharedInstance] isPackageInstalled:@"com.bosch.ebike.premium.map.de"]);

    [self registerNotifications];
    
    self.progressLabel.text = @"Initialisiert";
    self.progressView.progress = 0.0f;
    
    if (![[MapPackageManager sharedInstance] isPackageInstalled:@"com.bosch.ebike.premium.map.de"]) {
        [self authenticate];
    } else {
        [self moveToMain];
        //[self moveToMap];
    }
    //[self moveToMap];
}

- (void)registerNotifications
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(mapDataModifications:) name:MapDataModificationsNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(downloadFailed:) name:DownloadFailureNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(authenticationFailed:) name:USER_MANAGER_AUTHENTICATION_FAILED object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(authenticationSucceeded:) name:USER_MANAGER_AUTHENTICATION_SUCCEEDED object:nil];
}

- (void)authenticate
{
    NSLog(@"authenticate");
    [self performBlock:^{
        [[UserManager sharedInstance] authenticateUserWithUsername:@"marco@polo.de" andPassword:@"password1"];
    } afterDelay:DELAY];
}

- (void)downloadMap
{
    NSLog(@"downloadMap");
    [self performBlock:^{
        [[MapPackageManager sharedInstance] downloadMap:@"DE"
                                        withProgressBar:self.progressView];
    } afterDelay:DELAY];
}

- (void)authenticationSucceeded:(NSNotification *)notification
{
    NSLog(@"authenticationSucceeded");
    if (![[MapPackageManager sharedInstance] isPackageInstalled:@"com.bosch.ebike.premium.map.de"]) {
        //[self downloadMap];
        [self copyMap];
    } else {
        [self moveToMain];
    }
}

- (void)copyMap
{
    NSString* filePath = [[NSBundle mainBundle] pathForResource:@"DE" ofType:@"skm"];
    
    //filePath = [filePath substringToIndex:[filePath length] - 6];
    
    NSString *documentsDirectory = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSLog(@"Source Path: %@\n Documents Path: %@ ", filePath, documentsDirectory);
    
    NSError *error;
    
    [[NSFileManager defaultManager] copyItemAtPath:filePath
                                            toPath:documentsDirectory
                                             error:&error];
    NSLog(@"Error description-%@ \n", [error localizedDescription]);
    NSLog(@"Error reason-%@", [error localizedFailureReason]);
    
    //Install map
    //In documents must be a .skm file that will be cut and passed into SKMaps
    [[MapPackageManager sharedInstance] installMapPackage:@"DE" atPath:documentsDirectory];
}

- (void)authenticationFailed:(NSNotification *)notification
{
    NSLog(@"authenticationFailed");
    [self moveToMain];
}

- (void)mapDataModifications:(NSNotification *)notification
{
    NSLog(@"mapDataModifications");
    [self moveToMain];
}

- (void)downloadFailed:(NSNotification *)notification
{
    NSLog(@"downloadFailed");
    [self moveToMain];
}

- (void)moveToMain
{
    [self performBlock:^{
        [self performSegueWithIdentifier:@"MoveToMain"
                                  sender:nil];
    } afterDelay:DELAY];
}

- (void)moveToMap
{
    [self performBlock:^{
        [self performSegueWithIdentifier:@"MoveToMap"
                                  sender:nil];
    } afterDelay:DELAY];
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}

@end
