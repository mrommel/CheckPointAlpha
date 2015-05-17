//
//  DataManager.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Constants.h"
#import "AFDownloadRequestOperation.h"

@interface DataManager : NSObject

+ (DataManager *)sharedInstance;

- (void)getDataFromServerWithPath:(NSString *)path withBlock:(ResponseBlock)block;
- (void)fetchMapPachageZipFromServerWithPath:(NSString *)pathToZip withProgressBar:(UIProgressView *)progressBar withBlock:(ResponseBlock)block;

@end
