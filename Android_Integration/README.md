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
###Inmobi Publishers
Add the following line into your AndroidManifest.xml (This needs to go inside the application tag)
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
#Install

###Gradle

Add the following lines to your module dependencies

```gradle
compile fileTree(include: ['*.jar'], dir: 'libs')

compile(name: 'admost-sdk', ext: 'aar')
compile(name: 'unity-ads', ext: 'aar')
compile(name: 'mm-ad-sdk', ext: 'aar')
compile(name: 'loopme-sdk-5.1.0', ext: 'aar')
compile(name: 'aoc-release', ext: 'aar')
compile(name: 'youappi-android-sdk', ext: 'aar')

// AMR
compile 'com.android.volley:volley:1.0.0'

// GOOGLE
compile 'com.google.android.gms:play-services-ads:10.0.1'

// NATIVEX
compile 'com.google.code.gson:gson:2.6.2'

// FACEBOOK
compile 'com.facebook.android:audience-network-sdk:4.18.0'

// MOPUB
compile('com.mopub:mopub-sdk:4.11.0@aar') { transitive = true }
compile('com.mopub.volley:mopub-volley:1.1.0')

// APPNEXT
compile('com.appnext.sdk:appnext-sdk:1.7.6')
compile 'com.appnext.sdk:native-ads-sdk:1.7.6'

// PUBNATIVE
compile 'net.pubnative:library:2.3.8'
compile 'net.pubnative:library.interstitial:2.3.8'
compile 'net.pubnative:library.feed.banner:2.3.8'
compile 'net.pubnative:library.video:2.3.8'

// INLOCOMEDIA
compile 'com.inlocomedia.android:android-sdk:2.4.0'

// TEADS
compile('tv.teads.sdk:androidsdk:2.3.12:fullRelease@aar') { transitive = true; }

// ADCOLONY
compile 'com.adcolony:sdk:3.0.7'

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
    maven { url "http://dl.bintray.com/teads/TeadsSDK-android" }
    maven { url "http://repo.appnext.com/" }
    maven { url "https://fyber.bintray.com/maven" }
    maven { url "https://adcolony.bintray.com/AdColony" }
}
```

###Libs

Copy the following libraries to the libs folder of your app.

```sh
admost-sdk.aar
mm-ad-sdk.aar
unity-ads.aar
aoc-publisher-sdk-release-1.2.1.aar
loopme-sdk-5.1.0.aar
youappi-android-sdk.aar

AdFalconAndroidSDK3.3.0.jar
applovin-sdk-6.4.0.jar
amazon-ads-5.8.1.1.jar
applovin-sdk-6.4.0.jar
avocarrot-sdk-v.3.7.5.jar
chartboost.jar
conversant-android-sdk-2.4.2.jar
flurryAds_6.7.0.jar
flurryAnalytics_6.7.0.jar
FlyMobSdk-1.9.1.jar
heyzap-unified-platform-10.2.2.jar
InMobi-6.0.4.jar
instal-publisher-sdk-1.0.24.jar
io.display.sdk-1.3.0.jar
mediabrix-sdk-FBless.jar
MobFox-Android-SDK-Core-3.1.6.jar
NativeXMonetizationSDK_v5.5.9.jar
nativex-gson-2.6.2.jar
revmob.jar
RFMSDK.jar
SOMAAndroidSDK5.1.0.jar
StartAppInApp-3.5.4.jar
supersonic-6.4.21.jar
tapjoy-11.9.1.jar
vungle-publisher-adaptive-id-4.0.3.jar

////// Vungle ////////
vungle-dagger-2.7.jar
vungle-javax.inject-1.jar
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

@Override
public void onBackPressed() {
	super.onBackPressed();
	AdMost.getInstance().onBackPressed(this);
}

@Override
public void onActivityResult(int requestCode, int resultCode, Intent data) {
	AdMost.getInstance().onActivityResult(requestCode, resultCode, data);
}
```

### Spending Virtual Currencies with AdMostInterstitial

```java
OFFERWALL = new AdMostInterstitial(ACTIVITY, <<ZONE_ID>>, new AdMostAdListener() {
	@Override
	public void onAction(int value) {
		if (value == AdMostAdListener.CLOSED) {
			OFFERWALL.spendVirtualCurrency(OFFERWALL.getCurrentNetwork(), new AdMostVirtualCurrencyListener() {
				@Override
				public void onSuccess(String network, String currency, double balance) {
				AdMostLog.log(network + " " + currency + " " + balance);
				}
			
				@Override
				public void onError(String network, String error) {
				AdMostLog.log(network + " " + error);
				}
			});
		}
	}
});
```

### Requesting Native Ads

```java

/*
	ZONE_ID : Your ZONE_ID defined on admost mediation panels.
	TYPE : The height of your banner, it may have 3 values;
		1. AdMostManager.getInstance().AD_BANNER (50dp)
		2. AdMostManager.getInstance().AD_LEADERBOARD (90dp)
		3. AdMostManager.getInstance().AD_MEDIUM_RECTANGLE (250dp)
	BINDER : You can use your own layout design for banners, if you leave BINDER value null, default design will be applied.
*/

ADMOST_MEDIATION_VIEW = new AdMostView(ACTIVITY, <<ZONE_ID>>, <<TYPE>>,  new AdMostViewListener() {
    @Override
    public void onLoad(String network, int position) {
        if (network.equals(AdMostAdNetwork.NO_NETWORK)) {
             // No Banner Found
        } else {
            // Ad Loaded
            // You can get adview by calling ADMOST_MEDIATION_VIEW.getView(0)
            // Attach it to a layout for impression.
            // Calling ADMOST_MEDIATION_VIEW.getView(0) method multiple times will not cause any side effect.
        }
    }
}, <<BINDER>>);

// Add the following line to load an ad.
ADMOST_MEDIATION_VIEW.getView(0);
```

You have to call destroy method on ondestroy() method of the activity.

```java
ADMOST_MEDIATION_VIEW.destroy();
```

If you want to create your own design for native ads, you have to create a binder object and pass it to AdMostView constructor as BINDER value. Example implementation for binder creation is as follows;

```java
int layout = layout.design_for_your_banner;
AdMostViewBinder binder = new AdMostViewBinder.Builder(layout)
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

### Requesting FullScreen Ads

```java
AdMostInterstitial AD_INTERSTITIAL = new AdMostInterstitial(ACTIVITY, <<ZONE_ID>>, new AdMostAdListener() {
	@Override
	public void onAction(int value) {
		if (value == AdMostAdListener.FAILED) {
			// Failed to load
		} else if (value == AdMostAdListener.LOADED){
			// if AUTO_SHOW value is true then no need to call show method again.
			// Otherwise, you have to use show method like below
			// AD_INTERSTITIAL.show();
		}
	}
});

AD_INTERSTITIAL.refreshAd(AUTO_SHOW);
```

AUTO_SHOW (boolean) : Set true, if you want to show the fullscreen ad as soon as it is ready. Otherwise, you need to call show() method manually.

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

# MILLENNIAL & NEXAGE
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

# HEYZAP
-keep public class com.heyzap.** { *; }
-dontwarn com.heyzap.**

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

# STARTAPP
-keepattributes Exceptions, InnerClasses, Signature, Deprecated, SourceFile, LineNumberTable, *Annotation*, EnclosingMethod
-dontwarn android.webkit.JavascriptInterface
-keep class com.startapp.** { *; }
-dontwarn com.startapp.**

# AVOCARROT
-keep class com.avocarrot.** { *; }
-dontwarn com.avocarrot.**

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
-keep class com.mediabrix.** { *; }
-keep class com.moat.** { *; }
-keep class mdos.** { *; }
-dontwarn com.mediabrix.**
-dontwarn com.moat.**
-dontwarn mdos.**

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

# APPNEXT
-keep class com.appnext.** { *; }
-dontwarn com.appnext.**

# DISPLAYIO
-keep class io.display.sdk.Controller.** { *; }
-dontwarn io.display.sdk.Controller.**

# INLOCOMEDIA
-keep class com.inlocomedia.** { *; }
-dontwarn com.inlocomedia.**

# TEADS
# For WebView JavascriptInterface
-keepattributes JavascriptInterface
-keep public class tv.teads.sdk.adContainer.layout.webview.** { *; }

# Jackson
-dontwarn org.w3c.dom.bootstrap.DOMImplementationRegistry
-keepnames class com.fasterxml.jackson.** { *; }
-keep public class tv.teads.sdk.adServer.parser.json.** {
    public protected *;
    public void set*(***);
    public *** get*();
}
-keepattributes *Annotation*,EnclosingMethod,Signature
-keep class com.fasterxml.jackson.databind.ObjectMapper {
    public <methods>;
    protected <methods>;
}
-keep class com.fasterxml.jackson.databind.ObjectWriter {
    public ** writeValueAsString(**);
}

# Okio
-dontwarn okio.**

# Enums
-keepattributes InnerClasses
-keep public enum  tv.teads.sdk.adContent.AdContent$** {
    **[] $VALUES;
    public *;
}
-keep public enum  tv.teads.sdk.publisher.TeadsLog$** {
    **[] $VALUES;
    public *;
}

# Google Play Services (used by reflection)
-keep public class com.google.android.gms.ads.identifier.AdvertisingIdClient {
    **[] $VALUES;
    public *;
}

-keep public class com.google.android.gms.ads.identifier.AdvertisingIdClient$* {
   *;
}

# RUBICON
-keep public class com.rfm.** { *; }
-dontwarn com.rfm.**

# FYBER
-keep public class com.fyber.** { *; }
-dontwarn com.fyber.**

-keep class com.fyber.mediation.MediationConfigProvider {
    public static *;
}
-keep class com.fyber.mediation.MediationAdapterStarter {
    public static *;
}
-keepclassmembers class com.fyber.ads.videos.mediation.** {
    void setValue(java.lang.String);
}

# CONVERSANT
-keep class com.greystripe.** { *; }

# ARTOFCLICK
-keep class com.artofclick.publisher_sdk.** { *; }
-dontwarn com.artofclick.publisher_sdk.**

# INSTAL
-keep class com.instal.** { *; }
-dontwarn com.instal.**

#YouAppi
-keep class com.youappi.ai.sdk.** { *; }
-dontwarn com.youappi.ai.sdk.**

#AppBrain
-keep public class com.appbrain.KeepClass
-keep public class * implements com.appbrain.KeepClass
-keepclassmembers class * implements com.appbrain.KeepClass {
    <methods>;
}
-keep class android.webkit.JavascriptInterface
-dontwarn android.webkit.JavascriptInterface

# This is only needed when you don't include the Google Play services:
-dontwarn com.google.android.gms.**

```
