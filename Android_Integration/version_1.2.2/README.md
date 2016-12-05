#Release Notes v1.2.2

###New
* TeadsAds
* Rubicon
* HeyZap
* Fyber
* Conversant
* StartApp

###Updated
* DisplayIO (**v1.0.1**)
* InLocoMedia (**v2.4.0**)
* Facebook Audience Network (**4.18b**)
* Pubnative (**v2.3.6**)
* Mopub (**v4.11.0**)
* Inmobi (**v6.0.3**)
* Amazon (**v5.8.1.1**)
* Flymob (**v1.7.0**)
* Appnext (**v1.7.2**)
* Mobfox (**v3.0.0b**)

###Added
* Mopub Rewarded
* Tapjoy Offerwall

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
* Include Appnext SDK using gradle instead of adding jar file as library.
```sh
compile('com.appnext.sdk:appnext-sdk:1.7.2')
compile 'com.appnext.sdk:native-ads-sdk:1.7.2'
```
* Include Adcolony SDK using gradle instead of adding jar file as library.
```sh
compile 'com.adcolony:sdk:3.0.5'
compile 'com.android.support:support-annotations:24.2.1'
```
