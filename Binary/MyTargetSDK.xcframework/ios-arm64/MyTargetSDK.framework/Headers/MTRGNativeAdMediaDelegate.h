//
//  MTRGNativeAdMediaDelegate.h
//  myTargetSDK 5.30.0
//
//  Created by Seredkin Andrey on 27.01.2025.
//  Copyright © 2025 VK. All rights reserved.
//

@class MTRGNativeAd;
@class MTRGNativePromoCollageMedia;

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

@optional

/**
 @discussion Calls when collage thumbnail loaded for the ad.

 @param collageMedia Collage media for which thumbnail was loaded.
 @param nativeAd Current ad.
 */
- (void)onCollageThumbnailLoad:(MTRGNativePromoCollageMedia *)collageMedia nativeAd:(MTRGNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
