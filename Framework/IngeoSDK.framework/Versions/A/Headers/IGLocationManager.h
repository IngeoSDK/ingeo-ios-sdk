//
//  IGLocationManager.h
//  Ingeo
//
//  Created by Amit Palomo on 8/16/14.
//
//

#import <Foundation/Foundation.h>
#import "IGLocation.h"
#import "IGLocationManagerDelegate.h"

@protocol IGLocationManagerDelegate;

/**
 IGLocationManager is the central point for interacting with IngeoSDK. it provides configuration interface, activation methods and easy retriveal of location data.
 IGLocationManager does several (annoying) tasks for you, so you should worry less and focus on coding your app:
 
 * It handles the request for permission for location services from your users.
 * It is already configured for optimal usage and lowest battery consumption possible.
 * It runs in background to constantly deliver you with accurate location updates.
 * It provides you with the physical Motion State of your users (Standing, Started Moving, Moving Slow or Moving Fast).
 * It filters out noise and inaccurate or irrelevant location updates.
 * It resports anonymous location updates to Ingeo backend server to provide you with great Analytics Dashboard (can be disabled using `setIngeoBackendSupport:`).
 */

@interface IGLocationManager : NSObject

///---------------------------------------------------------------------------------------
/// @name ￼Initialize and Setup
///---------------------------------------------------------------------------------------

/**
 Initializes and authenticates IGLocationManager with delegate and secret API key
 
 @param delegate The delegate object to receive update events.
 @param key The secret API key you recieved from Ingeo.io.
 */
+ (id)initWithDelegate:(id<IGLocationManagerDelegate>)delegate secretAPIKey:(NSString *)key;

/**
 Enable or disable Ingeo backend support.
 
 Ingeo backend support is enabled by default, it provides seamless integration with Ingeo Analytics dashboard at http://admin.ingeo.io
 You may choose to completely disable all communication with Ingeo backend if you wish. By doing so you lose the following functionalities:
 
 * Analytics dashboard for user statistics and smart marketing for your app.
 * Offline location updates (location updates will not be queued on device while internet is unavailable).
 
 @param flag Boolean flag.
 */
+ (void)setIngeoBackendSupport:(BOOL)flag;

/**
 Set specific User ID

 You may wish to register a specific user ID to be associated with the current user session, this could be your own
 app user ID's or any other required identification you wish to provide.
 
 @param userId The User ID you wish to register.
 */
+ (void)setUserId:(NSString *)userId;

///---------------------------------------------------------------------------------------
/// @name ￼Location Monitoring Activation and Deactivation
///---------------------------------------------------------------------------------------

/**
 Starts the location monitoring service.
 */
+ (void)startUpdatingLocation;

/**
 Stops the location monitoring service.
 */
+ (void)stopUpdatingLocation;

///---------------------------------------------------------------------------------------
/// @name ￼IGLocationManager Configuration Properties
///---------------------------------------------------------------------------------------

/**
 Returns the IGLocationManagerDelegate protocol delegate.
 */
+ (id<IGLocationManagerDelegate>)delegate;

/**
 Returns the IGLocationManagerDelegate secret API key.
 */
+ (NSString *)secretAPIKey;

/**
 Returns the User ID associated with the current session.
 */
+ (NSString *)userId;

///---------------------------------------------------------------------------------------
/// @name ￼Retrieve Location Data
///---------------------------------------------------------------------------------------

/**
 Returns a IGLocation object representing the latest location measurement taken by IngeoSDK.
 */
+ (IGLocation *)currentLocation;

/**
 Returns the current user's Motion State.
 */
+ (IGMotionState)currentMotionState;

@end

