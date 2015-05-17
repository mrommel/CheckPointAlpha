//
//  SKManager.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "SKManager.h"

#import <SKMaps/SKMaps.h>
#import <SKMaps/SKRoutingService.h>

#import "Constants.h"

static NSString *const  kMapStyleFolderName                     =	@"BicycleStyle";
static NSString *const  kMapStyleFileName                       =	@"bicyclestyle.json";

static NSString *const kSkobblerMapApiKey = @"52adb7c0303194bb5fa1ae71a6177112e2219b524a69e427522cc892cb16cd5f";
static SKManager *shared = nil;

@implementation SKManager

+ (SKManager *)sharedInstance
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        shared = [[self alloc] init];
        shared.offlinePackageManager = [[SKOfflinePackagesManager alloc] init];
        shared.routingService = [SKRoutingService sharedInstance];
        [shared initializeSKMap];
    });
    return shared;
}

- (void)initializeSKMap
{
    SKMapsInitSettings *initSettings = [[SKMapsInitSettings alloc] init];
    initSettings.connectivityMode = SKConnectivityModeOnline;
    initSettings.mapStyle = [self loadSKMapStyle];
    [[SKMapsService sharedInstance] initializeSKMapsWithAPIKey:kSkobblerMapApiKey settings:initSettings];
}

//Custom Getter
- (id)mapView
{
    _mapView = [[SKMapView alloc] initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)];
    [_mapView.settings setFollowerMode:SKMapFollowerModeNone];
    [_mapView.settings setShowCurrentPosition:YES];
    [_mapView.settings setCompanyAttributionPosition:SKAttributionPositionNone];
    [_mapView.mapScaleView setHidden:NO];
    // Lock the map rotation
    [_mapView.settings setRotationEnabled:NO];
    //Disable animation
    [_mapView.settings setInertiaEnabled:NO];
    //Load Map Style
    [self loadSKMapStyle];
    
    return _mapView;
}

- (SKMapViewStyle *)loadSKMapStyle
{
    SKMapViewStyle *mapStyle = [SKMapViewStyle mapViewStyle];
    [mapStyle setResourcesFolderName:kMapStyleFolderName];
    [mapStyle setStyleFileName:kMapStyleFileName];
    return mapStyle;
}

@end
