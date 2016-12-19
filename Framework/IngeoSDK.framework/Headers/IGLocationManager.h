//
//  IGLocationManager.h
//  Ingeo
//
//  Created by Amit Palomo on 8/16/14.
//
//

#import <Foundation/Foundation.h>
#import "IGLocation.h"
#import "IGRegion.h"
#import "IGLocationManagerDelegate.h"



@protocol IGLocationManagerDelegate;

/**
 IGLocationManager is the central point for interacting with IngeoSDK. it provides configuration interface, activation methods and easy retriveal of location data.
 IGLocationManager does several (annoying) tasks for you:
 
 * It handles the request for permission for location services from your users.
 * It is configured for optimal usage and lowest battery consumption possible.
 * It runs in background to constantly deliver you with accurate location updates.
 * It provides you with the physical Motion State of your users (Standing, Walking, Driving slow or Driving fast).
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

/**
 Set custom server URL for submitting location updates
 
 You may wish to submit location updates to your own server. Your server should respond to POST requests on this URL containing the IGLocation object in JSON format.
 Note: Ingeo backend support gets disabled once a custom server URL is set.
 
 @param url The URL for submitting location updates
 */
+ (void)setCustomServerURL:(NSString *)url;

/**
 Set custom HTTP headers for location update POST requests
 
 If you choose to set a custom server URL for submitting location updates, you may also want
 to set custom HTTP headers (for authentication and such) with the outgoing location POST request.
 Simply provide a dictionary where keys represent the HTTP header names, and values represent the coresponding HTTP header values.
 
 @param headers A dictionary containing your custom HTTP headers
 */
+ (void)setCustomHTTPHeaders:(NSDictionary *)headers;


///---------------------------------------------------------------------------------------
/// @name ￼Location Monitoring Activation and Deactivation
///---------------------------------------------------------------------------------------

/**
 Starts the Always-On location monitoring service.
 */
+ (void)startUpdatingLocation;

/**
 Starts the Always-On location monitoring service.
 */
+ (void)startUpdatingLocationAlwaysOn;

/**
 Starts the When-In-Use location monitoring service.
 */
+ (void)startUpdatingLocationWhenInUse;

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


///---------------------------------------------------------------------------------------
/// @name ￼Regions
///---------------------------------------------------------------------------------------

+ (void)startMonitoringRegion:(IGRegion *)region
          registerResultBlock:(void (^)(NSError *error, NSString *identifier))result;

+ (void)stopMonitoringRegion:(IGRegion *)region;

+ (NSArray *)monitoredRegions;

@end
