//
//  AuthorizationManager.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "AuthorizationManager.h"

#import "STKeychain.h"

// Access token constant
NSString *const kAccessToken = @"access_token";
NSString *const kFacebookToken = @"facebook_token";
// Keychain service name
static NSString *const kServiceName = @"BoschAuthorizationService";

@interface AuthorizationManager()

@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *tokenType;
@property (nonatomic, readwrite, assign) AuthenticationProvider authenticationProvider;

@end

@implementation AuthorizationManager
@synthesize token = _token;

+ (AuthorizationManager *)sharedInstance
{
    static AuthorizationManager *shared = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        shared = [[self alloc] init];
        [shared accessToken];
    });
    
    return shared;
}

- (NSString *)accessToken
{
    if (!self.token && [self hasBoschAccessToken]) {
        self.token = [STKeychain getPasswordForUsername:kAccessToken andServiceName:kServiceName error:NULL];
        self.tokenType = kAccessToken;
    } else if (!self.token && [self hasFacebookAccessToken]) {
        self.token = [STKeychain getPasswordForUsername:kFacebookToken andServiceName:kServiceName error:NULL];
        self.tokenType = kFacebookToken;
    }
    
    return self.token;
}

- (void)saveAccessToken:(NSString *)accessToken isFacebookToken:(BOOL)fbToken
{
    if (!accessToken) {// invalid access token
        return;
    }
    self.token = accessToken;
    self.tokenType = (fbToken) ? kFacebookToken : kAccessToken;
    [STKeychain storeUsername:self.tokenType andPassword:self.token forServiceName:kServiceName updateExisting:YES error:NULL];
    self.authenticationProvider = self.tokenType == kFacebookToken ? FACEBOOK : BOSCH;
}

- (void)removeAccessToken
{
    self.token = nil;
    NSError *error = nil;
    [STKeychain deleteItemForUsername:self.tokenType andServiceName:kServiceName error:&error];
}

- (NSString *)getTokenType
{
    return self.tokenType;
}

- (BOOL)hasBoschAccessToken
{
    return ([STKeychain getPasswordForUsername:kAccessToken andServiceName:kServiceName error:NULL]) ? YES : NO;
}

- (BOOL)hasFacebookAccessToken
{
    return ([STKeychain getPasswordForUsername:kFacebookToken andServiceName:kServiceName error:NULL]) ? YES : NO;
}

@end
