
# AMR Unity Integration

* [Prerequisites](#prerequisites)
* [Setup](#setup)
  + [AMR Unity Package](#install1)
  + [Mediation Adapters](#install2)
* [Start Coding](#start-coding)
  + [Initialization](#usage1)
  + [Banner Ads](#usage2)
  + [Interstitial Ads](#usage3)
  + [Rewarded Video Ads](#usage4)

## Prerequisites
* Unity 5 or later. 
* Application Id provided in [Admost Mediation Dashboard](http://dashboard.admost.com).
* Zone Id(s) provided in [Admost Mediation Dashboard](http://dashboard.admost.com).

## Setup
  + <a name="install1"></a>AMR Unity Package  

[Download](http://www.kokteyl.com/unity/AMRUnity.unitypackage) and extract following package in your Unity Project;
```perl
AMRUnity.unitypackage
```
+ <a name="install2"></a>Mediation Adapters

All mediation adapters are included in target platform's plugins folder. At least one mediation adapter is required for AMRSDK to show banners. You can keep all adapters (recommended for maximized revenue) or start with a subset of adapters. For android platform you have to keep files which have 'amr_' prefix. Consult your AMR agent for further details.

## Start Coding
**<a name="usage1"></a>Initialization**   

To initialize Admost Mediation SDK, create and configure instance of an AMRSdkConfig and start the SDK with your config object.  
```c#
AMR.AMRSdkConfig config = new AMR.AMRSdkConfig();
config.ApplicationIdAndroid = "<Your Android App Id>";
config.ApplicationIdIOS = "<Your IOS App Id>";

config.BannerIdAndroid = "<Your Android Banner Zone Id>";
config.BannerIdIOS = "<Your IOS Banner Zone Id>";

config.InterstitialIdAndroid = "<Your Android Interstitial Zone Id>";
config.InterstitialIdIOS = "<Your IOS Interstitial Zone Id>";

config.RewardedVideoIdAndroid = "<Your Android Video Zone Id>";
config.RewardedVideoIdIOS = "<Your IOS Video Zone Id>";
                                            
AMR.AMRSDK.startWithConfig(config);
```  
**<a name="usage2"></a>Banner Ads**  

To create and show a banner ad run the following code
```c#
AMR.AMRSDK.showBanner(AMR.Enums.AMRSDKBannerPosition.BannerPositionTop);
```

Call `hideBanner` method to hide the banner;
```c#
AMR.AMRSDK.hideBanner();
```

**<a name="usage3"></a>Interstitial Ads**  

To load an Interstitial ad run the following code;
```c#
AMR.AMRSDK.loadInterstitial();
```
To show a loaded interstitial run the following code;
```c#
if (AMR.AMRSDK.isInterstitialReady())
	AMR.AMRSDK.showInterstitial();
```
You can subscribe to 2 callback functions `onInterstitialReady` and `onInterstitialDismiss` to catch interstitial events.  
```c#
// Interstitial Callbacks - Optional
AMR.AMRSDK.setOnInterstitialReady(onInterstitialReady);
AMR.AMRSDK.setOnInterstitialDismiss(onInterstitialDismiss);
public void onInterstitialReady()
{
}
public void onInterstitialDismiss()
{
}
```
**<a name="usage4"></a>Rewarded Video Ads**  

Rewarded video ads' implementation is pretty similar to Interstitial ads with 1 additional event `rewardedVideoComplete` to reward the user.

To load an rewarded video ad, run the following code;
```c#
AMR.AMRSDK.loadRewardedVideo();
```
To show a loaded rewarded video ad, run the following code;
```c#
if (AMR.AMRSDK.isRewardedVideoReady())
	AMR.AMRSDK.showRewardedVideo();
```
You can subscribe to 3 callback functions `OnVideoReady`,`OnVideoDismiss` and `OnVideoComplete` to catch rewarded video events.   
```c#
// Rewarded Video Callbacks - Optional
AMR.AMRSDK.setOnRewardedVideoReady(OnVideoReady);
AMR.AMRSDK.setOnRewardedVideoDismiss(OnVideoDismiss);
AMR.AMRSDK.setOnRewardedVideoComplete(OnVideoComplete);

public void OnVideoReady()
{
}

public void OnVideoDismiss()
{
}

public void OnVideoComplete()
{
}
```
