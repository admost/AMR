## [Integration Guides](https://admost.github.io/)

## What is AMR?
 
AMR (Admost Mediation Router) is a solely mobile ad mediation tool which is used to optimise the ad networks, country and ad type based, to maximise the revenue of applications.
 
## Which problem does AMR solve?
 
The main revenue stream of most applications is based on mobile advertisement through ad networks. And it is almost impossible to indicate any network is the best for all variables. Each ad network may have comparative advantage due to their eCPM- fill rate, ad type, advertisers… and also the audience and type of the application, itself. AMR corroborates applications to serve the ads through various ad networks regarding all these variables to reach the most revenue.  
 
## How does AMR solve this problem?
 
AMR is a client-server tool; its client part is an SDK embedded into apps and its server part is a database which keeps all the statistics collected from ad networks and its own SDK.

AMR SDK counts all impression numbers in each app for each ad placement and country and sends all these data to the database, also imports only revenue data from each ad network per country and placement by APIs automatically. eCPM rates are calculated in AMR database itself. AMR SDK pulls eCPM rates of each ad network for all the ad placements in the app for the country where the user opens the app.

Apps call only AMR SDK to get a list of ad networks in order of waterfall algorithm, so applications know which ad network is better to serve in order. 

AMR SDK’s profession is just routing the app in order of calling ad networks to maximise the earnings.
 
## Where the revenue goes?
 
AMR system works just as a router to call ad networks. There is no cash flow through AMR. App owners get all their revenues from ad networks on own accounts as usual.
 
## What does AMR dashboard show?
 
Normally all app owners who cooperate with many ad networks have to log in each ad network’ s dashboard to view all the statistic separately. 

By tracking all the networks data together on AMR dashboard, publishers have flexibility to view/ compare the performances of each network in various aspects; zone-placement-ad type breakdown, ad network-country breakdown and more…

 
## What is the differences of AMR from other mediation systems?
 
Most of the mediations systems are the extension or part of an ad network, where they try to serve their own inventory first and if they cannot serve their own, they call other ad networks based on a waterfall in some algorithms.

Admost is not an ad network, solely a technology company, which does not have any inventory to serve first by its own and only focuses on app owners to maximise the ad revenue from ad networks. It is not competitor of ad networks; the friendly platform between apps and ad networks.

The waterfall in most of mediations should be created by publishers manually as entering floor eCPM rates for each ad network for ad placement and for each country. It is almost impossible to keep all adjustments in the waterfall fresh, because eCPM rates of each ad network fluctuates. Mechanics of the waterfall in most cannot optimise the revenue by nature with manually entered floor prices, because if the first ad networks do not serve an ad, there is no guarantee that; the eCPM rate of the second ad network surpass the floor price. Which cause a revenue loss!

AMR counts all impression, calculates all eCPM rates and order the waterfall automatically itself; per country, per ad zone and per placement, so app publishers do not need to enter any floor price and do not encounter revenue lost.

The mediation systems with automatic waterfall order only consider eCPM rates or revenue of ad networks to make a request in order. Highest eCPM rated ad network always serve the ad first, which will cause other networks to get lower ad request and decrease in eCPM rates. Always requesting the same ad network limit the diversity of the ad and decrease the value of the placement. That will bring up lower click through rate and conversion; the efficiency of a single ad network in long term.

AMR’ s algorithm is based on the weighted eCPM rates and with the fill rate and also the diversity of the ads distribution. Primary objective is to gain the maximum efficiency of each network to increase the overall eCPM rate on average. Concisely, raising the value of each request and ad zone. Each of our publishers serve the highest diversified quality ads to their user, get the maximum efficiency from each ad network and the maximum earning in overall. 

Most of mediation systems consider eCPM rates of ad networks to create a waterfall. Though, the definition of an impression may alter in each ad network; so, the comparison of eCPM rates of these ad networks is like comparing apples to pears. That causes the wrong ordering and requesting in waterfall.

AMR calculates eCPM rates itself. The system counts each impression with same methodology and uses only revenue data of ad networks as base; compares apples to apples. So, the order of ad networks in the waterfall is very accurate.

## What is the pricing model of AMR?     

AMR is free of a charge for the three months. AMR charge commission fee for the total earning after third month. The commission rate is %5 of the total monthly revenue. We assert app publishers increase their revenues till 100% by using AMR.

For instance, your current mobile ad revenue is $100K and with the AMR integration;

The revenue increased by 50% and reached to $150K. Your net revenue is $142.5K with 5%($7.5K) commission rate cut-off. Net revenue increased by 42.5
 
## What is the termination period?
 
App owners can terminate the contract anytime they want. 

Admost can terminate the contract if the invoices are not paid in 60 days.
