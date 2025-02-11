//
//  MTRGNativeAdMediaDelegate.h
//  myTargetSDK 5.25.1
//
//  Created by Seredkin Andrey on 27.01.2025.
//  Copyright © 2025 VK. All rights reserved.
//

@class MTRGNativeAd;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Native ad media delegate protocol.
 */
@protocol MTRGNativeAdMediaDelegate <NSObject>

/**
 @discussion Calls when icon loaded for the ad.

 @param nativeAd Current ad.
 */
- (void)onIconLoadWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when image loaded for the ad.

 @param nativeAd Current ad.
 */
- (void)onImageLoadWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when adChoices image loaded for the ad.

 @param nativeAd Current ad.
 */
- (void)onAdChoicesIconLoadWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when media resources for the ad not loaded.

 @param nativeAd Current ad.
 */
- (void)onMediaLoadFailedWithNativeAd:(MTRGNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
