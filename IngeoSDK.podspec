
Pod::Spec.new do |s| 
  s.name           = "IngeoSDK"
  s.version        = "1.4.1"
  s.summary        = "Ingeo iOS SDK"
  s.homepage       = "http://ingeo.io"
  s.license        = 'Apache License, Version 2.0'
  s.author         = { "Amit Palomo" => "amit@ingeo.io" }
  s.platform       = :ios, '7.0'
  s.source         = { :git => "https://github.com/IngeoSDK/ingeo-ios-sdk.git", :tag => "v#{s.version}" }
  s.frameworks     = "CoreLocation", "CoreData", "SystemConfiguration"
  s.ios.vendored_frameworks = 'Framework/IngeoSDK.framework'
  s.requires_arc = true
end
