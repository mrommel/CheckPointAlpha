//
//  WSUserAPIManager.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "WSUserAPIManager.h"

#import "WSAPIClient.h"
#import "AFJSONRequestOperation.h"
#import "UIDevice+IdentifierAddition.h"
#import "AFHTTPRequestOperation.h"

@implementation WSUserAPIManager

+ (WSUserAPIManager *)sharedInstance
{
    static WSUserAPIManager *shared = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        shared = [[self alloc] init];
    });
    return shared;
}

- (void)authenticateUserWithUsername:(NSString *)username andPassword:(NSString *)password responseBlock:(ResponseBlock)block
{
    // Set first the authorization header
    [[WSAPIClient sharedClient] setAuthorizationHeaderWithUsername:username password:password];
    // Create the URL request
    
    //Append Unique Device Id
    NSString *pathWithMobileId = [NSString stringWithFormat:@"%@%@", @"login/generate_token?mobile_id=", [[[UIDevice currentDevice] identifierForVendor] UUIDString]];
    
    NSMutableURLRequest *request = [[WSAPIClient sharedClient] requestWithMethod:@"GET" path:pathWithMobileId parameters:nil];
    // Perform the request
    AFJSONRequestOperation *jsonOperation =
    [AFJSONRequestOperation JSONRequestOperationWithRequest:request
                                                    success:^(NSURLRequest *request, NSHTTPURLResponse *response, id JSON) {
                                                        if (block) {
                                                            block(JSON, nil);
                                                        }
                                                    } failure:^(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON) {
                                                        if (block) {
                                                            block(JSON, (WSError *)error);
                                                        }
                                                    }];
    [[WSAPIClient sharedClient] enqueueHTTPRequestOperation:jsonOperation];
}

@end
