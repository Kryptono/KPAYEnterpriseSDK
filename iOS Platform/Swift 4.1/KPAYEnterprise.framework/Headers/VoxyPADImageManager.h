//
//  VoxyPADImageManager.h
//  VoxyPADFramework
//
//  Created by Hong Thai on 11/13/15.
//  Copyright © 2015 VoxyPAD Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VoxyPADFrameworkEnumDefine.h"

extern NSString *const UIImagePickerControllerTrueOrientationOriginImage;


@interface VoxyPADImageManager : NSObject

+ (VoxyPADImageManager *)sharedImageManager;

////////////////////////////////////////////////////////
////////// IPAD ////////////////////////////////////////
////////////////////////////////////////////////////////

//Capture photo
- (void)launchCamera_iPad_FromRect:(CGRect)sourceRect
                            inView:(UIView *)view
                     fromDirection:(UIPopoverArrowDirection)direction
         completePickingPhotoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                 cancelLaunchBlock:(void(^)(void))cancelBlock
                      failureBlock:(void(^)(BOOL allowAccess))errorBlock;

//Record video
- (void)launchCamera_iPad_FromRect:(CGRect)sourceRect
                            inView:(UIView *)view
                     fromDirection:(UIPopoverArrowDirection)direction
                      videoQuality:(UIImagePickerControllerQualityType)quality
          videoMaxDurationInSecond:(NSTimeInterval)maxDurationInSecond
       completeRecordingVideoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                 cancelLaunchBlock:(void(^)())cancelBlock
                      failureBlock:(void(^)(BOOL allowAccess, EnumVXPVideoRecordingError error))errorBlock;

//Pick photo
- (void)launchPhotoLibrary_iPad_FromRect:(CGRect)sourceRect
                                  inView:(UIView *)view
                           fromDirection:(UIPopoverArrowDirection)direction
               completePickingPhotoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                       cancelLaunchBlock:(void(^)(void))cancelBlock
                            failureBlock:(void(^)(BOOL allowAccess))errorBlock;

//Pick video
// -- maxDurationInSecond: Pass negative argument will cause automatic assign default duration (which is 10 minutes)
- (void)launchPhotoLibrary_iPad_FromRect:(CGRect)sourceRect
                                  inView:(UIView *)view
                           fromDirection:(UIPopoverArrowDirection)direction
               completePickingVideoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                       cancelLaunchBlock:(void(^)(void))cancelBlock
                            failureBlock:(void(^)(BOOL allowAccess))errorBlock;

- (void)launchPhotoLibrary_iPad_FromRect:(CGRect)sourceRect
                                  inView:(UIView *)view
                           fromDirection:(UIPopoverArrowDirection)direction
                            videoQuality:(UIImagePickerControllerQualityType)quality
                videoMaxDurationInSecond:(NSTimeInterval)maxDurationInSecond
               completePickingVideoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                       cancelLaunchBlock:(void(^)(void))cancelBlock
                            failureBlock:(void(^)(BOOL allowAccess))errorBlock;


////////////////////////////////////////////////////////
////////// IPHONE //////////////////////////////////////
////////////////////////////////////////////////////////

//Capture photo
- (void)launchCamera_iPhone_FromController:(UIViewController *)controller
                 completePickingPhotoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                         cancelLaunchBlock:(void(^)(void))cancelBlock
                              failureBlock:(void(^)(BOOL allowAccess))errorBlock;

//Record video
// -- maxDurationInSecond: Pass negative argument will cause automatic assign default duration (which is 10 minutes)
- (void)launchCamera_iPhone_FromController:(UIViewController *)controller
                              videoQuality:(UIImagePickerControllerQualityType)quality
                  videoMaxDurationInSecond:(NSTimeInterval)maxDurationInSecond
               completeRecordingVideoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                         cancelLaunchBlock:(void(^)(void))cancelBlock
                              failureBlock:(void(^)(BOOL allowAccess, EnumVXPVideoRecordingError error))errorBlock;

//Pick photo
- (void)launchPhotoLibrary_iPhone_FromController:(UIViewController *)controller
                       completePickingPhotoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                               cancelLaunchBlock:(void(^)(void))cancelBlock
                                    failureBlock:(void(^)(BOOL allowAccess))errorBlock;

//Pick video
- (void)launchPhotoLibrary_iPhone_FromController:(UIViewController *)controller
                       completePickingVideoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                               cancelLaunchBlock:(void(^)(void))cancelBlock
                                    failureBlock:(void(^)(BOOL allowAccess))errorBlock;

- (void)launchPhotoLibrary_iPhone_FromController:(UIViewController *)controller
                                    videoQuality:(UIImagePickerControllerQualityType)quality
                        videoMaxDurationInSecond:(NSTimeInterval)maxDurationInSecond
                       completePickingVideoBlock:(void(^)(NSDictionary *infoDictionary))successBlock
                               cancelLaunchBlock:(void(^)(void))cancelBlock
                                    failureBlock:(void(^)(BOOL allowAccess))errorBlock;


- (void)forceDismissImagePickerIfShowing;

@end
