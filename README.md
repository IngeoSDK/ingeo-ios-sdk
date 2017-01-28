![IngeoSDK: iOS location tracking made easy (Swift & ObjC)](https://raw.githubusercontent.com/IngeoSDK/ingeo-ios-sdk/assets/IngeoSDK_logo.png)


[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/IngeoSDK.svg)](https://img.shields.io/cocoapods/v/IngeoSDK.svg)
[![Platform](https://img.shields.io/cocoapods/p/IngeoSDK.svg?style=flat)](http://cocoadocs.org/docsets/IngeoSDK)

# IngeoSDK for iOS

## Overview

IngeoSDK is a power-efficient location manager for iOS (Swift and Objective-C), which extends and improves CoreLocation.  
It uses unique algorithms to dynamically and constantly adjust CoreLocation's tracking configuration parameters according to user's
motion, behavior, speed and whereabouts. Thus enabling suited configuration scheme for optimized accuracy and minimum power consumption in real-time.  
Your app and/or server will receive the most relevant location data while in foreground or background - even when network is disconnected.
Off-course, or bad location samples are filtered out for you. Battery consumption is just ~2% per hour.  
Supports iPhone, iPad, iPod Touch running iOS 7.0+

For a full list of features visit: http://ingeo.io/sdk

## Demo, please?
1. [Download](https://github.com/IngeoSDK/ingeo-ios-sdk/archive/master.zip) as zip file or clone this repository.
2. Unzip and open the project file in ***Samples/Swift-Sample01*** directory using Xcode.
3. Edit *ViewController.swift* to enter your API key in the initializer method:
   ```swift
    IGLocationManager.initWithDelegate(self, secretAPIKey: "APIKEYGOESHERE")
   ```
                     
   To get a new API key, [Signup](http://admin.ingeo.io/signup.php) for free.  
4. Now simply run in iOS Simulator or your device and watch the debug console as the demo app takes you traveling through San Fransisco streets (using a recorded GPX file).

## Installing with CocoaPods

1. Add the following line to your Podfile:  
   ```
   pod 'IngeoSDK'
   ```

2. Run:  
   ```
   pod install
   ```

## Enable Location Services

1. In Xcode, Go to your target settings -> 'Capabilities' -> 'Background Modes'  
    Turn on 'Location updates'.

2. Edit your app's Info.plist and add the following String key (with empty value):  
   ```
    NSLocationAlwaysUsageDescription
   ```

## Usage

1. Import
   ```swift
   import IngeoSDK
   ```

2. Set Delegate
   ```swift
   class ViewController: UIViewController, IGLocationManagerDelegate {
   ```
   
2. Initialize  
   ```swift
   IGLocationManager.initWithDelegate(self, secretAPIKey: "APIKEYGOESHERE")
   ```
   
3. Start Location Monitoring
   ```swift
   IGLocationManager.startUpdatingLocationAlwaysOn()
   ```
   Or
   ```swift
   IGLocationManager.startUpdatingLocationWhenInUse()
   ```

4. Get the honey  
   Implement IGLocationManagerDelegate methods in your delegate.    

   Swift:

    ```swift
    func igLocationManager(manager: IGLocationManager!, didUpdateLocation igLocation: IGLocation!) {
        print("didUpdateLocation: \(igLocation.description)")
    }

    func igLocationManager(manager: IGLocationManager!, didDetectMotionState motionState: IGMotionState) {
        print("didDetectMotionState: \(IGLocation.stringForMotionState(motionState))")
    }
    ```

    Objective-C:
    ```objc
    - (void)igLocationManager:(IGLocationManager *)manager didUpdateLocation:(IGLocation *)igLocation {
        NSLog(@"didUpdateLocation: %@", [igLocation description]);
    }

    - (void)igLocationManager:(IGLocationManager *)manager didDetectMotionState:(IGMotionState)motionState {
        NSLog(@"didDetectMotionState: %@",[IGLocation stringForMotionState:motionState]);
    }
    ```

5. That's it. you've just enabled constant location monitoring.  
   Sit and watch your users on the Admin Dashboard http://admin.ingeo.io.

## API Documentation
   Full API reference: http://ingeo.io/sdk/docs

## License
   Apache v2.0

## Feedback
   Feel free to contact us at support@ingeo.io or open an issue here.

