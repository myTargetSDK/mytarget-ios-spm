//
//  MTRGNativeBannerAd.h
//  myTargetSDK 5.15.1
//
//  Created by Andrey Seredkin on 10/02/2020.
//  Copyright © 2020 Mail.Ru Group. All rights reserved.
//

#import <MyTargetSDK/MTRGBaseAd.h>
#import <MyTargetSDK/MTRGNativeAdProtocol.h>

@class MTRGNativeBannerAd;
@class MTRGNativeBanner;
@class MTRGImageData;

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
 @discussion Calls if there is no ad. (Required)
 
 @param reason The reason why there is no ad.
 @param nativeBannerAd Current ad.
 */
- (void)onNoAdWithReason:(NSString *)reason nativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

@optional

/**
 @discussion Class on show the native banner ad.
 
 @param nativeBannerAd Current banner ad.
 */
- (void)onAdShowWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

/**
 @discussion Calls on click by native banner ad.
 
 @param nativeBannerAd Current banner ad.
 */
- (void)onAdClickWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

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

@end

/**
 @discussion Banner media delegate's protocol.
 */
@protocol MTRGNativeBannerAdMediaDelegate <NSObject>

/**
 @discussion Call on load icon for native banner ad.
 
 @param nativeBannerAd Current banner ad.
 */
- (void)onIconLoadWithNativeBannerAd:(MTRGNativeBannerAd *)nativeBannerAd;

@end

/**
 @discussion Class of native banner ad.
 */
@interface MTRGNativeBannerAd : MTRGBaseAd <MTRGNativeAdProtocol>

/**
 @discussion Placement for ad choices.
 */
@property(nonatomic) MTRGAdChoicesPlacement adChoicesPlacement;

/**
 @discussion Delegate for the ad. Must conforms MTRGNativeBannerAdDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGNativeBannerAdDelegate> delegate;

/**
 @discussion Delegate for the media of the ad. Must conforms MTRGNativeBannerAdMediaDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGNativeBannerAdMediaDelegate> mediaDelegate;

/**
 @discussion Instance of native banner.
 */
@property(nonatomic, readonly, nullable) MTRGNativeBanner *banner;

/**
 @discussion Static constructor. Creates instance of the class with slot identifier.
 
 @param slotId Slot identifier.
 
 @return Instance of the class.
 */
+ (instancetype)nativeBannerAdWithSlotId:(NSUInteger)slotId;

- (instancetype)init NS_UNAVAILABLE;

/**
 @discussion Creates instance of the class with slot identifier.
 
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
 
 @param bidId Bid identifier.
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
