//
//  MTRGNativeBanner.h
//  myTargetSDK 5.15.1
//
//  Created by Andrey Seredkin on 10/02/2020.
//  Copyright © 2020 Mail.Ru Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MyTargetSDK/MTRGNavigationType.h>

@class MTRGImageData;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Data model for a native banner.
 */
@interface MTRGNativeBanner : NSObject

/**
 @discussion Advertising label for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *advertisingLabel;

/**
 @discussion Age restrictions for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *ageRestrictions;

/**
 @discussion Title for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *title;

/**
 @discussion Description text for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *descriptionText;

/**
 @discussion Disclaimer for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *disclaimer;

/**
 @discussion Domain for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *domain;

/**
 @discussion CTA text for the banner.
 */
@property(nonatomic, readonly, copy, nullable) NSString *ctaText;

/**
 @discussion Rating value for the banner.
 */
@property(nonatomic, readonly, nullable) NSNumber *rating;

/**
 @discussion Votes value for the banner.
 */
@property(nonatomic, readonly) NSUInteger votes;

/**
 @discussion Navigation type for the banner.
 */
@property(nonatomic, readonly) MTRGNavigationType navigationType;

/**
 @discussion Icon's image data for the banner.
 */
@property(nonatomic, readonly, nullable) MTRGImageData *icon;

@end

NS_ASSUME_NONNULL_END
