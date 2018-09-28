//
//  VoxyPADMacroDefine.h
//  VoxyPADFramework
//
//  Created by VoxyPAD
//  Copyright (c) 2015 VoxyPAD Inc. All rights reserved.
//

#define VXP_SYSTEM_VERSION_EQUAL_TO(string_value)                  ([[[UIDevice currentDevice] systemVersion] compare:string_value options:NSNumericSearch] == NSOrderedSame)
#define VXP_SYSTEM_VERSION_GREATER_THAN(string_value)              ([[[UIDevice currentDevice] systemVersion] compare:string_value options:NSNumericSearch] == NSOrderedDescending)
#define VXP_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(string_value)  ([[[UIDevice currentDevice] systemVersion] compare:string_value options:NSNumericSearch] != NSOrderedAscending)
#define VXP_SYSTEM_VERSION_LESS_THAN(string_value)                 ([[[UIDevice currentDevice] systemVersion] compare:string_value options:NSNumericSearch] == NSOrderedAscending)
#define VXP_SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(string_value)     ([[[UIDevice currentDevice] systemVersion] compare:string_value options:NSNumericSearch] != NSOrderedDescending)

#define VXP_RELEASE_SAFELY(__pointer) {if(__pointer) {[__pointer release]; __pointer = nil;}}
#define VXP_INVALIDATE_TIMER(_timer)     if (_timer) {[_timer invalidate]; [_timer release]; _timer = nil;}

#define VXP_IS_IPHONE_4_PORTRAIT ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )480 ) < DBL_EPSILON )
#define VXP_IS_IPHONE_4_LANDSCAPE ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.width - ( double )480 ) < DBL_EPSILON )
#define VXP_IS_IPHONE_5_PORTRAIT ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )
#define VXP_IS_IPHONE_5_LANDSCAPE ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.width - ( double )568 ) < DBL_EPSILON )
#define VXP_IS_IPHONE_6_PORTRAIT ([UIScreen mainScreen].bounds.size.height > 660.0)
#define VXP_IS_IPHONE_6_LANDSCAPE ([UIScreen mainScreen].bounds.size.width > 660.0)
#define VXP_IS_IPHONE_6_PLUS_PORTRAIT ([UIScreen mainScreen].bounds.size.height > 720.0)
#define VXP_IS_IPHONE_6_PLUS_LANDSCAPE ([UIScreen mainScreen].bounds.size.width > 720.0)

#define VXP_DEVICE_IS_IPHONE    [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone
#define VXP_DEVICE_IS_IPAD       [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad
#define VXP_DEVICE_IS_IPAD_PRO  VXP_DEVICE_IS_IPAD && (CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(1366, 1024)) || CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(1024, 1366)))

//Color
#define VXP_RGBCOLOR(r, g, b) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:1.0f]
#define VXP_ARGBCOLOR(r, g, b, a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define VXP_FRGBCOLOR(fr, fg, fb) [UIColor colorWithRed:fr green:fg blue:fb alpha:1.0f]
#define HVXP_EXCOLOR(hexValue) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:1.0]
#define VXP_HEXCOLOR_ALPHA(hexValue, a) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:a]


//User Default
#define VXP_SAVE_TO_USER_DEFAULT(_obj, _key) {NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];[defaults setObject:_obj forKey:_key];[defaults synchronize];}
#define VXP_GET_FROM_USER_DEFAULT(_key) [[NSUserDefaults standardUserDefaults] objectForKey:_key]
#define VXP_REMOVE_FROM_USER_DEFAULT(_key) {NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];[defaults removeObjectForKey:_key];[defaults synchronize];}

//Utils
#define VXP_IS_RETINA           [[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] && ([UIScreen mainScreen].scale ==2.0)
#define VXP_IMAGE_EXT_FOR_RETINA    VXP_IS_RETINA?@"@2x":@""
#define VXP_NSNUMBER_INT(__i)       [NSNumber numberWithInt:__i]
#define VXP_NSNUMBER_FLOAT(__f)       [NSNumber numberWithFloat:__f]
#define VXP_NSStringFromInt(__i)        [NSString stringWithFormat:@"%d",__i]

//
#define VXP_GET_MAIN_WINDOW [[UIApplication sharedApplication].windows objectAtIndex:0]


//
#define VXP_LOCALIZE_TEXT(key)  NSLocalizedString(key, @"")

//Log
#define ENABLE_LOGGER   1   //1: show log, the project which use this framework will see log
//0: not show log.
#define VXP_LOG(arg...)                 [VoxyPADLogger logConsole:arg]
