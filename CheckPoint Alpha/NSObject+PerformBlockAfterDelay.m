//
//  NSObject_PerformBlockAfterDelay.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "NSObject+PerformBlockAfterDelay.h"

@implementation NSObject (PerformBlockAfterDelay)

- (void)performBlock:(void (^)(void))block
          afterDelay:(NSTimeInterval)delay
{
    block = [[block copy] autorelease];
    [self performSelector:@selector(fireBlockAfterDelay:)
               withObject:block
               afterDelay:delay];
}

- (void)fireBlockAfterDelay:(void (^)(void))block {
    block();
}

@end
