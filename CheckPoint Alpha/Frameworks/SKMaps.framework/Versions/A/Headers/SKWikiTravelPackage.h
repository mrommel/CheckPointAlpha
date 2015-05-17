//
//  SKWikiTravelPackage.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

/**SKWikiTravelPackage - stores the basic information for a Wiki Travel package
 */
@interface SKWikiTravelPackage : NSObject
{
}

/**The name of the wiki travel package
 */
@property(nonatomic, strong) NSString *packageName;

/**The path to the wiki travel package
 */
@property(nonatomic, strong) NSString *packagePath;

/**Creates an empty SKWikiTravelPackage object
 @return - an empty autoreleased object
 */
+(instancetype)emptyWikiTravelPackage;

@end
