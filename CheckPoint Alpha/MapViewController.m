//
//  MapViewController.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "MapViewController.h"

#import "MapViewAnnotation.h"
#import "Constants.h"

@interface MapViewController ()

@end

@implementation MapViewController {
    CLLocationManager *locationManager;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    locationManager = [[CLLocationManager alloc] init];
    locationManager.delegate = self;
    locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    
    if (IS_OS_8_OR_LATER) {
        [locationManager requestWhenInUseAuthorization];
        [locationManager requestAlwaysAuthorization];
    }
    
    [self.mapView showsUserLocation];
    
    CLLocationCoordinate2D annotationCoord;
    annotationCoord.latitude = 52.490800;
    annotationCoord.longitude = 13.533670;
    self.mapView.centerCoordinate = annotationCoord;
    
    MKCoordinateRegion viewRegion = MKCoordinateRegionMakeWithDistance(annotationCoord, 500, 500);
    MKCoordinateRegion adjustedRegion = [self.mapView regionThatFits:viewRegion];
    [self.mapView setRegion:adjustedRegion animated:YES];
    
    self.mapView.delegate = self;
    self.mapView.mapType = MKMapTypeStandard;
    
#if TARGET==1
    NSArray* annotations = [self loadAnnotationsWithFileName:@"alpha"];
#else
    NSArray* annotations = [self loadAnnotationsWithFileName:@"beta"];
#endif
    // [self.mapView addAnnotations:];
    [self.mapView showAnnotations:annotations animated:YES];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [locationManager startUpdatingLocation];
}

- (NSMutableArray *)loadAnnotationsWithFileName:(NSString *)fileName
{
    NSMutableArray *annotations = [[NSMutableArray alloc] init];
    //Read locations details from plist
    NSString *path = [[NSBundle mainBundle] pathForResource:fileName ofType:@"plist"];
    NSArray *locations = [NSArray arrayWithContentsOfFile:path];
    for (NSDictionary *row in locations) {
        NSNumber *latitude = [row objectForKey:@"latitude"];
        NSNumber *longitude = [row objectForKey:@"longitude"];
        NSString *title = [row objectForKey:@"title"];
        //Create coordinates from the latitude and longitude values
        CLLocationCoordinate2D coord;
        coord.latitude = latitude.doubleValue;
        coord.longitude = longitude.doubleValue;
        
        MapViewAnnotation *annotation = [[MapViewAnnotation alloc] initWithTitle:title andCoordinate:coord];
        [annotations addObject:annotation];
    }
    return annotations;
}

#pragma mark - CLLocationManagerDelegate

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error
{
    NSLog(@"didFailWithError: %@", error);
    UIAlertView *errorAlert = [[UIAlertView alloc]
                               initWithTitle:@"Error" message:@"Failed to Get Your Location" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [errorAlert show];
}

- (void)locationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation
{
    /*NSLog(@"didUpdateToLocation: %@", newLocation);
    CLLocation *currentLocation = newLocation;
    
    if (currentLocation != nil) {
        
    }*/
}

@end
