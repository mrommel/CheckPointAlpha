//
//  SKPolygon.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <UIKit/UIColor.h>

/** SKPolygon stores the information related to a map polygon overlay. This object is used as an input parameter.
 */
@interface SKPolygon : NSObject

/** An array of CLLocation objects. Each location represents a vertex of the polygon. The first and the last vertices will be linked.
 */
@property(nonatomic,strong) NSArray *coordinates;

/** The inner/outer color of the polygon depending on the value of the isMask property.
 */
@property(nonatomic,strong) UIColor *fillColor;

/** The border color of the polygon. Set to nil for no border.
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

/** A newly initialized SKPolygon.
 */
+ (instancetype)polygon;

@end
