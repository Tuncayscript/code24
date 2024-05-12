/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 12, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef __FoundationErrors_h_GNUSTEP_BASE_INCLUDE
#define __FoundationErrors_h_GNUSTEP_BASE_INCLUDE

#import <Base/VersionMacros.h>
#import <Object.h>



/* These are those of the NSError code values for the NSCocoaErrorDomain
 * which are defined in the foundation/base library.
 */

enum
{

  NSFileErrorMaximum = 1023,
  NSFileErrorMinimum = 0,
  NSFileLockingError = 255,
  NSFileNoSuchFileError = 4,
  NSFileReadCorruptFileError = 259,
  NSFileReadInapplicableStringEncodingError = 261,
  NSFileReadInvalidFileNameError = 258,
  NSFileReadNoPermissionError = 257,
  NSFileReadNoSuchFileError = 260,
  NSFileReadUnknownError = 256,
  NSFileReadUnsupportedSchemeError = 262,
  NSFileWriteInapplicableStringEncodingError = 517,
  NSFileWriteInvalidFileNameError = 514,
  NSFileWriteFileExistsError = 516,
  NSFileWriteNoPermissionError = 513,
  NSFileWriteOutOfSpaceError = 640,
  NSFileWriteUnknownError = 512,
  NSFileWriteUnsupportedSchemeError = 518,
  NSFormattingError = 2048,
  NSFormattingErrorMaximum = 2559,
  NSFormattingErrorMinimum = 2048,
  NSKeyValueValidationError = 1024,
  NSUserCancelledError = 3072,
  NSValidationErrorMaximum = 2047,
  NSValidationErrorMinimum = 1024,


  NSExecutableArchitectureMismatchError = 3585,
  NSExecutableErrorMaximum = 3839,
  NSExecutableErrorMinimum = 3584,
  NSExecutableLinkError = 3588,
  NSExecutableLoadError = 3587,
  NSExecutableNotLoadableError = 3584,
  NSExecutableRuntimeMismatchError = 3586,
  NSFileReadTooLargeError = 263,
  NSFileReadUnknownStringEncodingError = 264,
#endif


  NSFileWriteVolumeReadOnlyError = 642,
  NSPropertyListErrorMaximum = 4095,
  NSPropertyListErrorMinimum = 3840,
  NSPropertyListReadCorruptError = 3840,
  NSPropertyListReadStreamError = 3842,
  NSPropertyListReadUnknownVersionError = 3841,
  NSPropertyListWriteStreamError = 3851,
#endif


#endif


  NSFeatureUnsupportedError = 3328,
  NSXPCConnectionErrorMaximum = 4224,
  NSXPCConnectionErrorMinimum = 4096,
  NSXPCConnectionInterrupted = 4097,
  NSXPCConnectionInvalid = 4099,
  NSXPCConnectionReplyInvalid = 4101,
#endif


  NSUbiquitousFileErrorMaximum = 4607,
  NSUbiquitousFileErrorMinimum = 4352,
  NSUbiquitousFileNotUploadedDueToQuotaError = 4354,
  NSUbiquitousFileUbiquityServerNotAvailable = 4355,
  NSUbiquitousFileUnavailableError = 4353, 
#endif


  NSPropertyListWriteInvalidError = 3852,       
  NSUserActivityConnectionUnavailableError = 4609,
  NSUserActivityErrorMaximum = 4863, 
  NSUserActivityErrorMinimum = 4608,
  NSUserActivityHandoffFailedError = 4608,
  NSUserActivityHandoffUserInfoTooLargeError = 4611,
  NSUserActivityRemoteApplicationTimedOutError = 4610,
#endif


  NSBundleErrorMaximum = 5119,
  NSBundleErrorMinimum = 4992,
  NSCoderErrorMaximum = 4991,
  NSCoderErrorMinimum = 4864,
  NSCoderReadCorruptError = 4864,
  NSCoderValueNotFoundError = 4865,
#endif


  NSCloudSharingConflictError = 5123,
  NSCloudSharingErrorMaximum = 5375,
  NSCloudSharingErrorMinimum = 5120, 
  NSCloudSharingNetworkFailureError = 5120,
  NSCloudSharingNoPermissionError = 5124,
  NSCloudSharingOtherError = 5375,
  NSCloudSharingQuotaExceededError = 5121,
  NSCloudSharingTooManyParticipantsError = 5122,
#endif


  NSCoderInvalidValueError = 4866, 
#endif

  GSFoundationPlaceHolderError = 9999
};

#endif
#endif

