//
//  MMCustomViewController.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "MMCustomViewController.h"
#import "MMAlertView.h"
#import "AnimatedTransitioning.h"

static CGFloat const kAlertMessageFontSize = 17.0f;

NSString *const kAlertTypeKey = @"AlertTypeKey";

@interface MMCustomViewController () <MMCustomViewControllerDelegate, UIViewControllerTransitioningDelegate>

@property (nonatomic, strong) UIViewController *parentVC;
@property (nonatomic, strong) UIViewController *srcViewController;
@property (nonatomic, strong) UIViewController *destViewController;
@property (nonatomic, strong) AlertDismissBlock alertDismissBlock;

@end

@implementation MMCustomViewController

- (void)showAlertOnParentViewController:(UIViewController *)parentViewController
                    withAlertParameters:(NSDictionary *)alertParameters
                    withCompletionBlock:(AlertDismissBlock)alertDismissBlock
{
    MMCustomAlertView *alertViewRef = nil;
    if (!alertParameters[kAlertTypeKey] || [alertParameters[kAlertTypeKey] isEqualToNumber:@(kNotifyUserAlert)]) {
        MMAlertView *alertView = [self createAlertView:alertParameters];
        [alertView setAlertDismissBlock:alertDismissBlock];
        [alertView setAlertViewControllerDelegate:self];
        [self setAlertView:alertView withParameters:alertParameters];
        alertViewRef = alertView;
    }
    
    alertViewRef.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view setBackgroundColor:[UIColor clearColor]];
    [self.view addSubview:alertViewRef];
    [self addConstraintsToAlert:alertViewRef];
    
    self.parentVC = parentViewController;
    self.modalPresentationStyle = UIModalPresentationCustom;
    [self setTransitioningDelegate:self];
    [parentViewController presentViewController:self animated:YES completion:^{
        DLog(@"Presented MMAlertViewController from %@", NSStringFromClass([parentViewController class]));
        [self.parentVC.view endEditing:YES];
    }];
}

- (void)showTransparentViewControllerOnParentViewController:(UIViewController *)parentViewController
{
    [self.view setBackgroundColor:[UIColor clearColor]];
    self.parentVC = parentViewController;
    self.modalPresentationStyle = UIModalPresentationCustom;
    [self setTransitioningDelegate:self];
    [parentViewController presentViewController:self animated:YES completion:^{
        DLog(@"Presented MMAlertViewController from %@", NSStringFromClass([parentViewController class]));
    }];
}

- (void)hideTransparentViewController
{
    [self hideMMAlertViewController];
}

- (void)addConstraintsToAlert:(MMCustomAlertView *)alert
{
    NSLayoutConstraint *top = [NSLayoutConstraint
                               constraintWithItem:alert
                               attribute:NSLayoutAttributeTop
                               relatedBy:NSLayoutRelationEqual
                               toItem:self.view
                               attribute:NSLayoutAttributeTop
                               multiplier:1.0
                               constant:1];
    
    NSLayoutConstraint *bottom = [NSLayoutConstraint
                                  constraintWithItem:alert
                                  attribute:NSLayoutAttributeBottom
                                  relatedBy:NSLayoutRelationEqual
                                  toItem:self.view
                                  attribute:NSLayoutAttributeBottom
                                  multiplier:1.0
                                  constant:1];
    
    NSLayoutConstraint *width = [NSLayoutConstraint
                                 constraintWithItem:alert
                                 attribute:NSLayoutAttributeWidth
                                 relatedBy:NSLayoutRelationEqual
                                 toItem:self.view
                                 attribute:NSLayoutAttributeWidth
                                 multiplier:1.0
                                 constant:1];
    
    [self.view addConstraints:@[top, width, bottom]];
}

- (void)hideMMAlertViewController
{
    [self dismissViewControllerAnimated:NO completion:^{
        DLog(@"Dismissing alert from %@", self.parentVC);
    }];
}

#pragma mark - NotifyUser Alert

- (MMAlertView *)createAlertView:(NSDictionary *)alertViewParameters
{
    MMAlertView *alertView = nil;
    if (alertViewParameters[kAlertAttributedtextkey]) {
        alertView = [[MMAlertView alloc] initWithTitle:alertViewParameters[kAlertTitleKey]
                                              delegate:self
                                               timeout:alertViewParameters[kAlertTimeoutKey]
                                         textAttribute:[self createAttributedAlertMessage:alertViewParameters[kAlertMessageKey]
                                                                             withBoldText:alertViewParameters[kAlertAttributedtextkey]]];
    } else {
        alertView = [[MMAlertView alloc] initWithTitle:alertViewParameters[kAlertTitleKey]
                                               message:alertViewParameters[kAlertMessageKey]
                                              delegate:self
                                               timeout:[alertViewParameters[kAlertTimeoutKey] integerValue]];
    }
    NSNumber *tagNumber = alertViewParameters[kAlertTagKey];
    [alertView setTag:[tagNumber integerValue]];
    
    return alertView;
}

- (void)setAlertView:(MMAlertView *)alertView withParameters:(NSDictionary *)alertViewParameters
{
    if ([self canDoRetry:alertViewParameters[kAlertErrorCode]]) {
        [alertView.yesButton setTitle:alertViewParameters[kAlertYesButtonKey] forState:UIControlStateNormal];
        [alertView.noButton setTitle:alertViewParameters[kAlertNoButtonKey] forState:UIControlStateNormal];
        [alertView setAlertButtonType:[alertViewParameters[kAlertButtonTypeKey] integerValue]];
        [alertView setAlertControlsStyle:[alertViewParameters[kAlertControlStyleKey] integerValue]];
    } else {
        [alertView.yesButton setTitle:NSLocalizedString(@"ok.text", nil) forState:UIControlStateNormal];
        [alertView.noButton setTitle:nil forState:UIControlStateNormal];
        [alertView setAlertButtonType:BTN_YES];
        [alertView setAlertControlsStyle:CS_GRAY];
    }
}

- (BOOL)canDoRetry:(NSInteger)errorCode
{
    return errorCode != NSURLErrorNotConnectedToInternet;
}

- (NSMutableAttributedString *)createAttributedAlertMessage:(NSString *)message withBoldText:(NSString *)attributedText
{
    NSRange rangeOfBoldText = [message rangeOfString:attributedText];
    NSMutableAttributedString *fullText = [[NSMutableAttributedString alloc] initWithString:message];
    [fullText addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:kAlertMessageFontSize] range:NSMakeRange(0, fullText.length)];
    [fullText addAttribute:NSFontAttributeName value:[UIFont boldSystemFontOfSize:kAlertMessageFontSize] range:rangeOfBoldText];
    [fullText addAttribute:NSForegroundColorAttributeName value:[UIColor whiteColor] range:NSMakeRange(0, fullText.length)];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    [paragraphStyle setAlignment:NSTextAlignmentCenter];
    [fullText addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, fullText.length)];
    
    return fullText;
}

#pragma mark - ViewController Transitioning Delegate methods

- (id <UIViewControllerAnimatedTransitioning>)animationControllerForPresentedController:(UIViewController *)presented presentingController:(UIViewController *)presenting sourceController:(UIViewController *)source
{
    AnimatedTransitioning *controller = [[AnimatedTransitioning alloc] init];
    self.srcViewController = source;
    self.destViewController = presented;
    [controller setSourceViewController:source andDestinationViewController:presented];
    controller.isPresenting = YES;
    
    return controller;
}

- (id <UIViewControllerAnimatedTransitioning>)animationControllerForDismissedController:(UIViewController *)dismissed
{
    AnimatedTransitioning *controller = [[AnimatedTransitioning alloc] init];
    [controller setSourceViewController:self.srcViewController andDestinationViewController:self.destViewController];
    controller.isPresenting = NO;
    
    return controller;
}

- (id <UIViewControllerInteractiveTransitioning>)interactionControllerForPresentation:(id <UIViewControllerAnimatedTransitioning>)animator
{
    return nil;
}

- (id <UIViewControllerInteractiveTransitioning>)interactionControllerForDismissal:(id <UIViewControllerAnimatedTransitioning>)animator
{
    return nil;
}

@end
