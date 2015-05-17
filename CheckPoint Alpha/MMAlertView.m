//
//  MMAlertView.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "Utilities.h"
#import "UIConstants.h"
#import "MMAlertView.h"
#import "MMCustomViewController.h"

@interface MMAlertView ()

@property (weak, nonatomic)		IBOutlet UIView				*view;
@property (weak, nonatomic)		IBOutlet UIView				*controlsView;
@property (weak, nonatomic)		IBOutlet UILabel			*titleLabel;
@property (weak, nonatomic)		IBOutlet UITextView			*descriptionTextView;
@property (weak, nonatomic)     id<MMAlertViewDelegate>		delegate;
@property (weak, nonatomic)		IBOutlet NSLayoutConstraint *noButtonWidthCstr;
@property (weak, nonatomic)		IBOutlet NSLayoutConstraint *yesButtonWidthCstr;

- (IBAction)onNOButtonAction:(id)sender;
- (IBAction)onYESButtonAction:(id)sender;

@end

@implementation MMAlertView

- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message delegate:(id<MMAlertViewDelegate>)delegate timeout:(NSInteger)timeout
{
    self = [self initAlertViewWithTitle:title delegate:delegate timeout:timeout];
    [self.descriptionTextView setText:message];
    
    return self;
}

- (instancetype)initWithTitle:(NSString *)title delegate:(id<MMAlertViewDelegate>)delegate timeout:(NSInteger)timeout textAttribute:(NSAttributedString *)attribute
{
    self = [self initAlertViewWithTitle:title delegate:delegate timeout:timeout];
    [self.descriptionTextView setAttributedText:attribute];
    
    return self;
}

- (instancetype)initAlertViewWithTitle:(NSString *)title delegate:(id)delegate timeout:(NSInteger)timeout
{
    if (self = [super initWithFrame:[[UIScreen mainScreen] bounds]]) {
        [self loadXibFile];
        [self addSubview:self.view];
        // Custom initialization
        [self setTitle:title];
        self.delegate = delegate;
        if (timeout > 0) {
            [self.controlsView removeFromSuperview];
            [self performSelector:@selector(autoDismissAlert) withObject:nil afterDelay:timeout];
        }
        [self.noButton setBackgroundImage:[Utilities getStretchedImageFor:kDarkOverlayButtonImage] forState:UIControlStateHighlighted];
        [self.yesButton setBackgroundImage:[Utilities getStretchedImageFor:kLightOverlayButtonImage] forState:UIControlStateHighlighted];
    }
    
    return self;
}

- (id)initWithFrame:(CGRect)frame
{
    return [self initWithTitle:nil message:nil delegate:nil timeout:0];
}

- (void)dismiss
{
    [self dismissWithAction:AA_NO_ACTION];
}

- (void)setAlertButtonType:(MMButtonType)buttonType
{
    CGFloat width = CGRectGetWidth(self.controlsView.bounds);
    switch (buttonType) {
        case BTN_NO:
            [self.yesButton removeFromSuperview];
            [self.noButtonWidthCstr setConstant:width];
            break;
        case BTN_YES:
            [self.noButton removeFromSuperview];
            [self.yesButtonWidthCstr setConstant:width];
            break;
        case BTN_NONE:
            [self.yesButton removeFromSuperview];
            [self.noButton removeFromSuperview];
        default:
            break;
    }
}

- (void)setAlertControlsStyle:(MMControlsStyle)controlsStyle
{
    switch (controlsStyle) {
        case CS_DEFAULT:
            [self.yesButton setBackgroundColor:RED_BUTTON_BACKGROUND_COLOR];
            [self.yesButton setTitleColor:WHITE_COLOR forState:UIControlStateNormal];
            break;
        case CS_BLUE:
            [self.yesButton setBackgroundColor:CYAN_BUTTON_BACKGROUND_COLOR];
            [self.yesButton setTitleColor:WHITE_COLOR forState:UIControlStateNormal];
            break;
        case CS_GREEN:
            [self.yesButton setBackgroundColor:GREEN_BUTTON_BACKGROUND_COLOR];
            [self.yesButton setTitleColor:GREEN_BUTTON_TITLE_COLOR forState:UIControlStateNormal];
            break;
        case CS_GRAY:
            [self.yesButton setBackgroundColor:GRAY_BUTTON_BACKGROUND_COLOR];
            [self.yesButton setTitleColor:WHITE_COLOR forState:UIControlStateNormal];
            [self.noButton setBackgroundColor:LIGHT_GRAY_ALERT_BUTTON_BACKGROUND_COLOR];
            [self.noButton setTitleColor:BLACK_ALERT_BUTTON_TITLE_COLOR forState:UIControlStateNormal];
            
            return;
        default:
            break;
    }
    
    [self.noButton setBackgroundColor:GRAY_BUTTON_BACKGROUND_COLOR];
    [self.noButton setTitleColor:WHITE_COLOR forState:UIControlStateNormal];
}

#pragma mark - IBAction methods

- (IBAction)onNOButtonAction:(id)sender
{
    [self dismissWithAction:AA_NO];
}

- (IBAction)onYESButtonAction:(id)sender
{
    [self dismissWithAction:AA_YES];
}

- (IBAction)autoDismissAlert
{
    [self dismissWithAction:AA_AUTO_DISMISS];
}

#pragma mark - Private methods

- (void)dismissWithAction:(MMAlertAction)action
{
    if (self.alertDismissBlock) {
        self.alertDismissBlock(action);
    }
    
    if (self.delegate) {
        [self.delegate alertView:self didDismissWithAction:action];
    }
    
    if (self.alertViewControllerDelegate) {
        [self.alertViewControllerDelegate hideMMAlertViewController];
    }
    
    [self hide];
}

- (void)setTitle:(NSString *)title
{
    if (title) {// we have a valid tile
        [self.titleLabel setText:title];
    } else {// we'll remove the title to make more room for description
        [self.titleLabel removeFromSuperview];
        NSLayoutConstraint *descriptionTextViewVSpaceCstr = [NSLayoutConstraint constraintWithItem:self.descriptionTextView
                                                                                         attribute:NSLayoutAttributeTop
                                                                                         relatedBy:NSLayoutRelationEqual
                                                                                            toItem:self
                                                                                         attribute:NSLayoutAttributeTop
                                                                                        multiplier:1.0f
                                                                                          constant:40.0f];
        [self addConstraint:descriptionTextViewVSpaceCstr];
    }
}

@end