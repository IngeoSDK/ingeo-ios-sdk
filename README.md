![IngeoSDK: iOS location tracking made easy (Swift & ObjC)](https://raw.githubusercontent.com/IngeoSDK/ingeo-ios-sdk/assets/IngeoSDK_logo.png)


[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/IngeoSDK.svg)](https://img.shields.io/cocoapods/v/IngeoSDK.svg)
[![Platform](https://img.shields.io/cocoapods/p/IngeoSDK.svg?style=flat)](http://cocoadocs.org/docsets/IngeoSDK)

# IngeoSDK for iOS

## Overview

IngeoSDK is a power-efficient location manager wrapper for iOS (Swift and Objective-C). It powers your app with
an always-on location tracking. It uses unique algorithms to dynamically adjust GPS power according to user
behaviour and whereabouts. Built to support iOS7 , iOS8 and iOS9, your app will
get the most relevant location data while in foreground or background - even when network is disconnected. Battery consumption is just 1% per hour. Location tracking should be automatic and just-work, so you can focus on building your app.

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
   IGLocationManager.startUpdatingLocation()
   ```

4. Get tha honey  
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
   You may also login to http://admin.ingeo.io to access the analytics dashboard.

## API Documentation
   Full API reference (jazzy): http://ingeo.io/sdk/docs

## License
   Apache v2.0

## Feedback
   Feel free to contact us at support@ingeo.io or open an issue here.

