
# AMR iOS Integration

* [Requirements](#requirements)
* [Install](#install)
  + [Core Libraries](#install1)
  + [External Frameworks Available On CocoaPods](#install2)
  + [External Frameworks Not Available On CocoaPods](#install3)
* [Preperation](#preperation)
  + [Zone IDs](#prep1) 
* [Usage](#usage)
  + [Initialization](#usage1)
  + [Requesting Banner Ads](#usage2)
  + [Requesting FullScreen Ads](#usage3)

## Requirements
* iOS 8 or later. 
* [CocoaPods](https://guides.cocoapods.org/using/getting-started.html)
* Zone IDs provided in [Admost Mediation Dashboard](http://dashboard.admost.com).

## Install
  + <a name="install1"></a>Core Libraries  
Add all files in admost-iOSSDK folder to your project (framework, headers, xibs and assets)
  + <a name="install2"></a>External Frameworks Available On CocoaPods  
Add following lines to your Podfile.
```perl
pod 'AFNetworking', '~> 3.1.0'
pod 'FBAudienceNetwork', '~> 4.11.0'
pod 'AdColony', '~> 2.6.1'
pod 'ChartboostSDK', '~> 6.4.0'
pod 'Google-Mobile-Ads-SDK', '~> 7.8.0'
pod 'FlurrySDK', '~>6.7'
pod 'FlurrySDK/FlurrySDK', '~>6.7'
pod 'FlurrySDK/FlurryAds', '~>6.7'
pod 'InMobiSDK'
pod 'mopub-ios-sdk', '~> 4.3.0'
pod 'LoopMeSDK', '~> 5.2.0'
pod 'VungleSDK-iOS', '~> 3.2.0.1'
pod 'MobFoxSDKCoreLib', :git => 'https://github.com/mobfox/MobFox-iOS-SDK-Core-Lib.git'
```
  + <a name="install3"></a>External Frameworks Not Available On CocoaPods  
You must add 2 external frameworks to your project manually. They are available in our demo app’s `frameworks` folder.
```
AmazonAd.framework
AdFalcon headers and lib
```
## Preperation
  + <a name="prep1"></a>Zone IDs  
Add Registery Keys you get from adnetwork’s dashboards to your `info.plist` file.
```plist
	<key>AdColonyRegisterKey</key>
	<string>####</string>
	<key>AdColonyZoneId</key>
	<string>####</string>
	<key>AmazonRegisterKey</key>
	<string>####</string>
	<key>ChartboostAppId</key>
	<string>####</string>
	<key>ChartboostAppSign</key>
	<string>####</string>
	<key>FlurryRegisterKey</key>
	<string>####</string>
	<key>InmobiRegisterKey</key>
	<string>####</string>
	<key>VungleRegisterKey</key>
	<string>####</string>
```
## Usage
  + <a name="usage1"></a>Initialization  
To initialize Admost Mediation SDK, import `ADMAdHandlerInitializer` to your `AppDelegate` file;  
```objectivec
#import “ADMAdHandlerInitializer.h”
```  
and add the following to your `didFinishLaunchingWithOptions` function;  
```objectivec
- (BOOL)application:(UIApplication *)application 
    didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [ADMAdHandlerInitializer SharedInstance];
  return YES;
}
```  
   This starts pre-caching and prepares the SDK to display ads.
  + <a name="usage2"></a>Requesting Banner Ads  
`ADMAdHandler` object is responsible for requesting and displaying banner ads. To start an ad request you should initialize an `ADMAdHandler` object with required parameters and set it's `delegate` as an object which implements `ADMAdLoadedDelegate` protocol. (Generally your UIViewController)  
First import `ADMAdHandler` file to your UIViewController;
```objectivec
#import "ADMAdHandler.h"
```
Create a strong ADMAdHandler variable;
```objectivec
@property (strong, nonatomic) ADMAdHandler* adHandler;
```
Initialize it with required parameters;
```objectivec
[[ADMAdHandler alloc] initWithADMZone:@"####"
                                isBig:YES
                             cellType:ADMAdCellTypeView
                   rootViewController:self
                       containerWidth:320];
```
### ADMAdHandler Parameters

| Parameter     | Type          | Description  |
| :-------------|-------------:|:-----|
| ADMZone      | `NSString` | Zone ID provided in [Admost Mediation Dashboard](http://dashboard.admost.com).|
| isBig      | `BOOL`      | Big or small banner according to your layout. `YES` for 250 points of height, `NO` for 50 points.   |
| cellType | `enum ADMAdCellType`      |    Use `ADMAdCellTypeView` as default. |
| rootViewController | `UIViewController`      | A `UIViewController` which will have the banner view as subview.  |
| containerWidth | `CGFloat`       | Width of banner, generally screen width |

Set its delegate as an `id<ADMAdLoadedDelegate>` object;
```objectivec
adHandler.delegate = self;
```
Load banner;
```objectivec
[self.adHandler loadBannerForPlacement:@"topbanner"]; 
```
### loadBannerForPlacement Parameters

| Parameter     | Type          | Description  |
| :-------------|-------------:|:-----|
| Placement      | `NSString` | Your custom placement string.|

Implement delegate methods to catch if your banner loaded successfully or failed.
```objectivec
#pragma mark - ADMAdLoadedDelegate protocol
- (void)didReceiveAd:(id)banner forPlacement:(NSString*)placement{
    [self.view addSubview:banner];
}
- (void)didFailToReceiveAdForPlacement:(NSString*)placement{
    NSLog(@"Failed to receive ad for placement: %@", placement);
}
```
### didReceiveAd, didFailToReceiveAd Parameters

| Parameter     | Type          | Description  |
| :-------------|-------------:|:-----|
| banner      | `UIView` | Banner view.|
| Placement      | `NSString` | Your custom placement name.|

The returned banner from `didReceiveAd` delegate method is in our customized container. You can use your custom native `UIView` by extending your `UIView`'s file owner Class from `ADMNativeViewCell` class and connect outlets from your xib to `ADMNativeViewCell` class. You should add your custom nibnames to your `info.plist `file with following keys;  
`bigXibName` for big `UIView` and `smallXibName` for small `UIView`.

  + <a name="usage3"></a>Requesting FullScreen Ads  
Interstitial ads are loaded same as banner ads however **they are not shown automatically. `showInterstitialForPlacement` method should be called after successfully receiving an interstital ad**.
Initialize an ADMAdHandler object and set it's delegate as described in [Requesting Banner Ads](#usage2) section above.  
Load interstitial;
```objectivec
[self.adHandler loadInterstitialForPlacement:@"interstitial"]; 
```
### loadInterstitialForPlacement Parameters

| Parameter     | Type          | Description  |
| :-------------|-------------:|:-----|
| Placement      | `NSString` | Your custom interstitial name.|


Implement delegate methods to catch if your interstitial loaded successfully or failed.
```objectivec
#pragma mark - ADMAdLoadedDelegate protocol

- (void)didReceiveInterstitial:(id)banner forPlacement:(NSString*)placement{
    [self.adHandler showInterstitialForPlacement:@”interstitial”]; 
}

- (void)didFailToReceiveInterstitialForPlacement:(NSString*)placement{
    NSLog(@"Failed to receive interstital for placement: %@", placement);
}
- (void)didDismissInterstitialForPlacement:(NSString *)placement{
    NSLog(@"Interstital dismissed for placement: %@", placement);
}
```
