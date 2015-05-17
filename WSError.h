//
//  WSError.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSInteger const kInvalidInputError                       = 9;
static NSInteger const kInvalidJSONError                        = 14;
static NSInteger const kAuthentificationFailed                  = 32;
static NSInteger const kPageNonexistent                         = 34;
static NSInteger const kInvalidToken                            = 89;
static NSInteger const kInvalidPasswordError                    = 100;
static NSInteger const kSamePasswordsError                      = 102;
static NSInteger const kNotModifiedError                        = 304;
static NSInteger const kBadRequestError                         = 400;
static NSInteger const kUnauthorizedError                       = 401;
static NSInteger const kForbiddenError                          = 403;
static NSInteger const kNotFoundError                           = 404;
static NSInteger const kInternalServerError                     = 500;
static NSInteger const kBadGatewayError                         = 502;
static NSInteger const kServiceUnavailableError                 = 503;
static NSInteger const kBluetoothDisabledError                  = 504;

@interface WSError : NSObject

@property (nonatomic, assign)	NSInteger code;
@property (nonatomic, copy)		NSString *message;
@property (nonatomic, copy)		NSString *title;
@property (nonatomic, strong)	NSError *error;

- (id)initWithResponseObject:(id)responseObject errorCode:(NSInteger)errorCode;
- (id)initWithResponseObject:(id)responseObject andError:(NSError *)afError errorCode:(NSInteger)errorCode;

@end
