//
//  SKTripAdvisorSearchServiceDelegate.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SKTripAdvisorSearchResult;
@class SKTripAdvisorSearchService;

/**The SKTripAdvisorSearchServiceDelegate defines a set of optional methods that you can use to receive search results. The SKTripAdvisorSearchService class uses these methods to notify the caller objects when a specific search operation finished. The searches happen asynchronously, but these methods are called on the main thread.
 */
@protocol SKTripAdvisorSearchServiceDelegate <NSObject>
@optional
/**Called for a successfull Trip Advisor local search operation.
 @param tripAdvisorSearchService - The trip advisor search service
 @param searchResults - Contains the result of a local search (a list of SKTripAdvisorSearchResult)
 */
-(void)tripAdvisorService:(SKTripAdvisorSearchService*)tripAdvisorSearchService didRetrieveLocalSearchResults:(NSArray *)searchResults;

/**Called for a failed Trip Advisor local search operation.
 @param tripAdvisorSearchService - The trip advisor search service
 */
-(void)tripAdvisorServiceDidFailToRetrieveLocalSearchResults:(SKTripAdvisorSearchService*)tripAdvisorSearchService;

/**Called for a successfull Trip Advisor POI detail search operation.
 @param tripAdvisorSearchService - The trip advisor search service
 @param searchResult - Contains further details about a POI
 */
-(void)tripAdvisorService:(SKTripAdvisorSearchService*)tripAdvisorSearchService didRetrievePOIDetails:(SKTripAdvisorSearchResult *)searchResult;

/**Called for a failed Trip Advisor POI details search operation.
 @param tripAdvisorSearchService - The trip advisor search service
 */
-(void)tripAdvisorServiceDidFailToRetrievePOIDetails:(SKTripAdvisorSearchService*)tripAdvisorSearchService;

@end
