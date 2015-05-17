//
//  WSError.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "WSError.h"

NSInteger kDefaultErrorCode = -1;

// Keys for parsing the error response
static NSString *const kErrors                              = @"errors";
static NSString *const kError                               = @"error";
static NSString *const kMessage                             = @"message";
static NSString *const kCode                                = @"code";

@implementation WSError

- (id)initWithResponseObject:(id)responseObject andError:(NSError *)afError errorCode:(NSInteger)errorCode
{
    if (self = [self initWithResponseObject:responseObject errorCode:errorCode]) {
        _error = afError;
    }
    
    return self;
}

- (id)initWithResponseObject:(id)responseObject errorCode:(NSInteger)errorCode
{
    if (self = [super init]) {
        self.code = errorCode;
        if (responseObject) {
            [self initializeWithData:responseObject];
        }
        [self setErrorTexts];
    }
    
    return self;
}

- (id)init
{
    return [self initWithResponseObject:nil errorCode:kDefaultErrorCode];
}

- (void)initializeWithData:(id)json
{
    NSError *error = nil;
    NSData *data = [json dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *jsonResponse = [NSJSONSerialization JSONObjectWithData:data
                                                                 options:kNilOptions
                                                                   error:&error];
    if (!error) {
        NSArray *errorsDictionary = jsonResponse[kErrors];
        if (errorsDictionary.count > 0) {
            if ([errorsDictionary[0][kCode] integerValue] == 0) {
                return;
            }
            self.code = [errorsDictionary[0][kCode] integerValue];
            self.message = errorsDictionary[0][kMessage];
        }
    }
}

- (void)setErrorTexts
{
    // TODO: Override text messages and change titles
    self.message = NSLocalizedString(@"error.message.unknown", nil);
    switch (self.code) {
        case kAuthentificationFailed:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kPageNonexistent:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kInvalidToken:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kInvalidPasswordError:
            self.title = NSLocalizedString(@"alert.error.title.text", nil);
            self.message = NSLocalizedString(@"settings.user.passwordChange.validation.alert4", nil);
            break;
            
        case kSamePasswordsError:
            self.title = NSLocalizedString(@"alert.error.title.text", nil);
            self.message = NSLocalizedString(@"settings.user.passwordChange.validation.alert3", nil);
            break;
            
        case kNotModifiedError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kBadRequestError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kUnauthorizedError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kForbiddenError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kNotFoundError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kInternalServerError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kBadGatewayError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kServiceUnavailableError:
            self.title = NSLocalizedString(@"alert.unexpectedError.title", nil);
            break;
            
        case kBluetoothDisabledError:
            self.title = NSLocalizedString(@"alert.error.title.text", nil);
            self.message = NSLocalizedString(@"error.message.bluetooth.disabled", nil);
            break;
            
        default:
            self.title = NSLocalizedString(@"alert.error.title.text", nil);
            self.message = NSLocalizedString(@"error.message.unknown", nil);
            break;
    }
}

@end
