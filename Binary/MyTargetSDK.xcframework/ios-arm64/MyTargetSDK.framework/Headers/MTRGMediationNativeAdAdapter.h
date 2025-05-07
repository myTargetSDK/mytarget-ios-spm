//
//  MTRGMediationNativeAdAdapter.h
//  myTargetSDK 5.30.0
//
// Copyright (c) 2019 Mail.Ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MyTargetSDK/MTRGMediationAdapter.h>
#import <MyTargetSDK/MTRGNativeAd.h>

@protocol MTRGMediationNativeAdConfigProtocol;
@protocol MTRGMediationNativeAdAdapter;
@protocol MTRGMediationNativeAdMediaDelegate;
@protocol MTRGMediationNativeAdChoicesOptionDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Protocol for mediation of native ad delegates.
 */
@protocol MTRGMediationNativeAdDelegate <NSObject>

/**
 @discussion Calls on load ad with promo banner.
 
 @param promoBanner Loaded banner.
 @param adapter Current adapter.
 */
- (void)onLoadWithNativePromoBanner:(MTRGNativePromoBanner *)promoBanner
							adapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Calls if there is no ad.

 @param error An error code/description.
 @param adapter Current adapter.
 */
- (void)onLoadFailedWithError:(NSError *)error
					  adapter:(id <MTRGMediationNativeAdAdapter>)adapter NS_SWIFT_NAME(onLoadFailed(error:adapter:));

/**
 @discussion Calls when ad shows for the adapter
 
 @param adapter Current adapter.
 */
- (void)onAdShowWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Calls on modal show the ad.
 
 @param adapter Current adapter.
 */
- (void)onShowModalWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Calls on modal dismiss.
 
 @param adapter Current adapter.
 */
- (void)onDismissModalWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Call on leave application.
 
 @param adapter Current adapter.
 */
- (void)onLeaveApplicationWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Calls if video is playing.
 
 @param adapter Current adapter.
 */
- (void)onVideoPlayWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Calls if video was paused.
 
 @param adapter Current adapter.
 */
- (void)onVideoPauseWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Calls if video was completed.
 
 @param adapter Current adapter.
 */
- (void)onVideoCompleteWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

@optional
/**
 @discussion Calls if there is no ad.

 @param reason The reason why there is no ad.
 @param adapter Current adapter.
 */
- (void)onNoAdWithReason:(NSString *)reason
				 adapter:(id <MTRGMediationNativeAdAdapter>)adapter __attribute__((deprecated("use onLoadFailed method instead.")));

/**
 @discussion Calls when video is ready to play.

 @param adapter Current adapter.
 */
- (void)onVideoReadyWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter;

/**
 @discussion Call on click by the ad.
 
 @param adapter Current adapter.
 */
- (void)onAdClickWithAdapter:(id <MTRGMediationNativeAdAdapter>)adapter __attribute__((deprecated("use onAdClickWithClickedView: adapter: instead.")));

/**
 @discussion Call on click by the ad.
 @param clickedView View that was clicked.
 @param adapter Current adapter.
 */
- (void)onAdClickWithClickedView:(nullable UIView *)clickedView adapter:(id <MTRGMediationNativeAdAdapter>)adapter;

@end

/**
 @discussion Protocol for native ad adapters.
 */
@protocol MTRGMediationNativeAdAdapter <MTRGMediationAdapter>

/**
 @discussion Delegate of the adapter. Must conforms MTRGMediationNativeAdDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGMediationNativeAdDelegate> delegate;

/**
 @discussion Load the adapter with configuration.
 
 @param mediationAdConfig Mediation's configuration.
 */
- (void)loadWithMediationAdConfig:(id <MTRGMediationNativeAdConfigProtocol>)mediationAdConfig NS_SWIFT_NAME(load(with:));

/**
 @discussion Registers view for the adapter.
 
 @param containerView View for the adapter.
 @param controller Controller for the adapter.
 @param clickableViews Array of view which will be clickable.
 @param adChoicesPlacement Ad choices for the adapter.
 */
- (void)registerView:(UIView *)containerView
	  withController:(UIViewController *)controller
  withClickableViews:(nullable NSArray<UIView *> *)clickableViews
  adChoicesPlacement:(MTRGAdChoicesPlacement)adChoicesPlacement;

/**
 @discussion Unregisters view.
 */
- (void)unregisterView;

/**
 @discussion Returns media view.
 
 @return Instance of UIView.
 */
- (nullable UIView *)mediaView;

@optional

/**
 @discussion Method to handle adChoices click. Used when the user controls adChoices himself.

 @param viewController Used UIViewController.
 @param sourceView UIView for iPad popover.
 */
- (void)handleAdChoicesClickWithController:(UIViewController *)viewController sourceView:(nullable UIView *)sourceView NS_SWIFT_NAME(handleAdChoicesClick(controller:sourceView:));

/**
 @discussion Setter for media delegate of the adapter. Must conforms MTRGMediationNativeAdMediaDelegate protocol.

 @param mediaDelegate Media delegate of the adapter.
 */
- (void)setMediaDelegate:(nullable id <MTRGMediationNativeAdMediaDelegate>)mediaDelegate;

/**
 @discussion Setter for AdChoicesOptionDelegate of the adapter. Must conforms MTRGMediationNativeAdChoicesOptionDelegate protocol.

 @param adChoicesOptionDelegate AdChoicesOptionDelegate of the adapter.
 */
- (void)setAdChoicesOptionDelegate:(nullable id <MTRGMediationNativeAdChoicesOptionDelegate>)adChoicesOptionDelegate;

/**
 @discussion Method to handle  click. Used when the user controls click himself. For private use only.

 @param isCta This parameter shows click on cta button.
 */
- (void)handleClick:(BOOL)isCta;

@end

NS_ASSUME_NONNULL_END
