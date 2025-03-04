//
//  MTRGNativePromoBanner.h
//  myTargetSDK 5.27.0
//
// Created by Timur on 2/12/18.
// Copyright (c) 2018 Mail.Ru Group. All rights reserved.
//

#import <MyTargetSDK/MTRGNativeBanner.h>

@class MTRGNativePromoCard;
@class MTRGNativePromoCollage;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Data model for a promo banner.
 */
@interface MTRGNativePromoBanner : MTRGNativeBanner

/**
 @discussion Category for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *category;

/**
 @discussion Subcategory for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *subcategory;

/**
 @discussion Image data for the banner.
 */
@property(nonatomic, readonly, nullable) MTRGImageData *image;

/**
 @discussion Array of promo cards for the banner.
 */
@property(nonatomic, readonly) NSArray<MTRGNativePromoCard *> *cards;

/**
 @discussion Flag determines video existing for the banner.
 */
@property(nonatomic, readonly) BOOL hasVideo;

/**
 @discussion Identifier for the banner.
 */
@property(nonatomic, readonly) NSString *bannerId;

/**
 @discussion Video duration for the banner.
 */
@property(nonatomic, readonly) NSTimeInterval videoDuration;

/**
 @discussion Collage data for the banner.
 */
@property(nonatomic, readonly, nullable) MTRGNativePromoCollage *collage;

@end

NS_ASSUME_NONNULL_END
