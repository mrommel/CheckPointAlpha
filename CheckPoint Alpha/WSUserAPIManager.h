//
//  WSUserAPIManager.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Constants.h"

@interface WSUserAPIManager : NSObject

+ (WSUserAPIManager *)sharedInstance;

// Authenticates the username and password againts the online server
- (void)authenticateUserWithUsername:(NSString *)username andPassword:(NSString *)password responseBlock:(ResponseBlock)block;

@end
