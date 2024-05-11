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
// Filename: Errors.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Saturday, May 11, 2024
// Purpose: These are those of the Error code values for the language's low level capabalities which are defined in the foundation/base library.
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef Errors_hpp
#define Errors_hpp

#import <VersionMacros.hpp>
#import <Object.hpp>

enum
{

  FileErrorMaximum = 1023,
  FileErrorMinimum = 0,
  FileLockingError = 255,
  FileNoSuchFileError = 4,
  FileReadCorruptFileError = 259,
  FileReadInapplicableStringEncodingError = 261,
  FileReadInvalidFileNameError = 258,
  FileReadNoPermissionError = 257,
  FileReadNoSuchFileError = 260,
  FileReadUnknownError = 256,
  FileReadUnsupportedSchemeError = 262,
  FileWriteInapplicableStringEncodingError = 517,
  FileWriteInvalidFileNameError = 514,
  FileWriteFileExistsError = 516,
  FileWriteNoPermissionError = 513,
  FileWriteOutOfSpaceError = 640,
  FileWriteUnknownError = 512,
  FileWriteUnsupportedSchemeError = 518,
  FormattingError = 2048,
  FormattingErrorMaximum = 2559,
  FormattingErrorMinimum = 2048,
  KeyValueValidationError = 1024,
  UserCancelledError = 3072,
  ValidationErrorMaximum = 2047,
  ValidationErrorMinimum = 1024,

#if OS_API_VERSION(MAC_OS_X_VERSION_10_5, GS_API_LATEST)
  ExecutableArchitectureMismatchError = 3585,
  ExecutableErrorMaximum = 3839,
  ExecutableErrorMinimum = 3584,
  ExecutableLinkError = 3588,
  ExecutableLoadError = 3587,
  ExecutableNotLoadableError = 3584,
  ExecutableRuntimeMismatchError = 3586,
  FileReadTooLargeError = 263,
  FileReadUnknownStringEncodingError = 264,
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
  FileWriteVolumeReadOnlyError = 642,
  PropertyListErrorMaximum = 4095,
  PropertyListErrorMinimum = 3840,
  PropertyListReadCorruptError = 3840,
  PropertyListReadStreamError = 3842,
  PropertyListReadUnknownVersionError = 3841,
  PropertyListWriteStreamError = 3851,
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_7, GS_API_LATEST)
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_8, GS_API_LATEST)
  FeatureUnsupportedError = 3328,
  XPCConnectionErrorMaximum = 4224,
  XPCConnectionErrorMinimum = 4096,
  XPCConnectionInterrupted = 4097,
  XPCConnectionInvalid = 4099,
  XPCConnectionReplyInvalid = 4101,
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_9, GS_API_LATEST)
  UbiquitousFileErrorMaximum = 4607,
  UbiquitousFileErrorMinimum = 4352,
  UbiquitousFileNotUploadedDueToQuotaError = 4354,
  UbiquitousFileUbiquityServerNotAvailable = 4355,
  UbiquitousFileUnavailableError = 4353, 
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_10, GS_API_LATEST)
  PropertyListWriteInvalidError = 3852,       
  UserActivityConnectionUnavailableError = 4609,
  UserActivityErrorMaximum = 4863, 
  UserActivityErrorMinimum = 4608,
  UserActivityHandoffFailedError = 4608,
  UserActivityHandoffUserInfoTooLargeError = 4611,
  UserActivityRemoteApplicationTimedOutError = 4610,
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
  BundleErrorMaximum = 5119,
  BundleErrorMinimum = 4992,
  CoderErrorMaximum = 4991,
  CoderErrorMinimum = 4864,
  CoderReadCorruptError = 4864,
  CoderValueNotFoundError = 4865,
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_12, GS_API_LATEST)
  CloudSharingConflictError = 5123,
  CloudSharingErrorMaximum = 5375,
  CloudSharingErrorMinimum = 5120, 
  CloudSharingNetworkFailureError = 5120,
  CloudSharingNoPermissionError = 5124,
  CloudSharingOtherError = 5375,
  CloudSharingQuotaExceededError = 5121,
  CloudSharingTooManyParticipantsError = 5122,
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_13, GS_API_LATEST)
  CoderInvalidValueError = 4866, 
#endif

  GSFoundationPlaceHolderError = 9999
};

#endif
#endif
