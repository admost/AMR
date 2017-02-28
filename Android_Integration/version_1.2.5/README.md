#Release Notes v1.2.5

###New
* Fyber Offerwall
* Ironsource Offerwall
* NativeX Offerwall

###Updated
* AppBrain
* Applovin
* ArtOfClick
* Avocarrot
* DisplayIO
* Fyber
* Heyzap
* Inmobi
* Mopub
* Smaato
* StartApp
* Supersonic(Ironsource)
* Unity Ads

###Fix
* Various bug fixes

###**Please refer to the following settings for gradle and libs usage of network sdk's.**

####Gradle

```gradle
repositories {
    flatDir {
        dirs 'libs'
    }
    maven { url "http://repo.appnext.com/" }
    maven { url "http://dl.bintray.com/teads/TeadsSDK-android" }
}
```

Add the following lines to your module dependencies

```gradle
dependencies {
	compile fileTree(include: ['*.jar'], dir: 'libs')

	compile(name: 'admost-sdk', ext: 'aar')
	compile(name: 'unity-ads', ext: 'aar')
	compile(name: 'mm-ad-sdk', ext: 'aar')
	compile(name: 'loopme-sdk-5.1.0', ext: 'aar')
	compile(name: 'aoc-release', ext: 'aar')

	compile 'com.android.volley:volley:1.0.0'// AMR
    compile 'com.android.support:support-annotations:25.2.0'// ADCOLONY
    compile 'com.android.support:recyclerview-v7:25.2.0'// AVOCARROT
    compile 'com.android.support:appcompat-v7:25.2.0'// AVOCARROT & DISPLAY
    compile 'com.android.support:support-v4:25.2.0' // DISPLAY

    compile 'com.google.android.gms:play-services-ads:10.0.1'

    compile('com.mopub:mopub-sdk:4.12.0@aar') { transitive = true }

    compile 'net.pubnative:library:2.3.9',
            'net.pubnative:library.interstitial:2.3.9',
            'net.pubnative:library.feed.banner:2.3.9',
            'net.pubnative:library.video:2.3.9'

    compile 'com.inlocomedia.android:android-sdk:2.4.7'

    compile 'com.appnext.sdk:appnext-sdk:1.7.6'
    compile 'com.appnext.sdk:native-ads-sdk:1.7.7'

    compile('tv.teads.sdk:androidsdk:2.3.12:fullRelease@aar') { transitive = true; }
}
```

####Libs

Copy the following libraries to the libs folder of your app from [this link](https://github.com/admost/AMR/tree/master/Android_Integration/libs). 