//
//  WSAPIClient.m
//  eBike
//
//  Created by Liliana Bulgaru on 12/13/12.
//  Copyright (c) 2012 MobilityMedia. All rights reserved.
//

#import "WSAPIClient.h"
#import "AFJSONRequestOperation.h"
#import "AuthorizationManager.h"
//#import "WSConstants.h"

static CGFloat const kTimeoutInterval = 30; //seconds

@implementation WSAPIClient

+ (WSAPIClient *)sharedClient
{
    static WSAPIClient *_sharedClient = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        DLog(@"api client %@", @"https://nyon-test.de/ebikeconnect/api/");
        _sharedClient = [[WSAPIClient alloc] initWithBaseURL:[NSURL URLWithString:@"https://nyon-test.de/ebikeconnect/api/"]];
    });
	
    return _sharedClient;
}

- (id)initWithBaseURL:(NSURL *)url
{
    if (self = [super initWithBaseURL:url]) {
        [self registerHTTPOperationClass:[AFJSONRequestOperation class]];
        [self setDefaultHeader:@"Accept" value:@"application/json"];
        [self setParameterEncoding:AFJSONParameterEncoding];
        NSString *accessToken = [[AuthorizationManager sharedInstance] accessToken];
        if (accessToken) {
            [self setAuthorizationHeaderWithUsername:[[AuthorizationManager sharedInstance] getTokenType] password:accessToken];
            DLog(@"TOKEN = %@", [self defaultValueForHeader:@"Authorization"]);
        }
    }
    
    return self;
}

// Override
- (NSMutableURLRequest *)requestWithMethod:(NSString *)method path:(NSString *)path parameters:(NSDictionary *)parameters
{
    NSMutableURLRequest *request = [super requestWithMethod:method path:path parameters:parameters];
    [request setTimeoutInterval:kTimeoutInterval];
    
    return request;
}

@end
