//
//  MMCustomAlertView.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "MMCustomAlertView.h"

@implementation MMCustomAlertView

- (void)loadXibFile
{
    // Load the view from nib file
    [[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self class]) owner:self options:nil];
}

- (void)show
{
    NSLog(@"Alert: %.0f, %.0f -> %.0fx%.0f ", self.frame.origin.x, self.frame.origin.y, self.frame.size.width, self.frame.size.height);
    [[[UIApplication sharedApplication] keyWindow] addSubview:self];
    [[[UIApplication sharedApplication] keyWindow] bringSubviewToFront:self];
    //[[[UIApplication sharedApplication] keyWindow] addSubview:self];
}

- (void)hide
{
    [self removeFromSuperview];
}

@end
