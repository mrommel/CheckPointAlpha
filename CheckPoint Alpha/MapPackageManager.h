//
//  MapPackageManager.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const MapDataModificationsNotification;
extern NSString *const DownloadFailureNotification;

@interface MapPackageManager : NSObject

+ (MapPackageManager *)sharedInstance;

- (BOOL)isPackageInstalled:(NSString *)productId;
- (void)downloadMap:(NSString *)countryCode withProgressBar:(UIProgressView *)progressBar;

- (void)installMapPackage:(NSString *)countryCode atPath:(NSString *)mapPathToFolder;

@end
