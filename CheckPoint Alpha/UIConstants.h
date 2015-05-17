//
//  UIConstants.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#ifndef eBike_UIConstants_h
#define eBike_UIConstants_h

// RGB color macro
// e.g. [self.switchNyonButton setBackgroundColor: UIColorFromRGB(0X2cd1fd)];
#define UIColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

// RGB color macro with alpha
// e.g. [self.switchNyonButton setBackgroundColor: UIColorFromARGB(0Xff2cd1fd)];
#define UIColorFromARGB(argbValue) [UIColor \
colorWithRed:((float)((argbValue & 0x00FF0000) >> 16))/255.0 \
green:((float)((argbValue & 0x0000FF00) >> 8))/255.0 \
blue:((float)(argbValue & 0x000000FF))/255.0 alpha: ((float)((argbValue & 0xFF000000) >> 24))/255.0]

//Widely used constants
static NSString *const  kShadowImage                            =   @"shadow_stnd";
static NSString *const  kLightOverlayButtonImage                =   @"onpress_overlay_lighten@2x.png";
static NSString *const  kDarkOverlayButtonImage                 =   @"onpress_overlay_darken@2x.png";
static NSString *const  kDefaultNavLeftButtonImage1             =   @"ph_firstlevel";
static NSString *const  kDefaultNavLeftButtonImage2             =   @"ph_secondlevel";

static NSString *const kCurrentPositionAnnotationImage          =	@"pin_current_location";
static NSString *const kStartPositionAnnotationImage            =	@"pin_start";
static NSString *const kDestinationPositionAnnotationImage      =	@"pin_destination";

//Customize Settings Screen
static NSString *const  kNavigationImage                        =   @"m_mainmenuheader.header.png";
static NSString *const  kCellArrowImage                         =   @"listitem_arrow";
static NSString *const  kImageExtension                         =   @"png";
static NSString *const  kNavigationOptCell                      =   @"NavigationOptCell";
static NSString *const	kInfoDefaultText                        =   @"N/A";
static NSString *const	kKiloMeterText                          =   @"km";
static NSString *const  kKiloMeterPerHourText                   =   @"km/h";
static NSString *const	kMeterText                              =   @"m";
static NSString *const  kDefaultBoschNyon                       =   @"Bosch Nyon";

static NSString *const	kFieldFirstName                         =	@"firstName";
static NSString *const	kFieldLastName                          =	@"lastName";
static NSString *const	kFieldEmail                             =	@"email";
static NSString *const	kFieldUnits                             =	@"units";
static NSString *const	kFieldPassword                          =	@"password";
static NSString *const	kFieldRepeatPassword                    =	@"repeatPassword";
static NSString *const	kFieldGender                            =	@"gender";
static NSString *const	kFieldBirthday                          =	@"birthDay";
static NSString *const	kFieldWeight                            =	@"weight";
static NSString *const	kFieldHeight                            =	@"height";
static NSString *const	kDateFormat                             =	@"yyyy";
static NSString *const	kWSDateFormat                           =	@"yyyy-MM-dd";

static const NSInteger  kMaxVisibleSearchLocationResult         =   5;
static const NSInteger  kMaxRecentDestinationsResults           =   10;
static const NSInteger  kAnnotationID                           =   777;
static const CGFloat    kMapZoomLevel                           =   13.5f;
static const CGFloat    kMapRangeZoomLevel                      =   8.5f;
static const CGFloat    kMapOverlayCircleBorderWidth            =   1.0f;
static const CGFloat    kCircleRadius                           =   1200.0f;
static const CGFloat    kCellTextLabelAlpha                     =   0.85f;
// Default top space used with view controllers
static const CGFloat    kDefaultTopSpace                        =   66.0f;

#define LIST_ITEM_EXTENDED_CELL_HEIGHT							95.0f
#define LIST_ITEM_CELL_HEIGHT									66.0f
#define MAIN_MENU_REVEAL_OFFSET									107.0f

#define BACKGROUND_COLOR                                        [UIColor colorWithRed:0.0f/255.0f green:0.0f/255.0f blue:0.0f/255.0f alpha:0.77f]
#define BACKGROUND_COLOR_CELL                                   [UIColor colorWithRed:200.0/255.0 green:200.0/255.0 blue:200.0/255.0 alpha:1.0f]
#define BACKGROUND_COLOR_MIDDLE_CELL                            [UIColor colorWithRed:230.0/255.0 green:230.0/255.0 blue:230.0/255.0 alpha:1.0f]
#define BACKGROUD_COLOR_LOGIN                                   [UIColor colorWithRed:45.0/255.0 green:45.0/255.0 blue:45.0/255.0 alpha:0.0]
#define CELL_TEXT_BLACK_COLOR                                   [UIColor colorWithRed:0.0f/255.0f green:0.0f/255.0f blue:0.0f/255.0f alpha:0.85f]
#define CELL_DARK_GREY_COLOR                                    [UIColor colorWithRed:227.0f/255.0f green:227.0f/255.0f blue:227.0f/255.0f alpha:1.0f]
#define CELL_BACKGROUND_COLOR_EVEN                              WHITE_COLOR
#define CELL_BACKGROUND_COLOR_ODD                               [UIColor colorWithWhite:0.9 alpha:1.0]
#define RED_COLOR                                               [UIColor colorWithRed:255/255.0 green:77.0/255.0 blue:77.0/255.0 alpha:1.0f]
#define MAP_OVERLAY_CIRCLE_COLOR								[UIColor colorWithRed:0.0/255.0 green:0.0/255.0 blue:0.0/255.0 alpha:0.5]
#define MAP_OVERLAY_CIRCLE_CLEAR_COLOR							[UIColor clearColor]
#define MAP_OVERLAY_CIRCLE_BORDER_COLOR							MAP_OVERLAY_CIRCLE_COLOR
#define WHITE_COLOR												[UIColor whiteColor]
#define LIGHT_GRAY_COLOR										[UIColor lightGrayColor]
#define GRAY_COLOR												[UIColor grayColor]
#define DEFAULT_ENABLE_COLOR									[UIColor colorWithRed:44.0f/255.0f green:209.0f/255.0f blue:253.0f/255.0f alpha:1.0f]
#define CLEAR_COLOR												[UIColor clearColor]
#define TABLE_CELL_BACKGROUND_COLOR								[UIColor colorWithRed:231.0f/255.0f green:231.0f/255.0f blue:231.0f/255.0f alpha:1.0f]
#define TABLE_CELL_SELECTION_COLOR                              [UIColor colorWithRed:224.0f/255.0f green:224.0f/255.0f blue:224.0f/255.0f alpha:1.0f]
#define SEARCH_ENABLE_COLOR										[UIColor colorWithRed:46.0/255.0 green:226/255.0 blue:113/255.0 alpha:1.0]
#define TABLE_BACKGROUND_COLOR									[UIColor colorWithRed:221.0f/255.0f green:221.0f/255.0f blue:221.0f/255.0f alpha:1.0f]
#define LIGHT_GRAY_ALERT_BUTTON_BACKGROUND_COLOR                [UIColor colorWithRed:216/255.0 green:216/255.0 blue:216/255.0 alpha:1.0f]
#define BLACK_ALERT_BUTTON_TITLE_COLOR                          [UIColor blackColor]
#define TABLE_HEADER_IMAGE_BACKGROUND_COLOR                     [UIColor colorWithRed:202.0f/255.0f green:202.0f/255.0f blue:202.0f/255.0f alpha:1.0f]

static CGRect const     kCellAccessoryImageFrame                =   {{290, 17}, {32, 32}};
static NSString *const  kEBikeSegueIdentifier                   =	@"eBikeSegueIdentifier";
static NSString *const  kMapStyleFolderName                     =	@"BicycleStyle";
static NSString *const  kMapStyleFileName                       =	@"bicyclestyle.json";

//For the registration related screens
#define VIEW_BACKGROUND_COLOR									[UIColor blackColor]
#define WHITE_BUTTON_COLOR										[UIColor whiteColor]
#define GREEN_BUTTON_BACKGROUND_COLOR							[UIColor colorWithRed:36.0/255.0 green:231.0/255.0 blue:137.0/255.0 alpha:1.0]
#define GREEN_BUTTON_TITLE_COLOR								[UIColor colorWithRed:26.0/255.0 green:145.0/255.0 blue:71.0/255.0 alpha:1.0]
#define GRAY_BUTTON_BACKGROUND_COLOR							[UIColor colorWithRed:76.0/255.0 green:76.0/255.0 blue:76.0/255.0 alpha:1.0]
#define CYAN_BUTTON_BACKGROUND_COLOR							[UIColor colorWithRed:84.0/255.0 green:217/255.0 blue:252.0/255.0 alpha:1.0]
#define RED_BUTTON_BACKGROUND_COLOR								[UIColor colorWithRed:255.0/255.0 green:77.0/255.0 blue:77.0/255.0 alpha:1.0]
#define FORGOT_PASSWORD_BUTTON_COLOR                            [UIColor colorWithRed:142.0f/255.0f green:142.0f/255.0f  blue:142.0f/255.0f  alpha:1.0]

// Alert related constants
#define ALERT_BACKGROUND_COLOR                                  [UIColor colorWithWhite:0.0 alpha:0.8]
#define ALERT_MESSAGE_FONT                                      [UIFont boldSystemFontOfSize:17.0]

//Alert timeout
static NSInteger const kAlertTimeoutInterval                    = 3;
static NSInteger const kDefaultTimeout                          = 0;

//Help Screen table
static const CGFloat kCellButtonAlpha                           = 0.85f;
static const CGRect  kCellButtonFrame                           = {{290.0f, 17.0f}, {32.0f, 32.0f}};
static const CGFloat kTableCellFontSize                         = 24.0f;
static const CGFloat kSectionHeaderHeight                       = 12.0f;

// Map annotation offset
static CGPoint const kAnnotationOffset                          = {32, 32};

#endif
