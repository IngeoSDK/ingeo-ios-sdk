//
//  IGLocationManagerDelegate.h
//  IngeoSDK
//
//  Created by Amit Palomo on 2/12/15.
//  Copyright (c) 2015 Ingeo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IGLocationManager.h"

@class IGLocationManager;

/**
 The IGLocationManagerDelegate protocol defines the methods used to receive location and heading updates from a IGLocationManager object.
 */

@protocol IGLocationManagerDelegate <NSObject>

@optional

///---------------------------------------------------------------------------------------
/// @name ￼Responding to Location Events
///---------------------------------------------------------------------------------------

/**
 Tells the delegate that a new location data is available.
 
 @param manager The IGLocationManager object that generated the update event.
 @param igLocation A IGLocation object containing the location data.
 */
- (void)igLocationManager:(IGLocationManager *)manager didUpdateLocation:(IGLocation *)igLocation;

/**
 Tells the delegate that a new Motion State was detected.
 
 @param manager The IGLocationManager object that generated the update event.
 @param motionState The new Motion State the user has just entered into.
 */
- (void)igLocationManager:(IGLocationManager *)manager didDetectMotionState:(IGMotionState)motionState;

@end