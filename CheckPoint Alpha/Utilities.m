//
//  Utilities.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 10.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "Utilities.h"

#import "Constants.h"
#import <CoreFoundation/CoreFoundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <netdb.h>
#include <arpa/inet.h>
#import <CommonCrypto/CommonDigest.h>

static NSString   *const kMetricUnits				=   @"kg,cm,km,m";
static NSString   *const kImperialUnits			    =   @"lbs,in,mi,ft";
static NSString   *const kMainStoryboardFile		=	@"UIMainStoryboardFile";
static NSString   *const kTransparentVCIdentifier	=	@"MMAlertViewController";
static NSString   *const kProductString             =   @"product";
static NSString   *const kProductIdSeparator        =   @".";
static NSUInteger  const kProductStringArrayIndex   =   4;

@implementation Utilities

+ (NSString *)getShortCountryForCurrentLocale
{
    NSLocale *currentLocale = [NSLocale currentLocale];  // get the current locale.
    NSString *countryCode = [currentLocale objectForKey:NSLocaleCountryCode];
    return countryCode;
}

+ (NSString *)getFullCountryByShortName:(NSString *)shortCountryName
{
    NSLocale *locale = [NSLocale currentLocale];
    return [locale displayNameForKey:NSLocaleCountryCode value:shortCountryName];
}

+ (void)setButtonTitleUnderline:(UIButton *)button
{
    NSMutableAttributedString *commentString = [[NSMutableAttributedString alloc] initWithString:button.titleLabel.text];
    [commentString addAttribute:NSUnderlineStyleAttributeName value:@(NSUnderlineStyleSingle) range:NSMakeRange(0, [commentString length])];
    [button setAttributedTitle:commentString forState:UIControlStateNormal];
}

+ (UIImage *)getStretchedImageFor:(NSString *)imageName
{
    UIImage *normalImage = [UIImage imageNamed:imageName];
    UIImage *stretchedImage = [normalImage resizableImageWithCapInsets:
                               UIEdgeInsetsMake(normalImage.size.height / 4.0,
                                                normalImage.size.width / 4.0,
                                                normalImage.size.height / 4.0,
                                                normalImage.size.width / 4.0) resizingMode:UIImageResizingModeStretch];
    return stretchedImage;
}

+ (NSString *)getTimeStringFromSeconds:(NSUInteger)seconds
{
    NSDate *startDate = [NSDate date];
    NSDate *endDate = [startDate dateByAddingTimeInterval:seconds];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit range = NSHourCalendarUnit | NSMinuteCalendarUnit;
    [calendar rangeOfUnit:range startDate:&startDate interval:nil forDate:startDate];
    [calendar rangeOfUnit:range startDate:&endDate interval:nil forDate:endDate];
    NSDateComponents *comps = [calendar components:range fromDate:startDate toDate:endDate options:0];
    if (comps.minute < 10) {
        return [NSString stringWithFormat:@"%ld:0%ld", (long)comps.hour, (long)comps.minute];
    }
    
    return [NSString stringWithFormat:@"%ld:%ld", (long)comps.hour, (long)comps.minute];
}

+ (NSString *)getDistanceInKmFromMeter:(NSUInteger)meterValue
{
    if (meterValue / 1000 >= 1000) {
        return [NSString stringWithFormat:@"%0.0f", (float)meterValue / 1000];
    }
    
    return [NSString stringWithFormat:@"%0.1f", [self roundDownDistance:(float)meterValue / 1000]];
}

+ (CGFloat)roundDownDistance:(CGFloat)distance
{
    distance = distance * 10;
    distance = floorf(distance);
    distance = distance / 10;
    
    return distance;
}

+ (NSDictionary *)getUnitSystemDictionaryForUnit:(NSString *)unit
{
    NSArray *unitSystemsArray = nil;
    NSArray *dictKeys = @[[NSString stringWithFormat:@"%@%@", unit, kWeightKey],
                          [NSString stringWithFormat:@"%@%@", unit, kHeightKey],
                          [NSString stringWithFormat:@"%@%@", unit, kDistanceKey],
                          [NSString stringWithFormat:@"%@%@", unit, kShortDistanceKey]];
    
    if ([[unit capitalizedString] isEqualToString:kMetricUnit]) {
        unitSystemsArray = [kMetricUnits componentsSeparatedByString:kComponentSeparatorString];
    } else {
        unitSystemsArray = [kImperialUnits componentsSeparatedByString:kComponentSeparatorString];
    }
    
    NSDictionary *unitDict = [NSDictionary dictionaryWithObjects:unitSystemsArray forKeys:dictKeys];
    
    return unitDict;
}

+ (NSString *)addressStringFromArray:(NSArray *)address
{
    return [address componentsJoinedByString:[NSString stringWithFormat:@"%@ ",kComponentSeparatorString]];
}

+ (NSArray *)getDecimalAsArray:(float)decimalNumber
{
    NSInteger intPart = (NSInteger)decimalNumber;
    float decimalPart = decimalNumber - intPart;
    NSArray *decimalAsArray = @[@(intPart), @(decimalPart)];
    return decimalAsArray;
}

//Date Converter method

+ (NSString *)convertDateString:(NSString *)dateString fromDateFormat:(NSString *)fromDateFormat toDateFormat:(NSString *)toDateFormat
{
    NSDateFormatter *newDateFormatter = [[NSDateFormatter alloc] init];
    [newDateFormatter setDateFormat:fromDateFormat];
    NSDate *convertedDate = [newDateFormatter dateFromString:dateString];
    [newDateFormatter setDateFormat:toDateFormat];
    return [newDateFormatter stringFromDate:convertedDate];
}

+ (NSString *)getTimeStamp
{
    NSTimeInterval timeInterval = [[NSDate date] timeIntervalSince1970];
    timeInterval *= 1000;//adding 3 more digits to match with server
    NSNumber *timestampNum = @(timeInterval);
    return [NSString stringWithFormat:@"%0.0f", [timestampNum doubleValue]];
}

+ (UInt8)getByteInRange:(NSRange)range usingData:(NSData *)data
{
    UInt8 byte = -1;
    NSData *subData = [data subdataWithRange:range];
    byte = *(const UInt8 *)[subData bytes];
    return byte;
}

+ (UInt32)getUInt32InRange:(NSRange)range usingData:(NSData *)data
{
    UInt32 int32 = -1;
    NSData *subData = [data subdataWithRange:range];
    int32 = *(const UInt32 *)[subData bytes];
    return int32;
}

+ (BOOL)isCLLocationCoordinateZero:(CLLocationCoordinate2D)location
{
    return location.latitude == 0 && location.longitude == 0;
}

+ (NSString *)generateJavaScriptCallForAltitudesArray:(NSArray *)altitudes distance:(NSInteger)distance
{
    NSString *altitudesString = [altitudes componentsJoinedByString:@","];
    return [NSString stringWithFormat:@"javascript:loadChart('[%@]','%ld','%ld')", altitudesString, (long)distance, (long)distance];
}

+ (BOOL)isEven:(NSInteger)number
{
    return number % 2 != 0;
}

+ (NSInteger)getCurrentYear
{
    return [[[NSCalendar currentCalendar] components: NSCalendarUnitYear fromDate:[NSDate date]] year];
}

+ (NSString *)getBirthdayForYear:(NSString *)year
{
    return [NSString stringWithFormat:@"%@-01-01", year];
}

+ (NSURL *)getStrippedBaseURLForURL:(NSURL *)url
{
    NSInteger urlPathComponents = [[url pathComponents] count];
    for (int i=0; i < urlPathComponents; i++) {
        url = [url URLByDeletingLastPathComponent];
    }
    
    return url;
}

+ (NSArray *)getIPAddressForHost:(NSString *)hostname
{
    NSMutableArray *ipAddresses = [[NSMutableArray alloc] init];
    CFHostRef hostRef = CFHostCreateWithName(kCFAllocatorDefault, (__bridge CFStringRef)hostname);
    Boolean lookup = CFHostStartInfoResolution(hostRef, kCFHostAddresses, NULL);
    NSArray *addresses = (__bridge NSArray *)CFHostGetAddressing(hostRef, &lookup);
    
    [addresses enumerateObjectsUsingBlock:^(NSData *obj, NSUInteger idx, BOOL *stop) {
        struct sockaddr_in *remoteAddr;
        CFDataRef saData = CFDataCreate(NULL, [obj bytes], [obj length]);
        remoteAddr = (struct sockaddr_in *)CFDataGetBytePtr(saData);
        
        if (remoteAddr != NULL) {
            NSString *strIP =[NSString stringWithCString:inet_ntoa(remoteAddr->sin_addr) encoding:NSASCIIStringEncoding];
            [ipAddresses addObject:strIP];
            DLog(@"DNS TO IP %lu:<%@>", (unsigned long)idx, strIP);
        }
    }];
    
    return ipAddresses;
}

+ (NSString *)getIPv6AddressForHost:(NSString *)hostname
{
    NSString *ipv6Str = nil;
    char const *website = [hostname UTF8String];
    struct hostent *remoteHostEnt = gethostbyname2(website, AF_INET6);
    
    if (remoteHostEnt != NULL) {
        struct in6_addr *remoteIn6Address = NULL;
        remoteIn6Address = (struct in6_addr *)remoteHostEnt->h_addr_list[0];
        char str[INET6_ADDRSTRLEN];
        inet_ntop(AF_INET6, remoteIn6Address, str, INET6_ADDRSTRLEN);
        DLog(@"%s\n", str);
        ipv6Str = [[NSString alloc] initWithUTF8String:str];
    }
    
    return ipv6Str;
}

+ (NSString *)getHostNameForIP:(NSString *)ipAddress
{
    struct in_addr ip;
    NSString *hostName = nil;
    ip.s_addr = inet_addr([ipAddress UTF8String]);
    struct hostent *hostnames = gethostbyaddr(&ip, sizeof(ip), AF_INET);
    
    if (hostnames != NULL && hostnames[0].h_name != NULL) {
        DLog(@"IP to DNS %s\n", hostnames[0].h_name);
        unsigned long hostLength = strlen(hostnames[0].h_name);
        hostName = [[NSString alloc] initWithBytes:hostnames[0].h_name length:hostLength encoding:NSUTF8StringEncoding];
    } else {
        herror("gethostbyaddr");
    }
    
    return hostName;
}

+ (NSString *)getHostNameForIPv6:(NSString *)ipAddress
{
    struct in6_addr ipv6;
    const char *ipChar = [ipAddress UTF8String];
    inet_pton(AF_INET6, ipChar, &ipv6);
    NSString *hostName = nil;
    struct hostent *hostnames = gethostbyaddr(&ipv6, sizeof(ipv6), AF_INET6);
    
    if (hostnames != NULL && hostnames[0].h_name != NULL) {
        DLog("%s\n", hostnames[0].h_name);
        unsigned long hostLength = strlen(hostnames[0].h_name);
        hostName = [[NSString alloc] initWithBytes:hostnames[0].h_name length:hostLength encoding:NSUTF8StringEncoding];
    } else {
        herror("gethostbyaddr");
    }
    
    return hostName;
}

+ (BOOL)containsString:(NSString *)searchString inString:(NSString *)string
{
    return [string rangeOfString:searchString
                         options:NSCaseInsensitiveSearch].location != NSNotFound;
}

+ (NSString *)getLocalizedGenderForEnglishGender:(NSString *)gender
{
    if ([gender isEqualToString:[kMale lowercaseString]]) {
        return NSLocalizedString(@"settings.user.picker.gender.male", nil);
    } else if ([gender isEqualToString:kFemale]) {
        return NSLocalizedString(@"settings.user.picker.gender.female", nil);
    }
    
    return nil;
}

+ (MMCustomViewController *)getTransparentViewController
{
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:[NSBundle mainBundle].infoDictionary[kMainStoryboardFile]
                                                         bundle:[NSBundle mainBundle]];
    
    return [storyboard instantiateViewControllerWithIdentifier:kTransparentVCIdentifier];
}

// Created intentionally two metods and didn't add a flag for adding or removing the string at index 4
// because I think is harder to use by mistake productId for app store instead of local and viceversa.
// Add string "product" from productIdentifier for local use
+ (NSSet *)updateProductIdFormatForItunesUse:(NSSet *)originalIds
{
    NSMutableSet *newProdIds =  [NSMutableSet new];
    for (NSString *oldId in originalIds) {
        NSMutableArray *arr = [NSMutableArray  arrayWithArray:[oldId componentsSeparatedByString:kProductIdSeparator]];
        [arr insertObject:kProductString atIndex:kProductStringArrayIndex];
        [newProdIds addObject:[arr componentsJoinedByString:kProductIdSeparator]];
    }
    
    return newProdIds;
}

// Removes string "product" from productIdentifier for local use
+ (NSSet *)updateProductIdsFormatForLocalUse:(NSSet *)originalIds
{
    NSMutableSet *newProdIds =  [NSMutableSet new];
    for (NSString *oldId in originalIds) {
        [newProdIds addObject:[Utilities updateSingleProductIdsFormatForLocalUse:oldId]];
    }
    
    return newProdIds;
}

+ (NSString *)updateSingleProductIdsFormatForLocalUse:(NSString *)originalId
{
    NSMutableArray *arr = [NSMutableArray  arrayWithArray:[originalId componentsSeparatedByString:kProductIdSeparator]];
    [arr removeObjectAtIndex:kProductStringArrayIndex];
    
    return [arr componentsJoinedByString:kProductIdSeparator];
}

+ (NSString *)md5StringFromData:(NSData *)data
{
    const int resultArraySize = 16;
    unsigned char resultCString[resultArraySize];
    void *cData = malloc([data length]);
    [data getBytes:cData length:[data length]];
    CC_MD5(cData, (unsigned int)[data length], resultCString);
    free(cData);
    
    NSString *result = @"";
    for (int index = 0; index < resultArraySize; index++) {
        result = [result stringByAppendingString:[NSString stringWithFormat:@"%02X", resultCString[index]]];
    }
    return result;
}

@end
