//
//  SKSearchService.h
//  ForeverMapNGX
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKSearchServiceDelegate.h"
#import "SKDefinitions.h"

@class SKMultiStepSearchSettings;
@class SKNearbySearchSettings;
@class SKOneLineSearchSettings;

/** SKSearchService class provides services for searching POIs and addresses.
    SKSearchService supports one search at a time. If multiple search requests were started, only the latest request will be processed.
 */
@interface SKSearchService : NSObject

/** Returns the singleton SKSearchService instance.
 */
+ (instancetype)sharedInstance;

/** The delegate that must conform to SKSearchServiceDelegate protocol, used for receiving search results.
 */
@property(atomic,weak) id<SKSearchServiceDelegate> searchServiceDelegate;

/** The maximum number of search results that will be returned by a search. The default value is 20.
 */
@property(nonatomic,assign) int searchResultsNumber;

/** The POI categories hierarchy. The keys are the main categories (SKPOIMainCategory) and the values are arrays of subcategories (SKPOICategory).
 */
@property(nonatomic,readonly,strong) NSDictionary *categoriesFromMainCategories;

/** Starts a multi-step search. It works only offline with data from offline packages.
 For geocoding an address, multiple steps are required: choosing the country, then the city, then the street, all from a previously retrieved list.
 The results will be retrieved on the searchService:didRetrieveMultiStepSearchResults: method of the SKSearchServiceDelegate protocol.
 For more information about search parameters, check SKMultiStepSearchSettings.
 @param multiStepObject Specifies the search settings.
 @return The status of starting the search operation.
 */
- (SKMapSearchStatus)startMultiStepSearchWithSettings:(SKMultiStepSearchSettings *)multiStepObject;

/** Starts a nearby search for streets and POIs around a coordinate.
 The results will be retrieved on the searchService:didRetrieveNearbySearchResults:withSearchMode: method of the SKSearchServiceDelegate protocol.
 For more information about search parameters, check SKNearbySearchSettings.
 @param nearbySearchObject Specifies the search settings.
 @return The status of starting the search operation.
 */
- (SKMapSearchStatus)startNearbySearchWithSettings:(SKNearbySearchSettings *)nearbySearchObject;

/** Cancels the ongoing search request.
 */
- (void)cancelSearch;

/** Supports multi line, country based address search. In offline mode, the address search works only if the user has downloaded map packages for a specific country.
 @param country The code of the country.
 @param state The name of the state.
 @param city The name of the city or zip code.
 @param street The name of the street.
 @param houseNumber The house number.
 @param searchMode Specifies the search type. (SKSearchOnline for an online search, SKSearchOffline for an offline search or SKSearchHybrid - tries to search online but if there are no search results, performs also an offline search).
 @return The status of starting the search operation.
 */
- (SKMapSearchStatus)startAddressSearchWithCountry:(NSString *)country state:(NSString *)state city:(NSString *)city street:(NSString *)street houseNumber:(NSString *)houseNumber searchMode:(SKSearchMode)searchMode;

/** Supports oneline search using the parameters provided by the oneLineSearchSettings.
 @param oneLineSearchSettings Specifies the search settings.
 @return The status of starting the search operation.
 */
- (SKMapSearchStatus)startOneLineSearch:(SKOneLineSearchSettings *)oneLineSearchSettings;

/** Supports search for house numbers from a street
 @param streetID - [In] The ID of the street for which the house number should be returned. This ID must be the ID of a street from a previous search operation.
 @return The status of starting the search operation.
 */
- (SKMapSearchStatus)startHouseNumberSearchWithId:(long long)streetID;
@end
