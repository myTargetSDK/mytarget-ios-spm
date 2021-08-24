//
//  MTRGPromoCardCollectionView.h
//  myTargetSDK 5.13.0
//
//  Created by Andrey Seredkin on 02.11.16.
//  Copyright © 2016 Mail.ru Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MyTargetSDK/MTRGNativePromoCard.h>
#import <MyTargetSDK/MTRGPromoCardSliderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Class for promo card collection view.
 */
@interface MTRGPromoCardCollectionView : UICollectionView <MTRGPromoCardSliderProtocol, UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

/**
 @discussion Card slider's delegate. Must conforms MTRGPromoCardSliderDelegate protocol.
 */
@property (nonatomic, weak, nullable) id <MTRGPromoCardSliderDelegate> cardSliderDelegate;

/**
 @discussion Flag determines it is clickable or not.
 */
@property (nonatomic) BOOL isCardsClickable;

/**
 @discussion Static constructor. Creates instance of the class.
 
 @return Instance of the class.
 */
+ (instancetype)create;

/**
 @discussion Sets cards for the collection.
 
 @param cards Array of promo cards.
 */
- (void)setCards:(NSArray<MTRGNativePromoCard *> *)cards;

@end

NS_ASSUME_NONNULL_END
