//
//  SKWikiTravelSearchObject.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKDefinitions.h"

/**SKWikiTravelSearchObject - contains the input parameters for a Wiki Travel search
 Important: to retrive the list of installed (offline) Wiki Travel articles set the isOffline flag to YES. In case the searchTerm is also empty, a search with such SKWikiTravelSearchObject will return the top level installed articles.
 */

@interface SKWikiTravelSearchObject : NSObject
{
}

/**The articol id of the parent articol object.
 */
@property(nonatomic, readwrite) unsigned long long parentArticolID;

/**The language code for the search (e.g. EN, DE,...).
 */
@property(nonatomic, strong) NSString *languageCode;

/**The search text used to filter the search results.
 */
@property(nonatomic, strong) NSString *searchTerm;

/**YES if the search should be made only on installed packages. By default this property is NO.
 */
@property(nonatomic, readwrite) BOOL isInstalled;

/**The maximum number of the Wiki Travel search results. By default the number is 20.
 */
@property(nonatomic, readwrite) int maximumResultsNumber;

/**Specify the way the comparison of searchTerm will take place. The default value is SKProximityMatch.
 */
@property(nonatomic, readwrite) SKWikiTravelSearchMode searchMode;

/**Specify what articles should be take into account when searching.
 */
@property(nonatomic, readwrite) SKArticleSearchType articleSearchType;

/**Creates an empty SKWikiTravelSearchObject
 @return - an empty autoreleased object
 */
+(instancetype)emptySKWikiTravelSearchObject;

@end
