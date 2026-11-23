//
//  MTRGAdsLightPixelParamsProvider.h
//  myTargetSDK 5.49.0
//
//  Created by Roman Karmanov on 02.11.2026.
//  Copyright © 2026 VK. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Provider of additional params for ads_light pixels. For internal partners only.

 In contrast to setAdsLightPixelParams:type:, which passes a ready-made dictionary to the SDK,
 the provider is asked for params right before a pixel of the corresponding type is sent.
 */
@protocol MTRGAdsLightPixelParamsProvider <NSObject>

/**
 @discussion Called right before a pixel of the corresponding type is sent. May be called from any thread.

 @param type Type of the pixel.
 @return Dictionary with additional parameters for the pixel; or nil.
 */
- (nullable NSDictionary<NSString *, NSString *> *)provideParamsForType:(NSString *)type;

@end

NS_ASSUME_NONNULL_END
