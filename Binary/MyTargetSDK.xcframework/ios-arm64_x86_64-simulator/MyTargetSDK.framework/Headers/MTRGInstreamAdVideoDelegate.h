//
//  MTRGInstreamAdVideoDelegate.h
//  myTargetSDK 5.42.1
//
//  Created by Seredkin Andrey on 16.02.2026.
//  Copyright © 2026 VK. All rights reserved.
//

@class MTRGInstreamAd;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Instream ad video delegate protocol.
 */
@protocol MTRGInstreamAdVideoDelegate <NSObject>

/**
 @discussion Calls when video starts with current ad.

 @param instreamAd Current ad.
 */
- (void)onVideoStartWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls when video pauses with current ad.

 @param instreamAd Current ad.
 */
- (void)onVideoPauseWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls when video resumes with current ad.

 @param instreamAd Current ad.
 */
- (void)onVideoResumeWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls when video stop with current ad.

 @param instreamAd Current ad.
 */
- (void)onVideoStopWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on video progress with current ad.

 @param instreamAd Current ad.
 */
- (void)onVideoProgressWithTime:(NSTimeInterval)time duration:(NSTimeInterval)duration instreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls when video completes with current ad.

 @param instreamAd Current ad.
 */
- (void)onVideoCompleteWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on video error with current ad.

 @param instreamAd Current ad.
 */
- (void)onVideoError:(NSError *)error instreamAd:(MTRGInstreamAd *)instreamAd;

@end

NS_ASSUME_NONNULL_END
