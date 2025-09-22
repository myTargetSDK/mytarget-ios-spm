//
//  MTRGMediationAdConfigProtocol.h
//  myTargetSDK 5.35.1
//
//  Created by Andrey Seredkin on 11.03.2024.
//  Copyright © 2024 VK. All rights reserved.
//

#import <MyTargetSDK/MTRGCustomParams.h>

@protocol MTRGPrivacyProtocol;
@protocol MTRGAdNetworkConfigProtocol;

@protocol MTRGMediationAdConfigProtocol <NSObject>

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

@end
