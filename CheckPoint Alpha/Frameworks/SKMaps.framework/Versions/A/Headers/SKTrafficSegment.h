//
//  SKTrafficSegment.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 SKTrafficSegment defines the speed profile for a road segment.
 */
@interface SKTrafficSegment : NSObject

/**Segment code.
 */
@property(nonatomic,assign) int code;
/**Closed segment or not. If closed, driving is not allowed at all.
 */
@property(nonatomic,assign, getter = isClosed) BOOL closed;

/**Current speed.
 */
@property(nonatomic,assign) int speed;

/**Reference speed.
 */
@property(nonatomic,assign) int referenceSpeed;

/**The speed bucket.
 */
@property(nonatomic,assign) int speedBucket;

/**Any subsegments.
 */
@property(nonatomic,strong) NSArray* subSegments;
@end
