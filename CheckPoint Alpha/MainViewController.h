//
//  ViewController.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SKMaps/SKMaps.h>

#import <CoreLocation/CoreLocation.h>

@interface MainViewController : UIViewController<CLLocationManagerDelegate, SKMapViewDelegate>

@property (nonatomic, strong)       CLLocationManager           *locationManager;
@property (nonatomic, readwrite) CLAuthorizationStatus           locationServicesStatus;

@end

