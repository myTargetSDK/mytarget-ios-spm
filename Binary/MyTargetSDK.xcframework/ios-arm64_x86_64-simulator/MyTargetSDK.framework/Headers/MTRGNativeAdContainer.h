//
//  MTRGNativeAdContainer.h
//  myTargetSDK 5.31.2
//
//  Created by Andrey Seredkin on 21/05/2019.
//  Copyright © 2019 Mail.Ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Container for the native ad.
 */
@interface MTRGNativeAdContainer : UIView

/**
 @discussion Ad view.
 */
@property(nonatomic, nullable) UIView *adView;

/**
 @discussion Advertising view. This property is required. Please provide it in accordance with the advertising regulations.
 */
@property(nonatomic, nullable) UIView *advertisingView;

/**
 @discussion View for displaying age restrictions. This property is required. Please provide it in accordance with the advertising regulations.
 */
@property(nonatomic, nullable) UIView *ageRestrictionsView;

/**
 @discussion View with title.
 */
@property(nonatomic, nullable) UIView *titleView;

/**
 @discussion View with description.
 */
@property(nonatomic, nullable) UIView *descriptionView;

/**
 @discussion View with category.  Properties: `categoryView` and `domainView` – are required. Please provide one of it in accordance with the advertising regulations.
 */
@property(nonatomic, nullable) UIView *categoryView;

/**
 @discussion View with icon. This property is required. Please provide it in accordance with the advertising regulations.
 */
@property(nonatomic, nullable) UIView *iconView;

/**
 @discussion View with media.
 */
@property(nonatomic, nullable) UIView *mediaView;

/**
 @discussion View with rating.
 */
@property(nonatomic, nullable) UIView *ratingView;

/**
 @discussion View with votes.
 */
@property(nonatomic, nullable) UIView *votesView;

/**
 @discussion View with domain. Properties: `categoryView` and `domainView` – are required. Please provide one of it in accordance with the advertising regulations.
 */
@property(nonatomic, nullable) UIView *domainView;

/**
 @discussion View with disclaimer. This property is required. Please provide it in accordance with the advertising regulations.
 */
@property(nonatomic, nullable) UIView *disclaimerView;

/**
 @discussion View with CTA.
 */
@property(nonatomic, nullable) UIView *ctaView;

/**
 @discussion View with adChoices. Please provide it when use MTRGAdChoicesPlacementDrawingManual
 */
@property(nonatomic, nullable) UIView *adChoicesView;

/**
 @discussion Static constructor. Creates instance of the class.
 
 @param adView View for the ad.
 
 @return Instance of the class.
 */
+ (instancetype)createWithAdView:(UIView *)adView;

@end

NS_ASSUME_NONNULL_END
