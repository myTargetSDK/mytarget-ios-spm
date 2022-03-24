//
//  MTRGAdView.h
//  myTargetSDK 5.15.1
//
// Created by Timur on 3/22/18.
// Copyright (c) 2018 Mail.Ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MTRGAdView;
@class MTRGAdSize;
@class MTRGCustomParams;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Protocol describes interface for MTRGAdView delegate.
 */
@protocol MTRGAdViewDelegate <NSObject>

/**
@discussion Calls on load the ad view. Required.

@param adView Loaded ad view.
*/
- (void)onLoadWithAdView:(MTRGAdView *)adView;

/**
 @discussion Calls when there is no ad for ad view. Required.
 
 @param reason String with a reason.
 @param adView Current ad view.
 */
- (void)onNoAdWithReason:(NSString *)reason adView:(MTRGAdView *)adView;

@optional

/**
 @discussion Calls on click.
 
 @param adView Instance of MTRGAdView which detects click.
 */
- (void)onAdClickWithAdView:(MTRGAdView *)adView;

/**
 @discussion Calls on show ad.
 
 @param adView Instance of MTRGAdView which shows ad.
 */
- (void)onAdShowWithAdView:(MTRGAdView *)adView;

/**
 @discussion Calls on modal show.
 
 @param adView Instance of MTRGAdView which shows modal.
 */
- (void)onShowModalWithAdView:(MTRGAdView *)adView;

/**
 @discussion Calls on modal dismiss.
 
 @param adView Instance of MTRGAdView which dismiss modal.
 */
- (void)onDismissModalWithAdView:(MTRGAdView *)adView;

/**
 @discussion Calls on leave application.
 
 @param adView Instance of MTRGAdView while leave application.
 */
- (void)onLeaveApplicationWithAdView:(MTRGAdView *)adView;

@end

/**
 @discussion Class describes view which contains ad.
 */
@interface MTRGAdView : UIView

/**
 @discussion Instance conforms MTRGAdViewDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGAdViewDelegate> delegate;

/**
 @discussion Instance of UIViewController which hosts the view.
 */
@property(nonatomic, weak, nullable) UIViewController *viewController;

/**
 @discussion Custom parameters of the view.
 */
@property(nonatomic, readonly) MTRGCustomParams *customParams;

/**
 @discussion Flag determines mediation status.
 */
@property(nonatomic) BOOL mediationEnabled;

/**
 @discussion Ad size.
 */
@property(nonatomic) MTRGAdSize *adSize;

/**
 @discussion Slot identifier.
 */
@property(nonatomic, readonly) NSUInteger slotId;

/**
 @discussion Flag determines should ad be refreshed or not.
 */
@property(nonatomic, readonly) BOOL shouldRefreshAd;

/**
 @discussion String contains ad source.
 */
@property(nonatomic, readonly, nullable) NSString *adSource;

/**
 @discussion Ad source priority.
 */
@property(nonatomic, readonly) float adSourcePriority;

/**
@discussion Static constructor. Creates view with slot identifier.

@param slotId Slot identifier.
 
@return Instance of MTRGAdView.
*/
+ (instancetype)adViewWithSlotId:(NSUInteger)slotId;

/**
 @discussion Static constructor. Creates view with slot identifier and flag for ad refresh.
 
 @param slotId Slot identifier.
 @param shouldRefreshAd Flag determines should ad be refreshed or not.
 
 @return Instance of MTRGAdView.
 */
+ (instancetype)adViewWithSlotId:(NSUInteger)slotId shouldRefreshAd:(BOOL)shouldRefreshAd;

/**
 @discussion Load the view.
 */
- (void)load;

/**
 @discussion Load the view with bid identifier.
 
 @param bidId Bid identifier.
 */
- (void)loadFromBid:(NSString *)bidId;

@end

NS_ASSUME_NONNULL_END
