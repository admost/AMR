#Release Notes v1.2.4

###New
* Avocarrot (**3.7.5**)
* ArtOfClick (**1.2.1**)

###Updated
* AdColony (**3.0.7**)
* Supersonic (**v.6.4.21**)
* UnityAds (**v.2.0.7**)
* AppNext (**v.1.7.6**)
* DisplayIO (**v.1.3.0**)
* StartAppInApp (**v.3.5.4**)
* Flurry (**v.6.7.0**)
* Pubnative (**v.2.3.8**)
* Teads (**v.2.3.12**)
* Inmobi (**v.6.0.4**)
* Flymob (**v.1.9.1**)
* Mobfox (**v.3.1.6**)
* Vungle (**v.4.0.3**)
* Heyzap (**v.10.2.2**)
* Smaato (**v.5.1.0**)

###Fix
* Various bug fixes

###Upgrading from 1.2.0 and Prior
* For inmobi publishers, add the following line into your AndroidManifest.xml (This needs to go inside the application tag)
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

###**Please refer to the following settings for gradle and libs usage of network sdk's.**

####Gradle

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

####Libs

Copy the following libraries to the libs folder of your app from [this link](https://github.com/admost/AMR/tree/master/Android_Integration/libs). 

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
