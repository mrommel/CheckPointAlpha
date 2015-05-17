//
//  UserManager.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <Foundation/Foundation.h>

// Authentication related constants
extern NSString *const USER_MANAGER_AUTHENTICATION_SUCCEEDED;
extern NSString *const USER_MANAGER_AUTHENTICATION_FAILED;
extern NSString *const USER_UPLOAD_FINISH_NOTIFICATION;
extern NSString *const USER_UPLOAD_FAIL_NOTIFICATION;
extern NSString *const USER_EMAIL_ALREADY_REGISTERED;
extern NSString *const USER_EMAIL_OK_TO_REGISTER;
extern NSString *const USER_REGISTER_FINISH_NOTIFICATION;
extern NSString *const USER_REGISTER_FAIL_NOTIFICATION;

@interface UserManager : NSObject

+ (UserManager *)sharedInstance;

- (void)authenticateUserWithUsername:(NSString *)username andPassword:(NSString *)password;

@end
