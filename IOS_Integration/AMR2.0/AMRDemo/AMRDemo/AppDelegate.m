//
//  AppDelegate.m
//  AMRDemo
//
//  Created by Tolga Seremet on 19/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "AppDelegate.h"
#import <AMRSDK/AMRSDK.h>

@interface AppDelegate () @end

#pragma mark - NSObject

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.

    [AMRSDK setLogLevel:AMRLogLevelAll];
    [AMRSDK startWithAppId:@"15066ddc-9c18-492c-8185-bea7e4c7f88c"];

    [AMRSDK setStatusBarHidden:YES];
//    [AMRSDK preloadBannersWithZoneIds:@[@"b4009772-de04-42c4-bbaa-c18da9e4a1ab",
//                                        @"8b72580f-c8ed-4080-aac0-004ecab65030",
//                                        @"1b65e016-5b26-4ba0-aff5-b500a96d5157" ]];


    [self startWithNavigationViewController];

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark - Choose viewcontroller

- (void)startWithBannerViewController {
    [self startWithViewControllerIdentifier:@"BannerViewController"];
}

- (void)startWithInterstitialViewController {
    [self startWithViewControllerIdentifier:@"InterstitialViewController"];
}

- (void)startWithRewardedVideoViewController {
    [self startWithViewControllerIdentifier:@"RewardedVideoViewController"];
}

- (void)startWithNavigationViewController {
    [self startWithViewControllerIdentifier:@"NavigationViewController"];
}

- (void)startWithViewControllerIdentifier:(NSString *)identifier {
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    UIViewController *viewController =[[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:identifier];
    self.window.rootViewController = viewController;
    [self.window makeKeyAndVisible];
}

@end
