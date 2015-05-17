//
//  SKWikiTravelPOIDetails.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

/**SKWikiTravelPOIDetails - stores the information about a Wiki Travel POI
 */
@interface SKWikiTravelPOIDetails : NSObject
{
}

/**The name of the Wiki Travel article in Englist
 */
@property(nonatomic, strong) NSString *englishArticleName;

/**The name of the Wiki Travel article in German
 */
@property(nonatomic, strong) NSString *germanArticleName;

/**The name of the Wiki Travel article in French
 */
@property(nonatomic, strong) NSString *frenchArticleName;

/**The name of the Wiki Travel article in Italian
 */
@property(nonatomic, strong) NSString *italianArticleName;

/**The name of the Wiki Travel article in Spanish
 */
@property(nonatomic, strong) NSString *spanishArticleName;

/**Creates an empty SKWikiTravelPOIDetails
 @return - an empty autoreleased object
 */
+(instancetype)emptySKWikiTravelPOIDetails;

@end
