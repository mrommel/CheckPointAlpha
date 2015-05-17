//
//  SKWikiTravelService.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKWikiTravelServiceDelegate.h"
#import "SKDefinitions.h"

@class SKWikiTravelSearchObject;
@class SKWikiTravelArticle;

/**SKWikiTravelService class provides support for managing wiki travel articlesSKWikiTravelService.
 */

@interface SKWikiTravelService : NSObject
{
}

/**Returns the shared defaults object.
 */
+(instancetype)sharedInstance;

/**The caller objects should adopt the SKWikiTravelServiceDelegate to receive callbacks.
 */
@property(atomic, weak) id<SKWikiTravelServiceDelegate> wikiTravelServiceDelegate;

/**Downloads the index file for a specific language. The index file is required for the wiki tarvel search. 
 @param languageCode - language code for the index file. Use lower case letters (e.g. de, en, ...)
 */
-(void)downloadWikiTravelIndexFile:(NSString *)languageCode;

/**Cancels an ongoing wiki travel index file download
 @param languageCode - language code for the index file. Use lower case letters (e.g. de, en, ...)
 */
-(void)cancelWikiTravelIndexFileDownload:(NSString *)languageCode;

/**Returns the list of installed index files
 @return The list of installed index files
 */
-(NSArray *)wikiTravelInstalledIndexFiles;

/**Instals a downloaded Wiki Travel package
 @param languageCode - language code for the wiki travel package.
 @param packageUrl - the download URL for the wiki travel package that needs to be installed.
 @param packagePath - the full path to the wiki travel package. The file will be deleted from this location.
 @return YES if the package was added with success, NO otherwise.
 */
-(BOOL)addWikiTravelPackage:(NSString *)languageCode withPackageName:(NSString *)packageUrl withPackagePath:(NSString *)packagePath;

/**Deletes an installed Wiki Travel package
 @param packagePath - the full path to the package that needs to be deleted.
 @return YES if the package was successfully deleted, NO otherwise.
 */
-(BOOL)deleteWikiTravelPackage:(NSString *)packagePath;

/**Returns the list of installed wiki travel packages for a specific language (an array of SKWikiTravelPackage objects)
 @param languageCode - language code for the installed wiki travel package.
 @return The list of installed packages
 */
-(NSArray *)installedPackages:(NSString *)languageCode;

/**Cancels an ongoing article load request.
 @param languageCode - language code for the article
 @param articleID - the article ID
 */
-(void)cancelArticleLoad:(NSString *)languageCode withArticleID:(unsigned long long) articleID;

/**Returns the content of a Wiki Travel article
 @param languageCode - language code for the article
 @param articleID - the article ID. This is retrieved by the Wiki Travel search.
 @return The Wiki Travel article represented by the SKWikiTravelArticle object
 */
-(SKWikiTravelArticle *)wikiTravelArticle:(NSString *)languageCode withArticleID:(unsigned long long) articleID;

/**Set the image size that should be downloaded for wiki travel articles. 
 @param wikiTravelArticleImageSize - the image size
 */
-(void)setWikiTravelArticleImageSize:(SKWikiTravelArticleImageSize)wikiTravelArticleImageSize;

/**Cancels an ongoing search request.
 */
-(void)cancelSearch;

/**Supports search for Wiki Travel articles
 @param wikiTravelSearchObject - [In] Specifies the search criterias
 @return - the search status (SKNoError for a successfull search)
 */
-(SKMapSearchStatus)wikiTravelSearch:(SKWikiTravelSearchObject *)wikiTravelSearchObject;

/**Returns the size (in bytes) of a Wiki Travel package that needs to be downloaded.
 @param languageCode - language code for the wiki travel package.
 @param articleID - the article ID. This is retrieved by the Wiki Travel search.
 @return The size in bytes for the Wiki Travel package 
 */
-(int)wikiTravelPackageDownloadSize:(NSString *)languageCode withArticleID:(unsigned long long) articleID;

@end
