//
//  MMCustomAlertView.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Constants.h"

@protocol MMCustomViewControllerDelegate;

@interface MMCustomAlertView : UIView

@property (strong, nonatomic) AlertDismissBlock alertDismissBlock;
@property (assign, nonatomic) id<MMCustomViewControllerDelegate> alertViewControllerDelegate;

- (void)loadXibFile;
// Shows the alert view
- (void)show;
- (void)hide;

@end