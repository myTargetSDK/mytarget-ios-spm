//
//  MTRGNativeAdWebViewDelegate.h
//  myTargetSDK 5.35.0
//
//  Created by Seredkin Andrey on 06.08.2025.
//  Copyright © 2025 VK. All rights reserved.
//

@class MTRGNativeAd;

NS_ASSUME_NONNULL_BEGIN

/**
 @discussion Native ad WebView delegate protocol.
 */
@protocol MTRGNativeAdWebViewDelegate <NSObject>

/**
 @discussion Calls when WebView start loading.

 @param nativeAd Current ad.
 */
- (void)onWebViewDidStartLoadWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when WebView finish loading.

 @param nativeAd Current ad.
 */
- (void)onWebViewDidFinishLoadWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when WebView fail loading.

 @param nativeAd Current ad.
 */
- (void)onWebViewDidFailWithError:(NSError *)error nativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when user started interaction with WebView.

 @param nativeAd Current ad.
 */
- (void)onWebViewInteractionDidStartWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when user interacts with WebView.

 @param nativeAd Current ad.
 */
- (void)onWebViewInteractionDidChangeWithNativeAd:(MTRGNativeAd *)nativeAd;

/**
 @discussion Calls when user ended interaction with WebView.

 @param nativeAd Current ad.
 */
- (void)onWebViewInteractionDidEndWithNativeAd:(MTRGNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
