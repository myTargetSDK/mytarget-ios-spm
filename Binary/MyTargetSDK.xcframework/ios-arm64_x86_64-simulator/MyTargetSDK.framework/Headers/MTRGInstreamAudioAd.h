//
//  MTRGInstreamAudioAd.h
//  myTargetSDK 5.15.1
//
// Created by Timur on 5/25/18.
// Copyright (c) 2018 Mail.Ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MyTargetSDK/MTRGBaseAd.h>

@class MTRGInstreamAudioAd;
@class MTRGShareButtonData;
@protocol MTRGInstreamAudioAdPlayer;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Class-companion for instream banner
 */
@interface MTRGInstreamAdCompanionBanner : NSObject

/**
 @discussion Banner's width.
 */
@property(nonatomic, readonly) NSUInteger width;

/**
 @discussion Banner's height.
 */
@property(nonatomic, readonly) NSUInteger height;

/**
 @discussion Asset's width.
 */
@property(nonatomic, readonly) NSUInteger assetWidth;

/**
 @discussion Asset's height.
 */
@property(nonatomic, readonly) NSUInteger assetHeight;

/**
 @discussion Expanded width.
 */
@property(nonatomic, readonly) NSUInteger expandedWidth;

/**
 @discussion Expanded height.
 */
@property(nonatomic, readonly) NSUInteger expandedHeight;

/**
 @discussion Flag determines clickable banner or not.
 */
@property(nonatomic, readonly) BOOL isClickable;

/**
 @discussion String for static resource.
 */
@property(nonatomic, readonly, copy, nullable) NSString *staticResource;

/**
 @discussion String for iFrame resource.
 */
@property(nonatomic, readonly, copy, nullable) NSString *iframeResource;

/**
 @discussion String for HTML resource.
 */
@property(nonatomic, readonly, copy, nullable) NSString *htmlResource;

/**
 @discussion API.
 */
@property(nonatomic, readonly, copy, nullable) NSString *apiFramework;

/**
 @discussion Slot identifier.
 */
@property(nonatomic, readonly, copy, nullable) NSString *adSlotID;

/**
 @discussion Required string.
 */
@property(nonatomic, readonly, copy, nullable) NSString *required;

- (instancetype)init NS_UNAVAILABLE;

@end

/**
 @discussion Class of instream audio banner.
 */
@interface MTRGInstreamAudioAdBanner : NSObject

/**
 @discussion Ad duration.
 */
@property(nonatomic, readonly) NSTimeInterval duration;

/**
 @discussion The flag determines whether the seek can be performed.
 */
@property(nonatomic, readonly) BOOL allowSeek;

/**
 @discussion The flag determines whether the skip can be performed.
 */
@property(nonatomic, readonly) BOOL allowSkip;

/**
 @discussion The flag determines whether the pause can be performed.
 */
@property(nonatomic, readonly) BOOL allowPause;

/**
 @discussion The flag determines whether the track change can be performed.
 */
@property(nonatomic, readonly) BOOL allowTrackChange;

/**
 @discussion The ad text.
 */
@property(nonatomic, readonly, copy, nullable) NSString *adText;

/**
 @discussion Array of Instances of banner's companions(MTRGInstreamAdCompanionBanner).
 */
@property(nonatomic, readonly) NSArray<MTRGInstreamAdCompanionBanner *> *companionBanners;

/**
 @discussion Array of share buttons(MTRGShareButtonData).
 */
@property(nonatomic, readonly) NSArray<MTRGShareButtonData *> *shareButtons;

- (instancetype)init NS_UNAVAILABLE;

@end

/**
 @discussion Protocol for delegates of instream audio ad.
 */
@protocol MTRGInstreamAudioAdDelegate <NSObject>

/**
 @discussion Calls on load with instream audio.(Required)
 
 @param instreamAudioAd Instance of MTRGInstreamAudioAd.
 */
- (void)onLoadWithInstreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when there is no ad for instream audio.(Required)
 
 @param reason String with reason.
 @param instreamAudioAd Current instream audio ad. Instance of MTRGInstreamAudioAd.
 */
- (void)onNoAdWithReason:(NSString *)reason instreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

@optional

/**
 @discussion Calls when error was happened.
 
 @param reason The reason of error.
 @param instreamAudioAd Current instream audio ad. Instance of MTRGInstreamAudioAd.
 */
- (void)onErrorWithReason:(NSString *)reason instreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when banner starts.
 
 @param banner Current audio banner.
 @param instreamAudioAd Current instream audio ad.
 */
- (void)onBannerStart:(MTRGInstreamAudioAdBanner *)banner instreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when banner complete.
 
 @param banner Current audio banner.
 @param instreamAudioAd Current instream audio ad.
 */
- (void)onBannerComplete:(MTRGInstreamAudioAdBanner *)banner instreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when banner time to left was changed.
 
 @param timeLeft Time in seconds.
 @param duration Full duration in seconds.
 @param instreamAudioAd Current instream audio ad.
 */
- (void)onBannerTimeLeftChange:(NSTimeInterval)timeLeft duration:(NSTimeInterval)duration instreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when ad complete with section.
 
 @param section Current section.
 @param instreamAudioAd Current instream audio ad.
 */
- (void)onCompleteWithSection:(NSString *)section instreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when modal was showed.
 
 @param instreamAudioAd Current instream audio ad.
 */
- (void)onShowModalWithInstreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when modal dismissed.
 
 @param instreamAudioAd Current instream audio ad.
 */
- (void)onDismissModalWithInstreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

/**
 @discussion Calls when application left.
 
 @param instreamAudioAd Current instream audio ad.
 */
- (void)onLeaveApplicationWithInstreamAudioAd:(MTRGInstreamAudioAd *)instreamAudioAd;

@end

/**
 @discussion Main class for instream audio ad.
 */
@interface MTRGInstreamAudioAd : MTRGBaseAd

/**
 @discussion Delegate of the class. Must conforms MTRGInstreamAudioAdDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGInstreamAudioAdDelegate> delegate;

/**
 @discussion Instance of audio player. Must conforms MTRGInstreamAudioAdPlayer.
 */
@property(nonatomic, nullable) id <MTRGInstreamAudioAdPlayer> player;

/**
 @discussion Current banner of the ad.
 */
@property(nonatomic, readonly, nullable) MTRGInstreamAudioAdBanner *currentBanner;

/**
 @discussion Array of modpoints for the ad.
 */
@property(nonatomic, readonly, copy) NSArray<NSNumber *> *midpoints;

/**
 @discussion Timeout for loading ad.
 */
@property(nonatomic) NSUInteger loadingTimeout;

/**
 @discussion Volume of instream audio ad.
 */
@property(nonatomic) float volume;

/**
 @discussion Static constructor. Creates instance of the class with slot identifier.
 
 @param slotId Slot identifier.
 */
+ (instancetype)instreamAudioAdWithSlotId:(NSUInteger)slotId;

- (instancetype)init NS_UNAVAILABLE;

/**
 @discussion Creates instance of the class with slot identifier.
 
 @param slotId Slot identifier.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId;

/**
 @discussion Load the ad.
 */
- (void)load;

/**
 @discussion Pause the audio ad.
 */
- (void)pause;

/**
 @discussion Resume the audio ad.
 */
- (void)resume;

/**
 @discussion Stop the audio ad.
 */
- (void)stop;

/**
 @discussion Skip current audio ad.
 */
- (void)skip;

/**
 @discussion Skip the banner.
 */
- (void)skipBanner;

/**
 @discussion Method to handle companion click.
 
 @param companionBanner The companion for the ad.
 @param controller Used UIViewController.
 */
- (void)handleCompanionClick:(MTRGInstreamAdCompanionBanner *)companionBanner withController:(UIViewController *)controller;

/**
 @discussion Method to handle companion show.
 
 @param companionBanner The companion for the ad.
 */
- (void)handleCompanionShow:(MTRGInstreamAdCompanionBanner *)companionBanner;

/**
 @discussion Starts preroll for the ad.
 */
- (void)startPreroll;

/**
 @discussion Starts postroll for the ad.
 */
- (void)startPostroll;

/**
 @discussion Starts pauseroll for the ad.
 */
- (void)startPauseroll;

/**
 @discussion Starts midroll for the ad at the point.
 
 @param point Point to start midroll.
 */
- (void)startMidrollWithPoint:(NSNumber *)point;

/**
 @discussion Method to cofigure midpoints for the ad.
 
 @param midpointsP Array of midpoints.
 @param audioDuration Duration of the audio ad.
 */
- (void)configureMidpointsP:(nullable NSArray<NSNumber *> *)midpointsP forAudioDuration:(NSTimeInterval)audioDuration;

/**
 @discussion Method to cofigure midpoints for the ad.
 
 @param midpoints Array of midpoints.
 @param audioDuration Duration of the audio ad.
 */
- (void)configureMidpoints:(nullable NSArray<NSNumber *> *)midpoints forAudioDuration:(NSTimeInterval)audioDuration;

/**
 @discussion Method to cofigure midpoints for the ad.
 
 @param audioDuration Duration of the audio ad.
 */
- (void)configureMidpointsForAudioDuration:(NSTimeInterval)audioDuration;

@end

NS_ASSUME_NONNULL_END
