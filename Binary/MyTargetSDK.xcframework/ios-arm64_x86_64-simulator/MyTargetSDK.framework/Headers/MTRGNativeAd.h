//
//  MTRGNativeAd.h
//  myTargetSDK 5.15.1
//
// Created by Timur on 2/1/18.
// Copyright (c) 2018 Mail.Ru Group. All rights reserved.
//

#import <MyTargetSDK/MTRGBaseAd.h>
#import <MyTargetSDK/MTRGNativeAdProtocol.h>

@class MTRGNativeAd;
@class MTRGNativePromoBanner;
@class MTRGImageData;

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
 @discussion Calls if there is no ad. (Required)
 
 @param reason The reason why there is no ad.
 @param nativeAd Current ad.
 */
- (void)onNoAdWithReason:(NSString *)reason nativeAd:(MTRGNativeAd *)nativeAd;

@optional

/**
 @discussion Class on show the native ad.
 
 @param nativeAd Current ad.
 */
- (void)onAdShowWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls on click by native ad.
 
 @param nativeAd Current ad.
 */
- (void)onAdClickWithNativeAd:(MTRGNativeAd *)nativeAd;

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

/**
 @discussion Calls when video plays with current ad.
 
 @param nativeAd Current ad.
 */
- (void)onVideoPlayWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when video pauses with current ad.
 
 @param nativeAd Current ad.
 */
- (void)onVideoPauseWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when video completes with current ad.
 
 @param nativeAd Current ad.
 */
- (void)onVideoCompleteWithNativeAd:(MTRGNativeAd *)nativeAd;

@end

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

@end

/**
 @discussion Base class for native ad.
 */
@interface MTRGNativeAd : MTRGBaseAd <MTRGNativeAdProtocol>

/**
 @discussion Placement for ad choices.
 */
@property(nonatomic) MTRGAdChoicesPlacement adChoicesPlacement;

/**
 @discussion Delegate for the ad. Must conforms MTRGNativeAdDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGNativeAdDelegate> delegate;

/**
 @discussion Delegate for the media of the ad. Must conforms MTRGNativeAdMediaDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGNativeAdMediaDelegate> mediaDelegate;

/**
 @discussion Promo banner for the ad.
 */
@property(nonatomic, readonly, nullable) MTRGNativePromoBanner *banner;

/**
 @discussion Static constructor. Create instance of the class with slot identifier.
 
 @param slotId Slot identifier.
 
 @return Instance of the class.
 */
+ (instancetype)nativeAdWithSlotId:(NSUInteger)slotId;

- (instancetype)init NS_UNAVAILABLE;

/**
 @discussion Create instance of the class with slot identifier.
 
 @param slotId Slot identifier.
 
 @return Instance of the class.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId;

/**
 @discussion Loads the ad.
 */
- (void)load;

/**
 @discussion Loads the ad from bid identifier.
 
 @param bidId Bid identifier for the ad.
 */
- (void)loadFromBid:(NSString *)bidId;

/**
 @discussion Registers view for the ad.
 
 @param containerView View for the ad.
 @param controller Controller for the ad.
 */
- (void)registerView:(UIView *)containerView withController:(UIViewController *)controller;

/**
 @discussion Registers view for the ad.
 
 @param containerView View for the ad.
 @param controller Controller for the ad.
 @param clickableViews Array of clickable views.
 */
- (void)registerView:(UIView *)containerView
	  withController:(UIViewController *)controller
  withClickableViews:(nullable NSArray<UIView *> *)clickableViews;

/**
 @discussion Unregister view for the ad.
 */
- (void)unregisterView;

@end

NS_ASSUME_NONNULL_END
