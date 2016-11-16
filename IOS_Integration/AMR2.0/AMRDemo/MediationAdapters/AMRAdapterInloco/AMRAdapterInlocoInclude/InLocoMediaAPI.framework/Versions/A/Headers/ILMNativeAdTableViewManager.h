//
//  ILMNativeAdTableViewManager.h
//  InLocoMediaAPI
//
//  Created by Rafael Gouveia on 6/10/16.
//  Copyright © 2016 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILMAdRequest.h"

@interface ILMNativeAdTableViewManager : NSObject

@property (readonly) UITableView *tableView;

- (id)init NS_UNAVAILABLE;
- (id)initWithNibName:(NSString *)nibName andAdCellHeight:(NSInteger)height;
//Link the manager with your tableView implementation
- (void)linkTableView:(UITableView *)tableView withDelegate:(NSObject <UITableViewDelegate> *)delegate andDataSource:(NSObject <UITableViewDataSource> *)dataSource;
//start loading ads
- (void)loadAds;
//start loading ads with the given adRequest
- (void)loadAds:(ILMAdRequest *)adRequest;

@end