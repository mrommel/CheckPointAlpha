//
//  ViewController.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "MainViewController.h"

#import <AudioToolbox/AudioToolbox.h>

#import "MapViewAnnotation.h"
#import "SKManager.h"
#import "LocationAwareController.h"
#import "MapPackageManager.h"
#import "WSUserAPIManager.h"
#import "Utilities.h"
#import "Constants.h"
#import "NSObject+PerformBlockAfterDelay.h"

@interface MainViewController ()

@property (nonatomic, strong) SKMapView						*skMapView;
//@property (nonatomic, strong) LocationAwareController       *locationAwareController;

@property (nonatomic, retain)       UILabel                     *lbl;
@property (nonatomic, assign)       CLLocationCoordinate2D      centerLocationCoordinate;

@property (nonatomic, assign)       int                         currentPoint;
@property (nonatomic, copy)       NSArray *annotations;

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.locationManager = [[CLLocationManager alloc] init];
    self.locationManager.delegate = self;
    self.locationManager.distanceFilter = kCLDistanceFilterNone;
    self.locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    
    if (IS_OS_8_OR_LATER) {
        [self.locationManager requestWhenInUseAuthorization];
        [self.locationManager requestAlwaysAuthorization];
    }
    
#if TARGET==1
    NSLog(@"Target == 1");
    self.annotations = [self loadAnnotationsWithFileName:@"alpha"];
#else
    NSLog(@"Target == 2");
    self.annotations = [self loadAnnotationsWithFileName:@"beta"];
#endif
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self.locationManager startUpdatingLocation];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    if (!self.skMapView) {
        [self addMapView];
    }
    [self playSound];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    [self.locationManager stopUpdatingLocation];
    self.skMapView = nil;
}

- (void)playSound
{
    SystemSoundID mBeep;
    
    // Create the sound
    NSString* path = [[NSBundle mainBundle]
                      pathForResource:@"beep" ofType:@"aiff"];
    NSURL* url = [NSURL fileURLWithPath:path];
    AudioServicesCreateSystemSoundID((__bridge CFURLRef)url, &mBeep);
    
    // Play the sound
    AudioServicesPlaySystemSound(mBeep);
    
    // Dispose of the sound
    AudioServicesDisposeSystemSoundID(mBeep);
}

- (NSMutableArray *)loadAnnotationsWithFileName:(NSString *)fileName
{
    int identifier = 777;
    NSMutableArray *annotations = [[NSMutableArray alloc] init];
    //Read locations details from plist
    NSString *path = [[NSBundle mainBundle] pathForResource:fileName ofType:@"plist"];
    NSArray *locations = [NSArray arrayWithContentsOfFile:path];
    for (NSDictionary *row in locations) {
        NSNumber *latitude = [row objectForKey:@"latitude"];
        NSNumber *longitude = [row objectForKey:@"longitude"];
        //Create coordinates from the latitude and longitude values
        CLLocationCoordinate2D coord;
        coord.latitude = latitude.doubleValue;
        coord.longitude = longitude.doubleValue;
        
        SKAnnotation *annotation = [SKAnnotation annotation];
        annotation.annotationType = SKAnnotationTypeMarker;
        annotation.location = coord;
        annotation.identifier = identifier;
        [annotations addObject:annotation];
        identifier++;
    }
    return annotations;
}

- (void)addMapView
{
    self.skMapView = [[SKManager sharedInstance] mapView];
    [self.view addSubview:self.skMapView];
    
    CLLocationCoordinate2D annotationCoord;
    annotationCoord.latitude = 52.490730;
    annotationCoord.longitude = 13.533969;
    
    [self.skMapView animateToLocation:annotationCoord withDuration:2];
    [self.skMapView animateToZoomLevel:18.5f];
    
    // Lock the map rotation
    [self.skMapView.settings setRotationEnabled:NO];
    self.skMapView.delegate = self;
    
    [self addButtons];
}

- (void)addButtons
{
    self.lbl = [[UILabel alloc] initWithFrame:CGRectMake(20, 90, 420, 20)];
    self.lbl.text = @"";
    [self.view addSubview:self.lbl];
    
    UIButton *centerBtn = [[UIButton alloc] initWithFrame:CGRectMake(30, 30, 30, 30)];
    UIImage *btnImage = [UIImage imageNamed:@"center.png"];
    [centerBtn setImage:btnImage forState:UIControlStateNormal];
    [centerBtn addTarget:self action:@selector(centerMap:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:centerBtn];

    [self performBlock:^{
        [self showAnnotations];
    } afterDelay:5];
}

- (void)centerMap:(UIButton *)sender
{
    //[self centerOnCurrentPosition];
    CLLocationCoordinate2D annotationCoord;
    annotationCoord.latitude = 52.490730;
    annotationCoord.longitude = 13.533969;
    
    [self.skMapView animateToLocation:annotationCoord withDuration:2];
}

- (void)showAnnotations
{
    [self.skMapView clearAllAnnotations];
    
    [self.skMapView addAnnotation:[self currentAnnotation]];
    [self.skMapView addAnnotation:[self goalAnnotation]];
    
    SKPolyline *polyline = [[SKPolyline alloc] init];
    NSMutableArray *coordinates = [[NSMutableArray alloc] init];
    SKAnnotation *annotation = [self currentAnnotation];
    [coordinates addObject:[[CLLocation alloc] initWithLatitude:annotation.location.latitude
                                                      longitude:annotation.location.longitude]];
    annotation = [self goalAnnotation];
    annotation.annotationType = SKAnnotationTypeDestinationFlag;
    [coordinates addObject:[[CLLocation alloc] initWithLatitude:annotation.location.latitude
                                                      longitude:annotation.location.longitude]];
    polyline.coordinates = coordinates;
    polyline.fillColor = [UIColor blackColor];
    polyline.lineWidth = 7;

    [self.skMapView addPolyline:polyline];
}

- (SKAnnotation *)currentAnnotation
{
    long index = self.currentPoint;
    if (index < 0) {
        index = 0;
    }
    if (index >= self.annotations.count) {
        index = self.annotations.count - 1;
    }
    
    SKAnnotation *annotation = self.annotations[index];
    annotation.annotationType = SKAnnotationTypeGreen;
    
    return annotation;
}

- (SKAnnotation *)goalAnnotation
{
    long index = self.currentPoint + 1;
    if (index < 0) {
        index = 0;
    }
    if (index >= self.annotations.count) {
        index = self.annotations.count - 1L;
    }
    
    SKAnnotation *annotation = self.annotations[index];
    annotation.annotationType = SKAnnotationTypeDestinationFlag;
    
    return annotation;
}

- (void)mapView:(SKMapView *)mapView didChangeToRegion:(SKCoordinateRegion)region
{
    DLog(@"Map region changed.\n Center:(%f,%f). Zoom:%f",region.center.latitude,region.center.longitude,region.zoomLevel);
}

- (void)locationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation {
    NSLog(@"OldLocation %f %f", oldLocation.coordinate.latitude, oldLocation.coordinate.longitude);
    NSLog(@"NewLocation %f %f", newLocation.coordinate.latitude, newLocation.coordinate.longitude);
    
    SKAnnotation *currentGoal = [self goalAnnotation];
    double delta = 5;
    
    CLLocation *goalLocation = [[CLLocation alloc] initWithLatitude:currentGoal.location.latitude longitude:currentGoal.location.longitude];
    double distance = [newLocation distanceFromLocation:goalLocation];
    
    BOOL nextPoint = distance < delta;
    
    self.lbl.text =[NSString stringWithFormat:@"Entfernung: %.0fm", distance];
    
    if (nextPoint) {
        self.currentPoint++;
        NSLog(@"Next point: %d", self.currentPoint);
        [self showAnnotations];
    }
}

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error
{
    NSLog(@"didFailWithError: %@", error);
    UIAlertView *errorAlert = [[UIAlertView alloc]
                               initWithTitle:@"Error" message:@"Failed to Get Your Location" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [errorAlert show];
}

@end
