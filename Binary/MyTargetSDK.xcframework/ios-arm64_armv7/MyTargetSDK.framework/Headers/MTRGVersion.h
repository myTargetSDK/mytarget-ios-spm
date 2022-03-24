//
//  MTRGVersion.h
//  myTargetSDK 5.15.1
//
//  Created by Andrey Seredkin on 29.06.17.
//  Copyright © 2017 Mail.ru Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Class to get current version of the SDK
 */
@interface MTRGVersion : NSObject

/**
 @discussion Method to get current version of SDK
 
 @return Version of SDK as NSString
 */
+ (NSString *)currentVersion;

@end

NS_ASSUME_NONNULL_END
