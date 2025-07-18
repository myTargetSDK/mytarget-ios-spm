//
//  MTRGPromoCardSliderProtocol.h
//  myTargetSDK 5.31.2
//
//  Created by Andrey Seredkin on 24.11.17.
//  Copyright © 2017 Mail.ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MTRGNativePromoCard;

/**
 @discussion Delegate's protocol for promo card slider.
 */
@protocol MTRGPromoCardSliderDelegate <NSObject>

/**
 @discussion Call on slide to visible cards. (Required)
 
 @param cards Array of visible cards.
 */
- (void)onSlideToVisibleCards:(NSArray<MTRGNativePromoCard *> *)cards;

@optional

/**
 @discussion Calls on card's render.
 
 @param card Rendered card.
 */
- (void)onRenderCard:(MTRGNativePromoCard *)card;

/**
 @discussion Calls on card click. (Required)
 
 @param card Clicked card.
 */
- (void)onCardClick:(MTRGNativePromoCard *)card __attribute__((deprecated("use onCardClick: clickedView: instead.")));

/**
 @discussion Calls on cta button click.

 @param card Clicked card.
 */
- (void)onCtaButtonClickWithCard:(MTRGNativePromoCard *)card __attribute__((deprecated("use onCtaButtonClickWithCard: clickedView: instead.")));

/**
 @discussion Calls on cta button click.

 @param card Clicked card.
 @param clickedView View that was clicked.
 */
- (void)onCtaButtonClickWithCard:(MTRGNativePromoCard *)card clickedView:(nullable UIView *)clickedView;

/**
@discussion Calls on card click.
 
@param card Clicked card.
@param clickedView View that was clicked.
*/
- (void)onCardClick:(MTRGNativePromoCard *)card clickedView:(nullable UIView *)clickedView;

@end

/**
 @discussion Protocol for card slider state.
 */
@protocol MTRGPromoCardSliderStateProtocol <NSObject>

@end

/**
 @discussion Protocol for card slider class.
 */
@protocol MTRGPromoCardSliderProtocol <NSObject>

/**
 @discussion Card slider delegate. Must conforms MTRGPromoCardSliderDelegate protocol.
 */
@property (nonatomic, weak, nullable) id <MTRGPromoCardSliderDelegate> cardSliderDelegate;

/**
 @discussion Flag determines it is clickable slider or not.
 */
@property (nonatomic) BOOL isCardsClickable;

/**
 @discussion Sets cards for the slider.
 
 @param cards Array of promo cards.
 */
- (void)setCards:(NSArray<MTRGNativePromoCard *> *)cards;

/**
 @discussion Returns array of visible cards in the slider.
 
 @return Array of MTRGNativePromoCard.
 */
- (NSArray<MTRGNativePromoCard *> *)visibleCards;

@optional

/**
 @discussion State of cards in collection.
 */
@property (nonatomic) id <MTRGPromoCardSliderStateProtocol> sliderState;

@end

NS_ASSUME_NONNULL_END
