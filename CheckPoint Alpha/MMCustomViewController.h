//
//  MMCustomViewController.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MMCustomAlertView.h"
#import "Constants.h"

typedef void (^CompletionBlock)(void);

@protocol MMCustomViewControllerDelegate <NSObject>

- (void)hideMMAlertViewController;

@end

@interface MMCustomViewController : UIViewController

@property (assign, nonatomic) id<MMCustomViewControllerDelegate>alertViewControllerDelegate;

- (void)showAlertOnParentViewController:(UIViewController *)parentViewController
                    withAlertParameters:(NSDictionary *)alertParameters
                    withCompletionBlock:(AlertDismissBlock)alertDismissBlock;

- (void)showTransparentViewControllerOnParentViewController:(UIViewController *)parentViewController;
- (void)hideTransparentViewController;

@end
