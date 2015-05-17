//
//  SKMapScaleView.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SKDefinitions.h"

/** SKMapView's scale view. Can be enabled to display the ratio of a distance on a map to the corresponding distance on the ground.
 */
@interface SKMapScaleView : UIView

/** The scale value in meters per pixel.
*/
@property(nonatomic, assign) CGFloat scale;

/** The measurement unit to be used when displaying the scale value. Default is SKDistanceFormatMetric.
 */
@property(nonatomic, assign) SKDistanceFormat distanceFormat;

/** Scale color. The default is black.
 */
@property(nonatomic, strong) UIColor *scaleColor;

/** The color of the text. The default is black.
 */
@property(nonatomic, strong) UIColor *textColor;

@end
