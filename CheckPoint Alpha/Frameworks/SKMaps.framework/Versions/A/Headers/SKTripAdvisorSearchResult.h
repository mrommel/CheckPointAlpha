//
//  SKTripAdvisorSearchResult.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKSearchResult.h"

/**SKTripAdvisorSearchResult - stores the information for a Trip Advisor search result retrieved by the Trip Advisor search
 */
@interface SKTripAdvisorSearchResult : SKSearchResult
{
}

/**Download URL for the search object thumbnail image. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, strong) NSString *thumbnailImageURL;

/**Download URL for the search object image. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, strong) NSString *imageURL;

/**The ranking for the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, strong) NSString *ranking;

/**The raw ranking for the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, readwrite) double rawRanking;

/**The rating for the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, readwrite) double rating;

/**The price for the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, strong) NSString *price;

/**The distance of the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, readwrite) long distance;

/**The number of reviews of the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, readwrite) int reviewCount;

/**The one line address for the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, strong) NSString *onelineAddress;

/**The URL for the POI retrieved by the search (it provides further information). Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, strong) NSString *poiUrl;

/**The class (e.g. for hotels) of the POI retrieved by the search. Some searches (e.g. Trip Advisor search) provide this information.
 */
@property(nonatomic, readwrite) int poiClass;

/**Creates an empty SKTripAdvisorSearchResult object
 @return - the default object
 */
+(instancetype)tripAdvisorSearchResult;

@end
