//
//  MTRGNativeAdVideoDelegate.h
//  myTargetSDK 5.29.0
//
//  Created by Seredkin Andrey on 27.01.2025.
//  Copyright © 2025 VK. All rights reserved.
//

@class MTRGNativeAd;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Native ad video delegate protocol.
 */
@protocol MTRGNativeAdVideoDelegate <NSObject>

/**
 @discussion Calls when video starts with current ad.

 @param nativeAd Current ad.
 */
- (void)onVideoStartWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when video pauses with current ad.

 @param nativeAd Current ad.
 */
- (void)onVideoPauseWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when video resumes with current ad.

 @param nativeAd Current ad.
 */
- (void)onVideoResumeWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when video replays with current ad.

 @param nativeAd Current ad.
 */
- (void)onVideoReplayWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on video progress with current ad.

 @param nativeAd Current ad.
 */
- (void)onVideoProgressWithTime:(NSTimeInterval)time duration:(NSTimeInterval)duration nativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when video completes with current ad.

 @param nativeAd Current ad.
 */
- (void)onVideoCompleteWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on video error with current ad.

 @param nativeAd Current ad.
 */
- (void)onVideoError:(NSError *)error nativeAd:(MTRGNativeAd *)nativeAd;

@optional

/**
 @discussion Called when the video becomes ready for playback.
 
 @param nativeAd Current ad.
 */

- (void)onVideoReadyWithNativeAd:(MTRGNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
