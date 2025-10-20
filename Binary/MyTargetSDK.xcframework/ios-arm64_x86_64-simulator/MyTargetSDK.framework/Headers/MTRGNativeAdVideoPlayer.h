//
//  MTRGNativeAdVideoPlayer.h
//  myTargetSDK 5.36.1
//
//  Created by Sharin Anton on 17.03.2025.
//  Copyright © 2025 VK. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol MTRGNativeAdVideoPlayer <NSObject>
/**
 * Method for setting volume on to native ad video
 */
- (void)setVolumeOn;
/**
 * Method for setting volume off to native ad video
 */
- (void)setVolumeOff;
/**
 * Method for playing native ad video
 */
- (void)play;
/**
 * Method for pausing native ad video
 */
- (void)pause;
/**
 * Method for replaying native ad video
 */
- (void)replay;
/**
+ * Method for stop native ad video
+ */
- (void)stop;
/**
 * Method for getting native ad player volume state
 */
- (BOOL)isVolumeOn;
/**
 * Method for getting native ad player is ready to play.
 */
- (BOOL)isVideoReady;

@end

NS_ASSUME_NONNULL_END
