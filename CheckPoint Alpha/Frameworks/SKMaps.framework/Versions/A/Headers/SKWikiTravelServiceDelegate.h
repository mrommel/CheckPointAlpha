//
//  SKWikiTravelServiceDelegate.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SKWikiTravelService;

/**The SKWikiTravelServiceDelegate defines a set of optional methods that you can use to receive wiki travel callbacks.
 */
@protocol SKWikiTravelServiceDelegate <NSObject>
@optional

/**Called for a successfull wiki travel index file download.
 @param wikiTravelService - The wiki travel service
 @param languageCode - language code for the index file.
 */
-(void)wikiTravelService:(SKWikiTravelService*)wikiTravelService didFinishDownloadingIndexFileForLanguage:(NSString *)languageCode;

/**Called for a failed wiki travel index file download.
 @param wikiTravelService - The wiki travel service
 @param languageCode - language code for the index file. 
 */
-(void)wikiTravelService:(SKWikiTravelService*)wikiTravelService didFailDownloadingIndexFileForLanguage:(NSString *)languageCode;

/**Called for a successfull wiki travel article or article image download. This callback will be called multiple times for an article (once for the article itself which is a JSON file and once for every article image)
 @param wikiTravelService - The wiki travel service
 @param path - the path to the wiki travel article or article image.
 */
-(void)wikiTravelService:(SKWikiTravelService*)wikiTravelService didFinishDownloadingArticleAtPath:(NSString *)path;

/**Called for a failed wiki travel article or article image download.
 @param wikiTravelService - The wiki travel service
 @param path - the path to the wiki travel article or article image for which the download failed.
 */
-(void)wikiTravelService:(SKWikiTravelService*)wikiTravelService didFailDownloadingArticleAtPath:(NSString *)path;

/**Called for a successfull Wiki Travel search
 @param wikiTravelService - The wiki travel service
 @param searchResults - Contains the Wiki Travel search results (a list of SKSearchResult)
 */
-(void)wikiTravelService:(SKWikiTravelService*)wikiTravelService didRetrieveSearchResults:(NSArray *)searchResults;

/**Called for a failed Wiki Travel search
 @param wikiTravelService - The wiki travel service
 */
-(void)wikiTravelServiceDidFailToRetrievelSearchResults:(SKWikiTravelService*)wikiTravelService;

@end
