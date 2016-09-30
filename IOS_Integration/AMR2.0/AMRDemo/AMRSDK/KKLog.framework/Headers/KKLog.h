//
//  KKLog.h
//  KKLog
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Log Levels

/** Log levels of AMRSDK. */
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

/**
 * Set log level of KKLog.
 * Example usage:
 * @code
 * KKLogSetLoglevel(KKLogLevelError);
 * @endcode
 * @param logLevel KKLogLevel enum value.
 */
void KKLogSetLoglevel(KKLogLevel logLevel);

/**
 * Set log prefix string to be added before log type prefix.
 * Example usage:
 * @code
 * KKLogSetLogPrefix(@"<MySDK> ");
 * @endcode
 * @param prefixString A string to print at the beginning if log.
 */
void KKLogSetLogPrefix(NSString* prefixString);

void KKLogError(NSString *error, ...);
void KKLogWarning(NSString *warning, ...);
void KKLogInfo(NSString *info, ...);
void KKLogMessage(NSString *message, ...);

@end
