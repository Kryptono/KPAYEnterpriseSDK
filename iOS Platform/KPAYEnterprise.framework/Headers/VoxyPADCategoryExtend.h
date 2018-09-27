//
//  VoxyPADFramework.h
//  VoxyPADFramework
//
//  Created by VoxyPAD
//  Copyright (c) 2015 VoxyPAD Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VoxyPADFrameworkEnumDefine.h"

@interface UIColor (VoxyPADExtend)

- (const CGFloat*)colorArray;

@end




@interface UIImage (VoxyPADExtend)

- (UIImage *)scaleToSize:(CGSize)size;
- (UIImage *)scaleAndCropToSquare:(CGSize)squareSize;
- (UIImage *)circleWithinBound:(CGSize)size;
- (UIImage *)cropFromRect:(CGRect)rect;

/*!
 @abstract Methods related to save image to disk
 @discussion These methods allow to save image synchronizingly or asynchronizingly
 */
- (BOOL)saveJPGImageToDiskAtPath:(NSString *)path;
- (BOOL)savePNGImageToDiskAtPath:(NSString *)path;
- (void)asyncSaveJPGImageToDiskAtPath:(NSString *)path;
- (void)asyncSavePNGImageToDiskAtPath:(NSString *)path;

/**
 @abstract Methods create image from QRCode
 @discussion Returns an image which contains a QR code for a set string.
             When the image is generated, the code is mapped in pixels without distorting the image.
             So the image can both contain and not contain the margins,
             this depends on the 'imageSize' parameter and size of the generated QR
 */
+ (UIImage *)QRCodeForString:(NSString *)qrString
                        size:(CGFloat)size
       imageAtCenterIfNeeded:(UIImage *)img;
+ (UIImage *)QRCodeForString:(NSString *)qrString
                        size:(CGFloat)size
                   fillColor:(UIColor *)fillColor
       imageAtCenterIfNeeded:(UIImage *)img;

/**
 @abstract Methods for Image Processing
 @discussion - Add an image onto self at a given position
             - Apply mask image with black background and transparent hole to an image with the same size
             - Blend 2 images together
             - Apply with tone color
             - Apply with poisson
             - Rotate image
 */
- (UIImage *)processAddImage:(UIImage *)topImage
                  atPosition:(CGPoint)position;
- (UIImage *)processApplyMask:(UIImage *)maskImage;
- (UIImage *)processBlendWithImage:(UIImage *)topImage;
- (UIImage *)processApplyToneColor:(UIColor *)toneColor;
- (UIImage *)processApplyPoissonBlendImage:(UIImage *)topImage
                                 maskImage:(UIImage *)maskImage;
- (UIImage *)processRotateWithAngleInRadians:(float)angleInRadians;

/**
 @abstract Methods create an image with a specific size and a specific color
 */
+ (UIImage *)imageFromColor:(UIColor *)color size:(CGSize)size;

/**
 Create an image from layer
 
 */
+ (UIImage *)imageFromLayer:(CALayer *)layer;


@end


@interface NSDate (VoxyPADExtend)

+ (NSDate *) dateWithString:(NSString *) dateString Format:(NSString *) formatString;

@end

@interface NSString (VoxyPADExtend)

+ (NSString*)UUIDString;
+ (NSString *)generateRandomStringWithLenght:(int)lenght;

- (NSString *)md5;

/*!
 @abstract Custom method to calculate the SHA-256 hash using Common Crypto
 */
- (NSString *)hashUsing_SHA_256;

/*!
 @abstract Convert string to image
 */
- (UIImage *)imageWithColor:(UIColor *)color font:(UIFont *)font;

/*!
 @abstract Method related to check if a string is an URL link
 @discussion Check the 'candidate' string is an URL link or not
 */
- (BOOL)isAValidURL;

/*!
 @abstract Method for trimming string
 */
- (NSString *)stringByTrimmingLeadingAndTrailingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)stringByTrimmingLeadingAndTrailingWhitespaceAndNewlineCharacters;
- (NSString *)stringByTrimmingLeadingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)stringByTrimmingLeadingWhitespaceAndNewlineCharacters;
- (NSString *)stringByTrimmingTrailingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)stringByTrimmingTrailingWhitespaceAndNewlineCharacters;
- (NSString *)stringByPerfectTrimming;

/*!
 @abstract Method for removing prefix/suffix
 */
- (NSString *)stringByRemovePrefix:(NSString *)prefix;
- (NSString *)stringByRemoveSuffix:(NSString *)suffix;


/*!
 @abstract Method for letters on string
 */
- (NSString *)firstLetter;
- (BOOL)justAlphabetCharacterOnly;

- (NSString *)firstAlphabetLetter;

/*!
 @abstract Checking phone is valid or not. Moreover, normalize phone and maybe create a valid one
with country code at prefix, removing 0 leading,...
 */
- (NSString *)normalizeIfIsAValidPhoneNumberWithCountryCode:(NSString *)countryCode; //ex: +84, +1,...

/*!
 @abstract Method for get boundingRect of string
 */
- (CGSize)boundingRectWithSize:(CGSize)boundingSize
                          font:(UIFont *)font;

@end



@interface UIView (VoxyPADExtend)

@property (nonatomic, readonly) CGFloat top;
@property (nonatomic, readonly) CGFloat bottom;
@property (nonatomic, readonly) CGFloat left;
@property (nonatomic, readonly) CGFloat right;
@property (nonatomic, readonly) CGFloat midWidth;
@property (nonatomic, readonly) CGFloat midHeight;
@property (nonatomic, readonly) CGFloat width;
@property (nonatomic, readonly) CGFloat height;

/*!
 @abstract Method convert view to image
 */
- (UIImage *)image;

/*!
 @abstract Method rounds desire corners
 @param corners mix of values of UIRectCorner
 */
- (void)roundCorners:(UIRectCorner)corners
              radius:(CGFloat)radius;

/*!
 @abstract Method animate view with genie animation style
 @discussion After the animation has completed the view's transform will be changed to match the destination's rect, i.e.
     view's transform (and thus the frame) will change, however the bounds and center will *not* change.
 */

- (void)animateGenieInTransitionWithDuration:(NSTimeInterval)duration
                      destinationRect:(CGRect)destRect
                      destinationEdge:(EnumVXPViewGeniePosition)destEdge
                                  completion:(void (^)(void))completion;

/*!
 @abstract Method animate view with genie animation style
 @discussion After the animation has completed the view's transform will be changed to CGAffineTransformIdentity.
 */

- (void)animateGenieOutTransitionWithDuration:(NSTimeInterval)duration
                             startRect:(CGRect)startRect
                             startEdge:(EnumVXPViewGeniePosition)startEdge
                                   completion:(void (^)(void))completion;

@end



@interface UILabel (VoxyPADExtend)

- (void)setTextColor:(UIColor *)textColor inRange:(NSRange)range;
- (void)setFont:(UIFont *)font inRange:(NSRange)range;

@end



@interface UITextView (VoxyPADExtend)

@property (nonatomic, retain) NSString *placeHolder;
@property (nonatomic, retain) UIColor *placeHolderColor;

/*!
 @abstract Get string automatically insert new line character within UITextView
 @discussion This method takes in the `UITextView` and returns the string
  representation which includes the newline characters
 */
- (NSString*)stringByInsertNewLineCharacterForWordwrap;

@end



@interface UITextField (VoxyPADExtend)

- (void)changePlaceholderColor:(UIColor *)newColor;


@end



@interface UITabBarItem (VoxyPADExtend)
- (id)initWithTitle:(NSString *)title
              image:(UIImage *)image
      selectedImage:(UIImage *)selectedImage
                tag:(int)tagIndex;
@end




@interface UIButton (VoxyPADExtend)

- (void)setBackgroundColor:(UIColor *)color forState:(UIControlState) state;
- (void)setBackgroundImageWithLayer:(CAGradientLayer *) layer forState:(UIControlState) state;

@end

