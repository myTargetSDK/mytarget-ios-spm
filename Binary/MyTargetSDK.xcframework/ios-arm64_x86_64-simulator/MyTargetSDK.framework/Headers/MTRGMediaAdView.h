//
//  MTRGMediaAdView.h
//  myTargetSDK 5.31.2
//
//  Created by Andrey Seredkin on 19.08.16.
//  Copyright © 2016 Mail.ru. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MTRGMediaAdView;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Protocol for media view delegate.
 */
@protocol MTRGMediaAdViewDelegate <NSObject>

/**
 @discussion Calls on image size change.
 
 @param mediaAdView Current media ad view.
 */
- (void)onImageSizeChanged:(MTRGMediaAdView *)mediaAdView;

@end

/**
 @discussion Media ad view.
 */
@interface MTRGMediaAdView : UIView

/**
 @discussion Delegate for media view. Must conforms MTRGMediaAdViewDelegate protocol.
 */
@property(nonatomic, weak, nullable) id <MTRGMediaAdViewDelegate> delegate;

/**
 @discussion Aspect ratio for the media view.
 */
@property(nonatomic, readonly) CGFloat aspectRatio;

/**
 @discussion Image view container.
 */
@property(nonatomic, readonly) UIImageView *imageView;

/**
 @discussion Image view for the play image
 */
@property(nonatomic, readonly) UIImageView *playImageView;

/**
 @discussion Activity indicator for the media view.
 */
@property(nonatomic, readonly) UIActivityIndicatorView *activityIndicatorView;

/**
 @discussion Collage image views or empty NSArray, if the media view does not contain collage.
 This property available after adView registration.
 */
@property(nonatomic, readonly) NSArray<UIImageView *> *collageImageViews;

/**
 @discussion Static contstructor of the class.
 
 @return Instance of the class.
 */
+ (instancetype)create;

/**
 @discussion Method for collage size
 */
- (CGSize)collageSizeForAvailableSize:(CGSize)availableSize;

@end

NS_ASSUME_NONNULL_END
