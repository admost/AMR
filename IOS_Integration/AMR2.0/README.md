
# AMR iOS Integration

* [Prerequisites](#prerequisites)
* [Setup](#setup)
  + [Installation With CocoaPods](#install00)
    + [Create your podfile and install](#install0)
  + [Manual Installation](#install11)
    + [AMR Framework Files](#install1)
    + [Other Frameworks and Libraries](#install2)
    + [Mediation Adapters](#install3)
  + [Xcode Setup](#install4)
* [Start Coding](#start-coding)
  + [Initialization](#usage1)
  + [Banner Ads](#usage2)
  + [Interstitial Ads](#usage3)
  + [Rewarded Video Ads](#usage4)

## Prerequisites
* iOS 7 or later. 
* Application Id provided in [Admost Mediation Dashboard](http://dashboard.admost.com).
* Zone Id(s) provided in [Admost Mediation Dashboard](http://dashboard.admost.com).
* For testing you can use following IDs;
```
Application Id: @"15066ddc-9c18-492c-8185-bea7e4c7f88c"
Banner Zone Id: @"b4009772-de04-42c4-bbaa-c18da9e4a1ab"
Interstitial Zone Id: @"39f74377-5682-436a-9338-9d1c4df410bd"
RewardedVideo Zone Id: @"2bdefd44-5269-4cbc-b93a-373b74a2f067"
```

## Setup
You can install AMR SDK and mediation adapters using CocoaPods (recommended) or add AMR SDK framework files and mediation adapters files manually to your project.  
### <a name="install00"></a>Installation With CocoaPods  
[CocoaPods](http://cocoapods.org) is a dependency manager for Swift and Objective-C Cocoa projects which automates and simplifies the process of using 3rd-party libraries like AMR in your projects. See [getting started](https://guides.cocoapods.org/using/getting-started.html) guide for more information on installing cocoapods.  
+ <a name="install0"></a>**Create your podfile and install**  

At least one mediation adapter is required for AMRSDK to show banners. You can add all adapters (recommended for maximized revenue) or start with a subset of adapters. Consult your AMR agent for further details.  
To integrate AMR SDK and mediation adapters into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '7.0'

use_frameworks!

target 'MyAwesomeTarget' do
    #core SDK
   pod 'AMRSDK', '~> 1.0'
    #mediation adapters
   pod 'AMRAdapterAdcolony', '~> 3.0'
   pod 'AMRAdapterAdfalcon', '~> 3.2'
   pod 'AMRAdapterAdmob', '~> 7.16'
   pod 'AMRAdapterAdmost', '~> 1.0'
   pod 'AMRAdapterAmazon', '~> 2.2'
   pod 'AMRAdapterApplovin', '~> 3.4'
   pod 'AMRAdapterAppnext', '~> 1.7'
   pod 'AMRAdapterAvocarrot', '~> 4.2' #ios 8+
   pod 'AMRAdapterChartboost', '~> 6.5'
   pod 'AMRAdapterConversant', '~> 4.5'
   pod 'AMRAdapterFacebook', '~> 4.18'
   pod 'AMRAdapterFlurry', '~> 7.6'
   pod 'AMRAdapterFyber', '~> 8.6'
   pod 'AMRAdapterInloco', '~> 2.2'
   pod 'AMRAdapterInmobi', '~> 6.0'
   pod 'AMRAdapterLoopme', '~> 6.0'
   pod 'AMRAdapterMobfox', '~> 2.4'
   pod 'AMRAdapterMopub', '~> 4.11'
   pod 'AMRAdapterNativex', '~> 5.5'
   pod 'AMRAdapterNexage', '~> 6.3'
   pod 'AMRAdapterPubnative', '~> 1.4' #ios 8+
   pod 'AMRAdapterRevmob', '~> 9.2'
   pod 'AMRAdapterSmaato', '~> 8.0'
   pod 'AMRAdapterStartapp', '~> 3.4'
   pod 'AMRAdapterSupersonic', '~> 6.4'
   pod 'AMRAdapterTapjoy', '~> 11.8'
   pod 'AMRAdapterUnity', '~> 2.0'
   pod 'AMRAdapterVungle', '~> 4.0'

end

```
Then, run the following command:

```bash
$ pod install
```
Additionally if you want to install Admost Adserver SDK add following line to your podfile  
```ruby
  pod 'AMRAdmostSDK', '~> 1.0'
```
After you complete pod installation you can skip to [Xcode Setup](#install4) step.

### <a name="install11"></a>Manual Installation  
+ <a name="install1"></a>**AMR Framework Files**  

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
AMRAdapterAdcolony
AMRAdapterAdFalcon
AMRAdapterAdmob
AMRAdapterAdmost
AMRAdapterAmazon
AMRAdapterApplovin
AMRAdapterAppnext
AMRAdapterAvocarrot -iOS 8+
AMRAdapterChartboost
AMRAdapterConversant
AMRAdapterFacebook
AMRAdapterFlurry
AMRAdapterFyber
AMRAdapterInloco
AMRAdapterInmobi
AMRAdapterLoopme
AMRAdapterMobfox
AMRAdapterMopub
AMRAdapterNativex
AMRAdapterNexage
AMRAdapterPubNative -iOS 8+
AMRAdapterRevmob
AMRAdapterSmaato
AMRAdapterStartapp
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
For testing you can use following Application Id;
```
Application Id: @"15066ddc-9c18-492c-8185-bea7e4c7f88c"
```
+ <a name="usage2"></a>**Banner Ads**  

To create and show a banner ad first import `AMRSDK.h` to your `UIViewController` file;  
```objectivec
#import <AMRSDK/AMRSDK.h>
```
and create an `AMRBanner` object, initialize it with your Banner Zone Id and set it's `delegate` to an object (generally your viewController) which conforms to `<AMRBannerDelegate>` protocol.  
```objectivec
AMRBanner *mpuBanner;
mpuBanner = [AMRBanner bannerForZoneId:@"<zoneId>"];
mpuBanner.delegate = self;
```  
For testing you can use following Banner Zone Id;
```
Banner Zone Id: @"b4009772-de04-42c4-bbaa-c18da9e4a1ab"
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
and create an `AMRInterstitial` object, initialize it with your Interstitial Zone Id and set it's `delegate` to an object (generally your viewController) which conforms to `<AMRInterstitialDelegate>` protocol.  
```objectivec
AMRInterstitial *fullScreen;
fullScreen = [AMRInterstitial interstitialForZoneId:@"<zoneId>"];
fullScreen.delegate = self;
[fullScreen loadInterstitial];
```  
For testing you can use following Interstitial Zone Id;
```
Interstitial Zone Id: @"39f74377-5682-436a-9338-9d1c4df410bd"
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
and create an `AMRRewardedVideo` object, initialize it with your RewardedVideo Zone Id and set it's `delegate` to an object (generally your viewController) which conforms to `<AMRRewardedVideoDelegate>` protocol.  
```objectivec
AMRRewardedVideo *rewardedVideo;
rewardedVideo = [AMRRewardedVideo rewardedVideoForZoneId:@"<zoneId>"];
rewardedVideo.delegate = self;
[rewardedVideo loadRewardedVideo];
```  
For testing you can use following RewardedVideo Zone Id;
```
RewardedVideo Zone Id: @"2bdefd44-5269-4cbc-b93a-373b74a2f067"
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
