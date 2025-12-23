//
//  MTRGPrivacyProtocol.h
//  myTargetSDK 5.37.5
//
//  Created by Andrey Seredkin on 14.03.2024.
//  Copyright © 2024 VK. All rights reserved.
//

@protocol MTRGPrivacyProtocol <NSObject>

/**
 @discussion Flag of user's consent
 */
@property(nonatomic, readonly) BOOL isConsent;

/**
 @discussion Age of restriction
 */
@property(nonatomic, readonly) BOOL userAgeRestricted;

/**
 @discussion User's consent
 */
@property(nonatomic, readonly, nullable) NSNumber *userConsent;

/**
 @discussion User's ccpa consent
 */
@property(nonatomic, readonly, nullable) NSNumber *ccpaUserConsent;

/**
 @discussion User's AB consent
 */
@property(nonatomic, readonly, nullable) NSNumber *iABUserConsent;

@end
