//
//  SKTrafficUpdateData.h
//  SKMaps
//
//  Copyright (c) 2014 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    SKChangedETANoAlternative = 0,
    SKChangedETABetterAlternative,
    SKBlockageFoundNoAlternative,
    SKBlockageFoundBetterAlternative,
    SKLostTrafficInfo
} SKTrafficUpdateType;

/** It's used for storing the information about a traffic update.
 */
@interface SKTrafficUpdateData : NSObject

/**The type of the update.
 */
@property(nonatomic,assign) SKTrafficUpdateType type;

/**The initial duration of the current route.
 */
@property(nonatomic,assign) int oldDurationOfCurrentRoute;

/**The duration of the current route after the traffic update.
 */
@property(nonatomic,assign) int newDurationOfCurrentRoute;

/**The duration of the alternative route, if we have one.
 */
@property(nonatomic,assign) int durationOfNewRoute;

/** Returns an autoreleased object */
+ (instancetype)trafficUpdateData;

@end
