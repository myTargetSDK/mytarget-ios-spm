//
//  MTRGInterstitialAd.h
//  myTargetSDK 5.15.1
//
// Created by Timur on 3/5/18.
// Copyright (c) 2018 MailRu Group. All rights reserved.
//

#import <MyTargetSDK/MTRGBaseInterstitialAd.h>

@class MTRGInterstitialAd;

NS_ASSUME_NONNULL_BEGIN

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
 @discussion Call when there is no an ad. (Required)
 
 @param reason The reason why there is no an ad.
 @param interstitialAd Current ad.
 */
- (void)onNoAdWithReason:(NSString *)reason interstitialAd:(MTRGInterstitialAd *)interstitialAd;

@optional

/**
 @discussion Calls on click by the ad.
 
 @param interstitialAd Current ad.
 */
- (void)onClickWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls on close the ad.
 
 @param interstitialAd Current ad.
 */
- (void)onCloseWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls when video ad is complete.
 
 @param interstitialAd Current ad.
 */
- (void)onVideoCompleteWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls when interstitial ad was displayed.
 
 @param interstitialAd Current ad.
 */
- (void)onDisplayWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

/**
 @discussion Calls on leave application while ad is showing.
 
 @param interstitialAd Current ad.
 */
- (void)onLeaveApplicationWithInterstitialAd:(MTRGInterstitialAd *)interstitialAd;

@end

/**
 @discussion Class describes interstitial ad.
 */
@interface MTRGInterstitialAd : MTRGBaseInterstitialAd

/**
 @discussion Delegate for the ad. Must conforms MTRGInterstitialAdDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGInterstitialAdDelegate> delegate;

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
