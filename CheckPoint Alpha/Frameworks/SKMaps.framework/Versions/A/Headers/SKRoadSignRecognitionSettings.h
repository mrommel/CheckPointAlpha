//
//  SKRoadSignRecognitionSettings.h
//  SKMaps
//
//  Created by Korosi Csongor on 5/13/14.
//  Copyright (c) 2014 Skobbler. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, SKRoadSignRecognitionType)
{
    SKRoadSignRecognitionTypeReal = 0,
    SKRoadSignRecognitionTypeSimulation = 1,
};

typedef NS_ENUM(NSInteger, SKRoadSignRecognitionCountryCode)
{
    SKRoadSignRecognitionCountryCodeUnknown = 0,
    SKRoadSignRecognitionCountryCodeAD = 1,   // Andorra
    SKRoadSignRecognitionCountryCodeAT = 2,   // Austria
    SKRoadSignRecognitionCountryCodeBE = 3,   // Belgium
    SKRoadSignRecognitionCountryCodeBG = 4,   // Bulgaria
    SKRoadSignRecognitionCountryCodeCH = 5,   // Switzerland
    SKRoadSignRecognitionCountryCodeCZ = 6,   // Czech Republic
    SKRoadSignRecognitionCountryCodeDE = 7,   // Germany
    SKRoadSignRecognitionCountryCodeDK = 8,   // Denmark
    SKRoadSignRecognitionCountryCodeES = 9,   // Spain
    SKRoadSignRecognitionCountryCodeFI = 10,  // Finland
    SKRoadSignRecognitionCountryCodeFR = 11,  // France
    SKRoadSignRecognitionCountryCodeGB = 12,  // United Kingdom
    SKRoadSignRecognitionCountryCodeGR = 13,  // Greece
    SKRoadSignRecognitionCountryCodeHU = 14,  // Hungary
    SKRoadSignRecognitionCountryCodeHR = 15,  // Croatia
    SKRoadSignRecognitionCountryCodeIE = 16,  // Ireland
    SKRoadSignRecognitionCountryCodeIT = 17,  // Italy
    SKRoadSignRecognitionCountryCodeIS = 18,  // Island
    SKRoadSignRecognitionCountryCodeLI = 19,  // Liechtenstein
    SKRoadSignRecognitionCountryCodeLU = 20,  // Luxembourg
    SKRoadSignRecognitionCountryCodeMC = 21,  // Monaco
    SKRoadSignRecognitionCountryCodeMT = 22,  // Malta
    SKRoadSignRecognitionCountryCodeNL = 23,  // Netherlands
    SKRoadSignRecognitionCountryCodeNOR = 24, // Norway
    SKRoadSignRecognitionCountryCodePL = 25,  // Poland
    SKRoadSignRecognitionCountryCodePT = 26,  // Portugal
    SKRoadSignRecognitionCountryCodeRO = 27,  // Romania
    SKRoadSignRecognitionCountryCodeSE = 28,  // Sweden
    SKRoadSignRecognitionCountryCodeSM = 29,  // San Marino
    SKRoadSignRecognitionCountryCodeSI = 30,  // Slovenia
    SKRoadSignRecognitionCountryCodeSK = 31,  // Slovakia
    SKRoadSignRecognitionCountryCodeVA = 32   // Vatican
};

/** Contatins the configuration of the road sign recognition.
 */
@interface SKRoadSignRecognitionSettings : NSObject

/** The type of the detection.
 */
@property(nonatomic,assign) SKRoadSignRecognitionType type;

/** The code of the country.
 */
@property(nonatomic,assign) SKRoadSignRecognitionCountryCode countryCode;

/** The width factor of the image tile.
 */
@property(nonatomic,assign) float imageTileWidthFactor;

/** The height factor of the image tile.
 */
@property(nonatomic,assign) float imageTileHeightFactor;

@end
