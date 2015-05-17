//
//  SKTripAdvisorSearchService.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKTripAdvisorSearchServiceDelegate.h"
#import "SKDefinitions.h"

@class SKTripAdvisorSearchObject;

/**SKTripAdvisorSearchService class provides services for POI searches.
 */

@interface SKTripAdvisorSearchService : NSObject
{
}

/**Returns the shared defaults object.
 */
+(instancetype)sharedInstance;

/**The caller objects should adopt the SKTripAdvisorSearchServiceDelegate to receive callbacks.
 */
@property(atomic, weak) id<SKTripAdvisorSearchServiceDelegate> tripAdvisorSearchServiceDelegate;

/**Supports Trip Advisor POI local search.
 @param tripAdvisorSearchObject - stores the input parameters for the Trip Advisor local search.
 @return - the search status (SKNoError for a successfull search)
 search results - the search results are returned through delegate calls (tripAdvisorLocalSearchResultsRetrieved, failedToRetrieveTripAdvisorLocalSearchResults)
 */
-(SKMapSearchStatus)localSearch:(SKTripAdvisorSearchObject *)tripAdvisorSearchObject;

/**Supports Trip Advisor search for POI details.
 @param poiID - stores the ID of a POI retrieved by a previous Trip Advisor search.
 @return - the search status (SKNoError for a successfull search)
 */
-(SKMapSearchStatus)poiDetails:(long long)poiID;

/**Cancels an ongoing search request.
 */
-(void)cancelSearch;

@end
