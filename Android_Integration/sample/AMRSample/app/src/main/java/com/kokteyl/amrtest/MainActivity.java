package com.kokteyl.amrtest;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import admost.sdk.AdMostInterstitial;
import admost.sdk.AdMostManager;
import admost.sdk.AdMostView;
import admost.sdk.AdMostViewBinder;
import admost.sdk.base.AdMost;
import admost.sdk.base.AdMostAdNetwork;
import admost.sdk.base.AdMostConfiguration;
import admost.sdk.base.AdMostLog;
import admost.sdk.listener.AdMostAdListener;
import admost.sdk.listener.AdMostViewListener;

public class MainActivity extends Activity {

    AdMostView ad;
    AdMostInterstitial interstitial;
    AdMostInterstitial video;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.showVideo).setVisibility(View.GONE);
        findViewById(R.id.showInterstitial).setVisibility(View.GONE);

        AdMostConfiguration.Builder configuration = new AdMostConfiguration.Builder(this, getString(R.string.AMR_APP_ID));
        AdMost.getInstance().init(configuration.build());

        getInterstitial();
        getVideo();
        getBanner();

        findViewById(R.id.showInterstitial).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (interstitial != null && interstitial.isLoaded()) {
                    findViewById(R.id.showInterstitial).setVisibility(View.GONE);
                    interstitial.show();
                }
            }
        });

        findViewById(R.id.refreshBanner).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getBanner();
            }
        });

        findViewById(R.id.showVideo).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (video != null && video.isLoaded()) {
                    findViewById(R.id.showVideo).setVisibility(View.GONE);
                    video.show();
                }
            }
        });

        findViewById(R.id.listPage).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, ListActivity.class);
                startActivity(intent);
            }
        });

    }

    private void getBanner() {

        // This is just for your own style, left null if you want default layout style

        final AdMostViewBinder binder = new AdMostViewBinder.Builder(R.layout.custom_layout)
                .titleId(R.id.cardTitle)
                .textId(R.id.cardDetailText)
                .callToActionId(R.id.CallToActionTextView)
                .iconImageId(R.id.cardIcon)
                .mainImageId(R.id.cardImage)
                .attributionId(R.id.cardAttribution)
                .build();

        ((LinearLayout) findViewById(R.id.adLayout)).removeAllViews();

        if (ad != null) {
            ad.destroy();
        }

        ((TextView) findViewById(R.id.loadedNetwork)).setText("");

        ad = new AdMostView(MainActivity.this, getString(R.string.AMR_BANNER), AdMostManager.getInstance().AD_MEDIUM_RECTANGLE, new AdMostViewListener() {
            @Override
            public void onLoad(String network, int position) {
                if (!network.equals(AdMostAdNetwork.NO_NETWORK)) {
                    LinearLayout viewAd = (LinearLayout) findViewById(R.id.adLayout);
                    viewAd.removeAllViews();
                    if (ad.getView().getParent() != null && ad.getView().getParent() instanceof ViewGroup) {
                        ((ViewGroup) ad.getView().getParent()).removeAllViews();
                    }
                    viewAd.addView(ad.getView());
                } else {
                    // NO FILL
                }
                ((TextView) findViewById(R.id.loadedNetwork)).setText(network);
            }
        }, binder);

        ad.getView();
    }

    private void getVideo() {

        if (video == null) {

            AdMostAdListener listener = new AdMostAdListener() {
                @Override
                public void onAction(int value) {
                    if (value == AdMostAdListener.LOADED) {
                        AdMostLog.log(value + " MainActivity LOADED");
                        findViewById(R.id.showVideo).setVisibility(View.VISIBLE);
                    } else if (value == AdMostAdListener.COMPLETED) {
                        AdMostLog.log(value + " MainActivity COMPLETED");
                    } else if (value == AdMostAdListener.FAILED) {
                        AdMostLog.log(value + " MainActivity FAILED");
                    } else if (value == AdMostAdListener.CLOSED) {
                        AdMostLog.log(value + " MainActivity CLOSED");
                        getVideo();
                    }
                }

                @Override
                public void onShown(String s) {
                    super.onShown(s);
                    AdMostLog.log(s + " MainActivity OnShown");
                }
            };

            video = new AdMostInterstitial(MainActivity.this, getString(R.string.AMR_VIDEO), listener);
        }

        video.refreshAd(false);
    }

    private void getInterstitial() {

        if (interstitial == null) {

            AdMostAdListener listener = new AdMostAdListener() {
                @Override
                public void onAction(int value) {
                    if (value == AdMostAdListener.LOADED) {
                        findViewById(R.id.showInterstitial).setVisibility(View.VISIBLE);
                        AdMostLog.log(value + " MainActivity LOADED");
                    } else if (value == AdMostAdListener.FAILED) {
                        AdMostLog.log(value + " MainActivity FAILED");
                    } else if (value == AdMostAdListener.CLOSED) {
                        AdMostLog.log(value + " MainActivity CLOSED");
                        findViewById(R.id.showInterstitial).setVisibility(View.GONE);
                        getInterstitial();

                    }
                }

                @Override
                public void onShown(String s) {
                    super.onShown(s);
                    AdMostLog.log(s + " MainActivity OnShown");
                }
            };

            interstitial = new AdMostInterstitial(MainActivity.this, getString(R.string.AMR_FULLSCREEN), listener);
        }

        interstitial.refreshAd(false);
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        AdMost.getInstance().onBackPressed(this);
    }

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
        AdMost.getInstance().stop();
        if (interstitial != null) {
            interstitial.destroy();
        }
        if (video != null) {
            video.destroy();
        }
    }

}
