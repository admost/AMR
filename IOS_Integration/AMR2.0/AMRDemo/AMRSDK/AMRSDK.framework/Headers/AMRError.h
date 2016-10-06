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
 * @see https://github.com/kokteyldev/AMR/blob/master/IOS_Integration/README.md for more information.
 */
@property NSInteger errorCode;
/**
 * Description of error.
 */
@property NSString *errorDescription;
@end
