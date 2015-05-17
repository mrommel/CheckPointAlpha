//
//  SKMapView+Traffic.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import "SKMaps/SKMapView.h"

@class SKBoundingBox;

@interface SKMapView(Traffic)
/**
 Adds traffic info, to be rendered on the map. 
 @param trafficInfo An array of SKTrafficSegment objects.
 @param boundingBox The bounding box of the traffic info.
 */
-(void)addTrafficInfo:(NSArray*)trafficInfo inBoundingBox:(SKBoundingBox*)boundingBox;

/**
 Enables/disables the rendering of the traffic data on map.
 @param trafficMode A boolean value indicating the appereance of the traffic data.
 */
-(void)displayTrafficWithMode:(SKTrafficMode)trafficMode;

@end
