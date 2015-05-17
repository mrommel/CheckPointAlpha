//
//  SKPositionerService.h
//  ForeverMapNGX
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLLocationManager.h>
#import "SKDefinitions.h"
#import "SKPositionerServiceDelegate.h"

/** SKPositionerService is used for managing GPS position related operations.
 */
@interface SKPositionerService : NSObject

/** The delegate that must conform to SKPositionerServiceDelegate protocol, used for receiving different GPS location updates.
 */
@property(nonatomic,weak) id<SKPositionerServiceDelegate> delegate;

/** The activity type of the location positioner.
 */
@property(nonatomic,assign) CLActivityType activityType;

/** The overall accuracy of the latest received GPS positions.
 */
@property(nonatomic,readonly,assign) SKGPSAccuracyLevel gpsAccuracyLevel;

/** Last GPS coordinate reported by the device.
 */
@property(nonatomic,readonly,assign) CLLocationCoordinate2D currentCoordinate;

/** The current position stored by the library, in the SKPosition format.
 */
@property(nonatomic,readonly,assign) SKPosition currentPosition;

/** The current  position stored by the library, matched on a road segment, in the SKPosition format.
 */
@property(nonatomic,readonly,assign) SKPosition currentMatchedPosition;

/** Path to the log file to be used for simulating a navigation.
 */
@property(nonatomic,strong) NSString* positionsLogFilePath;

/** Returns the singleton SKPositionerService instance.
 */
+ (instancetype)sharedInstance;

/** Starts updating GPS locations.
 */
- (void)startLocationUpdate;

/** Stops updating GPS locations.
 */
- (void)cancelLocationUpdate;

#pragma mark - Position simulation

/** Starts replaying a log file that was previously recorded. Positions saved there will be used instead of those received from the GPS hardware.
 @param logFileNameWithPath The path to the log file.
 @return Success/Failure of the operation.
 */
- (BOOL)startPositionReplayFromLog:(NSString *)logFileNameWithPath;

/** Stops the replaying of GPS positions.
 @return Success/Failure of the operation.
 */
- (BOOL)stopPositionReplay;

/** Sets the position replaying rate. The time interval between the replay of positions is shortened directly proportional to the rate.
 @param rate The rate of replaying.
 @return Success/Failure of the operation.
 */
- (BOOL)setPositionReplayRate:(double)rate;

/** Increases simulation replaying rate. This value will be added to the previous route simulation speed.
 @param withValue The value to increase with.
 @return Success/Failure of the operation.
 */
- (BOOL)increaseRouteSimulationSpeed:(int)withValue;

/** Decreases simulation replaying rate. This value will be subtracted from the previous route simulation speed.
 @param withValue The value to decrease with.
 @return Success/Failure of the operation.
 */
- (BOOL)decreaseRouteSimulationSpeed:(double)withValue;

@end
