//
//  AnimatedTransitioning.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "AnimatedTransitioning.h"

@interface AnimatedTransitioning()

@property (nonatomic, strong) UIViewController *srcViewController;
@property (nonatomic, strong) UIViewController *destViewController;

@end

@implementation AnimatedTransitioning

- (NSTimeInterval)transitionDuration:(id <UIViewControllerContextTransitioning>)transitionContext
{
    return 0.0f;
}

- (void)animateTransition:(id <UIViewControllerContextTransitioning>)transitionContext
{
    UIView *inView = [transitionContext containerView];
    [inView addSubview:self.destViewController.view];
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    self.destViewController.view.backgroundColor = [UIColor clearColor];
    [self.destViewController.view setFrame:CGRectMake(0, screenRect.size.height, self.srcViewController.view.frame.size.width, self.srcViewController.view.frame.size.height)];
    
    [UIView animateWithDuration:0.0f
                     animations:^{
                         [self.destViewController.view setFrame:CGRectMake(0, 0, self.srcViewController.view.frame.size.width, self.srcViewController.view.frame.size.height)];
                     }
                     completion:^(BOOL finished) {
                         [transitionContext completeTransition:YES];
                     }
     ];
}

- (void)setSourceViewController:(UIViewController *)sourceViewController andDestinationViewController:(UIViewController *)destinationViewController
{
    self.srcViewController = sourceViewController;
    self.destViewController = destinationViewController;
}

@end
