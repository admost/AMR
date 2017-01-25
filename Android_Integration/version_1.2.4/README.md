#Release Notes v1.2.3

###New
* Avocarrot (**3.7.5**)
* ArtOfClick (**1.2.1**)

###Updated
* AdColony (**3.0.6**)
* Facebook Audience Network (**v.4.18**)
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
