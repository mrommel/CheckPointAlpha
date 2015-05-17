//
//  SKAppleSearchService.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class SKAppleSearchObject;

/** SKAppleSearchService class provides services for searching addresses using Apple geocoder.
 
 Important:
 SKAppleSearchService supports one search at a time. If multiple search requests were started, only the latest request will be processed.
 
 Usage:
 
 1. Create an SKAppleSearchObject
 
 2. Assign to the SKAppleSearchObject a CLGeocodeCompletionHandler where the results will be processed
 
 e.g. CLGeocodeCompletionHandler handler = ^(NSArray *placemarks, NSError *error){
       // results processing
 };
 
 3. Send a search request:
 
 e.g.  [ [SKAppleSearchService sharedInstance] addressSearch:searchObject withCompletionHandler:handler];
 
 4. Receive the search results in the completion handler specified above
  
 5. Cancel an ongoing search request if needed. (before sending a new search request, if the caller object is destroyed before the search results arrive)
 
 [ [SKAppleSearchService sharedInstance] cancelSearch];
 */

@interface SKAppleSearchService : NSObject

/** Returns and array of country strings that are fully supported by Apple geocoder.
 */
@property(nonatomic, strong, readonly) NSArray *supportedCountries;

/**Returns the shared defaults object.
 */
+(instancetype)sharedInstance;

/**Supports address search using Apple geocoder
 @param appleSearchObject - [In] Specifies the search criterias
 @param region - [In] Specifies circular search area with center, radius
 @param completionHandler - [In] Competion handler executed when search is finished
 */
-(void)startAddressSearchWithObject:(SKAppleSearchObject *)appleSearchObject inRegion:(CLRegion *)region withCompletionHandler:(CLGeocodeCompletionHandler) completionHandler;

/**Cancels an ongoing search request.
 */
-(void)cancelSearch;


@end
