# IngeoSDK for iOS

## Overview

IngeoSDK for iOS is a drop-in framework which is super easy to integrate and use.
It adds full location based capabilities to your app with just few lines of code.
You get always-ON location awareness while keeping low battery consumption.

## Installation

1. [Download](https://github.com/IngeoSDK/ingeo-ios-sdk/archive/master.zip) as zip file or clone this repository.
2. Unzip and drag **IngeoSDK.framework** from Framework folder to your project.
3. Add the following frameworks to your Xcode project (don't worry,  these are dynamic
   bindings and will not increase your app size):   
   *CoreLocation*  
   *CoreData*  
   *CFNetwork*  
   *SystemConfiguration*  

4. Linker Settings  
   In Xcode, Go to 'Build Settings' -> 'Linking' -> 'Other Linker Flags'.  
   Enter **-ObjC** and save.

5. Import IngeoSDK with: 
   ```#import <IngeoSDK/IngeoSDK.h>```

6. Initialize
   Add the following line in your Controller (viewDidLoad or wherever you want):  
   ```
   [IGLocationManager initWithDelegate:self secretAPIKey:@"APIKEYGOESHERE"];
   ```

7. Start Location Monitoring
   ```
   [IGLocationManager startUpdatingLocation];
   ```

## USAGE


## LICENCE


## FEEDBACK
