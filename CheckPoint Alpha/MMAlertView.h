//
//  MMAlertView.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "MMCustomAlertView.h"

@protocol MMAlertViewDelegate;

typedef NS_ENUM(NSInteger, MMAlertAction)
{
    AA_NO_ACTION = -1,
    AA_NO,
    AA_YES,
    AA_AUTO_DISMISS
};

typedef NS_ENUM(NSUInteger, MMButtonType)
{
    BTN_NO,
    BTN_YES,
    BTN_BOTH,
    BTN_NONE
};

//Alert Parameters
static NSString *const kAlertTitleKey                   = @"title";
static NSString *const kAlertMessageKey                 = @"message";
static NSString *const kAlertTimeoutKey                 = @"timeout";
static NSString *const kAlertTagKey                     = @"tag";
static NSString *const kAlertYesButtonKey               = @"yesButton";
static NSString *const kAlertNoButtonKey                = @"noButton";
static NSString *const kAlertButtonTypeKey              = @"buttonType";
static NSString *const kAlertControlStyleKey            = @"controlStyle";
static NSString *const kAlertAttributedtextkey          = @"attributedText";
static NSString *const kAlertErrorCode                  = @"error_code";

@interface MMAlertView : MMCustomAlertView

@property (weak, nonatomic) IBOutlet UIButton *noButton;
@property (weak, nonatomic) IBOutlet UIButton *yesButton;

// Designated initializer. If timeout value is grater than 0, the alert will be dismissed by user choice.
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message delegate:(id<MMAlertViewDelegate>)delegate timeout:(NSInteger)timeout;
- (instancetype)initWithTitle:(NSString *)title delegate:(id<MMAlertViewDelegate>)delegate timeout:(NSInteger)timeout textAttribute:(NSAttributedString *)attribute;
// Dismisses the alert view
- (void)dismiss;
- (void)setAlertControlsStyle:(MMControlsStyle)controlsStyle;
- (void)setAlertButtonType:(MMButtonType)buttonType;

@end

@protocol MMAlertViewDelegate <NSObject>

- (void)alertView:(MMAlertView *)alertView didDismissWithAction:(MMAlertAction)action;

@end
