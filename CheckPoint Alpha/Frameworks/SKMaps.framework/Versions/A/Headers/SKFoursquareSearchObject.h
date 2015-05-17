//
//  SKFoursquareSearchObject.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKDefinitions.h"
#import <CoreGraphics/CGGeometry.h>

/**SKFoursquareSearchObject - contains the input parameters for a Foursquare search
 */
@interface SKFoursquareSearchObject : NSObject
{
}

/**The location where the search takes place.
 */
@property(nonatomic, readwrite) CLLocationCoordinate2D coordinate;

/**Specifies the search category for the POI's. Supported values: food, nightlife, coffee, shopping, sights, arts, trending
 */
@property(nonatomic, strong) NSString *searchCategory;

/**Search radius in meters.
 */
@property(nonatomic, readwrite) int radius;

/**The page index. There is a maximum results per page on server side so pagination should be used by clients to retrieve all the results.
 */
@property(nonatomic, readwrite) int pageIndex;

/**The number of items per page.
 */
@property(nonatomic, readwrite) int itemsPerPage;

/**Specifies the search text. Note: has no effect when a category is specified.
 */
@property(nonatomic, strong) NSString *searchTerm;

/**The sort order for the search results. The default value is to sort by relevance
 */
@property(nonatomic, readwrite) SKFoursquareSortOrder foursquareSortOrder;

/**Specifies the image size in pixels for the result images. The default value is 50 pixels width and 50 pixels height
 */
@property(nonatomic, readwrite) CGSize imageSize;

/**Creates a default SKFoursquareSearchObject object
 @return - the default object
 */
+(instancetype)foursquareSearchObject;

@end
