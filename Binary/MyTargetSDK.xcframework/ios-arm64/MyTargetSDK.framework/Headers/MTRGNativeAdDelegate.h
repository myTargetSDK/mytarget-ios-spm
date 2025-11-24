//
//  MTRGNativeAdDelegate.h
//  myTargetSDK 5.38.0
//
//  Created by Seredkin Andrey on 27.01.2025.
//  Copyright © 2025 VK. All rights reserved.
//

@class MTRGNativeAd;
@class MTRGNativePromoBanner;
@class MTRGNativePromoCollageMedia;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Delegate's protocol for the native ad.
 */
@protocol MTRGNativeAdDelegate <NSObject>

/**
 @discussion Calls on load native promo banner. (Required)

 @param promoBanner Loaded banner.
 @param nativeAd Current ad.
 */
- (void)onLoadWithNativePromoBanner:(MTRGNativePromoBanner *)promoBanner nativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls if there is no ad.

 @param error An error code/description.
 @param nativeAd Current ad.
 */
- (void)onLoadFailedWithError:(NSError *)error nativeAd:(MTRGNativeAd *)nativeAd NS_SWIFT_NAME(onLoadFailed(error:nativeAd:));

@optional

/**
 @discussion Calls if there is no ad.

 @param reason The reason why there is no ad.
 @param nativeAd Current ad.
 */
- (void)onNoAdWithReason:(NSString *)reason nativeAd:(MTRGNativeAd *)nativeAd __attribute__((deprecated("use onLoadFailed method instead.")));

/**
 @discussion Class on show the native ad.

 @param nativeAd Current ad.
 */
- (void)onAdShowWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on click by native ad.
 
 @param clickedView View that was clicked.
 @param nativeAd Current ad.
 */
- (void)onAdClickWithClikedView:(nullable UIView *)clickedView nativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on click by native ad.

 @param nativeAd Current ad.
 */
- (void)onAdClickWithNativeAd:(MTRGNativeAd *)nativeAd __attribute__((deprecated("use onAdClickWithClikedView: nativeAd: method instead.")));

/**
 @discussion Calls on click by collage thumbnail.
 For better UX, it's recommended to implement full screen view for selected media

 @param collageMedia Collage media which has been clicked
 @param thumbnailView UIImageView which has been clicked
 @param nativeAd Current ad.
 */
- (void)onCollageThumbnailClick:(MTRGNativePromoCollageMedia *)collageMedia thumbnailView:(UIImageView *)thumbnailView nativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on modal show.

 @param nativeAd Current ad.
 */
- (void)onShowModalWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on modal dismiss.

 @param nativeAd Current ad.
 */
- (void)onDismissModalWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on application leave.

 @param nativeAd Current ad.
 */
- (void)onLeaveApplicationWithNativeAd:(MTRGNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
