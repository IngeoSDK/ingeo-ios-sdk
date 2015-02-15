//
//  ViewController.m
//  iOS-Sample01
//
//  Created by Amit Palomo on 12/29/14.
//  Copyright (c) 2014 Ingeo. All rights reserved.
//

#import "ViewController.h"
#import <IngeoSDK/IngeoSDK.h>
#import <MapKit/MapKit.h>

@interface ViewController () <IGLocationManagerDelegate>

@property (strong, nonatomic) MKMapView *mapView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self deployMap];
    
#error Please use your app secret API key. get it from http://ingeo.io.
    [IGLocationManager initWithDelegate:self secretAPIKey:@"APIKEYGOESHERE"];
    
    [IGLocationManager startUpdatingLocation];
    
}

- (void)deployMap
{
    _mapView = [[MKMapView alloc] initWithFrame:self.view.frame];
    _mapView.showsUserLocation = YES;
    _mapView.userTrackingMode = MKUserTrackingModeFollow;
    self.view = _mapView;
}

#pragma mark - IGLocationManagerDelegate

- (void)igLocationManager:(IGLocationManager *)manager didUpdateLocation:(IGLocation *)igLocation
{
    
    NSLog(@"didUpdateLocation: %@", [igLocation description]);
    
}

- (void)igLocationManager:(IGLocationManager *)manager didDetectMotionState:(IGMotionState)motionState
{
    
    NSLog(@"didDetectMotionState: %@",[IGLocation stringForMotionState:motionState]);
    
}


@end