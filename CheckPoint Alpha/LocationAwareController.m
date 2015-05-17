//
//  LocationAwareController.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "LocationAwareController.h"
#import "UIConstants.h"
#import "MMAlertView.h"

static const CGFloat kUpdateLocationInterval = 30.0f;
static const CGFloat kLSTextViewInsets       = 14.0f;


@interface LocationAwareController () <MMAlertViewDelegate>

@property (nonatomic, weak)      UIViewController<CLLocationManagerDelegate>      *viewController;
@property (nonatomic, readwrite) CLAuthorizationStatus                            locationServicesStatus;
@property (nonatomic, strong)    MMAlertView                                      *locationServicesAlert;
@property (nonatomic, strong)    UITextView                                       *locationServicesTextView;

@end

@implementation LocationAwareController

- (instancetype)initWithViewController:(UIViewController<CLLocationManagerDelegate> *)viewController
{
    self = [super init];
    if (self) {
        self.viewController = viewController;
    }
    return self;
}

- (void)startListening
{
    [self checkLocationServices];
    [self startUpdatingCurrentLocation];
}

- (void)stopListening
{
    [self stopUpdatingCurrentLocation];
}

#pragma mark - Current location

- (void)startUpdatingCurrentLocation
{
    // if locationManager does not currently exist, create it.
    if (!_locationManager) {
        _locationManager = [[CLLocationManager alloc] init];
        [_locationManager setDelegate:self];
        _locationManager.distanceFilter = kCLDistanceFilterNone;
        _locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    }
    if (self.locationServicesStatus != kCLAuthorizationStatusDenied) {
        [_locationManager startUpdatingLocation];
    }
}

- (void)stopUpdatingCurrentLocation
{
    [_locationManager stopUpdatingLocation];
}

#pragma mak - MMAlertViewDelegate methods

- (void)alertView:(MMAlertView *)alertView didDismissWithAction:(MMAlertAction)action
{
    self.locationServicesAlert = nil;
    if (self.locationServicesStatus == kCLAuthorizationStatusDenied && !self.locationServicesTextView) {
        self.locationServicesTextView = [self createAndShowLocationServicesTextView];
    }
}

#pragma mark - CLLocationManagerDelegate - Location updates

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation
{
    NSLog(@"Got new location: %f %f", newLocation.coordinate.latitude, newLocation.coordinate.longitude);
    
    if (self.viewController != self.viewController.navigationController.topViewController) {
        // We are not top view controller - so we ignore this call
        return;
    }
    // if the location is older than 30s ignore
    if (fabs([newLocation.timestamp timeIntervalSinceDate:[NSDate date]]) > kUpdateLocationInterval) {
        return;
    }
    _currentLocationCoordinate = [newLocation coordinate];
    [self stopUpdatingCurrentLocation];
    if ([self.viewController respondsToSelector:@selector(locationManager:didUpdateToLocation:fromLocation:)]) {
        [self.viewController locationManager:manager didUpdateToLocation:newLocation fromLocation:oldLocation];
    }
}

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error
{
    if (self.viewController != self.viewController.navigationController.topViewController) {
        // We are not top view controller - so we ignore this call
        return;
    }
    DLog(@"%@", error);
    // stop updating
    [self stopUpdatingCurrentLocation];
    if ([self.viewController respondsToSelector:@selector(locationManager:didFailWithError:)]) {
        [self.viewController locationManager:manager didFailWithError:error];
    }
}

// invoked when the authorization status changes for this application
- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status
{
    if ([self checkLocationServices] == kCLAuthorizationStatusAuthorized) {
        [self startUpdatingCurrentLocation];
    }
    if ([self.viewController respondsToSelector:@selector(locationManager:didChangeAuthorizationStatus:)]) {
        [self.viewController locationManager:manager didChangeAuthorizationStatus:status];
    }
}

#pragma mark - Public methods

- (BOOL)isLocationServiceAuthorized
{
    return self.locationServicesStatus == kCLAuthorizationStatusAuthorizedAlways;
}

- (CGFloat)calculateDistanceInKmFromLocation:(CLLocation *)from
{
    CLLocationDistance distance = [self calculateDistanceFromLocation:_currentLocationCoordinate toLocation:from.coordinate];
    distance /= 1000; // Convert to kilometers
    return distance;
}

- (CGFloat)calculateDistanceFromLocation:(CLLocationCoordinate2D)fromLocation toLocation:(CLLocationCoordinate2D)toLocation
{
    if (_currentLocationCoordinate.latitude == 0.0f && _currentLocationCoordinate.longitude == 0.0f) {
        return -1.0f;
    }
    
    CLLocation *locA = [[CLLocation alloc] initWithLatitude:fromLocation.latitude longitude:fromLocation.longitude];
    CLLocation *locB = [[CLLocation alloc] initWithLatitude:toLocation.latitude longitude:toLocation.longitude];
    CLLocationDistance distance = [locA distanceFromLocation:locB];
    return distance;
}

#pragma mark - Private methods

- (CLAuthorizationStatus)checkLocationServices
{
    BOOL locationServicesEnabled = [CLLocationManager locationServicesEnabled];
    CLAuthorizationStatus authorizationStatus = [CLLocationManager authorizationStatus];
    locationServicesEnabled = locationServicesEnabled && authorizationStatus == kCLAuthorizationStatusAuthorizedAlways;
    if (locationServicesEnabled) {
        self.locationServicesStatus = kCLAuthorizationStatusAuthorizedAlways;
        [self.locationServicesAlert dismiss];
        [self.locationServicesTextView removeFromSuperview];
        self.locationServicesTextView = nil;
    } else {
        self.locationServicesStatus = authorizationStatus;
        /*if (!self.locationServicesAlert && !self.locationServicesTextView && (authorizationStatus == kCLAuthorizationStatusDenied || authorizationStatus == kCLAuthorizationStatusDenied ==kCLAuthorizationStatusNotDetermined)) {
            [self showLocationServicesAlert];
        }*/
        if (IS_OS_8_OR_LATER && authorizationStatus == kCLAuthorizationStatusNotDetermined) {
            [self.locationManager requestAlwaysAuthorization];
        }
    }
    return self.locationServicesStatus;
}

- (void)showLocationServicesAlert
{
    self.locationServicesAlert = [[MMAlertView alloc] initWithTitle:NSLocalizedString(@"alert.error.title.text", nil)
                                                            message:NSLocalizedString(@"alert.locationServicesDisabled.message", nil)
                                                           delegate:self
                                                            timeout:0];
    [self.locationServicesAlert setAlertButtonType:BTN_NO];
    [self.locationServicesAlert.noButton setTitle:NSLocalizedString(@"ok.text", nil) forState:UIControlStateNormal];
    [self.locationServicesAlert show];
}

- (UITextView *)createAndShowLocationServicesTextView
{
    UITextView *textView = [[UITextView alloc] initWithFrame:CGRectZero];
    [textView setBackgroundColor:ALERT_BACKGROUND_COLOR];
    [textView setText:NSLocalizedString(@"locationServices.stepsToEnable.text", nil)];
    [textView setTextAlignment:NSTextAlignmentLeft];
    [textView setTextColor:[UIColor whiteColor]];
    [textView setFont:ALERT_MESSAGE_FONT];
    [textView setTextContainerInset:UIEdgeInsetsMake(2 * kLSTextViewInsets, kLSTextViewInsets, kLSTextViewInsets, kLSTextViewInsets)];
    [textView setEditable:NO];
    [textView setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.viewController.view addSubview:textView];
    [self addConstraintsToLocationServicesTextView:textView];
    return textView;
}

- (void)addConstraintsToLocationServicesTextView:(UITextView *)textView
{
    NSLayoutConstraint *topConstraint = [NSLayoutConstraint
                                         constraintWithItem:textView
                                         attribute:NSLayoutAttributeTop
                                         relatedBy:NSLayoutRelationEqual
                                         toItem:self.viewController.view
                                         attribute:NSLayoutAttributeTop
                                         multiplier:1.0
                                         constant:kDefaultTopSpace];
    NSLayoutConstraint *leftConstraint = [NSLayoutConstraint
                                          constraintWithItem:textView
                                          attribute:NSLayoutAttributeLeading
                                          relatedBy:NSLayoutRelationEqual
                                          toItem:self.viewController.view
                                          attribute:NSLayoutAttributeLeading
                                          multiplier:1.0
                                          constant:0];
    NSLayoutConstraint *bottomConstraint = [NSLayoutConstraint
                                            constraintWithItem:textView
                                            attribute:NSLayoutAttributeBottom
                                            relatedBy:NSLayoutRelationEqual
                                            toItem:self.viewController.view
                                            attribute:NSLayoutAttributeBottom
                                            multiplier:1.0
                                            constant:0];
    NSLayoutConstraint *rightConstraint = [NSLayoutConstraint
                                           constraintWithItem:textView
                                           attribute:NSLayoutAttributeTrailing
                                           relatedBy:NSLayoutRelationEqual
                                           toItem:self.viewController.view
                                           attribute:NSLayoutAttributeTrailing
                                           multiplier:1.0
                                           constant:0];
    [self.viewController.view addConstraints:@[topConstraint, leftConstraint, bottomConstraint, rightConstraint]];
}

@end

