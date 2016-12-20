#Release Notes v1.2.3

###Updated
* AdColony (**3.0.6**)
* Facebook Audience Network (**v.4.18**)
* Supersonic (**v.6.4.20**)
* Applovin (**v.6.4.0**)
* LoopMe (**v.5.1.0**)
* UnityAds (**v.2.0.6**)
* TapJoy (**v.11.9.1**)
* AppNext (**v.1.7.5**)
* DisplayIO (**v.1.2.1**)
* StartAppInApp (**v.3.5.2**)

###Fix
* Various bug fixes

###Upgrading from 1.2.0 and Prior
* Please refer to AMR Android Integration document for getting latest Gradle and Libs from Install section
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
compile('com.appnext.sdk:appnext-sdk:1.7.5')
compile 'com.appnext.sdk:native-ads-sdk:1.7.5'
```
* Include Adcolony SDK using gradle instead of adding jar file as library.
```sh
compile 'com.adcolony:sdk:3.0.6'
compile 'com.android.support:support-annotations:24.2.1'
```
