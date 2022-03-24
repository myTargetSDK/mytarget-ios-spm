//
//  MTRGNativeAdLoader.h
//  myTargetSDK 5.15.1
//
//  Created by Andrey Seredkin on 31.05.2018.
//  Copyright © 2018 Mail.Ru Group. All rights reserved.
//

#import <MyTargetSDK/MTRGNativeAd.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Class-loader for native ad
 */
@interface MTRGNativeAdLoader : MTRGBaseAd

/**
 @discussion Cache policy for the native ad.
 */
@property(nonatomic) MTRGCachePolicy cachePolicy;

/**
 @discussion Placement for ad choices.
 */
@property(nonatomic) MTRGAdChoicesPlacement adChoicesPlacement;

/**
 @discussion Static constructor. Creates instance of the class with count and slot identifier.
 
 @param count Count to load
 @param slotId Slot identifier.
 
 @return Instance of the class
 */
+ (instancetype)loaderForCount:(NSUInteger)count slotId:(NSUInteger)slotId;

- (instancetype)init NS_UNAVAILABLE;

/**
 @discussion Method loads ad.
 
 @param completionBlock Block which will be called on load.
 */
- (void)loadWithCompletionBlock:(void (^)(NSArray<MTRGNativeAd *> *nativeAds))completionBlock;

@end

NS_ASSUME_NONNULL_END
