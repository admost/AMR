
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

Extract following package in your Unity Project;
```perl
AMRUnity.unitypackage
```
+ <a name="install2"></a>Mediation Adapters

All mediation adapters are included in target platform's plugins folder. At least one mediation adapter is required for AMRSDK to show banners. You can keep all adapters listed below (recommended for maximized revenue) or start with a subset of adapters. Consult your AMR agent for further details.  
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
## Start Coding
+ <a name="usage1"></a>Initialization   

To initialize Admost Mediation SDK, create an instance of AMRSDK and start the SDK with your iOS and Android application Ids;  
```c#
AMRSdk = new AMR.AMRSDK();
AMRSdk.startWithAppId(<Your iOS App Id>, <Your Android App Id>);
```  
+ <a name="usage2"></a>Banner Ads  

To create and show a banner ad first create a `AMRBannerView` object
```c#
BannerView = new AMR.AMRBannerView();
```
and call `loadBannerForZoneId` method with your iOS and Android Zone Ids, banner placement and callback handler who implements `AMRBannerViewDelegate` interface;  
```c#
BannerView.loadBannerForZoneId( <Your iOS Zone Id>,
                                <Your Android Zone Id>, 
                                BannerPositionTop,
                                this);
```
There are 2 callback methods in `<AMRBannerViewDelegate>` interface.  
`didReceiveBanner` callback method is called to inform the app that the banner is loaded.
```c#
public void didReceiveBanner()
{
    Debug.Log("Banner Received");
}
```
If `didFailToReceiveBanner` callback method is called investigate `error` to address the problem.
```c#
public void didFailtoReceiveBanner(string error)
{
	Debug.Log("ERROR: "+error);
}
```

Call `hideBanner` method to hide the banner;
```c#
Banner.hideBanner();
```

+ <a name="usage3"></a>Interstitial Ads  

To create and show an Interstitial ad first create a `AMRInterstitialView` object
```c#
InterstitialView = new AMR.AMRInterstitialView();
```
and call `loadInterstitialForZoneId` method with your iOS and Android Zone Ids and callback handler who implements `AMRInterstitialViewDelegate` interface;  
```c#
InterstitialView.loadInterstitialForZoneId( <Your iOS Zone Id>,
                                            <Your Android Zone Id>, 
                                            this);
```
There are 3 callback methods in `<AMRInterstitialDelegate>` interface.  
When `didReceiveInterstitial` callback method is called just call the `showInterstitial` method to present interstitial;
```c#
public void didReceiveInterstitial()
{
    InterstitialView.showInterstitial();
}
```
`didDismissInterstitial` callback method is called to inform the application that the interstitial is no longer present. You can use this callback to resume paused tasks during interstitial presentation.
```c#
public void didDismissInterstitial()
{
    Debug.Log("Interstitial Dismissed");
}
```
If `didFailToReceiveInterstitial` callback method is called investigate `error` to adress the problem.
```c#
public void didFailtoReceiveInterstitial(string error)
{
	Debug.Log("ERROR: " + error);
}
```
+ <a name="usage4"></a>Rewarded Video Ads  

Rewarded video ads' implementation is pretty similar to Interstitial ads with 1 additional callback `didCompleteRewardedVideo` to reward the user.

To create and show an Rewarded Video ad first create a `AMRRewardedVideoView` object
```c#
RewardedVideoView = new AMR.AMRRewardedVideoView();
```
and call `loadRewardedVideoForZoneId` method with your iOS and Android Zone Ids and callback handler who implements `AMRRewardedVideoViewDelegate` interface;  
```c#
RewardedVideoView.loadRewardedVideoForZoneId(   <Your iOS Zone Id>,
                                                <Your Android Zone Id>, 
                                                this);
```
There are 4 callback methods in `<AMRRewardedVideoDelegate>` protocol.  
When `didReceiveRewardedVideo` callback method is called just call the `showRewardedVideo` method to present Rewarded Video ad.
```c#
public void didReceiveRewardedVideo()
{
    RewardedVideoView.showRewardedVideo();
}
```
`didCompleteRewardedVideo` callback method is called to inform the application that the user finished watching the video and can be rewarded. Use this callback to reward the user.
```c#
public void didCompleteRewardedVideo()
{
    Debug.Log("Complete");
}
```
`didDismissRewardedVideo` callback method is called to inform the application that the rewarded video is no longer present. You can use this callback to resume paused tasks during rewarded video presentation.
```c#
public void didDismissRewardedVideo()
{
    Debug.Log("Rewarded Video Dismissed");
}
```
If `didFailToReceiveRewardedVideo` callback method is called investigate `error` to adress the problem.
```c#
public void didFailtoReceiveRewardedVideo(string error)
{
    Debug.Log("ERROR: " + error);
}
```
