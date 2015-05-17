//
//  WSAPIClient.h
//  eBike
//
//  Created by Liliana Bulgaru on 12/13/12.
//  Copyright (c) 2012 MobilityMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFHTTPClient.h"

@interface WSAPIClient : AFHTTPClient

+ (WSAPIClient *)sharedClient;

@end
