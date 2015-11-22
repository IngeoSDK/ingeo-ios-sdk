//
//  IGRegionTrigger.h
//  IngeoSDK
//
//  Created by Amit Palomo on 9/16/15.
//  Copyright (c) 2015 Ingeo. All rights reserved.
//

#import <IngeoSDK/IngeoSDK.h>

typedef NS_ENUM(NSInteger, IGRegionEvents) {
    IGRegionEventEntry = 1 << 0,
    IGRegionEventExit = 1 << 1,
};

@interface IGRegionTrigger : IGTrigger <NSCopying>

@property (assign, nonatomic) CLLocationCoordinate2D center;
@property (assign, nonatomic) double radius;
@property (assign, nonatomic) IGRegionEvents events;

+ (instancetype)triggerWithRegionAt:(CLLocationCoordinate2D)center
                             radius:(double)radius
                                 on:(IGRegionEvents)events;

@end
