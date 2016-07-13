## Change Log (v1.1.1)  

<b>New</b>  
UnityAds Interstitial and Rewarded Video added  
FlyMob native and interstitial added  
Facebook rewarded added  

<b>Fixes</b>  
Inmobi banner bug fix  
Universal Image Loader replaced with Volley Image Loader  
Admost interstitial close button enlarged  
Native ads performance fixes  

<b>Sdk Upgrades</b>   
Amazon sdk upgraded to 5.7.2  
Mobfox core lib sdk upgraded to 2.0.9  

## Upgrade From 1.0.7  

<b>Gradle</b>  
compile project(':admost-sdk1.1.1')  
compile project(':unity-ads1.5.8')  
compile 'com.android.volley:volley:1.0.0'  
compile 'com.amazon.android:mobile-ads:5.7.2'  
compile 'com.flymob:FlyMobSdk:1.3.4'  
compile 'com.github.mobfox:MobFox-Android-SDK-Core:2.0.9'  

<b>Manifest</b>  
Only needed if FLYMOB or UNITYADS sdks added.  
```
<!-- FLYMOB -->
   <activity
     android:name="com.flymob.sdk.common.ads.interstitial.activity.FlyMobActivity"
     android:configChanges="keyboardHidden|orientation|screenSize" />
   <!--MRAID video-->
   <activity
     android:name="com.flymob.sdk.common.ads.interstitial.activity.FlyMobVideoActivity"
     android:configChanges="keyboardHidden|orientation|screenSize" />
   <!--MRAID video end-->
   <service
     android:name="com.flymob.sdk.common.server.FlyMobService"
     android:exported="false" />

<!-- UNITYADS -->
<activity
     android:name="com.unity3d.ads.android.view.UnityAdsFullscreenActivity"
     android:configChanges="fontScale|keyboard|keyboardHidden|locale|mnc|mcc|navigation|orientation|screenLayout|screenSize|smallestScreenSize|uiMode|touchscreen"
     android:theme="@android:style/Theme.NoTitleBar.Fullscreen"
     android:hardwareAccelerated="true"
     tools:ignore="UnusedAttribute"/>    
```

<b>Initialization</b>  
The following configuration line have to be added to the AMR initialization. Only needed if unityads added to the project.    

```
configuration.initIds(AdMostAdNetwork.UNITY, UNITY_ID);
AdMost.getInstance().init(configuration.build());
```

<b>Proguard</>  
```
# FLYMOB
-keep public class com.flymob.sdk.common.** { public *; }
# UNITY
-keep class com.unity3d.ads.android.** { *; }
# VOLLEY
-keep class com.android.volley.** { *; }
-keep interface com.android.volley.** { *; }
-keep class org.apache.commons.logging.**
```
