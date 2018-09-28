//
//  FrameworkEnumDefine.h
//  VoxyPADFramework
//
//  Created by VoxyPAD
//  Copyright (c) 2015 VoxyPAD Inc. All rights reserved.
//

#ifndef VoxyPADFramework_FrameworkEnumDefine_h
#define VoxyPADFramework_FrameworkEnumDefine_h

enum voxypad_view_genie_animation_position {
    kVXPViewGeniePositionTop = 0,
    kVXPViewGeniePositionLeft,
    kVXPViewGeniePositionBottom,
    kVXPViewGeniePositionRight,
};
typedef enum voxypad_view_genie_animation_position EnumVXPViewGeniePosition;

enum voxypad_video_recording_error {
    kVXPVideoRecordingErrorNone = 0,
    kVXPVideoRecordingErrorNoCameraDetected,
    kVXPVideoRecordingErrorRecordingNotSupport
};
typedef enum voxypad_video_recording_error EnumVXPVideoRecordingError;



enum voxypadphonebook_duplicate_type {
    kVoxyPADPhonebookDuplicateTypeAll = 0,
    kVoxyPADPhonebookDuplicateTypePhone,
    kVoxyPADPhonebookDuplicateTypeEmail,
    kVoxyPADPhonebookDuplicateTypeCompany,
    kVoxyPADPhonebookDuplicateTypeAddress,
    kVoxyPADPhonebookDuplicateTypeBirthday,
    kVoxyPADPhonebookDuplicateTypeName,
};
typedef enum voxypadphonebook_duplicate_type EnumVoxyPADhonebookDuplicateType;


#endif
