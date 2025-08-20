//
//  MTRGNativeBannerAdDelegate.h
//  myTargetSDK 5.34.1
//
//  Created by Seredkin Andrey on 27.01.2025.
//  Copyright © 2025 VK. All rights reserved.
//

@class MTRGNativeBannerAd;
@class MTRGNativeBanner;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Native banner ad delegate's protocol.
 */
@protocol MTRGNativeBannerAdDelegate <NSObject>

/**
 @discussion Calls on load banner ad. (Required)

 @param banner Loaded banner.
 @param nativeBannerAd Current ad.
 */
- (void)onLoadWithNativeBanner:(MTRGNativeBanner *)banner nativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls if there is no ad.

 @param error An error code/description.
 @param nativeBannerAd Current ad.
 */
- (void)onLoadFailedWithError:(NSError *)error nativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd NS_SWIFT_NAME(onLoadFailed(error:nativeBannerAd:));

@optional

/**
 @discussion Calls if there is no ad.

 @param reason The reason why there is no ad.
 @param nativeBannerAd Current ad.
 */
- (void)onNoAdWithReason:(NSString *)reason nativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd __attribute__((deprecated("use onLoadFailed method instead.")));

/**
 @discussion Class on show the native banner ad.

 @param nativeBannerAd Current banner ad.
 */
- (void)onAdShowWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls on click by native banner ad.

 @param nativeBannerAd Current banner ad.
 */
- (void)onAdClickWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd __attribute__((deprecated("use onAdClickWithClickedView: nativeBannerAd: method instead.")));;

/**
 @discussion Calls on modal show.

 @param nativeBannerAd Current banner ad.
 */
- (void)onShowModalWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls on modal dismiss.

 @param nativeBannerAd Current banner ad.
 */
- (void)onDismissModalWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls on application leave.

 @param nativeBannerAd Current banner ad.
 */
- (void)onLeaveApplicationWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls on click by native banner ad.
 @param clickedView View that was clicked.
 @param nativeBannerAd Current banner ad.
 */
- (void)onAdClickWithClickedView:(nullable UIView *)clickedView nativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

@end



NS_ASSUME_NONNULL_END
