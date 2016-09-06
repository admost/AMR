//
//  KKLog.h
//  KKLog
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>


#pragma mark - Log Levels
typedef NS_ENUM(NSInteger, KKLogLevel){
    // No logs
    KKLogLevelSilent = 0,

    // All errors logged
    KKLogLevelError = 1,

    // All errors and warnings logged
    KKLogLevelWarning = 2,

    // All errors, warnings and infos logged
    KKLogLevelInfo = 3,

    // All logged
    KKLogLevelAll = 99
};

@interface KKLog : NSObject
+ (void)LogLevel:(KKLogLevel)logLevel;

+ (void)KKLogError:(NSString *)error;
+ (void)KKLogWarning:(NSString *)warning;
+ (void)KKLogInfo:(NSString *)info;
+ (void)KKLog:(NSString *)message;

@end
