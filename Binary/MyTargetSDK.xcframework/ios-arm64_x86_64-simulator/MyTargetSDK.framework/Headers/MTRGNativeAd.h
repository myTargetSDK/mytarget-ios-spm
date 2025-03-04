//
//  MTRGNativeAd.h
//  myTargetSDK 5.27.0
//
// Created by Timur on 2/1/18.
// Copyright (c) 2018 Mail.Ru Group. All rights reserved.
//

#import <MyTargetSDK/MTRGBaseAd.h>
#import <MyTargetSDK/MTRGNativeAdProtocol.h>
#import <MyTargetSDK/MTRGNativeAdDelegate.h>
#import <MyTargetSDK/MTRGNativeAdVideoDelegate.h>
#import <MyTargetSDK/MTRGNativeAdMediaDelegate.h>

@class MTRGNativeAd;
@class MTRGNativePromoBanner;
@class MTRGImageData;
@class MTRGBannerMediaRecovery;
@protocol MTRGMenuFactory;
@protocol MTRGNativeAdChoicesOptionDelegate;

NS_ASSUME_NONNULL_BEGIN

@protocol MTRGExternalClickHandler <NSObject>

- (BOOL)handleClickWithDeepLink:(nullable NSString *)deepLink
                           link:(nullable NSString *)link
                isOpenInBrowser:(BOOL)isOpenInBrowser;
@end

@protocol MTRGNativeAdVideoPlayer <NSObject>

/**
 * Method for setting volume on to native ad video
 */
- (void)setVolumeOn;
/**
 * Method for setting volume off to native ad video
 */
- (void)setVolumeOff;
/**
 * Method for playing native ad video
 */
- (void)play;
/**
 * Method for pausing native ad video
 */
- (void)pause;
/**
 * Method for replaying native ad video
 */
- (void)replay;
/**
 * Method for getting native ad player volume state
 */
- (BOOL)isVolumeOn;

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
 @discussion Delegate for the video of the ad. Must conforms MTRGNativeAdVideoDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGNativeAdVideoDelegate> videoDelegate;

/**
 @discussion Delegate for the media of the ad. Must conforms MTRGNativeAdMediaDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGNativeAdMediaDelegate> mediaDelegate;

/**
 @discussion Delegate for the AdChoices options. Must conforms MTRGNativeAdChoicesOptionDelegate protocol.
 See MTRGNativeAdChoicesOptionDelegate.h
 */
@property(nonatomic, weak, nullable) id <MTRGNativeAdChoicesOptionDelegate> adChoicesOptionDelegate;

/**
 @discussion Recovery option for media downloads in banner.
 */
@property(nonatomic, nonnull) MTRGBannerMediaRecovery *bannerMediaRecovery;

/**
 @discussion Timeout for media downloads in banner.
 */
@property(nonatomic) NSTimeInterval bannerMediaTimeout;

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

/**
 @discussion Static constructor. Create instance of the class with slot identifier and menu factory.

 @param slotId Slot identifier.
 @param adChoicesMenuFactory Menu factory for drawing adChoices menu manually. See MTRGMenuFactory protocol.

 @return Instance of the class.
 */
+ (instancetype)nativeAdWithSlotId:(NSUInteger)slotId adChoicesMenuFactory:(id<MTRGMenuFactory>)adChoicesMenuFactory;

- (instancetype)init NS_UNAVAILABLE;

/**
 @discussion Create instance of the class with slot identifier.
 
 @param slotId Slot identifier.
 
 @return Instance of the class.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId;

/**
 @discussion Create instance of the class with slot identifier.

 @param slotId Slot identifier.
 @param adChoicesMenuFactory Menu factory for drawing adChoices menu manually. See MTRGMenuFactory protocol.

 @return Instance of the class.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId adChoicesMenuFactory:(id<MTRGMenuFactory>)adChoicesMenuFactory;

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

/**
 @discussion Method to handle adChoices click.

 @param viewController Used UIViewController.
 @param sourceView UIView for iPad popover.
 */
- (void)handleAdChoicesClickWithController:(UIViewController *)viewController sourceView:(nullable UIView *)sourceView NS_SWIFT_NAME(handleAdChoicesClick(controller:sourceView:));

/**
 @discussion Method to set internal object.
 */
- (void)setInternalObject:(id)object;


/**
 @discussion Method to get native player.
 */
- (nullable id <MTRGNativeAdVideoPlayer>)getVideoPlayer;

@end

NS_ASSUME_NONNULL_END
