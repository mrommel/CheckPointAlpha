//
//  LocationAwareController.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface LocationAwareController : NSObject <CLLocationManagerDelegate>

@property (nonatomic, strong)       CLLocationManager           *locationManager;
@property (nonatomic, readonly)     CLLocationCoordinate2D      currentLocationCoordinate;
@property (nonatomic, readonly)     CLAuthorizationStatus       locationServicesStatus;

// Designated initializer
- (instancetype)initWithViewController:(UIViewController<CLLocationManagerDelegate> *)viewController;

// Starts/Stops listening for current location
- (void)startListening;
- (void)stopListening;

- (BOOL)isLocationServiceAuthorized;
- (void)startUpdatingCurrentLocation;
- (void)stopUpdatingCurrentLocation;
- (CGFloat)calculateDistanceInKmFromLocation:(CLLocation *)from;
- (CGFloat)calculateDistanceFromLocation:(CLLocationCoordinate2D)fromLocation toLocation:(CLLocationCoordinate2D)toLocation;

@end
