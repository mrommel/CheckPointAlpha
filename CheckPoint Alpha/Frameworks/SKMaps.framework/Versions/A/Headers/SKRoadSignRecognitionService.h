//
//  RoadSignDetectionService.h
//  BoschRoadSignDetectionDemo
//
//  Created by Korosi Csongor on 12/12/13.
//  Copyright (c) 2013 Korosi Csongor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SKRoadSignRecognitionSettings.h"
#import <UIKit/UIKit.h>
@class SKRoadSignRecognitionService;

typedef NS_ENUM(NSInteger, SKRoadSign)
{
    UNKNOWN              =   0, ///< Undefined
    SL5                  =   1, ///< Speed Limit
    SL10                 =   2, ///< Speed Limit
    SL15                 =   3, ///< Speed Limit
    SL20                 =   4, ///< Speed Limit
    SL25                 =   5, ///< Speed Limit
    SL30                 =   6, ///< Speed Limit
    SL35                 =   7, ///< Speed Limit
    SL40                 =   8, ///< Speed Limit
    SL45                 =   9, ///< Speed Limit
    SL50                 =  10, ///< Speed Limit
    SL55                 =  11, ///< Speed Limit
    SL60                 =  12, ///< Speed Limit
    SL65                 =  13, ///< Speed Limit
    SL70                 =  14, ///< Speed Limit
    SL75                 =  15, ///< Speed Limit
    SL80                 =  16, ///< Speed Limit
    SL85                 =  17, ///< Speed Limit
    SL90                 =  18, ///< Speed Limit
    SL95                 =  19, ///< Speed Limit
    SL100                =  20, ///< Speed Limit
    SL105                =  21, ///< Speed Limit
    SL110                =  22, ///< Speed Limit
    SL115                =  23, ///< Speed Limit
    SL120                =  24, ///< Speed Limit
    SL125                =  25, ///< Speed Limit
    SL130                =  26, ///< Speed Limit
    SL135                =  27, ///< Speed Limit
    SL140                =  28, ///< Speed Limit
    SL145                =  29, ///< Speed Limit
    SL150                =  30, ///< Speed Limit
    SL155                =  31, ///< Speed Limit
    SL160                =  32, ///< Speed Limit
    OP                   =  33, ///< Overtaking Prohibited Passenger Cars
    OL                   =  34, ///< Overtaking Prohibited Passenger Lorries
    ESL                  =  35, ///< End of Speed Limit
    EOP                  =  36, ///< End of Overtaking Prohibited Passenger Cars
    EOL                  =  37, ///< End of Overtaking Prohibited Passenger Lorries
    EA                   =  38, ///< End of All
    VSL5                 =  39, ///< VMS -> variable message sign
    VSL10                =  40, ///< VMS
    VSL15                =  41, ///< VMS
    VSL20                =  42, ///< VMS
    VSL25                =  43, ///< VMS
    VSL30                =  44, ///< VMS
    VSL35                =  45, ///< VMS
    VSL40                =  46, ///< VMS
    VSL45                =  47, ///< VMS
    VSL50                =  48, ///< VMS
    VSL55                =  49, ///< VMS
    VSL60                =  50, ///< VMS
    VSL65                =  51, ///< VMS
    VSL70                =  52, ///< VMS
    VSL75                =  53, ///< VMS
    VSL80                =  54, ///< VMS
    VSL85                =  55, ///< VMS
    VSL90                =  56, ///< VMS
    VSL95                =  57, ///< VMS
    VSL100               =  58, ///< VMS
    VSL105               =  59, ///< VMS
    VSL110               =  60, ///< VMS
    VSL115               =  61, ///< VMS
    VSL120               =  62, ///< VMS
    VSL125               =  63, ///< VMS
    VSL130               =  64, ///< VMS
    VSL135               =  65, ///< VMS
    VSL140               =  66, ///< VMS
    VSL145               =  67, ///< VMS
    VSL150               =  68, ///< VMS
    VSL155               =  69, ///< VMS
    VSL160               =  70, ///< VMS
    VOP                  =  71, ///< VMS
    VOL                  =  72, ///< VMS
    VESL                 =  73, ///< VMS
    VEOP                 =  74, ///< VMS
    VEOL                 =  75, ///< VMS
    VEA                  =  76, ///< VMS
    ADDCAR               =  77, ///< valid for passenger cars
    ADDLORRY             =  78, ///< valid for lorries (independent of number of axles)
    ADDTRAILER           =  79, ///< valid for passenger cars with trailers
    ADDCARAVAN           =  80, ///< valid for passenger cars with caravans
    ADDBUS               =  81, ///< valid for buses
    ADDTRACTOR           =  82, ///< valid for tractors
    ADDMCYCLE            =  83, ///< valid for motorcycles or mopeds
    ADDLORRYBUSTRAILER   =  84, ///< vaild for Lorries, Buses and Passenger Cars with Trailer
    ADDLORRYBUS          =  85, ///< vaild for Lorries and Buses
    ADDHAZMAT            =  86, ///< valid for dangerous goods
    ADDTANK              =  87, ///< valid for tanks
    ADDTRAM              =  88, ///< valid for trams
    ADDWET               =  89, ///< valid when wet
    ADDFOG               =  90, ///< valid during fog
    ADDRAIN              =  91, ///< valid during rain
    ADDSNOW              =  92, ///< valid during snow
    ADDTIME              =  93, ///< valid during given time
    ADDSECTION           =  94, ///< valid for the given distance
    ADDDISTANCE          =  95, ///< valid after the given distance
    ADDWEIGHT            =  96, ///< valid for ego weight over given threshold
    ADDEXITL             =  97, ///< valid for exiting left
    ADDEXITR             =  98, ///< valid for exiting right
    ADDLANES             =  99, ///< valid for given lanes
    ADDRADAR             = 100, ///< info about speed check
    ADDRAPPEL            = 101, ///< repetition info (FR)
    ADDPRIOTURN          = 102, ///< regulate bend in priority road
    ADDLORRY_EXCEPT      = 103, ///< valid for everyone except Lorries
    ADDTRACTOR_OVER      = 104, ///< Tractors may be overtaken (AS for OP)
    NOENTRY              = 105, ///< No entry, One-way street
    NOALL                = 106, ///< Entry Prohibited for all vehicles
    NOCAR                = 107, ///< Entry Prohibited for cars
    NOLORRY              = 108, ///< Entry Prohibited for Lorries
    NOHAZMAT             = 109, ///< Entry Prohibited for Dangerous Goods
    NOBIKE               = 110, ///< Entry Prohibited for Motorbikes
    NOPED                = 111, ///< Entry Prohibited for Pedestrians
    NOCARBIKE            = 112, ///< Entry Prohibited for Cars and Motorbikes
    NOTWOWAY             = 113, ///< Entry Prohibited in case of oncoming traffic (two arrows)
    WEIGHT               = 114, ///< Entry Prohibited if ego weight above threshold
    HEIGHT               = 115, ///< Entry Prohibited if ego height above threshold
    WIDTH                = 116, ///< Entry Prohibited if ego width above threshold
    LENGTH               = 117, ///< Entry Prohibited if ego length above threshold
    PRIOC                = 118, ///< Have Right of Way at next Crossing
    GIVEWAY              = 119, ///< Give Right of Way at next Crossing
    PRIORL               = 120, ///< Left yields to right at next Crossing
    WARNDANGER           = 121, ///< General Warning (!)
    WARNCURVEL           = 122, ///< Warning of left curve
    WARNCURVER           = 123, ///< Warning of right curve
    WARNDCURVEL          = 124, ///< Warning of left double curve
    WARNDCURVER          = 125, ///< Warning of right double curve
    WARNTRAIN            = 126, ///< Warning of railway crossing
    WARNJAM              = 127, ///< Warning of traffic jams
    WARNANIMAL           = 128, ///< Warning of animals (deer)
    WARNRWORKS           = 129, ///< Warning of road works
    WARNSLOPED           = 130, ///< Warning of down slopes
    WARNSLOPEU           = 131, ///< Warning of up slopes
    PRIOS                = 132, ///< Priority street (rhombic)
    EPRIOS               = 133, ///< End Priority street (rhombic)
    STOP                 = 134, ///< Stop Sign (octagonal)
    EXIT                 = 135, ///< German Motorway Exit (blue and white)
    ASL                  = 136, ///< Advice Speed Limit (blue and white)
    EASL                 = 137, ///< End of Advice Speed Limit (blue and white)
    MSL                  = 138, ///< Minimum Speed Limit (blue and white)
    EMSL                 = 139, ///< End of Minimum Speed Limit (blue and white)
    MLC                  = 140, ///< Military Load Class (DE, yellow)
    WBDIAGL              = 141, ///< Diagonal Arrow from lower left to upper right or vice versa (blue and white)
    WBDIAGR              = 142, ///< Diagonal Arrow from upper left to lower right or vice versa (blue and white)
    WBROUND              = 143, ///< Roundabout Sign (blue and white)
    NOLTURN              = 144, ///< Left Turn Prohibited (red border)
    NORTURN              = 145, ///< Right Turn Prohibited (red border)
    NOUTURN              = 146, ///< U-Turn Prohibited (red border)
    NOPARK               = 147, ///< Parking Prohibited (red and blue)
    NOSTOP               = 148, ///< Stopping Prohibited (red and blue)
    SMOG                 = 149, ///< Entry Prohibited due to smog (red border, plate)
    UMWELT               = 150, ///< Umwelt Zone (DE, red border, plate)
    EUMWELT              = 151, ///< End of Umwelt Zone (DE, red border, plate)
    DOUANE               = 152, ///< Douane (customs border)
    LOGO_LIDL            = 153, ///< Company Logo LIDL
    LOGO_ESSO            = 154, ///< Company Logo ESSO
    LOGO_SHELL           = 155, ///< Company Logo SHELL
    LOGO_VW              = 156, ///< Company Logo VW
    PICT_HOTEL           = 157, ///< Pictogram Hotel
    PICT_PHONE           = 158, ///< Pictogram Phone
    PICT_FOOD            = 159, ///< Pictogram Restaurant (Knife and Fork)
    LAMP                 = 160, ///< White blobs on black background (lamps etc)
    ADDTEXT              = 161, ///< General Text
    REJECTION            = 162, ///< Rejection Class
    ADDSIGN              = 163, ///< general add sign
    FWAY                 = 164, ///< German Autobahn
    EFWAY                = 165, ///< End German Autobahn
    HWAY                 = 166, ///< German Autostrasse
    EHWAY                = 167, ///< End German Autostrasse
    NORIDER              = 168, ///< Entry Prohibited for horse riders
    ADDRAINSNOW          = 169, ///< valid during rain or snow
    ADDHUMP              = 170, ///< restriction because of speed hump
    WARNCONST            = 171, ///< warning of constriction
    WARNCONSTL           = 172, ///< warning of constriction left
    WARNCONSTR           = 173, ///< warning of constriction right
    WARNPED              = 174, ///< warning of pedestrians
    WARNKIDS             = 175, ///< warning of children
    WARNBIKE             = 176, ///< warning of bikes
    WARNSKID             = 177, ///< warning of skidding
    ZEBRA                = 178, ///< zebra crossing
    ONEWAYS              = 179, ///< one way street (sideways)
    ONEWAYU              = 180, ///< one way street (arrow up)
    VADDLORRYBUSTRAILER  = 181, ///< vaild for Lorries, Buses and Passenger Cars with Trailer (VMS)
    VADDLORRYBUS         = 182, ///< vaild for Lorries and Buses (VMS)
    VADDLORRYTRAILER     = 183, ///< valid for Lorries and Passenger Cars with Trailer (VMS)
    ADDLORRYTRAILER      = 184,
};

/** SKRoadSignRecognitionServiceDelegate protocol is used for providing information about detected road signs.
 */
@protocol SKRoadSignRecognitionServiceDelegate <NSObject>

/** Called when a road sign is recognized.
 @param roadSignRecognitionService The road sign recognition service.
 @param signString The string representation of the detected sign.
 */
- (void)roadSignDetectionService:(SKRoadSignRecognitionService*)roadSignRecognitionService didDetectPartialSign:(SKRoadSign)partialSign additionalSign:(SKRoadSign)additionalSign;

/** Called when a road sign is recognized.
 @param roadSignRecognitionService The road sign recognition service.
 @param signImage The image taken by the camera about the recognized road sign.
 */
- (void)roadSignDetectionService:(SKRoadSignRecognitionService*)roadSignRecognitionService didArriveCompleteImage:(UIImage*)signImage;
@end

/** SKRoadSignRecognitionService is used for detecting road signs on the route. It has a delegate, that will be notified when a road sign is detected.
 */
@interface SKRoadSignRecognitionService : NSObject

/** The delegate of the SKRoadSignRecognitionService.
 */
@property(nonatomic,weak) id<SKRoadSignRecognitionServiceDelegate> delegate;

/** The configuration of the library.
 */
@property(nonatomic,strong) SKRoadSignRecognitionSettings *settings;

/** The view containing the frames captured by the camera.
 */
@property(nonatomic,strong) UIView *roadSignRecognitionView;

/** Starts the recognition.
 */
-(void)start;

/** Stops the recognition.
 */
-(void)stop;

/** Returns the singleton SKRoadSignRecognitionService instance.
 */
+ (SKRoadSignRecognitionService*)sharedInstance;

@end
