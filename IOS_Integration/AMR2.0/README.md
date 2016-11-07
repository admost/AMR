
# AMR iOS Integration

* [Prerequisites](#prerequisites)
* [Setup](#setup)
  + [AMR Framework files](#install1)
  + [Other Frameworks and Libraries](#install2)
  + [Mediation Adapters](#install3)
  + [Xcode setup](#install4)
* [Start Coding](#start-coding)
  + [Initialization](#usage1)
  + [Banner Ads](#usage2)
  + [Interstitial Ads](#usage3)
  + [Rewarded Video Ads](#usage4)

## Prerequisites
* iOS 7 or later. 
* Application Id provided in [Admost Mediation Dashboard](http://dashboard.admost.com).
* Zone Id(s) provided in [Admost Mediation Dashboard](http://dashboard.admost.com).

## Setup
  + <a name="install1"></a>**AMR Framework files**  

Drag and drop following files in [AMRDemo/AMRSDK](https://github.com/kokteyldev/AMR/tree/master/IOS_Integration/AMR2.0/AMRDemo/AMRSDK) folder to your project.
```perl
AMRSDK.framework
AMRResources.bundle
KKLog.framework
```
  + <a name="install2"></a>**Other Frameworks and Libraries**  

Add following frameworks and libraries to your project
```perl
AddressBook.framework
AdSupport.framework
AudioToolbox.framework
AVFoundation.framework
AVKit.framework
CFNetwork.framework
CoreGraphics.framework
CoreLocation.framework
CoreMedia.framework
CoreMotion.framework
CoreTelephony.framework
EventKit.framework
EventKitUI.framework
Foundation.framework
JavaScriptCore.framework
libsqlite3.tbd
libz.tbd
MediaPlayer.framework
QuartzCore.framework
SafariServices.framework
StoreKit.framework
SystemConfiguration.framework
UIKit.framework
WebKit.framework
```
+ <a name="install3"></a>**Mediation Adapters**  

At least one mediation adapter is required for AMRSDK to show banners. You can add all adapters (recommended for maximized revenue) or start with a subset of adapters. Consult your AMR agent for further details.  
Create a folder called Mediation Adapters (name is optonal) and add adapters in [AMRDemo/MediationAdapters](https://github.com/kokteyldev/AMR/tree/master/IOS_Integration/AMR2.0/AMRDemo/MediationAdapters) folder.  
```perl
AMRAdapterAdFalcon
AMRAdapterAdcolony
AMRAdapterAdmob
AMRAdapterAdmost
AMRAdapterAmazon
AMRAdapterApplovin
AMRAdapterAppnext
AMRAdapterChartboost
AMRAdapterFacebook
AMRAdapterFlurry
AMRAdapterInmobi
AMRAdapterLoopme
AMRAdapterMobfox
AMRAdapterMopub
AMRAdapterNativex
AMRAdapterNexage
AMRAdapterRevmob
AMRAdapterSmaato
AMRAdapterSupersonic
AMRAdapterTapjoy
AMRAdapterUnity
AMRAdapterVungle
```
+ <a name="install4"></a>**Xcode Setup**  

Make sure `$(PROJECT_DIR) recursive` is set in your target's `Framework Search Paths` in `Build Settings`.  
Add `-ObjC` flag in your target's `Other Linker Flags` in `Build Settings`.  
Add following lines to your `plist` file.
```plist
<key>NSAppTransportSecurity</key>
<dict>
  <key>NSAllowsArbitraryLoads</key>
  <true/>
</dict>
```
```plist
<key>NSCalendarsUsageDescription</key>
<string>Some ad content may access calendar</string>
```  


## Start Coding
+ <a name="usage1"></a>**Initialization**   

To initialize Admost Mediation SDK, import `AMRSDK.h` to your `AppDelegate` file;  
```objectivec
#import <AMRSDK/AMRSDK.h>
```  
and initialize AMRSDK with your Application Id in `didFinishLaunchingWithOptions` callback;  
```objectivec
- (BOOL)application:(UIApplication *)application 
    didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [AMRSDK startWithAppId:@"<appId>"];
  return YES;
}
```  
+ <a name="usage2"></a>**Banner Ads**  

To create and show a banner ad first import `AMRSDK.h` to your `UIViewController` file;  
```objectivec
#import <AMRSDK/AMRSDK.h>
```
and create an `AMRBanner` object, initialize it with your Zone Id and set it's `delegate` to an object (generally your viewController) which conforms to `<AMRBannerDelegate>` protocol.  
```objectivec
AMRBanner *mpuBanner;
mpuBanner = [AMRBanner bannerForZoneId:@"<zoneId>"];
mpuBanner.delegate = self;
```
Optionally you can set the width of the banner, default value is screen width.
```objectivec
mpuBanner.bannerWidth = 300;
```
Start loading banner with `loadBanner` method and wait for the `<AMRBannerDelegate>` protocol callbacks.
```objectivec
[mpuBanner loadBanner];
```
There are 2 callback methods in `<AMRBannerDelegate>` protocol.  
When `didReceiveBanner` callback method is called just add banner's `bannerView` as a subview on your viewcontroller to show banner.
```objectivec
- (void)didReceiveBanner:(AMRBanner *)banner {
    [self.view addSubview:banner.bannerView];
}
```
If `didFailToReceiveBanner` callback method is called investigate `error` to adress the problem.
```objectivec
- (void)didFailToReceiveBanner:(AMRBanner *)banner error:(AMRError *)error {
    NSLog(error.errorDescription);
}
```
+ <a name="usage3"></a>**Interstitial Ads**  

To create and show an interstitial ad first import `AMRSDK.h` to your `UIViewController` file;  
```objectivec
#import <AMRSDK/AMRSDK.h>
```
and create an `AMRInterstitial` object, initialize it with your Zone Id and set it's `delegate` to an object (generally your viewController) which conforms to `<AMRInterstitialDelegate>` protocol.  
```objectivec
AMRInterstitial *fullScreen;
fullScreen = [AMRInterstitial interstitialForZoneId:@"<zoneId>"];
fullScreen.delegate = self;
[fullScreen loadInterstitial];
```
There are 3 callback methods in `<AMRInterstitialDelegate>` protocol.  
When `didReceiveInterstitial` callback method is called just call the `showFromViewController` method to present interstitial from a viewController.
```objectivec
- (void)didReceiveInterstitial:(AMRInterstitial *)interstitial {
    [interstitial showFromViewController:self];
}
```
`didDismissInterstitial` callback method is called to inform the application that the interstitial is no longer present. You can use this callback to resume paused tasks during interstitial presentation.
```objectivec
- (void)didDismissInterstitial:(AMRInterstitial *)interstitial {
    [animation resume];
}
```
If `didFailToReceiveInterstitial` callback method is called investigate `error` to adress the problem.
```objectivec
- (void)didFailToReceiveInterstitial:(AMRInterstitial *)interstitial error:(AMRError *)error {
    NSLog(error.errorDescription);
}
```
+ <a name="usage4"></a>**Rewarded Video Ads**  

Rewarded video ads' implementation is pretty similar to Interstitial ads with 1 additional callback `didCompleteRewardedVideo` to reward the user.
To create and show a rewarded video ad first import `AMRSDK.h` to your `UIViewController` file;  
```objectivec
#import <AMRSDK/AMRSDK.h>
```
and create an `AMRRewardedVideo` object, initialize it with your Zone Id and set it's `delegate` to an object (generally your viewController) which conforms to `<AMRRewardedVideoDelegate>` protocol.  
```objectivec
AMRRewardedVideo *rewardedVideo;
rewardedVideo = [AMRRewardedVideo rewardedVideoForZoneId:@"<zoneId>"];
rewardedVideo.delegate = self;
[rewardedVideo loadRewardedVideo];
```
There are 4 callback methods in `<AMRRewardedVideoDelegate>` protocol.  
When `didReceiveRewardedVideo` callback method is called just call the `showFromViewController` method to present rewarded video from a viewController.
```objectivec
- (void)didReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo {
    [rewardedVideo showFromViewController:self];
}
```
`didCompleteRewardedVideo` callback method is called to inform the application that the user finished watching the video and can be rewarded. Use this callback to reward the user.
```objectivec
- (void)didCompleteRewardedVideo:(AMRRewardedVideo *)rewardedVideo {
    [player reward];
}
```
`didDismissRewardedVideo` callback method is called to inform the application that the rewarded video is no longer present. You can use this callback to resume paused tasks during rewarded video presentation.
```objectivec
- (void)didDismissRewardedVideo:(AMRRewardedVideo *)rewardedVideo {
    [animation resume];
}
```
If `didFailToReceiveRewardedVideo` callback method is called investigate `error` to adress the problem.
```objectivec
- (void)didFailToReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo error:(AMRError *)error {
    NSLog(error.errorDescription);
}
```
