#AMR Android Integration

* [Requirements](#requirements)  
* [Install](#install)
 * [Gradle](#gradle)
 * [Libs](#libs)
* [Usage](#usage)
 * [Initialization](#initialization)
 * [Requesting Native Ads](#requesting-native-ads)
 * [Requesting FullScreen Ads](#requesting-fullscreen-ads)
 * [Requesting Video Ads](#requesting-video-ads)
* [Misc](#misc)
 * [Proguard](#proguard)


#Requirements

* Android 2.3 (Gingerbread - API Version 9) or later.
* Zone Ids provided in Admost Mediation Dashboard.

Add the following permissions optionally for improve user targeting into your AndroidManifest.xml 

```sh
<uses-permission android:name="android.permission.READ_PHONE_STATE"/>
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION"/>
<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION"/>
```

###AppLovin Publishers
Add the following line into your AndroidManifest.xml (This needs to go inside the application tag)
```sh
<meta-data android:name="applovin.sdk.key" android:value="<SDK_KEY>" />
```

#Install

###Gradle

Add the following lines to your module dependencies

```gradle
compile fileTree(include: ['*.jar'], dir: 'libs')

compile(name: 'admost-sdk', ext: 'aar')
compile(name: 'unity-ads', ext: 'aar')
compile(name: 'mm-ad-sdk', ext: 'aar')

// AMR
compile 'com.android.volley:volley:1.0.0'

// GOOGLE
compile 'com.google.android.gms:play-services-ads:9.2.1'

// NATIVEX
compile 'com.google.code.gson:gson:2.6.2'

// AMAZON
compile 'com.amazon.android:mobile-ads:5.7.2'

// FACEBOOK
compile 'com.facebook.android:audience-network-sdk:4.11.0'

// FLURRY
compile 'com.flurry.android:ads:6.2.0'
compile 'com.flurry.android:analytics:6.2.0'

// INMOBI
compile 'com.inmobi.monetization:inmobi-ads:5.3.1'

// MOPUB
compile('com.mopub:mopub-sdk:4.8.0@aar') { transitive = true }
compile('com.mopub.volley:mopub-volley:1.1.0')

// SUPERSONIC
compile 'com.supersonic.sdk:mediationsdk:6.4.17@jar'

// PUBNATIVE
compile 'net.pubnative:library:2.2.1'
compile 'net.pubnative:library.interstitial:2.2.1'
compile 'net.pubnative:library.feed.banner:2.2.1'
compile 'net.pubnative:library.video:2.2.1'

// INLOCOMEDIA
compile 'com.inlocomedia.android:android-sdk:2.3.3'
```

And Repositories as follows;

```gradle
repositories {
    flatDir {
        dirs 'libs'
    }
    mavenCentral()
    maven { url "https://jitpack.io" }
    maven { url "https://dl.bintray.com/supersonic/android-sdk" }
}
```

###Libs

Copy the following libraries to the libs folder of your app.

```sh
admost-sdk.aar
mm-ad-sdk.aar
unity-ads.aar

adcolony.jar
AdFalconAndroidSDK3.2.0.jar
applovin-sdk-6.3.0.jar
AppnextAndroidSDK.jar
chartboost.jar
FlyMobSdk-1.5.5.jar
loopme-sdk-4.8.0.jar
HyperAdxSDK_1.2.7.jar
mediabrix-sdk-FBless.jar
MobFox-Android-SDK-Core-2.2.0.jar
NativeXMonetizationSDK_v5.5.7.1.jar
revmob.jar
SOMAAndroidSDK5.0.8.jar
tapjoy-11.8.1.jar
vungle-publisher-adaptive-id-4.0.2.jar

////// Vungle ////////
Dagger-1.2.2.jar
Javax.inject-1.jar
nineoldandroids-2.4.0.jar
```

Only admost-sdk.aar and volley library are compulsory for mediation system. If you don’t add any one of the network to your app, the SDK will detect that the ad network library isn't there and fail gracefully; the request will continue with the next network in the mediation waterfall.

#Usage

Admost Mediation library is a lean yet complete library that allows you to request and show ads.

Basic integration steps are:

### Initialization

Initialize the Admost Mediation SDK in your application’s first Activity. This starts pre-caching and prepares the SDK to display ads.

```java
AdMostConfiguration.Builder configuration = new AdMostConfiguration.Builder(this, <<ADMOST_APP_ID>>);

//Optional
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
```

### Requesting Native Ads

You will need to create a AdmostView. Add all the required parameters to it and start it with a listener for extra tracking.

```java
int TYPE = AdMostManager.getInstance().AD_BANNER; 
// AD_LEADERBOARD for 90dp height, AD_MEDIUM_RECTANGLE for big banners (height : 250dp)
// You can use the following layouts by default, or define other layouts for your own designs
int layout = admost.sdk.R.layout.admost_native;
if (TYPE == AdMostManager.getInstance().AD_BANNER)
layout = admost.sdk.R.layout.admost_native_50;
AdMostLog.setLogEnabled(true);
AdMostViewBinder binder = new AdMostViewBinder.Builder(layout)
        .titleId(admost.sdk.R.id.ad_headline)
        .textId(admost.sdk.R.id.ad_body)
        .callToActionId(admost.sdk.R.id.ad_call_to_action)
        .iconImageId(admost.sdk.R.id.ad_app_icon)
        .mainImageId(admost.sdk.R.id.ad_image)
        .backImageId(admost.sdk.R.id.ad_back)
        .attributionId(admost.sdk.R.id.ad_attribution)
        .isFixed(false)
        .isCloseable(false)//(type & AD_CLOSEABLE) != 0
        .build();

// ZONE_ID : Your ZONE_ID defined on admost mediation panels.

ADMOST_MEDIATION_VIEW = new AdMostView(ACTIVITY, <<ZONE_ID>>, TYPE,  new AdMostViewListener() {
    @Override
    public void onLoad(String network, int position) {
        if (network.equals(AdMostAdNetwork.NO_NETWORK)) {
             // No Banner Found
        } else {
            // Ad Loaded, You can get ad view by calling ADMOST_MEDIATION_VIEW.getView(postion)
            // Calling ADMOST_MEDIATION_VIEW.getView method multiple times will not cause any side effect.
        }
    }
}, binder);

// Add the following line to get an ad from the admost mediation system.
int POSITION = 0;
ADMOST_MEDIATION_VIEW.getView(POSITION);
```

You have to call destroy method on ondestroy() method of the activity.

```java
ADMOST_MEDIATION_VIEW.destroy();
```

### Requesting FullScreen Ads

```java
AdMostInterstitial AD_INTERSTITIAL = new AdMostInterstitial(ACTIVITY, <<ZONE_ID>>, new AdMostAdListener() {
	@Override
	public void onAction(int value) {
		if (value == AdMostAdListener.FAILED) {
			// Failed
		} else {
			// if it is auto loaded then no need to call show. Show will automatically triggered.
			AD_INTERSTITIAL.show();
		}
	}
});

AD_INTERSTITIAL.refreshAd(AUTO_LOAD);
```

AUTO_LOAD (boolean) : Set true, if you want to show the fullscreen ad as soon as it is ready. Otherwise, you need to call show() method manually.

You have to call destroy method on ondestroy() method of the activity.

```java
AD_INTERSTITIAL.destroy();
```

### Requesting Video Ads

```java
AdMostInterstitial AD_VIDEO = new AdMostInterstitial(ACTIVITY, <<ZONE_ID>>, new AdMostAdListener() {
	@Override
	public void onAction(int value) {
		if (value == AdMostAdListener.LOADED) {
                    AdMostLog.log("LOADED");
                } else if (value == AdMostAdListener.COMPLETED) {
                    AdMostLog.log("COMPLETED");
                } else if (value == AdMostAdListener.FAILED) {
                    AdMostLog.log("FAILED");
                } else if (value == AdMostAdListener.CLOSED) {
                    AdMostLog.log("CLOSED");
                }
	}
	
	//OPTIONAL
	@Override
            public void onRewarded(int value) {
                AdMostLog.log("REWARDED " + value);
            }
});

AD_VIDEO.refreshAd(AUTO_LOAD);
```

AUTO_LOAD (boolean) : Set true, if you want to show the fullscreen ad as soon as it is ready. Otherwise, you need to call show() method manually.

#Misc

###Proguard

If you are using Proguard, add these lines to your Proguard file

```proguard
# ADMOST
-keepattributes Exceptions, InnerClasses
-dontwarn admost.sdk.**
-keep class admost.sdk.** { *; }

# VOLLEY
-keep class com.android.volley.** { *; }
-keep interface com.android.volley.** { *; }
-keep class org.apache.commons.logging.**

# GOOGLE
-keep class com.android.vending.billing.**
-keep public class com.google.android.gms.ads.** { public *; }
-keep public class com.google.ads.** { public *; }
-keep class com.google.android.gms.** { *; }
-dontwarn com.google.android.gms.**
-keep public class com.google.android.gms.common.internal.safeparcel.SafeParcelable { public static final *** NULL; }
-keepnames class * implements android.os.Parcelable
-keepclassmembers class * implements android.os.Parcelable { public static final *** CREATOR; }
-keep @interface android.support.annotation.Keep
-keep @android.support.annotation.Keep class *
-keepclasseswithmembers class * { @android.support.annotation.Keep <fields>; }
-keepclasseswithmembers class * { @android.support.annotation.Keep <methods>; }
-keep @interface com.google.android.gms.common.annotation.KeepName
-keepnames @com.google.android.gms.common.annotation.KeepName class *
-keepclassmembernames class * { @com.google.android.gms.common.annotation.KeepName *; }
-keep @interface com.google.android.gms.common.util.DynamiteApi
-keep public @com.google.android.gms.common.util.DynamiteApi class * { public <fields>; public <methods>; }
-keep public @com.google.android.gms.common.util.DynamiteApi class * { *; }
-keep class com.google.android.apps.common.proguard.UsedBy*
-keep @com.google.android.apps.common.proguard.UsedBy* class *
-keepclassmembers class * { @com.google.android.apps.common.proguard.UsedBy* *; }
-dontwarn android.security.NetworkSecurityPolicy
-dontwarn android.app.Notification

# MILLENNIAL
-keep class com.millennialmedia.** { *; }
-dontwarn com.millennialmedia.**

# MOBFOX
-dontwarn com.mobfox.**
-keep class com.mobfox.** { *; }

# MOPUB
-keepclassmembers class com.mopub.** { public *; }
-dontnote com.mopub.**
-dontwarn com.mopub.**
-keep public class com.mopub.**
-keep public class android.webkit.JavascriptInterface {}
-keep class * extends com.mopub.mobileads.CustomEventBanner {}
-keep class * extends com.mopub.mobileads.CustomEventInterstitial {}
-keep class * extends com.mopub.nativeads.CustomEventNative {}

# REVMOB
-dontwarn com.revmob.**
-keep class com.revmob.** { public *; }

# INMOBI
-keep class com.inmobi.** {*;}
-dontwarn com.inmobi.**

# CHARTBOOST
-dontwarn org.apache.http.**
-dontwarn com.chartboost.sdk.impl.**
-keep class com.chartboost.sdk.** { *; }
-keepattributes *Annotation*

# SMAATO
-dontwarn com.smaato.**
-keep class com.smaato.** { public *; }
-assumenosideeffects class android.util.Log {
    public static *** d(...);
    public static *** v(...);
    public static *** i(...);
}
-keep public class com.smaato.soma.internal.connector.OrmmaBridge { public *; }
-keepattributes *Annotation*

# ADCOLONY
-dontwarn com.jirbo.adcolony.**
-keep class com.jirbo.adcolony.** { *; }

# VUNGLE
-dontwarn com.vungle.**
-keep class com.vungle.** { public *; }
-keep class javax.inject.*
-keepattributes *Annotation*
-keepattributes Signature
-keep class dagger.*

# AMAZON
-dontwarn com.amazon.**
-keep class com.amazon.** { *; }
-dontwarn org.apache.http.**
-keepattributes *Annotation*

# FACEBOOK
-dontwarn com.facebook.ads.**
-dontnote com.facebook.ads.**
-keep class com.facebook.** { *; }
-keepattributes Signature

# FLURRY
-keep class com.flurry.** { *; }
-dontwarn com.flurry.**
-keepattributes *Annotation*,EnclosingMethod,Signature
-keepclasseswithmembers class * { public <init>(android.content.Context, android.util.AttributeSet, int); }

# SUPERSONICADS
-dontwarn com.supersonicads.**
-keep class com.supersonicads.** { *; }
-dontwarn com.supersonic.**
-keep class com.supersonic.** { *; }

# APPLOVIN
-dontwarn com.applovin.**
-keep class com.applovin.** { *; }

# LOOPME
-dontwarn com.loopme.**
-keep class com.loopme.** { *; }

# ADFALCON
-dontwarn com.noqoush.**
-keep class com.noqoush.** { *; }

# MEDIABRIX
-dontwarn com.mediabrix.**
-keep class com.mediabrix.** { *; }
-dontwarn com.moat.analytics.**
-keep class com.moat.analytics.** { *; }

# NATIVEX
-dontwarn com.nativex.**
-keep class com.nativex.** { *; }

# UNITY
-dontwarn com.unity3d.**
-keep class com.unity3d.ads.android.** { *; }

# FLYMOB
-dontwarn com.flymob.sdk.**
-keep public class com.flymob.sdk.common.** { public *; }

# TAPJOY
-keep class com.tapjoy.** { *; }
-keepattributes JavascriptInterface
-keep class * extends java.util.ListResourceBundle { protected Object[][] getContents(); }
-keep public class com.google.android.gms.common.internal.safeparcel.SafeParcelable { public static final *** NULL; }
-keepnames @com.google.android.gms.common.annotation.KeepName class *
-keepclassmembernames class * { @com.google.android.gms.common.annotation.KeepName *; }
-keepnames class * implements android.os.Parcelable { public static final ** CREATOR; }
-keep class com.google.android.gms.ads.identifier.** { *; }
-dontwarn com.tapjoy.internal.**

# PUBNATIVE
-keepattributes Signature
-keep class net.pubnative.** { *; }
-dontwarn net.pubnative.**
-keep class com.squareup.picasso.** { *; }
-dontwarn com.squareup.picasso.**

# HYPERADS
-dontwarn com.hyperadx.**
-keep class com.hyperadx.** { public *; }

# APPNEXT
-keep class com.appnext.** { *; }
-dontwarn com.appnext.**

# DISPLAYIO
-keep class io.display.sdk.Controller.** { *; }
-dontwarn io.display.sdk.Controller.**

# INLOCOMEDIA
-keep class com.inlocomedia.** { *; }
-dontwarn com.inlocomedia.**

```
