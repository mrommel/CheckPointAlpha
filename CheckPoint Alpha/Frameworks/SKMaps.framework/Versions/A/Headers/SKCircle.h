//
//  SKCircle.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <UIKit/UIColor.h>

/** SKCircle stores the information related to a circle map overlay. This object is used as an input parameter.
 */
@interface SKCircle : NSObject

/** The center coordinate of the circle.
 */
@property(nonatomic,assign) CLLocationCoordinate2D centerCoordinate;

/** The radius of the circle in meters.
 */
@property(nonatomic,assign) float radius;

/** The inner/outer color of the circle depending on the value of the isMask property.
 */
@property(nonatomic,strong) UIColor *fillColor;

/** The border color of the circle. Set to nil for no border.
 */
@property(nonatomic,strong) UIColor *strokeColor;

/** The width of the border. Should be a value in [ 1, 10 ] interval.
 */
@property(nonatomic,assign) int borderWidth;

/** If YES, the outer area will be colored according to the rest of the settings.
 */
@property(nonatomic,assign) BOOL isMask;

/** Scale of the outer mask. Multiplies the radius value of the circle. If set to 0, the entire map will be colored.
 */
@property(nonatomic,assign) float maskedObjectScale;

/** The number of pixels of a dotted line. Set to 0 for solid boder.
 */
@property(nonatomic,assign) int borderDotsSize;

/** The number of pixels between the dotted lines.
 */
@property(nonatomic,assign) int borderDotsSpacingSize;

/** The number of points to represent the border of the circle (is bounded in the [ 36, 180 ] interval).
 */
@property(nonatomic,assign) int numberOfPoints;

/** A newly initialized SKCircle.
 */
+ (instancetype)circle;

@end
