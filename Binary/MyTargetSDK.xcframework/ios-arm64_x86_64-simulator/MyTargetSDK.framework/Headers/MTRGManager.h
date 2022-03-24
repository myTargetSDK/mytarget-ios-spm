//
//  MTRGManager.h
//  myTargetSDK 5.15.1
//
//  Created by Anton Bulankin on 18.09.15.
//  Copyright © 2015 Mail.ru. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MTRGConfig;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Main class to initialize the SDK and manage debug mode of the SDK
 */
@interface MTRGManager : NSObject

/**
 @discussion Instance of MTRGConfig
 */
@property(class, atomic, nonnull) MTRGConfig *sdkConfig;

/**
 @discussion Method to init the SDK
 */
+ (void)initSdk;

/**
 @discussion Method to define debug mode status
 
 @param enabled Flag of status of debug mode
 */
+ (void)setDebugMode:(BOOL)enabled;

/**
 @discussion Method to get bidder token.
 
 @return Bidder token as a NSString
 */
+ (NSString *)getBidderToken; // this method should be called on background thread

@end

NS_ASSUME_NONNULL_END
