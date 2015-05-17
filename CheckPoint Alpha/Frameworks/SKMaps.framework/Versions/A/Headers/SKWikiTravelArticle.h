//
//  SKWikiTravelArticle.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKDefinitions.h"

/**SKWikiTravelArticle class provides support for storing information about a Wiki Travel article.
 */
@interface SKWikiTravelArticle : NSObject
{
}

/**The download status for the Wiki Travel article (possible values: MissingArticle, MissingArticleImages, CompleteArticle)
 */
@property(nonatomic, readwrite) SKWikiArticleDownloadStatus articleDownloadStatus;

/**The path to the downloaded article
 */
@property(nonatomic, strong) NSString *path;

/**An array of paths to the article images 
 */
@property(nonatomic, strong) NSArray *downloadedImages;

/**Creates an empty SKWikiTravelArticle object
 @return - an empty autoreleased object
 */
+(instancetype)wikiTravelArticle;

@end
