//
//  SKAnnotationText.h
//  SKMaps
//
//  Copyright (c) 2014 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

/** Used to add custom text for an annotation.
 */
@interface SKAnnotationText : NSObject

/** The text to be displayed below the POI image.
 */
@property(nonatomic,strong) NSString *text;

/** The color of the text.
 */
@property(nonatomic,strong) UIColor *textColor;

/** The color of the text's outline.
 */
@property(nonatomic,strong) UIColor *textOutlineColor;

/** The offset of the text relative to the image.
 */
@property(nonatomic,assign) int verticalOffset;

/** A newly initialized SKAnnotationText.
 */
+ (instancetype)annotationText;

@end
