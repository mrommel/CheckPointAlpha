//
//  SKTrafficSubSegment.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 SKTrafficSubSegment defines SKTrafficSegment's subsegment speed profile.
 */
@interface SKTrafficSubSegment : NSObject

/**
 First offset.
 */
@property(nonatomic,assign) int offset1;
/**
 Second offset.
 */
@property(nonatomic,assign) int offset2;

/**
 Current speed.
 */
@property(nonatomic,assign) int speed;
@end
