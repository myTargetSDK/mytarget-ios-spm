// swift-tools-version:5.3

import PackageDescription

let package = Package(
	name: "MyTargetSDK",
	platforms:
	[
		.iOS(.v10)
	],
	products:
	[
		.library(
			name: "MyTargetSDK",
			targets: ["MyTargetSDKLib"])
	],
	dependencies:
	[
		.package(name: "MyTrackerSDK",
				 url: "https://github.com/myTrackerSDK/mytracker-ios-spm.git",
				 .upToNextMinor(from: "3.0.3"))
	],
	targets:
	[
		.target(name: "MyTargetSDKLib",
				dependencies: ["MyTargetSDK", "MyTrackerSDK"],
				path: "MyTargetPackageWrapper",
				linkerSettings: [
					.linkedFramework("SystemConfiguration"),
					.linkedFramework("CoreTelephony"),
					.linkedFramework("StoreKit"),
					.linkedFramework("AdSupport"),
					.linkedFramework("CoreGraphics"),
					.linkedFramework("AVFoundation"),
					.linkedFramework("CoreMedia"),
					.linkedFramework("SafariServices")
				]
		),
		.binaryTarget(name: "MyTargetSDK",
					  path: "Binary/MyTargetSDK.xcframework")
	]
)
