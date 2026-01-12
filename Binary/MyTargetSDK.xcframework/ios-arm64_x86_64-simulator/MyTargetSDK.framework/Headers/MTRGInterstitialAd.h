//
//  MTRGInterstitialAd.h
//  myTargetSDK 5.39.0
//
// Created by Timur on 3/5/18.
// Copyright (c) 2018 MailRu Group. All rights reserved.
//

#import <MyTargetSDK/MTRGBaseInterstitialAd.h>

@class MTRGInterstitialAd;
@class MTRGAdBannerInfo;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MTRGInterstitialAdDelegate

/**
 @discussion Protocol for delegates of an interstitial ad.
 */
@protocol MTRGInterstitialAdDelegate <NSObject>

/**
 @discussion Calls when interstitial ad is loaded. (Required)
 
 @param interstitialAd Current ad.
 */
- (void)onLoadWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls if there is no ad.

 @param error An error code/description.
 @param interstitialAd Current ad.
 */
- (void)onLoadFailedWithError:(NSError *)error interstitialAd:(MTRGInterstitialAd *)interstitialAd NS_SWIFT_NAME(onLoadFailed(error:interstitialAd:));

@optional

/**
 @discussion Call when there is no an ad.

 @param reason The reason why there is no an ad.
 @param interstitialAd Current ad.
 */
- (void)onNoAdWithReason:(NSString *)reason interstitialAd:(MTRGInterstitialAd *)interstitialAd __attribute__((deprecated("use onLoadFailed method instead.")));

/**
 @discussion Calls on click by the ad.
 
 @param interstitialAd Current ad.
 */
- (void)onClickWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd __attribute__((deprecated("use MTRGInterstitialAdBannerDelegate onTrackImpressionWithInterstitialAd:banner: method instead.")));

/**
 @discussion Calls on close the ad.
 
 @param interstitialAd Current ad.
 */
- (void)onCloseWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls when video ad is complete.
 
 @param interstitialAd Current ad.
 */
- (void)onVideoCompleteWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd __attribute__((deprecated("use MTRGInterstitialAdVideoDelegate onVideoCompleteWithInterstitialAd:banner: method instead.")));

/**
 @discussion Calls when interstitial ad was displayed.
 
 @param interstitialAd Current ad.
 */
- (void)onDisplayWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls when interstitial ad failed to show.

 @param interstitialAd Current ad.
 */
- (void)onFailedToShowWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls on leave application while ad is showing.
 
 @param interstitialAd Current ad.
 */
- (void)onLeaveApplicationWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls when impression is tracked.
 
 @param interstitialAd Current ad.
 */
- (void)onTrackImpressionWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd __attribute__((deprecated("use MTRGInterstitialAdBannerDelegate onTrackImpressionWithInterstitialAd:banner: method instead.")));

@end

#pragma mark - MTRGInterstitialVideoDelegate

/**
 @discussion Protocol for delegates of an interstitial ad video.
 */
@protocol MTRGInterstitialAdVideoDelegate <NSObject>

/**
 @discussion Calls on video volume changes with current ad.

 @param volume Current volume of video.
 @param interstitialAd Current ad.
 @param banner Current ad banner.
 */
- (void)onVideoVolumeChangeWithVolume:(NSTimeInterval)volume interstitialAd:(MTRGInterstitialAd *)interstitialAd banner:(nullable MTRGAdBannerInfo *)banner;

/**
 @discussion Calls when video ad is complete.
 
 @param interstitialAd Current ad.
 @param banner Current ad banner.
 */
- (void)onVideoCompleteWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd banner:(nullable MTRGAdBannerInfo *)banner;

@end

#pragma mark - MTRGInterstitialAdBannerDelegate

/**
 @discussion Protocol for delegates of an interstitial ad banner.
 */

@protocol MTRGInterstitialAdBannerDelegate <NSObject>

/**
 @discussion Calls when impression is tracked.
 
 @param interstitialAd Current ad.
 @param banner Current ad banner.
 */
- (void)onTrackImpressionWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd banner:(nullable MTRGAdBannerInfo *)banner;

/**
 @discussion Calls on click by the ad.
 
 @param interstitialAd Current ad.
 @param banner Current ad banner.
 */
- (void)onClickWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd banner:(nullable MTRGAdBannerInfo *)banner;

/**
 @discussion Calls on skip by the ad.
 
 @param interstitialAd Current ad.
 @param banner Current ad banner.
 */
- (void)onSkipWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd banner:(nullable MTRGAdBannerInfo *)banner;

@end

#pragma mark - MTRGInterstitialAd

/**
 @discussion Class describes interstitial ad.
 */
@interface MTRGInterstitialAd : MTRGBaseInterstitialAd

/**
 @discussion Delegate for the ad. Must conforms MTRGInterstitialAdDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGInterstitialAdDelegate> delegate;

/**
 @discussion Delegate for the video of the ad. Must conforms MTRGInterstitialAdVideoDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGInterstitialAdVideoDelegate> videoDelegate;

/**
 @discussion Delegate for the banner of the ad. Must conforms MTRGInterstitialAdBannerDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGInterstitialAdBannerDelegate> bannerDelegate;

/**
 @discussion Static constructor. Creates instance with slot identifier.
 
 @param slotId Slot identifier.
 */
+ (instancetype)interstitialAdWithSlotId:(NSUInteger)slotId;

/**
 @discussion Creates instance with slot identifier.
 
 @param slotId Slot identifier.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId;

@end

NS_ASSUME_NONNULL_END
