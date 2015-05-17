//
//  Constants.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

@class WSError;

#ifndef eBike_Constants_h
#define eBike_Constants_h

#define IS_OS_8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)

#define    SCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
#define    SCREEN_HEIGHT   [UIScreen mainScreen].bounds.size.height

//Button Type
typedef NS_ENUM(NSUInteger, AvailableInFields) {
    SINGLE_DATA_FIELD = 1,
    DOUBLE_DATA_FIELD = 2,
    GRAPH_DATA_FIELD = 3
};

typedef NS_ENUM(NSUInteger, PanelState) {
    LOCKED_PANEL = 0,
    HELP_PANEL = 1,
    ACTIVE_PANEL = 2,
};

typedef NS_ENUM(NSUInteger, LayoutState) {
    GRAPH_LAYOUT = 0,
    MIXED_LAYOUT = 1,
    VALUES_LAYOUT = 2,
};

typedef NS_ENUM(NSUInteger, ScreenType) {
    bike = 0,
    fitness = 1,
};

//Value Field Dictionary Keys
#define kGraphValueFields               @"graphValueFields"
#define kSingleValueFields              @"singleValueFields"
#define kDoubleValuefields              @"doubleValueFields"

#define kTextureTileUnavailable         @"texture_tile_unavailable"

typedef NS_ENUM(NSUInteger, FieldType) {
    SINGLE  = 1,
    DOUBLE  = 2,
    GRAPH   = 3
};

typedef NS_ENUM(NSUInteger, MMControlsStyle)
{
    CS_DEFAULT,
    CS_BLUE,
    CS_GREEN,
    CS_BLACK,
    CS_GRAY
};

// Bike types
typedef NS_ENUM(NSUInteger, DriveUnitType) {
    kDriveUnitActiveLine25 = 0,
    kDriveUnitPerformance25,
    kDriveUnitPerformance45
};

extern NSString *const kAlpha;
extern NSString *const kValueLayoutType;
extern NSString *const kMixedLayoutType;
extern NSString *const kGraphLayoutType;
extern NSString *const kID;
extern NSString *const kQtMinVersion;
extern NSString *const kQtMaxVersion;
extern NSString *const kAvailableInFields;
extern NSString *const kTick;
extern NSString *const kBackgroundImg;
extern NSString *const kBGColor;
extern NSString *const kFontColor;
extern NSString *const kIcon;
extern NSString *const kText;
extern NSString *const kSubtext;
extern NSString *const kAlertTypeKey;

#if OEM == 1
#define VERSION @1
#else
#define VERSION @2
#endif

static float const kMetersPerKm                                 = 1000.0;
static float const kInchPerCm                                   = 0.393701;
static float const kYardPerMeter                                = 1.09361;
static float const kMilePerKm                                   = 0.621371;
static float const kFeetPerMeter                                = 3.28084;
static float const kPoundPerKg                                  = 2.20462;
static float const kMilePerMeter                                = 0.000621371;

static NSInteger const kMetersInKilometer                       = 1000;
static NSInteger const kFeetInMile                              = 5200;
static NSInteger const kSecondsInHour                           = 3600;
static NSInteger const kSecondsInDay                            = (24 * kSecondsInHour);
static NSInteger const kMinutesInHour                           = 60;
static NSInteger const kSecondsInMinute                         = 60;

static NSString *const kTimeFormat                              = @"h:mm a";
static NSString *const kWeightKey                               = @"weight";
static NSString *const kHeightKey                               = @"height";
static NSString *const kMetricUnit                              = @"Metric";
static NSString *const kImperialUnit                            = @"Imperial";
static NSString *const kMale									= @"Male";
static NSString *const kFemale									= @"Female";
static NSString *const kDistanceKey                             = @"distance";
static NSString *const kShortDistanceKey                        = @"shortdistance";
static NSString *const kGenderKey                               = @"Gender";
static NSString *const kMillimeters                             = @"mm";
static NSString *const kSeedFileName                            = @"seedFile";
static NSString *const kMapPackagesFileName                     = @"MapPackagesFile";

//Type of ranges
static NSString *const kRangeTypeActive25                       = @"Active25";
static NSString *const kRangeTypePerformance25                  = @"Performance25";
static NSString *const kRangeTypePerformance45                  = @"Performance45";

//Types of profile
static NSString *const kRangeProfileEco                         = @"ECO";
static NSString *const kRangeProfileTour                        = @"TOUR";
static NSString *const kRangeProfileSport                       = @"SPORT";
static NSString *const kRangeProfileTurbo                       = @"TURBO";

static NSString *const kLatitude								= @"latitude";
static NSString *const kLongitude								= @"longitude";
static NSString *kRoutePlatformMobile							= @"MOBILE";
static NSString *kRouteTypeNavigation							= @"NAVIGATION";

static NSString *const kUserId                                  = @"user_id";

//Ranges
static NSInteger const kRangeActive25EnergyEconomyEco           = 367;
static NSInteger const kRangeActive25EnergyEconomyTour          = 223;
static NSInteger const kRangeActive25EnergyEconomySport         = 171;
static NSInteger const kRangeActive25EnergyEconomyTurbo         = 144;

static NSInteger const kRangePerformance25EnergyEconomyEco      = 341;
static NSInteger const kRangePerformance25EnergyEconomyTour     = 171;
static NSInteger const kRangePerformance25EnergyEconomySport    = 144;
static NSInteger const kRangePerformance25EnergyEconomyTurbo    = 118;

static NSInteger const kRangePerformance45EnergyEconomyEco      = 249;
static NSInteger const kRangePerformance45EnergyEconomyTour     = 131;
static NSInteger const kRangePerformance45EnergyEconomySport    = 105;
static NSInteger const kRangePerformance45EnergyEconomyTurbo    = 92;

extern NSString *const SYNC_DID_FINISH_NOTIFICATION;
extern NSString *const SYNC_DONE_NOTIFICATION;
extern NSString *const SETTINGS_SYNC_DONE_NOTIFICATION;
extern NSString *const kFirstTimeLoginNotification;

static NSString *const kBUISettingsPath                         = @"/settings";
static NSString *const kBUISyncRequest							= @"/sync/request";
static NSString *const kBUISyncLicenses							= @"/purchase/licenses";

NS_ENUM(NSUInteger, SKMapAnnotationTypes) {
    SKAnnotationTypeStartPosition = 38,
    SKAnnotationTypeDestinationPosition = 39,
    SKAnnotationTypeCurrentPositionArrow = 44,
    SKAnnotationTypeCurrentPosition = 46,
};

typedef NS_ENUM(NSUInteger, DataLayoutType){
    kDataTypeRide = 0,
    kDataTypeFitness
};

typedef NS_ENUM(NSUInteger, SettingType) {
    kSettingsAll,
    kSettingsBike,
    kSettingsUser,
    kSettingsBUI,
    kCustomAssistance,
    kCustomScreens
};

typedef void (^ResponseBlock)(id responseObj, WSError *error);
typedef void (^VoidCompletionBlock)(void);
typedef void (^AlertDismissBlock)(NSInteger buttonIndex);

typedef NS_ENUM(NSUInteger, MMCustomAlertType) {
    kNotifyUserAlert = 0,
    kShopAlert
};

typedef NS_ENUM(NSUInteger, BikeSpeed) {
    kBikeSpeed25 = 25,
    kBikeSpeed45 = 45
};

//CustomAssistance
static NSInteger const	kPointsPerLevel							= 5;
static NSInteger const	kMaxAssistFactorActive25				= 225;
static NSInteger const	kMaxAssistFactorPerformance25			= 275;
static NSInteger const	kMaxAssistFactorPerformance45			= 400;

static NSString *const	kComponentSeparatorString				= @",";
static NSString *const	kScreenTypeBike							= @"bike";
static NSString *const	kScreenTypeFitness						= @"fitness";
//Request types
static NSString *const	kPOSTRequest							= @"POST";
static NSString *const	kPUTRequest								= @"PUT";

static NSString *const	kDateFormatWithTime						= @"yyyy-mm-dd hh:mm:ss";
static NSString *const	kMinDefaultDate							= @"1900-01-01 00:00:00";
static NSString *const	kDateFormatMMddyy						= @"MM/dd/yy";
static NSString *const	kDateFormatddMMyy						= @"dd/MM/yyyy";
static NSString *const	kDateFormatddMMyyyy						= @"dd-MM-yyyy";
static NSInteger const	kMinYear								= 1900;
static NSInteger const	kMinRequiredAge							= 12;
static NSString *const	kMainMenuVCIdentifier					= @"MainMenuID";
static NSString *const	kAlertDescriptionBoldText				= @"Nyon";
static NSString *const kHelpScreenDataSource                    = @"HelpScreenDataSource";
static NSString *const kLicenseTitle                            = @"title";
static NSString *const kLicenseText                             = @"text";
// Constants related to Network Lookup
static NSString *const	kIPv4									= @"ipv4";
static NSString *const	kIPv6									= @"ipv6";
static NSString *const	kIPAddressKey							= @"address";
static NSString *const	kProtocolTypeKey						= @"type";
static NSString *const	kHostNameKey							= @"name";
static NSString *const  kSkobblerLogo                           = @"skobbler_logo";
static NSInteger const  kDefaultLoadingAlertAlpha				= 1.0f;
// Root JSON
static NSString *const kRoot                                    = @"root";
//Measure units
static NSString *const  kMileUnit                               = @"mi";
static NSString *const  kKilometerUnit                          = @"km";

//Product ids
#if PROD_ENV == 1
static NSString	*const kRealReachProductId						= @"com.bosch.ebike.premium.realreach";
static NSString *const kTopographicMapsProductId				= @"com.bosch.ebike.premium.3dmaps";
static NSString *const kCustomModesProductId					= @"com.bosch.ebike.premium.custommodes";
static NSString *const kNavigationProductId						= @"com.bosch.ebike.premium.navigation";
#else
static NSString	*const kRealReachProductId						= @"com.bosch.eb.premium.realreach";
static NSString *const kTopographicMapsProductId				= @"com.bosch.eb.premium.3dmaps";
static NSString *const kCustomModesProductId					= @"com.bosch.eb.premium.custommodes";
static NSString *const kNavigationProductId						= @"com.bosch.eb.premium.navigation";
#endif

static NSString *kSkobblerDevHostnameRoot						= @".skobbler.net";
static NSString *kSkobblerHostnameRoot							= @".sko.fm";
static NSString *kSkobblerIPAddress								= @"54.230.44.126";
static NSString *const kDefaultBikeName                         = @"Bosch eBike";

//Core data member key
static NSString *const kCDUser                                  = @"user";
static NSString *const kUserIDDefaultsKey                       = @"UserID";
static CGFloat   const kCoordinateDelta                         = 0.00005;

#define LOADING_BACKGROUND_COLOR [UIColor colorWithWhite:1.0 alpha:0.8]

#define MMLocalize(str) NSLocalizedString(str, nil)

#endif
