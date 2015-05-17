//
//  SKFoursquareSearchServiceDelegate.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SKFoursquareSearchResult;
@class SKFoursquareSearchService;

/**The SKFoursquareSearchServiceDelegate defines a set of optional methods that you can use to receive search results. The SKFoursquareSearchService class uses these methods to notify the caller objects when a specific search operation finished. The searches happen asynchronously, but these methods are called on the main thread.
 */

@protocol SKFoursquareSearchServiceDelegate <NSObject>
@optional
/**Called for a successfull Foursquare local search operation.
 @param foursquareSearchService - The foursquare search service
 @param searchResults - Contains the result of a local search
 */
-(void)foursquareSearchService:(SKFoursquareSearchService*)foursquareSearchService didRetrieveSearchResults:(NSArray *)searchResults;

/**Called for a failed Foursquare local search operation.
 @param foursquareSearchService - The foursquare search service
 */
-(void)foursquareSearchServiceDidFailToRetrieveLocalSearchResults:(SKFoursquareSearchService*)foursquareSearchService;

/**Called for a successfull Foursquare POI detail search operation.
 @param foursquareSearchService - The foursquare search service
 @param foursquareSearchResult - Contains further details about a POI
 */
-(void)foursquareSearchService:(SKFoursquareSearchService*)foursquareSearchService didRetrievePOIDetails:(SKFoursquareSearchResult *)foursquareSearchResult;

/**Called for a failed Foursquare POI details search operation.
 @param foursquareSearchService - The foursquare search service
 */
-(void)foursquareSearchServiceDidFailToRetrievePOIDetails:(SKFoursquareSearchService*)foursquareSearchService;

@end
