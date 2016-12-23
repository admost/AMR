
# AMR Cordova Integration

* [Prerequisites](#prerequisites)
* [Setup](#setup)
  + [Install Plugin](#install1)
  + [Mediation Adapters](#install2)
* [Start Coding](#start-coding)
  + [Configuration](#usage1)
  + [Initialize AMR Plugin](#usage2)
  + [Banner Ads](#usage3)
  + [Interstitial Ads](#usage4)
  + [Video Ads](#usage5)
* [Notes](#notes)
  + [Remove Unsused Adaptors](#notes1)

## Prerequisites
* [Cocoapods](https://cocoapods.org) for iOS. 
* Application Id provided in [Admost Mediation Dashboard](http://dashboard.admost.com).
* Zone Id(s) provided in [Admost Mediation Dashboard](http://dashboard.admost.com).

## Setup
  + <a name="install1"></a>Install Plugin 
```perl
$ cordova plugin add https://github.com/admost/AMR-CORDOVA-PLUGIN
```
+ <a name="install2"></a>Mediation Adapters

All mediation adapters are included in the plugin. At least one mediation adapter is required for AMRSDK to show ads. You can keep all adapters (recommended for maximized revenue) or start with a subset of adapters. Consult your AMR agent for further details.

## Start Coding
+ <a name="usage1"></a>Configuration   
To configure AMR Plugin, replace the necessary keys with your own keys. amrAppId and at least one zoneId is necessary;   
```javascript
var ad_units = {
            ios : {
            amrAppId: '<AMR_APP_ID>',
            amrBannerZoneId: '<AMR_BANNER_ZONE_ID>',
            amrInterstitialZoneId: '<AMR_INTERSTITIAL_ZONE_ID>',
            amrVideoZoneId: '<AMR_VIDEO_ZONE_ID>'
            },
            android : {
            amrAppId: '<AMR_APP_ID>',
            amrBannerZoneId: '<AMR_BANNER_ZONE_ID>',
            amrInterstitialZoneId: '<AMR_INTERSTITIAL_ZONE_ID>',
            amrVideoZoneId: '<AMR_VIDEO_ZONE_ID>'
            }
        };

var amrIds = ( /(android)/i.test(navigator.userAgent) ) ? ad_units.android : ad_units.ios;

window.plugins.Amr.setOptions( {
                                amrAppId: amrIds.amrAppId,
                                amrBannerZoneId: amrIds.amrBannerZoneId,
                                amrInterstitialZoneId: amrIds.amrInterstitialZoneId,
                                amrVideoZoneId: amrIds.amrVideoZoneId,
                                //optional parameters
                                adSize: window.plugins.Amr.AD_SIZE.LEADERBOARD,  //android only. Use BANNER, LEADERBOARD, MEDIUM_RECTANGLE
                                bannerWidth: 300, //iOS only
                                bannerAtTop: true, // set to true, to put banner at top
                                overlap: true, // banner will overlap webview
                                offsetTopBar: true, // set to true to avoid ios7 status bar overlap
                                autoShowBanner: true, // auto show banner ad when loaded
                                autoShowInterstitial: true, // auto show interstitial ad when loaded
                                autoShowVideo: true // auto show video ad when loaded
                                });
```  
+ <a name="usage2"></a>Initialize AMR Plugin  

Call `initAMR` method to initialize AMR Plugin;
```javascript
window.plugins.Amr.initAMR();
```
+ <a name="usage3"></a>Banner Ads 

Call `createBannerAd` method to create banner. If you set `autoShowBanner` as `true` banner will be shown automaticly;
```javascript
window.plugins.Amr.createBannerAd();
```
Otherwise you have to call `showBannerAd` method to show banner manually;
```javascript
window.plugins.Amr.showBannerAd(true);
```
Call `showBannerAd` method with a false boolean parameter to hide banner;
```javascript
window.plugins.Amr.showBannerAd(false);
```
Call `destroyBannerAd` method to close banner;
```javascript
window.plugins.Amr.destroyBannerAd();
```
Register for banner events;
```javascript
document.addEventListener('onReceiveBannerAd', function(){});
document.addEventListener('onFailedToReceiveBannerAd', function(error){});
```
+ <a name="usage4"></a>Interstitial Ads 

Call `createInterstitialAd` method to create interstitial;
```javascript
window.plugins.Amr.createInterstitialAd();
```
Call `showInterstitialAd` method to show interstitial manually;
```javascript
window.plugins.Amr.showInterstitialAd();
```
Register for interstitial events;
```javascript
document.addEventListener('onReceiveInterstitialAd', function(){ });
document.addEventListener('onFailedToReceiveInterstitialAd', function(error){ });
document.addEventListener('onDismissInterstitialAd', function(){ });
```

+ <a name="usage5"></a>Video Ads 

Call `createVideoAd` method to create video;
```javascript
window.plugins.Amr.createVideoAd();
```
Call `showVideoAd` method to show video manually;
```javascript
window.plugins.Amr.showVideoAd();
```
Register for video events;
```javascript
document.addEventListener('onReceiveVideoAd', function(){ });
document.addEventListener('onFailedToReceiveVideoAd', function(error){});
document.addEventListener('onDismissVideoAd', function(){ });
document.addEventListener('onCompleteVideoAd', function(){ });
```

## Notes

+ <a name="notes1"></a>Remove Unsused Adaptors

To remove unsused AMR adaptors from your project;
  * Find 'Podfile' file in your project and delete unused AMR adaptor lines.
  * On terminal, navigate your iOS project folder, then execute following code;
```perl
$ pod install
```
