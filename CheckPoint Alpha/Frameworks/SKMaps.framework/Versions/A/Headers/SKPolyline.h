//
//  SKPolyline.h
//  SKMaps
//
//  Created by Alex Cimpean on 4/3/14.
//  Copyright (c) 2014 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <UIKit/UIColor.h>

/** SKPolyline stores the information related to a map plyline overlay. This object is used as an input parameter.
 */
@interface SKPolyline : NSObject

/** An array of CLLocation objects. Each location represents a vertex of the polyline.
 */
@property(nonatomic,strong) NSArray *coordinates;

/** The color of the polyline.
 */
@property(nonatomic,strong) UIColor *fillColor;

/** The width of the polyline. Should be a value in [ 1, 10 ] interval.
 */
@property(nonatomic,assign) int lineWidth;

/** The width of the backgrund line. Should be a value in [ 1, 10 ] interval.
 */
@property(nonatomic,assign) int backgroundLineWidth;

/** The number of pixels of a dotted line. Set to 0 for solid boder.
 */
@property(nonatomic,assign) int borderDotsSize;

/** The number of pixels between the dotted lines.
 */
@property(nonatomic,assign) int borderDotsSpacingSize;

/** A newly initialized SKPolyline.
 */
+ (instancetype)polyline;

@end
