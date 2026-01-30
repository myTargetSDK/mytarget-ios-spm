//
//  MTRGPromoCardViewProtocol.h
//  myTargetSDK 5.39.1
//
//  Created by Andrey Seredkin on 20.10.16.
//  Copyright © 2016 Mail.Ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MTRGMediaAdView;

/**
 @discussion Delegate's protocol for promo card view.
 */
@protocol MTRGPromoCardViewDelegate <NSObject>

@optional

/**
 @discussion Calls on cta button click.

 @param cardIndex Index of the current card.
 */
- (void)onCtaButtonClickAtCardIndex:(NSInteger)cardIndex __attribute__((deprecated("use onCtaButtonClickAtCardIndex: clickedView: instead.")));

/**
 @discussion Calls on cta button click.
 
 @param cardIndex Index of the current card.
 @param clickedView View that was clicked.
 */
- (void)onCtaButtonClickAtCardIndex:(NSInteger)cardIndex clickedView:(nullable UIView *)clickedView;

@end

/**
 @discussion Protocol for promo card views.
 */
@protocol MTRGPromoCardViewProtocol <NSObject>

@required

/**
 @discussion Label for a title.
 */
@property(nonatomic, readonly) UILabel *titleLabel;

/**
 @discussion Label for a description.
 */
@property(nonatomic, readonly) UILabel *descriptionLabel;

/**
 @discussion Label for a CTA button.
 */
@property(nonatomic, readonly) UILabel *ctaButtonLabel;

/**
 @discussion Media view.
 */
@property(nonatomic, readonly) MTRGMediaAdView *mediaAdView;

/**
 @discussion Returns height of the card for a width.
 
 @param width Width of the card.
 
 @return Calculated height.
 */
- (CGFloat)heightWithCardWidth:(CGFloat)width;

@optional

@property(nonatomic) NSInteger cardIndex;

@property(nonatomic, weak, nullable) id<MTRGPromoCardViewDelegate> cardViewDelegate;

@end

NS_ASSUME_NONNULL_END
