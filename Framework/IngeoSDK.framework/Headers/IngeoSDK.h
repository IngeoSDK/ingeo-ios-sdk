//
//  IngeoSDK.h
//  IngeoSDK
//
//  Created by Amit Palomo on 11/27/14.
//  Copyright (c) 2014 Ingeo. All rights reserved.
//

#if __has_feature(modules)
@import CoreLocation;
@import CoreData;
@import SystemConfiguration;
#else
#import <CoreLocation/CoreLocation.h>
#import <CoreData/CoreData.h>
#import <SystemConfiguration/SystemConfiguration.h>
#endif


#import "IGLocationManager.h"
#import "IGLocation.h"
#import "IGNotificationsManager.h"
#import "IGTrigger.h"
#import "IGRegionTrigger.h"

