//
//  SKTrafficIncidentUpdateInfo.h
//  SKMaps
//
//  Created by Alex Cimpean on 2/20/14.
//  Copyright (c) 2014 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 */
@interface SKTrafficIncidentUpdateInfo : NSObject

/**The id of the incident.
 */
@property(nonatomic,assign) int incidentId;

/**The distance to the incident, in meters.
 */
@property(nonatomic,assign) int distanceInMeters;

/**The distance to the incident, in seconds.
 */
@property(nonatomic,assign) float distanceInSeconds;

/**Returns an autoreleased SKTrafficIncidentUpdateInfo object
 */
+(instancetype)trafficIncidentUpdateInfo;

@end
