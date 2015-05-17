//
//  SKTrafficIncident.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import "SKDefinitions.h"

/**
 SKTrafficIncident is used to store information about a traffic incident.
 */
@interface SKTrafficIncident : NSObject

/**The id of the incident.
 */
@property(nonatomic,assign) int incidentId;

/**The type of the incident.
 */
@property(nonatomic,assign) SKIncidentType type;

/**The severity of the incident.
 */
@property(nonatomic,assign) int severity;

/**The delay of the incident, in minutes.
 */
@property(nonatomic,assign) int delay;

/**The span of the incident in kms.
 */
@property(nonatomic,assign) int span;

/**The distance to the incident, in meters.
 */
@property(nonatomic,assign) int distanceInMeters;

/**The distance to the incident, in seconds.
 */
@property(nonatomic,assign) float distanceInSeconds;

/**The location of the incident.
 */
@property(nonatomic,assign) CLLocationCoordinate2D location;

/**The description of the incident.
 */
@property(nonatomic,strong) NSString* info;

/**The name of the road where the incident is.
 */
@property(nonatomic,strong) NSString* roadName;

/**Returns an autoreleased SKTrafficIncident object
 */
+(instancetype)trafficIncident;

@end
