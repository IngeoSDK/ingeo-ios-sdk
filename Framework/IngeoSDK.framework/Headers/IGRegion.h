//
//  IGRegion.h
//  IngeoSDK
//
//  Created by Amit Palomo on 9/16/15.
//  Copyright (c) 2015 Ingeo. All rights reserved.
//

#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLCircularRegion.h>


typedef NS_ENUM(NSInteger, IGRegionEvents) {
    IGRegionEventEntry = 1 << 0,
    IGRegionEventExit = 1 << 1,
};

@interface IGRegion : CLCircularRegion <NSCopying>

@property (assign, nonatomic) IGRegionEvents events;

+ (instancetype)regionAt:(CLLocationCoordinate2D)center
                  radius:(double)radius
                      on:(IGRegionEvents)events
              identifier:(NSString *)identifier;

@end