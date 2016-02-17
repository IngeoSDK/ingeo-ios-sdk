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
 
 @param manager The IGLocationManager object that generated the motion state change.
 @param motionState The Motion State the user is currently at.
 */
- (void)igLocationManager:(IGLocationManager *)manager didDetectMotionState:(IGMotionState)motionState;

/**
 Tells the delegate that the user entered the specified region.
 
 @param manager The IGLocationManager object reporting the event.
 @param region An object containing information about the region that was entered.
 */
- (void)igLocationManager:(IGLocationManager *)manager didEnterRegion:(CLRegion *)region;

/**
 Tells the delegate that the user left the specified region.
 
 @param manager The IGLocationManager object reporting the event.
 @param region An object containing information about the region that was exited.
 */
- (void)igLocationManager:(IGLocationManager *)manager didExitRegion:(CLRegion *)region;

@end