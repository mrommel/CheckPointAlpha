//
//  AuthorizationManager.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

extern NSString *const kAccessToken;
extern NSString *const kFacebookToken;

typedef NS_ENUM(NSUInteger, AuthenticationProvider) {
    BOSCH = 0,
    FACEBOOK
};
//
//  Manager that handles the authorization across the entire app (things like saving/accessing authorization tokens)
//
@interface AuthorizationManager : NSObject

+ (AuthorizationManager *)sharedInstance;

@property (nonatomic, readonly, assign) AuthenticationProvider authenticationProvider;

// Returns the current access token. It may be nil.
- (NSString *)accessToken;
// Saves the current access token in the keychain
- (void)saveAccessToken:(NSString *)accessToken isFacebookToken:(BOOL)fbToken;
// Removes the current access token from the keychain
- (void)removeAccessToken;
- (NSString *)getTokenType;
- (BOOL)hasFacebookAccessToken;
- (BOOL)hasBoschAccessToken;

@end
