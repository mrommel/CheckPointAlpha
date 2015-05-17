//
//  Utilities.h
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class MMCustomViewController;

@interface Utilities : NSObject

+ (NSString *)getShortCountryForCurrentLocale;
+ (NSString *)getFullCountryByShortName:(NSString *)shortCountryName;
+ (UIImage *)getStretchedImageFor:(NSString *)imageName;
+ (void)setButtonTitleUnderline:(UIButton *)button;
+ (NSString *)getTimeStringFromSeconds:(NSUInteger)seconds;
+ (NSString *)getDistanceInKmFromMeter:(NSUInteger)meterValue;
+ (NSDictionary *)getUnitSystemDictionaryForUnit:(NSString *)unit;
+ (NSArray *)getDecimalAsArray:(float)decimalNumber;
+ (NSString *)convertDateString:(NSString *)dateString fromDateFormat:(NSString *)fromDateFormat toDateFormat:(NSString *)toDateFormat;
+ (NSString *)getTimeStamp;
+ (UInt8)getByteInRange:(NSRange)range usingData:(NSData *)data;
+ (UInt32)getUInt32InRange:(NSRange)range usingData:(NSData *)data;
+ (BOOL)isCLLocationCoordinateZero:(CLLocationCoordinate2D)location;
+ (NSString *)generateJavaScriptCallForAltitudesArray:(NSArray *)altitudes distance:(NSInteger)distance;
+ (BOOL)isEven:(NSInteger)number;
+ (NSInteger)getCurrentYear;
+ (NSString *)getBirthdayForYear:(NSString *)year;
+ (NSURL *)getStrippedBaseURLForURL:(NSURL *)url;
+ (NSArray *)getIPAddressForHost:(NSString *)hostname;
+ (NSString *)getIPv6AddressForHost:(NSString *)hostname;
+ (NSString *)getHostNameForIP:(NSString *)ipAddress;
+ (NSString *)getHostNameForIPv6:(NSString *)ipAddress;

+ (BOOL)containsString:(NSString *)searchString inString:(NSString *)string;
+ (NSString *)getLocalizedGenderForEnglishGender:(NSString *)gender;
+ (MMCustomViewController *)getTransparentViewController;
+ (NSString *)updateSingleProductIdsFormatForLocalUse:(NSString *)originalId;
+ (NSSet *)updateProductIdsFormatForLocalUse:(NSSet *)originalIds;
+ (NSSet *)updateProductIdFormatForItunesUse:(NSSet *)originalIds;
+ (NSString *)md5StringFromData:(NSData *)data;
+ (NSString *)addressStringFromArray:(NSArray *)address;

@end

