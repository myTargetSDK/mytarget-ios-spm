//
//  MTRGNativeBannerAd.h
//  myTargetSDK 5.39.1
//
//  Created by Andrey Seredkin on 10/02/2020.
//  Copyright © 2020 Mail.Ru Group. All rights reserved.
//

#import <MyTargetSDK/MTRGBaseAd.h>
#import <MyTargetSDK/MTRGNativeAdProtocol.h>
#import <MyTargetSDK/MTRGNativeBannerAdDelegate.h>
#import <MyTargetSDK/MTRGNativeBannerAdMediaDelegate.h>

@class MTRGNativeBannerAd;
@class MTRGNativeBanner;
@class MTRGImageData;
@class MTRGBannerMediaRecovery;
@protocol MTRGMenuFactory;
@protocol MTRGNativeBannerAdChoicesOptionDelegate;

NS_ASSUME_NONNULL_BEGIN

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
 @discussion Delegate for the AdChoices options. Must conforms MTRGNativeBannerAdChoicesOptionDelegate protocol.
 See MTRGNativeBannerAdChoicesOptionDelegate.h
 */
@property(nonatomic, weak, nullable) id <MTRGNativeBannerAdChoicesOptionDelegate> adChoicesOptionDelegate;

/**
 @discussion Recovery option for media downloads in banner.
 */
@property(nonatomic, nonnull) MTRGBannerMediaRecovery *bannerMediaRecovery;

/**
 @discussion Timeout for media downloads in banner.
 */
@property(nonatomic) NSTimeInterval bannerMediaTimeout;

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

/**
 @discussion Static constructor. Creates instance of the class with slot identifier and menu factory.

 @param slotId Slot identifier.
 @param adChoicesMenuFactory AdChoices menu factory.

 @return Instance of the class.
 */
+ (instancetype)nativeBannerAdWithSlotId:(NSUInteger)slotId adChoicesMenuFactory:(id<MTRGMenuFactory>)adChoicesMenuFactory;

- (instancetype)init NS_UNAVAILABLE;

/**
 @discussion Creates instance of the class with slot identifier.
 
 @param slotId Slot identifier.
 
 @return Instance of the class.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId;

/**
 @discussion Creates instance of the class with slot identifier and menu factory.

 @param slotId Slot identifier.
 @param adChoicesMenuFactory AdChoices menu factory.

 @return Instance of the class.
 */
- (instancetype)initWithSlotId:(NSUInteger)slotId adChoicesMenuFactory:(id<MTRGMenuFactory>)adChoicesMenuFactory;

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

/**
 @discussion Method to handle adChoices click.

 @param viewController Used UIViewController.
 @param sourceView UIView for iPad popover.
 */
- (void)handleAdChoicesClickWithController:(UIViewController *)viewController sourceView:(nullable UIView *)sourceView NS_SWIFT_NAME(handleAdChoicesClick(controller:sourceView:));

@end

NS_ASSUME_NONNULL_END
