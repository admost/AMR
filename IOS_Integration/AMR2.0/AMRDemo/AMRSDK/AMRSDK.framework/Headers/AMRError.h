//
//  AMRError.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AMRError : NSObject
/**
 * Error code.
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 */
@property NSInteger errorCode;
/**
 * Description of error.
 */
@property NSString *errorDescription;
+ (instancetype)errorWithError:(NSError *)error;
@end
