// swift-tools-version:5.3

import PackageDescription

let package = Package(
	name: "MyTargetSDK",
	platforms:
	[
		.iOS(.v9)
	],
	products:
	[
		.library(
			name: "MyTargetSDK",
			targets: ["MyTargetSDKLib"]),
	],
	targets:
	[
		.target(name: "MyTargetSDKLib",
				dependencies: ["MyTargetSDK"],
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
					  path: "Binary/MyTargetSDK.xcframework"),
	]
)
