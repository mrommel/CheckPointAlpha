//
//  UserManager.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "UserManager.h"

#import "WSUserAPIManager.h"
#import "AuthorizationManager.h"
#import "WSAPIClient.h"

static NSString *const kWifiToken   = @"wifi_token";

// Authentication related constants
NSString *const USER_MANAGER_AUTHENTICATION_SUCCEEDED = @"UserManagerAuthenticationSucceeded";
NSString *const USER_MANAGER_AUTHENTICATION_FAILED = @"UserManagerAuthenticationFailed";

@implementation UserManager

static UserManager *shared = nil;

#pragma mark - Initializer

+ (UserManager *)sharedInstance
{
    @synchronized (self) {
        if (shared == nil) {
            shared = [[self alloc] init];
        }
    }
    
    return shared;
}

- (void)authenticateUserWithUsername:(NSString *)username andPassword:(NSString *)password
{
    [[WSUserAPIManager sharedInstance] authenticateUserWithUsername:username andPassword:password responseBlock:^(id responseObject, WSError *error) {
        if (error) {
            // Post login failed notification
            [[NSNotificationCenter defaultCenter] postNotificationName:USER_MANAGER_AUTHENTICATION_FAILED object:nil];
        } else {
            [self saveAccessToken:responseObject];
            // Post login succeeded notification
            [[NSNotificationCenter defaultCenter] postNotificationName:USER_MANAGER_AUTHENTICATION_SUCCEEDED object:nil];
        }
    }];
}

- (void)saveAccessToken:(id)responseObject
{
    // Save the access token
    NSString *accessToken = responseObject[kAccessToken];
    DLog(@"%@", accessToken);
    //appending the unique device id to the token
    accessToken = [accessToken stringByAppendingFormat:@":%@", [[[UIDevice currentDevice] identifierForVendor] UUIDString]];
    [[AuthorizationManager sharedInstance] saveAccessToken:accessToken isFacebookToken:NO];
    [[WSAPIClient sharedClient] setAuthorizationHeaderWithUsername:kAccessToken password:[[AuthorizationManager sharedInstance] accessToken]];
}

@end
