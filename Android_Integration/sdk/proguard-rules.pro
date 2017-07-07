# ADMOST
-keepattributes Exceptions, InnerClasses
-dontwarn admost.sdk.**
-keep class admost.sdk.** {*;}

# VOLLEY
-keep class com.android.volley.** { *; }
-keep interface com.android.volley.** { *; }
-keep class org.apache.commons.logging.**

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# ADCOLONY
-dontwarn com.jirbo.adcolony.**
-keep class com.jirbo.adcolony.** { *; }

# ADMOB / ADX / GOOGLE
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

# ADTRIAL
-keep class com.adtrial.** { *; }
-dontwarn com.adtrial.**

# AMAZON
-dontwarn com.amazon.**
-keep class com.amazon.** { *; }
-dontwarn org.apache.http.**
-keepattributes *Annotation*

# APPLOVIN
-dontwarn com.applovin.**
-keep class com.applovin.** { *; }

# APPNEXT
-keep class com.appnext.** { *; }
-dontwarn com.appnext.**

# AVOCARROT
-keep class com.avocarrot.** { *; }
-dontwarn com.avocarrot.**
-keep class com.google.android.exoplayer2.SimpleExoPlayer
-dontwarn com.google.android.exoplayer2.SimpleExoPlayer

# CACTUSROAD
-keep class com.thecactusroad.sdk.** { *; }
-dontwarn com.thecactusroad.sdk.**

# CHARTBOOST
-dontwarn org.apache.http.**
-dontwarn com.chartboost.sdk.impl.**
-keep class com.chartboost.sdk.** { *; }
-keepattributes *Annotation*

# DISPLAYIO
-keep class io.display.sdk.** { *; }
-dontwarn io.display.sdk.**

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

# FLYMOB
-dontwarn com.flymob.sdk.**
-keep public class com.flymob.sdk.common.** { public *; }

# FYBER
-keep public class com.fyber.** { *; }
-dontwarn com.fyber.**
-keep class com.fyber.mediation.MediationConfigProvider { public static *; }
-keep class com.fyber.mediation.MediationAdapterStarter { public static *; }
-keepclassmembers class com.fyber.ads.videos.mediation.** { void setValue(java.lang.String); }

# INLOCOMEDIA
-dontwarn in.ubee.**, com.inlocomedia.**
-keep class in.ubee.**, com.inlocomedia.** { *; }
-keepclassmembers class in.ubee.**, com.inlocomedia.** { *; }
-keep class com.google.android.gms.common.GooglePlayServicesUtil {*;}
-keep class com.google.android.gms.ads.identifier.AdvertisingIdClient {*;}
-keep class com.google.android.gms.ads.identifier.AdvertisingIdClient$Info {*;}
-keep class com.google.android.gms.location.Geofence { *; }
-keep class com.google.android.gms.location.ActivityRecognition { *; }

# INMOBI
-keepattributes SourceFile,LineNumberTable
-keep class com.inmobi.** {*;}
-dontwarn com.inmobi.**
-keep public class com.google.android.gms.**
-dontwarn com.google.android.gms.**
-dontwarn com.squareup.picasso.**
-keep class com.google.android.gms.ads.identifier.AdvertisingIdClient{public *;}
-keep class com.google.android.gms.ads.identifier.AdvertisingIdClient$Info{public *;}
-keep class com.squareup.picasso.** {*;}
-dontwarn com.squareup.picasso.**
-dontwarn com.squareup.okhttp.**
-keep class com.moat.** {*;}
-dontwarn com.moat.**
-keep class com.integralads.avid.library.* {*;}

# INNERACTIVE
-dontwarn com.inneractive.api.ads.**
-keep class com.inneractive.api.ads.** {*;}
-keepclassmembers class com.inneractive.api.ads.** {*;}
-keepclassmembers class com.inneractive.api.ads.sdk.nativead.** {*;}
-keepattributes Signature
-keepattributes *Annotation*
-keep class sun.misc.Unsafe { *; }
-keep class com.google.gson.stream.** { *; }
-keep class com.google.gson.examples.android.model.** { *; }
-keep class com.google.gson.Gson { *; }
-keep class com.google.gson.GsonBuilder { *; }
-keep class com.google.gson.FieldNamingStrategy { *; }

# IRONSOURCE
-dontwarn com.ironsource.**
-keep class com.ironsource.** { *; }

# LEADBOLT
-dontwarn android.support.v4.**
-keep public class com.google.android.gms.* { public *; }
-dontwarn com.google.android.gms.**
-keep class com.apptracker.** { *; }
-dontwarn com.apptracker.**
-keepclassmembers class **.R$* { public static <fields>; }
-keep class **.R$*

# LOOPME
-dontwarn com.loopme.**
-keep class com.loopme.** { *; }

# MEDIABRIX
-keep class com.mediabrix.** { *; }
-keep class com.moat.** { *; }
-keep class mdos.** { *; }
-dontwarn com.mediabrix.**
-dontwarn com.moat.**
-dontwarn mdos.**

# MILLENNIAL & NEXAGE
-keep class com.millennialmedia.** { *; }
-dontwarn com.millennialmedia.**

# MOBFOX
-dontwarn com.mobfox.**
-keep class com.mobfox.** { *; }

# MOBUSI
-keep class com.mobusi.adsmobusi.** { *; }
-dontwarn com.mobusi.adsmobusi.**

# MOPUB
-keepclassmembers class com.mopub.** { public *; }
-dontnote com.mopub.**
-dontwarn com.mopub.**
-keep public class com.mopub.**
-keep public class android.webkit.JavascriptInterface {}
-keep class * extends com.mopub.mobileads.CustomEventBanner {}
-keep class * extends com.mopub.mobileads.CustomEventInterstitial {}
-keep class * extends com.mopub.nativeads.CustomEventNative {}
-keep class com.mopub.mobileads.** {*;}

# NATIVEX
-dontwarn com.nativex.**
-keep class com.nativex.** { *; }

# OUTBID
-dontwarn outbid.com.outbidsdk.**
-keep class outbid.com.outbidsdk.** { *; }

# PUBNATIVE
-keepattributes Signature
-keep class net.pubnative.** { *; }
-dontwarn net.pubnative.**
-keep class com.squareup.picasso.** { *; }
-dontwarn com.squareup.picasso.**

# REVMOB
-dontwarn rm.com.android.sdk.**
-keep class rm.com.android.sdk.** { public *; }

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

# STARTAPP
-keepattributes Exceptions, InnerClasses, Signature, Deprecated, SourceFile, LineNumberTable, *Annotation*, EnclosingMethod
-dontwarn android.webkit.JavascriptInterface
-keep class com.startapp.** { *; }
-dontwarn com.startapp.**

# TAPJOY
-keep class com.tapjoy.** {*;}
-keep class com.moat.** {*;}
-keepattributes JavascriptInterface
-keepattributes *Annotation*
-keep class * extends java.util.ListResourceBundle {protected Object[][] getContents();}
-keep public class com.google.android.gms.common.internal.safeparcel.SafeParcelable {public static final *** NULL;}
-keepnames @com.google.android.gms.common.annotation.KeepName class *
-keepclassmembernames class * {@com.google.android.gms.common.annotation.KeepName *;}
-keepnames class * implements android.os.Parcelable {public static final ** CREATOR;}
-keep class com.google.android.gms.ads.identifier.** {*;}
-dontwarn com.tapjoy.**

# TAPPX
-keepattributes *Annotation*
-keepclassmembers class com.google.**.R$* { public static <fields>; }
-keep public class com.google.ads.** {*;}
-keep public class com.google.android.gms.** {*;}
-keep public class com.tappx.** { *; }
-dontwarn com.tappx.**

# UNITY
-dontwarn com.unity3d.**
-keep class com.unity3d.ads.** { *; }

# VUNGLE
-dontwarn com.vungle.**
-keep class com.vungle.** { *; }
-keep class javax.inject.**
-keepattributes *Annotation*
-keepattributes Signature
-keep class dagger.**
-keep class de.greenbot.**
-keep class rx.**

# YOUAPPI
-keep class com.youappi.ai.sdk.** { *; }
-dontwarn com.youappi.ai.sdk.**