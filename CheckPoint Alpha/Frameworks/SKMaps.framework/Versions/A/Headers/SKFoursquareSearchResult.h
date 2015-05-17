//
//  SKFoursquareSearchResult.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKSearchResult.h"

/**SKFoursquareSearchResult - stores the information for a Foursquare search result
 */

@interface SKFoursquareSearchResult : SKSearchResult
{
}

/**The unique identifier for the Foursquare search result.
 */
@property(nonatomic, strong) NSString *resultId;

/**The distance of the POI retrieved by the search from the search center.
 */
@property(nonatomic, readwrite) long distance;

/**The rating for the POI retrieved by the search.
 */
@property(nonatomic, readwrite) double rating;

/**Users tip count.
 */
@property(nonatomic, readwrite) int tipCount;

/**Check in count.
 */
@property(nonatomic, readwrite) int checkinCount;

/**Number of users that reported being cheched in at the moment.
 */
@property(nonatomic, readwrite) int hereNowCount;

/**The list with the foursquare Poi images (an array with the SKFoursquarePoiImage).
 */
@property(nonatomic, strong) NSArray *foursquareSearchPoiImageList;

/**The URL for the Foursquare POI.
 */
@property(nonatomic, strong) NSString *foursquarePOIUrl;

/**The Web URL for the Foursquare POI.
 */
@property(nonatomic, strong) NSString *webSiteUrl;

/**The phone number for the Foursquare POI.
 */
@property(nonatomic, strong) NSString *phoneNumber;

/**The list with the tags for the foursquare Poi.
 */
@property(nonatomic, strong) NSArray *foursquareSearchPoiTagList;

/**Creates a default SKFoursquareSearchResult object
 @return - the default object
 */
+(instancetype)foursquareSearchResult;

@end
