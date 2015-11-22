//
//  IGNotification.h
//  IngeoSDK
//
//  Created by Amit Palomo on 6/3/15.
//  Copyright (c) 2015 Ingeo. All rights reserved.
//

#import <Foundation/Foundation.h>
// CoreLocation
#import <CoreLocation/CoreLocation.h>
#import "IGTrigger.h"

@class UILocalNotification;



@interface IGNotification : NSObject

@property (nonatomic, strong) IGTrigger *trigger;
@property (nonatomic, assign) BOOL repeat;
@property (nonatomic, strong) UILocalNotification *notification;


@end
