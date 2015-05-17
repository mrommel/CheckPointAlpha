//
//  SKFoursquareSearchService.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKFoursquareSearchServiceDelegate.h"
#import "SKDefinitions.h"
#import <CoreGraphics/CGGeometry.h>

@class SKFoursquareSearchObject;

/**SKFoursquareSearchService class provides services for POI searches.
 */

@interface SKFoursquareSearchService : NSObject
{
}

/**Returns the shared defaults object.
 */
+(instancetype)sharedInstance;

/**The caller objects should adopt the SKFoursquareSearchServiceDelegate to receive callbacks.
 */
@property(atomic, weak) id<SKFoursquareSearchServiceDelegate> foursquareSearchServiceDelegate;

/**Supports Foursquare local search.
 @param foursquareSearchObject - stores the input parameters for the Foursquare local search.
 @return - the search status (SKNoError for a successfull search)
 search results - the search results are returned through delegate calls (foursquareLocalSearchResultsRetrieved, failedToRetrieveFoursquareLocalSearchResults)
 */
-(SKMapSearchStatus)localSearch:(SKFoursquareSearchObject *)foursquareSearchObject;

/**Supports Foursquare search for POI details.
 @param poiID - stores the id of the POI retrieved by a previous Foursquare search
 @param imageSize - the image size in pixels for the result images. The default value is 50 pixels width and 50 pixels height
 @return - the search status (SKNoError for a successfull search)
 search results - the search results are returned through delegate calls (foursquarePoiDetailsRetrieved, failedToRetrieveFoursquarePoiDetails)
 */
-(SKMapSearchStatus)foursquarePoiDetails:(NSString *)poiID withImageSize:(CGSize)imageSize;

/**Cancels an ongoing search request.
 */
-(void)cancelSearch;

@end
