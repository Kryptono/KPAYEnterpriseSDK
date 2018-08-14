//
//  KPFramework.h
//  KryptonoPaymentSDK
//
//  Copyright © 2018 Kryptono Exchange. All rights reserved.
//

#import <UIKit/UIKit.h>


enum kpf_supported_localization {
    kPFSL_English = 0,
    kPFSL_ChineseSimplified
};
typedef enum kpf_supported_localization KPFSupportedLocalization;

enum kpf_error {
    KPFError_No_Error = 0,
    
    //Configuration
    KPFError_Framework_Not_Configured,
    
    KPFError_InvalidClientKey,
    KPFError_InvalidChecksumKey,
    KPFError_EnterpriseNotFound,
    KPFError_WrongClientKeyType,
    
    //User
    kPFError_User_Identity_Is_Null,
    
    //Language
    KPFError_Language_Not_Supported,

    //
    KPFError_Requested_Amount_Must_Be_Greater_Than_Zero
};
typedef enum kpf_error KPFError;


@protocol KPFrameworkProtocol;
@interface KPFramework : NSObject

//MUST CALL THIS METHOD AT BEGINNING
+ (BOOL)configureWithClientKey:(NSString *)clientKey
                   checksumKey:(NSString *)checksumKey;


+ (KPFError)setDesiredLanguage:(KPFSupportedLocalization)lang;


+ (void)launchFromController:(UIViewController * _Nonnull )sourceController
                userIdentity:(NSString * _Nonnull )userId
                    delegate:(id<KPFrameworkProtocol>)delegate
   yourCryptoRequestedAmount:(double)amount;

+ (void)launchFromController:(UIViewController * _Nonnull )sourceController
                userIdentity:(NSString * _Nonnull )userId
                    delegate:(id<KPFrameworkProtocol>)delegate;

@end


@protocol KPFrameworkProtocol <NSObject>

@required
- (void)kpFramework:(KPFramework *)kpframework
  didReceivePayment:(NSString *)paymentId
              error:(KPFError)error;
    
@end
