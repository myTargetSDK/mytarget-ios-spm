//
//  MTRGInstreamAd.h
//  myTargetSDK 5.15.1
//
// Created by Timur on 5/4/18.
// Copyright (c) 2018 Mail.Ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MyTargetSDK/MTRGBaseAd.h>

@protocol MTRGInstreamAdPlayer;
@class MTRGInstreamAd;
@class AVPlayer;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Instream ad banner.
 */
@interface MTRGInstreamAdBanner : NSObject

/**
 @discussion Duration of showing the banner.
 */
@property(nonatomic, readonly) NSTimeInterval duration;

/**
 @discussion Allows pause or not.
 */
@property(nonatomic, readonly) BOOL allowPause;

/**
 @discussion Allows close or not.
 */
@property(nonatomic, readonly) BOOL allowClose;

/**
 @discussion Delay to close the banner.
 */
@property(nonatomic, readonly) NSTimeInterval allowCloseDelay;

/**
 @discussion Size of the banner.
 */
@property(nonatomic, readonly) CGSize size;

/**
 @discussion CTA text.
 */
@property(nonatomic, readonly, copy, nullable) NSString *ctaText;

/**
 @discussion The banner identifier.
 */
@property(nonatomic, readonly) NSString *bannerId;

- (instancetype)init NS_UNAVAILABLE;

@end

/**
 @discussion Protocol of delegate of instream ad.
 */
@protocol MTRGInstreamAdDelegate <NSObject>

/**
 @discussion Calls when instream ad is loaded. Required.
 
 @param instreamAd Current instream ad.
 */
- (void)onLoadWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls if there is no ad. Required.
 
 @param reason Reason why there is no ad.
 @param instreamAd Current instream ad.
 */
- (void)onNoAdWithReason:(NSString *)reason instreamAd:(MTRGInstreamAd *)instreamAd;

@optional

/**
 @discussion Calls on error for the ad.
 
 @param reason Reason of the error.
 @param instreamAd Current instream ad.
 */
- (void)onErrorWithReason:(NSString *)reason instreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on banner's start.
 
 @param banner Current instream ad banner.
 @param instreamAd Current instream ad.
 */
- (void)onBannerStart:(MTRGInstreamAdBanner *)banner instreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on banner's complete.
 
 @param banner Current instream ad banner.
 @param instreamAd Current instream ad.
 */
- (void)onBannerComplete:(MTRGInstreamAdBanner *)banner instreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on banner's time left change.
 
 @param timeLeft Remaining playback time.
 @param duration Duration of video.
 @param instreamAd Current instream ad.
 */
- (void)onBannerTimeLeftChange:(NSTimeInterval)timeLeft duration:(NSTimeInterval)duration instreamAd:(MTRGInstreamAd *)instreamAd;


/**
 @discussion Calls on banner's complete with section.
 
 @param section Current section of the ad banner.
 @param instreamAd Current instream ad.
 */
- (void)onCompleteWithSection:(NSString *)section instreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on banner's modal show.
 
 @param instreamAd Current instream ad.
 */
- (void)onShowModalWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on banner's modal dismiss.
 
 @param instreamAd Current instream ad.
 */
- (void)onDismissModalWithInstreamAd:(MTRGInstreamAd *)instreamAd;

/**
 @discussion Calls on application leave while banner is showing.
 
 @param instreamAd Current instream ad.
 */
- (void)onLeaveApplicationWithInstreamAd:(MTRGInstreamAd *)instreamAd;

@end

/**
 @discussion Class for an instream ad.
 */
@interface MTRGInstreamAd : MTRGBaseAd

/**
 @discussion Delegate of the ad.
 */
@property(nonatomic, weak, nullable) id <MTRGInstreamAdDelegate> delegate;

/**
 @discussion Player for the ad. Conforms MTRGInstreamAdPlayer protocol.
 */
@property(nonatomic, nullable) id <MTRGInstreamAdPlayer> player;

/**
 @discussion Array of midpoint for the ad.
 */
@property(nonatomic, readonly, copy) NSArray<NSNumber *> *midpoints;

/**
 @discussion Array of section names.
 */
@property(nonatomic, readonly) NSArray<NSString *> *videoSectionNames;

/**
 @discussion Instance of the AVPlayer.
 */
@property(nonatomic, readonly, nullable) AVPlayer *avPlayer;

/**
 @discussion Parameter sets quality of playing video.
 */
@property(nonatomic) NSUInteger videoQuality;

/**
 @discussion Timeout of loading the ad.
 */
@property(nonatomic) NSUInteger loadingTimeout;

/**
 @discussion Determines ad shows fullscreen or not.
 */
@property(nonatomic) BOOL fullscreen;

/**
 @discussion Volume of the ad.
 */
@property(nonatomic) float volume;

/**
 @discussion Static constructor. Creates instream ad with slot identifier.
 
 @param slotId Slot identifier.
 
 @return Instance of the class.
 */
+ (instancetype)instreamAdWithSlotId:(NSUInteger)slotId;

- (instancetype)init NS_UNAVAILABLE;

/**
 @discussion Creates instream ad with slot identifier.
 
 @param slotId Slot identifier.
 
 @return Instance of the class.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId;

/**
 @discussion Loads the ad.
 */
- (void)load;

/**
 @discussion Pauses the ad.
 */
- (void)pause;

/**
 @discussion Resumes the ad.
 */
- (void)resume;

/**
 @discussion Stops the ad.
 */
- (void)stop;

/**
 @discussion Skips the ad.
 */
- (void)skip;

/**
 @discussion Skips the banner.
 */
- (void)skipBanner;

/**
 @discussion Method to handle click with specific controller.
 
 @param controller Instance of UIViewController.
 */
- (void)handleClickWithController:(UIViewController *)controller;

/**
 @discussion Starts preroll.
 */
- (void)startPreroll;

/**
 @discussion Stops preroll.
 */
- (void)startPostroll;

/**
 @discussion Starts pauseroll.
 */
- (void)startPauseroll;

/**
 @discussion Starts midroll at the point.
 
 @param point Point to start the midroll.
 */
- (void)startMidrollWithPoint:(NSNumber *)point;

/**
 @discussion Starts using of the default player.
 */
- (void)useDefaultPlayer;

/**
 @discussion Method to configure midpoints for the ad.
 
 @param midpointsP Array of midpoints.
 @param videoDuration Duration of the video ad.
 */
- (void)configureMidpointsP:(nullable NSArray<NSNumber *> *)midpointsP
		   forVideoDuration:(NSTimeInterval)videoDuration;

/**
 @discussion Method to configure midpoints for the ad.
 
 @param midpoints Array of midpoints.
 @param videoDuration Duration of the video ad.
 */
- (void)configureMidpoints:(nullable NSArray<NSNumber *> *)midpoints
		  forVideoDuration:(NSTimeInterval)videoDuration;

/**
 @discussion Method to configure midpoints for the ad.
 
 @param videoDuration Duration of the video ad.
 */
- (void)configureMidpointsForVideoDuration:(NSTimeInterval)videoDuration;

@end

NS_ASSUME_NONNULL_END
