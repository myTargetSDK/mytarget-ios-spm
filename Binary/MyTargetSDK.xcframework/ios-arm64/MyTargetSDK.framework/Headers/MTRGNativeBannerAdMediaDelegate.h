//
//  MTRGNativeBannerAdMediaDelegate.h
//  myTargetSDK 5.34.0
//
//  Created by Seredkin Andrey on 27.01.2025.
//  Copyright © 2025 VK. All rights reserved.
//

@class MTRGNativeBannerAd;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Banner media delegate's protocol.
 */
@protocol MTRGNativeBannerAdMediaDelegate <NSObject>

/**
 @discussion Call on load icon for native banner ad.

 @param nativeBannerAd Current banner ad.
 */
- (void)onIconLoadWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls when adChoices image loaded for the ad.

 @param nativeBannerAd Current banner ad.
 */
- (void)onAdChoicesIconLoadWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls when media resources for the ad not loaded.

 @param nativeBannerAd Current ad.
 */
- (void)onMediaLoadFailedWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

@end

NS_ASSUME_NONNULL_END
