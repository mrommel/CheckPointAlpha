//
//  MapViewAnnotation.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "MapViewAnnotation.h"

@implementation MapViewAnnotation

@synthesize coordinate = _coordinate;
@synthesize title = _title;

- (id)initWithTitle:(NSString *)title andCoordinate:(CLLocationCoordinate2D)coordinate
{
    self = [super init];
    
    if (self) {
        _title = title;
        _coordinate = coordinate;
    }
    
    return self;
}
@end
