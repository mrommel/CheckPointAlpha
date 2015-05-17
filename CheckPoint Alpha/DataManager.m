//
//  DataManager.m
//  CheckPoint Alpha
//
//  Created by Michael Rommel on 11.11.14.
//  Copyright (c) 2014 Michael Rommel. All rights reserved.
//

#import "DataManager.h"

#import "WSAPIClient.h"
#import "WSError.h"

@interface DataManager ()

@property (strong, nonatomic) NSMutableSet *operations;

@end

@implementation DataManager

+ (DataManager *)sharedInstance
{
    static DataManager *sharedDataManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedDataManager = [[self alloc] init];
        sharedDataManager.operations = [NSMutableSet new];
    });
    
    return sharedDataManager;
}

- (void)setAuthorizationHeaderWithUsername:(NSString *)user password:(NSString *)password
{
    [[WSAPIClient sharedClient] setAuthorizationHeaderWithUsername:user password:password];
}

#pragma mark - Instance methods

//Request for a JSON
- (void)getDataFromServerWithPath:(NSString *)path withBlock:(ResponseBlock)block
{
    [[WSAPIClient sharedClient] getPath:path parameters:nil success:^(AFHTTPRequestOperation *operation, id responseObject) {
        if (responseObject) {
            DLog(@"***JSON*** %@",responseObject);
            NSDictionary *result = @{};
            if ([responseObject isKindOfClass:[NSDictionary class]]) {
                result = responseObject;
            }
            
            if (block) {
                block(result, nil);
            }
        } else {
            DLog(@"NO VALID JSON FOUND!!");
            if (block) {
                block(@{}, nil);
            }
        }
        
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        DLog(@"***ERROR*** %@", operation.response);
        if (block) {
            block(operation.responseString, [[WSError alloc] initWithResponseObject:operation.responseString errorCode:operation.response.statusCode]);
        }
    }];
}

static NSString * AFBase64EncodedStringFromString(NSString *string) {
    NSData *data = [NSData dataWithBytes:[string UTF8String] length:[string lengthOfBytesUsingEncoding:NSUTF8StringEncoding]];
    NSUInteger length = [data length];
    NSMutableData *mutableData = [NSMutableData dataWithLength:((length + 2) / 3) * 4];
    
    uint8_t *input = (uint8_t *)[data bytes];
    uint8_t *output = (uint8_t *)[mutableData mutableBytes];
    
    for (NSUInteger i = 0; i < length; i += 3) {
        NSUInteger value = 0;
        for (NSUInteger j = i; j < (i + 3); j++) {
            value <<= 8;
            if (j < length) {
                value |= (0xFF & input[j]);
            }
        }
        
        static uint8_t const kAFBase64EncodingTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        
        NSUInteger idx = (i / 3) * 4;
        output[idx + 0] = kAFBase64EncodingTable[(value >> 18) & 0x3F];
        output[idx + 1] = kAFBase64EncodingTable[(value >> 12) & 0x3F];
        output[idx + 2] = (i + 1) < length ? kAFBase64EncodingTable[(value >> 6)  & 0x3F] : '=';
        output[idx + 3] = (i + 2) < length ? kAFBase64EncodingTable[(value >> 0)  & 0x3F] : '=';
    }
    
    return [[NSString alloc] initWithData:mutableData encoding:NSASCIIStringEncoding];
}

//Request for a ZIP file
- (void)fetchMapPachageZipFromServerWithPath:(NSString *)pathToZip withProgressBar:(UIProgressView *)progressBar withBlock:(ResponseBlock)block
{
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:pathToZip]];
        //Save  file to Documents
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *path = [paths[0] stringByAppendingPathComponent:[pathToZip lastPathComponent]];
        // removes the map data if is already saved
        NSFileManager *fileManager = [NSFileManager defaultManager];
        [fileManager removeItemAtPath:path error:NULL];
        AFDownloadRequestOperation *operation = [[AFDownloadRequestOperation alloc] initWithRequest:request targetPath:path shouldResume:NO];
        
        NSLog(@"%@",operation.targetPath);
        [self.operations addObject:operation];
        
        [operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
            NSLog(@"Successfully downloaded file to %@", path);
            [self.operations removeObject:operation];
            if (responseObject) {
                block(responseObject, nil);
            }
        } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
            NSLog(@"Error: %@", error);
            if (block) {
                [self.operations removeObject:operation];
                progressBar.hidden = YES;
                block(operation.responseString, [[WSError alloc] initWithResponseObject:operation.responseString errorCode:operation.response.statusCode]);
            }
        }];
        
        [operation setProgressiveDownloadProgressBlock:^(NSInteger bytesRead, long long totalBytesRead, long long totalBytesExpected, long long totalBytesReadForFile, long long totalBytesExpectedToReadForFile) {
            dispatch_async(dispatch_get_main_queue(), ^{
                //progress bar action
                if (progressBar.isHidden) {
                    progressBar.hidden = NO;
                }
                progressBar.progress = (CGFloat) totalBytesRead / (CGFloat) totalBytesExpectedToReadForFile;
                NSLog(@"%@ --> %f", pathToZip, progressBar.progress * 100);
            });
        }];
        
        DLog(@"headers %@", request.allHTTPHeaderFields);
        [[WSAPIClient sharedClient] enqueueHTTPRequestOperation:operation];
    });
}

- (AFDownloadRequestOperation *)getDownloadOperationByCountryCode:(NSString *)countryCode
{
    for (AFDownloadRequestOperation *operation in self.operations) {
        NSString *operationCountryCode = [[operation.targetPath lastPathComponent] stringByDeletingPathExtension];
        if ([operationCountryCode isEqualToString:countryCode]) {
            return operation;
        }
    }
    return nil;
}

- (void)cancelDownload:(AFDownloadRequestOperation* )downloadOperation
{
    [downloadOperation cancel];
    [self.operations removeObject:downloadOperation];
}

@end
