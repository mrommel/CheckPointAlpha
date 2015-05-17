//
//  SKManager.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SKOfflinePackagesManager;
@class SKMapView;
@class SKRoutingService;

@interface SKManager : NSObject

@property (nonatomic, strong) SKOfflinePackagesManager *offlinePackageManager;
@property (nonatomic, strong) SKMapView *mapView;
@property (nonatomic, strong) SKRoutingService *routingService;

+ (SKManager *)sharedInstance;

- (void)initializeSKMap;

@end
