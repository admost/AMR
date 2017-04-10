# AMR Android Integration
* [Requirements](#requirements)  
* [Install](#install)
  + [Libs](#libs)
  + [Manifest](#manifest)
  + [Gradle](#gradle)
* [Usage](#usage)
	+ [Initialization](#initialization)
	+ [Banner Ads](#banner-ads)
	+ [Interstitial Ads](#interstitial-ads)
	+ [Rewarded Video Ads](#rewarded-video-ads)
	+ [Offerwalls](#offerwalls)
* [Misc](#misc)
	+ [Proguard](#proguard)
# Requirements
* Android 2.3 (Gingerbread - API Version 9) or later.
* APP ID & ZONE ID(s) provided in [Admost Mediation Dashboard](http://dashboard.admost.com).
# Install
### Libs
Copy the following libraries to the libs folder of your app from [this link](https://github.com/admost/AMR/tree/master/Android_Integration/libs).
Only Admost, Volley and Google Play Services Ads libraries are compulsory for mediation system. If you don’t add any one of the network to your app, the SDK will detect that the ad network library isn't there and fail gracefully; the request will continue with the next network in the mediation waterfall.
### Manifest
Add the following permissions optionally into your AndroidManifest.xml for improve user targeting and will result in higer performance.
```sh
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION"/>
<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION"/>
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>
<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
<uses-permission android:name="android.permission.READ_PHONE_STATE"/>
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" android:maxSdkVersion="18" />
```
Add the following lines inside the application tag.
#### AppLovin Publishers
```sh
<meta-data android:name="applovin.sdk.key" android:value="< SDK_KEY >" />
```
#### Inmobi Publishers
```sh
<receiver
    android:name="com.inmobi.commons.core.utilities.uid.ImIdShareBroadCastReceiver"
    android:enabled="true"
    android:exported="true"
    tools:ignore="ExportedReceiver">
    <intent-filter>
	<action android:name="com.inmobi.share.id" />
    </intent-filter>
</receiver>
```
#### Videmob Publishers
```sh
<provider
    android:name="com.cydersoft.core.database.CydersoftContentProvider"
    android:authorities="< PACKAGE_NAME >"
    android:exported="false" />
```
### Gradle
Add the following lines to your module dependencies.
```gradle
compile fileTree(include: ['*.jar'], dir: 'libs')

compile(name: 'admost-1.2.7', ext: 'aar')
compile(name: 'artofclick-1.2.3', ext: 'aar')
compile(name: 'appnext-2.0.0', ext: 'aar')
compile(name: 'facebook-4.20', ext: 'aar')
compile(name: 'loopme-5.1.0', ext: 'aar')
compile(name: 'millenialmedia-6.3.1', ext: 'aar')
compile(name: 'unityads-2.1.0', ext: 'aar')
compile(name: 'youappi-1.0', ext: 'aar')

compile project(':lib-videmob')

compile 'com.android.volley:volley:1.0.0'
compile 'com.google.android.gms:play-services-ads:10.0.1'
compile('com.mopub:mopub-sdk:4.13.0@aar') { transitive = true }
compile('tv.teads.sdk:androidsdk:2.3.12:fullRelease@aar') { transitive = true }
compile 'com.inlocomedia.android:android-sdk:2.4.7'
compile 'net.pubnative:library:2.3.13',
        'net.pubnative:library.interstitial:2.3.13',
        'net.pubnative:library.feed.banner:2.3.13',
        'net.pubnative:library.video:2.3.13'
```
#### AdColony
```gradle
compile 'com.android.support:support-annotations:+'
```
#### AdFalcon, NativeX
```gradle
compile 'com.google.code.gson:gson:+'
```
#### Appnext Publishers
```gradle
compile 'com.google.android.gms:play-services-basement:+'
compile 'com.google.android.gms:play-services-location:+'
```
#### Avocarrot
```gradle
compile 'com.android.support:recyclerview-v7:+'
compile 'com.android.support:appcompat-v7:+'
```
#### DisplayIO
```gradle
compile 'com.android.support:appcompat-v7:+'
compile 'com.android.support:support-v4:+'
compile 'com.android.support:percent:+'
```
#### MediaBrix
```gradle
compile 'com.android.support:support-v4:+'
```
##### And Repositories as follows
```gradle
repositories {
    flatDir {
        dirs 'libs'
    }
    jcenter()
    maven { url "http://dl.bintray.com/teads/TeadsSDK-android" }
}
```
# Usage
Admost Mediation library is a lean yet complete library that allows you to request and show ads.
Basic integration steps are:

### Initialization
Initialize the Admost Mediation SDK in your application’s launcher Activity. This starts pre-caching and prepares the SDK to display ads.
```java
AdMostConfiguration.Builder configuration = new AdMostConfiguration.Builder(this, < ADMOST_APP_ID >);

// OPTIONAL
configuration.age(24);
configuration.gender(AdMost.GENDER_MALE);
configuration.interests(“Games, Sports, News”);

AdMost.getInstance().init(configuration.build());
```
For all ad type, AMR sdk has to be aware of the activities lifecycle. So please use the following methods of AMR in your activities which ads are called.
```java
@Override
public void onStart() {
    super.onStart();
    AdMost.getInstance().onStart(this);
}

@Override
public void onResume() {
    super.onResume();
    AdMost.getInstance().onResume(this);
}

@Override
public void onPause() {
    super.onPause();
    AdMost.getInstance().onPause(this);
}

@Override
public void onStop() {
    super.onStop();
    AdMost.getInstance().onStop(this);
}

@Override
public void onDestroy() {
    super.onDestroy();
    AdMost.getInstance().onDestroy(this);
}

@Override
public void onBackPressed() {
    super.onBackPressed();
    AdMost.getInstance().onBackPressed(this);
}

@Override
public void onActivityResult(int requestCode, int resultCode, Intent data) {
    //Only for Fyber Publishers
    if (requestCode == AdMost.FYBER_REQUEST_CODE)
        OFFERWALL.setFyberResult(resultCode, data);
}
```
### Banner Ads
```java
/*
ZONE_ID : Your ZONE_ID defined on admost mediation panels.
TYPE    : The height of your banner, it may have 3 values;
            1. AdMostManager.getInstance().AD_BANNER (50dp)
            2. AdMostManager.getInstance().AD_LEADERBOARD (90dp)
            3. AdMostManager.getInstance().AD_MEDIUM_RECTANGLE (250dp)
BINDER  : You can use your own layout design for banners, if you leave BINDER value null, default design will be applied.
*/

BANNER = new AdMostView(ACTIVITY, < ZONE_ID >, < TYPE >, new AdMostViewListener() {
    @Override
    public void onLoad(String network, int position) {
        if (network.equals(AdMostAdNetwork.NO_NETWORK)) {
            // No Ad Found
        } else {
            // Ad Loaded
            // You can get adview by calling BANNER.getView()
            // Attach it to a layout for impression.
            // Calling BANNER.getView() method multiple times will not cause any side effect.
        }
    }
}, < BINDER >);

// Add the following line to load an ad.
BANNER.getView();
```
You have to call destroy() method on onDestroy() method of the activity.
```java
BANNER.destroy();
```
### Customize Native Ad Appearance (Optional)
If you want to create your own design for native ads, you have to create a binder object and pass it to AdMostView constructor as BINDER value. Example implementation for binder creation is as follows;
```java
int layout = layout.design_for_your_banner;
AdMostViewBinder BINDER = new AdMostViewBinder.Builder(layout)
	.titleId(R.id.ad_headline)
	.textId(R.id.ad_body)
	.callToActionId(R.id.ad_call_to_action)
	.iconImageId(R.id.ad_app_icon)
	.mainImageId(R.id.ad_image)
	.backImageId(R.id.ad_back)
	.attributionId(R.id.ad_attribution)
	.isFixed(false)
	.isCloseable(false)
	.build();
```
### Interstitial Ads
```java
AdMostInterstitial INTERSTITIAL = new AdMostInterstitial(ACTIVITY, < ZONE_ID >, new AdMostAdListener() {
    @Override
    public void onAction(int value) {
        if (value == AdMostAdListener.LOADED){
            // if AUTO_SHOW value is TRUE then no need to call show method again.
            // Otherwise, you have to use show method like below
            // INTERSTITIAL.show();
        } else if (value == AdMostAdListener.FAILED) {
            // No Ad Found
        } else if (value == AdMostAdListener.CLOSED) {
            // Ad Closed
        }
    }
});

INTERSTITIAL.refreshAd(AUTO_SHOW);
```
AUTO_SHOW (boolean) : Set true, if you want to show the fullscreen ad as soon as it is ready. Otherwise, you need to call show() method manually.

You have to call destroy method on onDestroy() method of the activity.
```java
INTERSTITIAL.destroy();
```
### Rewarded Video Ads
```java
AdMostInterstitial VIDEO = new AdMostInterstitial(ACTIVITY, < ZONE_ID >, new AdMostAdListener() {
	@Override
	public void onAction(int value) {
        if (value == AdMostAdListener.LOADED) {
            // Ad Loaded
        } else if (value == AdMostAdListener.COMPLETED) {
            // Video Ad Completed
        } else if (value == AdMostAdListener.FAILED) {
            // No Ad Found
        } else if (value == AdMostAdListener.CLOSED) {
            // Ad Closed
        }
	}

	@Override
	public void onRewarded(int value) {
		// User is Rewarded
	}
});
```
### Offerwalls
```java
OFFERWALL = new AdMostInterstitial(ACTIVITY, < ZONE_ID >, new AdMostAdListener() {
    @Override
    public void onAction(int value) {
        if (value == AdMostAdListener.LOADED) {
            // Ad Loaded
        } else if (value == AdMostAdListener.FAILED) {
            // No Ad Found
        } else if (value == AdMostAdListener.CLOSED) {
            // Ad Closed
        }
    }
});
```

#### Spending Virtual Currencies
```java
OFFERWALL.spendVirtualCurrency(new AdMostVirtualCurrencyListener() {
    @Override
    public void onSuccess(String network, String currency, double balance) {
        // User rewarded (This method can be triggered multiple times depends on Offerwall Zone)
    }

    @Override
    public void onError(String network, String error) {
        // Error
    }
});
```

# Misc

### Proguard

If you are using Proguard, add [these lines](https://github.com/admost/AMR/tree/master/Android_Integration/sdk/proguard-rules.pro) to your Proguard file.
