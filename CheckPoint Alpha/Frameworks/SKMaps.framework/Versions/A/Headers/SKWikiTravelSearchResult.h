//
//  SKWikiTravelSearchResult.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKSearchResult.h"

/**SKWikiTravelSearchResult - stores the information for a Wiki Travel search result
 */
@interface SKWikiTravelSearchResult : SKSearchResult
{
}

/**It's available only for Wiki Travel articols. It specifies the number of children for a Wiki Travel articol.
 */
@property(nonatomic, readwrite) int numberOfChildren;

/**It's available only for Wiki Travel articols. It specifies if a Wiki Travel articol is downloaded.
 */
@property(nonatomic, readwrite) BOOL isDowloaded;

/**The download URL for a Wiki Travel package. Used only in search objects retrived by a Wiki Travel search.
 */
@property(nonatomic, strong) NSString *wikiTravelPackageURL;

/**Creates an empty SKWikiTravelSearchResult object
 @return - the default object
 */
+(instancetype)wikiTravelSearchResult;

@end
