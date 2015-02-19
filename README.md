# IngeoSDK for iOS

## Overview

IngeoSDK is a location library for iOS which powers your app with an always-ON (24/7) location awareness while keeping low battery consumption. It uses unique algorithms to dynamically adjust GPS power and monitoring mode according to user behaviour and whereabouts. Battery consumption is just 2% per hour. We believe that location monitoring should be simple and should just-work, so you focus on building your app.

For a full list of IngeoSDK features visit: http://ingeo.io/sdk

## Installation

1. [Download](https://github.com/IngeoSDK/ingeo-ios-sdk/archive/master.zip) as zip file or clone this repository.  

2. Unzip and drag **IngeoSDK.framework** from *Framework* folder to your project.

3. Add the following frameworks to your Xcode project (don't worry, these are dynamic
   bindings and will not increase your app size):   
   *CoreLocation*  
   *CoreData*  
   *CFNetwork*  
   *SystemConfiguration*  

4. Linker Settings  
   In Xcode, Go to 'Build Settings' -> 'Linking' -> 'Other Linker Flags'.  
   Enter **-ObjC** and save.

5. Background Modes
   In Xcode, Go to 'Capabilities' -> 'Background Modes'
   Enable 'Location updates' mode.

6. Info.plist
   Edit your app's Info.plist and add the following String key:
   NSLocationAlwaysUsageDescription

## USAGE

1. Import
   ```objc
   #import <IngeoSDK/IngeoSDK.h>
   ```
   
2. Initialize  
   Add the following line in your Controller (viewDidLoad or wherever you want):  
   ```objc
   [IGLocationManager initWithDelegate:self secretAPIKey:@"APIKEYGOESHERE"];
   ```
   
3. Start Location Monitoring
   ```objc
   [IGLocationManager startUpdatingLocation];
   ```

4. That's it. you've just enabled location monitoring for your app.
   You should now focus on building great location based features!
   Login to http://admin.ingeo.io to access the analytics dashboard.

## LICENCE


## FEEDBACK
