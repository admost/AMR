//
//  MMRequestInfo.h
//  MMAdSDK
//
//  Copyright (c) 2015 Millennial Media, Inc. All rights reserved.
//

#ifndef MMRequestInfo_Header_h
#define MMRequestInfo_Header_h

#import <Foundation/Foundation.h>

/**
 * The object used to configure per-request settings. This object should only be constructed if the context in
 * which your ad placement request is made can be used to imply any additional information useful for targeting.
 */
@interface MMRequestInfo : NSObject

/** Keywords relevant to this individual request, e.g. `["videotapes"]` */
@property (nonatomic, copy, nullable) NSArray* keywords;


/**
 * The impression group ID for sites that are enabled to group traffic in this way.
 */
@property (nonatomic, copy, nullable) NSString* impressionGroup;

@end

#endif
