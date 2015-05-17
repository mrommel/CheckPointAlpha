//
//  SKTripAdvisorSearchObject.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import "SKDefinitions.h"

/**SKTripAdvisorSearchObject - contains the input parameters for a Trip Advisor search
 */
@interface SKTripAdvisorSearchObject : NSObject
{
}

/**The location where the search takes place.
 */
@property(nonatomic, readwrite) CLLocationCoordinate2D coordinate;

/**Search radius in meters.
 */
@property(nonatomic, readwrite) int radius;

/**The type of the POI's returned by the search.
 */
@property(nonatomic, readwrite) SKTripAdvisorPOIType tripAdvisorPOIType;

/**The page index.
 */
@property(nonatomic, readwrite) int pageIndex;

/**The number of items per page.
 */
@property(nonatomic, readwrite) int itemsPerPage;

/**The sort order for the search results. The default value is to sort by distance.
 */
@property(nonatomic, readwrite) SKTripAdvisorSortOrder tripAdvisorSortOrder;

@end
