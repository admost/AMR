
# AMR Unity Integration

* [Prerequisites](#prerequisites)
* [Setup](#setup)
  + [AMR Unity Packages](#install1)
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
  + <a name="install1"></a>AMR Unity Packages  

You can import AMR core SDK and network adapter packages from [AMR-UNITY-PACKAGES](https://github.com/admost/AMR-UNITY-PACKAGES) folder.
Please refer to following table for required (R) and optional (O) packages for your target platform.

| Integration                         | Android | iOS |
|-------------------------------------|---------|-----|
| amr_unity_core.unitypackage         |    R    |  R  |
| amr_android_core.unitypackage       |    R    |  -  |
| amr_android_adcolony.unitypackage   |    O    |  -  |
| amr_android_admob_adx.unitypackage  |    O    |  -  |
| amr_android_applovin.unitypackage   |    O    |  -  |
| amr_android_appnext.unitypackage    |    O    |  -  |
| amr_android_avocarrot.unitypackage  |    O    |  -  |
| amr_android_chartboost.unitypackage |    O    |  -  |
| amr_android_facebook.unitypackage   |    O    |  -  |
| amr_android_flurry.unitypackage     |    O    |  -  |
| amr_android_flymob.unitypackage     |    O    |  -  |
| amr_android_inmobi.unitypackage     |    O    |  -  |
| amr_android_ironsource.unitypackage |    O    |  -  |
| amr_android_leadbolt.unitypackage   |    O    |  -  |
| amr_android_loopme.unitypackage     |    O    |  -  |
| amr_android_mobfox.unitypackage     |    O    |  -  |
| amr_android_mopub.unitypackage      |    O    |  -  |
| amr_android_nativex.unitypackage    |    O    |  -  |
| amr_android_revmob.unitypackage     |    O    |  -  |
| amr_android_startapp.unitypackage   |    O    |  -  |
| amr_android_tapjoy.unitypackage     |    O    |  -  |
| amr_android_unityads.unitypackage   |    O    |  -  |
| amr_android_vungle.unitypackage     |    O    |  -  |
| amr_ios_core.unitypackage           |    -    |  R  |
| amr_ios_adcolony.unitypackage       |    -    |  O  |
| amr_ios_admob_adx.unitypackage      |    -    |  O  |
| amr_ios_amazon_adx.unitypackage     |    -    |  O  |
| amr_ios_applovin.unitypackage       |    -    |  O  |
| amr_ios_appnext.unitypackage        |    -    |  O  |
| amr_ios_chartboost.unitypackage     |    -    |  O  |
| amr_ios_facebook.unitypackage       |    -    |  O  |
| amr_ios_flurry.unitypackage         |    -    |  O  |
| amr_ios_fyber.unitypackage          |    -    |  O  |
| amr_ios_inmobi.unitypackage         |    -    |  O  |
| amr_ios_ironsource.unitypackage     |    -    |  O  |
| amr_ios_leadbolt.unitypackage       |    -    |  O  |
| amr_ios_loopme.unitypackage         |    -    |  O  |
| amr_ios_mobfox.unitypackage         |    -    |  O  |
| amr_ios_mobusi.unitypackage         |    -    |  O  |
| amr_ios_mopub.unitypackage          |    -    |  O  |
| amr_ios_nativex.unitypackage        |    -    |  O  |
| amr_ios_nexage.unitypackage         |    -    |  O  |
| amr_ios_pubnative.unitypackage      |    -    |  O  |
| amr_ios_revmob.unitypackage         |    -    |  O  |
| amr_ios_smaato.unitypackage         |    -    |  O  |
| amr_ios_startapp.unitypackage       |    -    |  O  |
| amr_ios_tapjoy.unitypackage         |    -    |  O  |
| amr_ios_tappx.unitypackage          |    -    |  O  |
| amr_ios_unityads.unitypackage       |    -    |  O  |
| amr_ios_vungle.unitypackage         |    -    |  O  |

## Start Coding
**<a name="usage1"></a>Initialization**   

To initialize Admost Mediation SDK, create and configure instance of an `AMRSdkConfig` and start the SDK with your config object.  
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

Call onApplicationPause in each of the Unity Scenes:
```c#
void OnApplicationPause(Boolean paused)
{   
	if (paused)
	{
	    AMR.AMRSDK.onPause();
	    AMR.AMRSDK.onStop();
	} else
	{
	    AMR.AMRSDK.onStart();
	    AMR.AMRSDK.onResume();
	}
}
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
