##What is AMR?
 
AMR (Admost Mediation Router) is a mobile mediation system which is used to optimize the ads revenues of mobile apps. 
 
##Which problem does AMR solve?
 
The main revenue channel of most of the apps is ads revenue which comes from ad networks like Admob (Google), Mopub (Twitter), Audience Network (Facebook), Flurry (Yahoo), Amazon, inMobi, Adcolony, Vungle, Chartboost and much more.
 
It is almost impossible to say one of them is the best for all countries all the time. Each network has some advantages. Some of them has very high fill rates, some of them has very high eCPM rates, some of them are better for normal banners or native banners or video banners or rewarded videos or interstitials. Some of them are much better for some periods.  
 
AMR helps apps to show ads from different ad networks to reach the most revenue. 
 
##How does AMR solve this problem?
 
AMR is a client-server tool. Its client part is an SDK embedded into apps. Its server part is a database which keeps all statistics collected from ad networks and its own SDK and calculates ecpm rates. Calculating eCPM rates correctly is the most important feature of the AMR.
 
AMR SDK counts all impression numbers in each app for each ad placement and for each country and sends all these data to AMR database. AMR also imports all the revenue from each ad network for each ad placement and for each country by APIs automatically. eCPM values are calculated in the AMR database. AMR SDK pulls eCPM rates of each ad network for all the ad placements in the app for the country where the user opens the app.
 
Apps call only AMR SDK to get a list of ad networks in order to show in the app. So apps know which ad network is better to call first or second or third for a specific user. 
 
AMR SDK’s job is just to tell the app the order of calling ad networks to get best results. It works like a router which optimises the traffic.
 
##Where the revenue goes?
 
AMR system works just as a router to call ad networks. App owners get all their revenues from ad networks as usual.
 
#What does AMR dashboard show?
 
Normally all app owners who are working with many ad networks have to log in each ad network
to see all the statistics and revenue. AMR already collects all this data and shows it in its own dashboard. 
 
By seeing all the data together, it is really useful and easy to compare ad networks performances in various aspects. There is no other way to see statistics of all ad networks together in one dashboard without AMR.
 
##What is the differences of AMR from other mediations systems?
 
Most of the mediations systems are part of an ad network, so they try to show their ads first. If they can not show themselves, then they call other ad networks based on a waterfall.
 
Admost is not an ad network, it is solely a technology company, so it doesn’t have any banner to show before other ad networks. It tries to help app owners to maximise ad revenue from ad networks. It is not competitor of ad networks. It is a platform between apps and ad networks.
 
The waterfall in most of ad networks should be created by app owners manually as entering floor ecpm rates for each ad network for ad placement and for each country. It is almost impossible to keep this waterfall fresh. Because ecpm rates of each ad network may change everyday.
 
AMR calculates all ecpm rates automatically, app owners does not need to enter any floor price.
 
Mechanics of waterfall in ad networks can not optimise the revenue by nature. Because if the main ad network can not show an ad whose ecpm rate is more than second ad network, it calls second ad network. But there is no guarantee that second ad network can show a banner whose ecpm rate is more than floor rate entered to waterfall.
 
AMR waterfall is based on real data calculated automatically, so there is no need to enter a floor rate. It calls the ad network which has highest ecpm rate first, if this ad network does not return any banner, it calls second, if it does not return any banner either, it calls third one. It calls all other ad networks some to collect some statistics from all of them, so it can use them next day.
 
Most of mediation systems uses ecpm rates of ad networks to create a waterfall. But definition of impression in each ad network can be different from each other. So comparison of ecpm rates of ad networks is like comparison of apples and pears. It causes wrong order of ad networks in waterfalls.
 
AMR calculates ecpm rates itself. It counts all impressions with same methodology and uses only revenue data of ad networks. It compares apples with apples. So order of ad networks in the waterfall is the very accurate.
 
##What is the pricing model of AMR?     
 
AMR is totally free for the first month for a new app owner. If the app owner is happy to use AMR and wants to continue to use it, Admost gets 15% of the total revenue which is earned from all ad placement used in AMR.
 
We believe app owners can increase their revenues between 50% and 200% by using AMR. 
 
###Sample :
 
Average monthly revenue of the app is $100.
Revenue of the app with AMR is $200 in the first month.
The fee for the first month is $0.
Revenue increase of the app owner is 100%. 
 
Revenue of the app with AMR is $200 in the second month.
The fee for the first month is $30.
Revenue increase of the app owner is 70%. 
 
App owners should pay the fee to Admost in 60 days after invoicing.
 
##What is the termination period?
 
App owners can terminate the contract anytime they want. But they have to pay the invoices for the past periods.
 
Admost can terminate the contract if the invoices are not paid in 60 days.
 

