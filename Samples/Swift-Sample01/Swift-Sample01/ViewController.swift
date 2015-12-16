//
//  ViewController.swift
//  Swift-Sample01
//
//  Created by Amit Palomo on 15/12/2015.
//  Copyright © 2015 Amit Palomo. All rights reserved.
//

import UIKit
import MapKit

class ViewController: UIViewController, IGLocationManagerDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        mapSetup()

        // Please use your app secret API key. get it at http://ingeo.io/signup.php
        IGLocationManager.initWithDelegate(self, secretAPIKey: "APIKEYGOESHERE")
        
        IGLocationManager.startUpdatingLocation()
        
    }

    func mapSetup() {
        let mapView = MKMapView.init(frame: self.view.frame)
        mapView.showsUserLocation = true
        mapView.setUserTrackingMode(MKUserTrackingMode.Follow, animated: false)
        self.view = mapView
    }

    // MARK: IGLocationManagerDelegate
    
    func igLocationManager(manager: IGLocationManager!, didUpdateLocation igLocation: IGLocation!) {
        print("didUpdateLocation: \(igLocation.description)")
    }
    
    func igLocationManager(manager: IGLocationManager!, didDetectMotionState motionState: IGMotionState) {
        print("didDetectMotionState: \(IGLocation.stringForMotionState(motionState))")
        
    }
}

