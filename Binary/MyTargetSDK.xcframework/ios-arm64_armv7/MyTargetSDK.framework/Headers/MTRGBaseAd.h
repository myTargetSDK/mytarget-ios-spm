//
//  MTRGBaseAd.h
//  myTargetSDK 5.15.1
//
// Created by Timur on 2/1/18.
// Copyright (c) 2018 Mail.Ru Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MTRGCustomParams;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Base class of ad.
 */
@interface MTRGBaseAd : NSObject

/**
 @discussion Custom parameters
 */
@property(nonatomic, readonly) MTRGCustomParams *customParams;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
