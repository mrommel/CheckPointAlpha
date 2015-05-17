//
//  SKFoursquareImage.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

/**SKFoursquarePoiImage - stores the information for a Foursquare search result POI image
 */

@interface SKFoursquarePoiImage : NSObject
{
}

/**Specifies the image size in pixels for the result images.
 */
@property(nonatomic, readwrite) CGSize imageSize;

/**Specifies the URL for the Foursquare search result POI image.
 */
@property(nonatomic, strong) NSString *imageURL;

/**Creates a default SKFoursquarePoiImage object
 @return - the default object
 */
+(instancetype)foursquarePoiImage;

@end
