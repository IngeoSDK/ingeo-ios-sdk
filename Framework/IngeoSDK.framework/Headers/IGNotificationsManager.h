//
//  IGNotificationsManager.h
//  IngeoSDK
//
//  Created by Amit Palomo on 6/18/15.
//  Copyright (c) 2015 Ingeo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IGNotification.h"

@interface IGNotificationsManager : NSObject


+ (void)requestForLocalNotificationsPermission;


+ (BOOL)isLocalNotificationsPermissionAllowed;


+ (void)registerNotificationTriggeredBy:(IGRegion *)region
                                   text:(NSString *)text
                                openURL:(NSString *)url
                                 repeat:(BOOL)repeat
                    registerResultBlock:(void (^)(NSError *error, NSString *identifier))result;

+ (NSArray *)activeNotifications;

+ (BOOL)unregisterNotification:(IGNotification *)notification;

@end
