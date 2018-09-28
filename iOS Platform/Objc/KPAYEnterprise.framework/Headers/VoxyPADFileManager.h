//
//  VoxyPADFileManager.h
//  VoxyPADFramework
//
//  Created by Hong Thai on 11/11/15.
//  Copyright © 2015 VoxyPAD Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface VoxyPADFileManager : NSObject

+ (NSString *)getDocumentDirectory;
+ (BOOL)createDicrectoryInDocumentIfNeeded:(NSString *)dirName;

+ (NSString *)getLibraryCacheDirectory;
+ (BOOL)createDicrectoryInCacheIfNeeded:(NSString *)dirName;

+ (NSString *)getLibraryAppSupportDirectory;
+ (BOOL)createDicrectoryInAppSupportIfNeeded:(NSString *)dirName;

+ (BOOL)createDicrectoryIfNeeded:(NSString *)dirName atPath:(NSString *)srcPath;

+ (BOOL)deleteDirectoryAtPathIfExisted:(NSString *)path;
+ (BOOL)deleteFileAtPathIfExisted:(NSString *)path;

+ (UIImage *)imageFromDisk:(NSString *)fullPath;
+ (BOOL)saveImageToDisk:(UIImage *)image
               withPath:(NSString *)path
               fileName:(NSString *)filename
              extension:(NSString *)extension;


@end
