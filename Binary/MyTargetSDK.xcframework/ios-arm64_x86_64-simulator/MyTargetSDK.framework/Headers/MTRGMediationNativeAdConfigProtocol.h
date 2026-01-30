//
//  MTRGMediationNativeAdConfigProtocol.h
//  myTargetSDK 5.39.1
//
//  Created by Andrey Seredkin on 12.03.2024.
//  Copyright © 2024 VK. All rights reserved.
//

#import <MyTargetSDK/MTRGCachePolicy.h>
#import <MyTargetSDK/MTRGAdChoicesPlacement.h>
#import <MyTargetSDK/MTRGCustomParams.h>

@protocol MTRGPrivacyProtocol;
@protocol MTRGMenuFactory;
@protocol MTRGAdNetworkConfigProtocol;
@protocol MTRGMediationAdConfigProtocol;

@protocol MTRGMediationNativeAdConfigProtocol <MTRGMediationAdConfigProtocol>

/**
 @discussion Placement ID
 */
@property(nonatomic, readonly, copy, nonnull) NSString *placementId;

/**
 @discussion Payload
 */
@property(nonatomic, readonly, copy, nullable) NSString *payload;

/**
 @discussion Server parameters
 */
@property(nonatomic, readonly, nonnull) NSDictionary<NSString *, NSString *> *serverParams;

/**
 @discussion User's age
 */
@property(nonatomic, readonly, nullable) NSNumber *age;

/**
 @discussion User's gender
 */
@property(nonatomic, readonly) MTRGGender gender;

/**
 @discussion Instance of object MTRGPrivacy. Describes privacy settings
 */
@property(nonatomic, readonly, nonnull) id <MTRGPrivacyProtocol> privacy;

/**
 @discussion Additional data for mediation
 */
@property(nonatomic, readonly, nullable) id <MTRGAdNetworkConfigProtocol> adNetworkConfig;

/**
 @discussion Cache policy for the native ad.
 */
@property(nonatomic, readonly) MTRGCachePolicy cachePolicy;

/**
 @discussion Placement for ad choices.
 */
@property(nonatomic, readonly) MTRGAdChoicesPlacement adChoicesPlacement;

/**
 @discussion Menu factory for drawing adChoices menu manually. See MTRGMenuFactory protocol.
 */
@property(nonatomic, readonly, nonnull) id <MTRGMenuFactory> adChoicesMenuFactory;

@end
