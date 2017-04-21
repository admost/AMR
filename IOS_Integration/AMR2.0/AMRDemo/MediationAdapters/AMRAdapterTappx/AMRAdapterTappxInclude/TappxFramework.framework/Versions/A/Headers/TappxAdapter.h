//
//  TappxAdapter.h
//  TappxFramework
//
//  Created by David Alarcon on 02/01/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class TappxMediatorStep;
@class TappxAdvertisement;
@class UIViewController;

@protocol TappxAdapter <NSObject>
@property (nonatomic, strong, readonly) NSString* adapterId;
- (void)adaptFromAdvertisement:(TappxAdvertisement*)advertisement atStep:(TappxMediatorStep*)step withCompletionHandler:(void(^)(id mediation, NSError* error))completion;
@optional
- (void)presentAdvertisementToViewController:(UIViewController*)vc onClose:(void(^)())close;
- (void)presentAdvertisementToViewController:(UIViewController*)vc onClose:(void(^)())close andLocation:(CGPoint)location andPosition:(NSString*)position;
- (id)initWithId:(NSString*)id;
@end
