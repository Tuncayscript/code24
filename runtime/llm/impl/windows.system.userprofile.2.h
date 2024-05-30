/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#pragma once
#ifndef LLM_OS_System_UserProfile_2_H
#define LLM_OS_System_UserProfile_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.System.UserProfile.1.h"
LLM_EXPORT namespace llm:OS::System::UserProfile
{
    struct AdvertisingManager
    {
        AdvertisingManager() = delete;
        [[nodiscard]] static auto AdvertisingId();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) AdvertisingManagerForUser : llm:OS::System::UserProfile::IAdvertisingManagerForUser
    {
        AdvertisingManagerForUser(std::nullptr_t) noexcept {}
        AdvertisingManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::UserProfile::IAdvertisingManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AssignedAccessSettings : llm:OS::System::UserProfile::IAssignedAccessSettings
    {
        AssignedAccessSettings(std::nullptr_t) noexcept {}
        AssignedAccessSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::UserProfile::IAssignedAccessSettings(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) DiagnosticsSettings : llm:OS::System::UserProfile::IDiagnosticsSettings
    {
        DiagnosticsSettings(std::nullptr_t) noexcept {}
        DiagnosticsSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::UserProfile::IDiagnosticsSettings(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) FirstSignInSettings : llm:OS::System::UserProfile::IFirstSignInSettings
    {
        FirstSignInSettings(std::nullptr_t) noexcept {}
        FirstSignInSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::UserProfile::IFirstSignInSettings(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct GlobalizationPreferences
    {
        GlobalizationPreferences() = delete;
        [[nodiscard]] static auto Calendars();
        [[nodiscard]] static auto Clocks();
        [[nodiscard]] static auto Currencies();
        [[nodiscard]] static auto Languages();
        [[nodiscard]] static auto HomeGeographicRegion();
        [[nodiscard]] static auto WeekStartsOn();
        static auto TrySetHomeGeographicRegion(param::hstring const& region);
        static auto TrySetLanguages(param::iterable<hstring> const& languageTags);
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) GlobalizationPreferencesForUser : llm:OS::System::UserProfile::IGlobalizationPreferencesForUser
    {
        GlobalizationPreferencesForUser(std::nullptr_t) noexcept {}
        GlobalizationPreferencesForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::UserProfile::IGlobalizationPreferencesForUser(ptr, take_ownership_from_abi) {}
    };
    struct LockScreen
    {
        LockScreen() = delete;
        static auto RequestSetImageFeedAsync(llm:OS::Foundation::Uri const& syndicationFeedUri);
        static auto TryRemoveImageFeed();
        [[nodiscard]] static auto OriginalImageFile();
        static auto GetImageStream();
        static auto SetImageFileAsync(llm:OS::Storage::IStorageFile const& value);
        static auto SetImageStreamAsync(llm:OS::Storage::Streams::IRandomAccessStream const& value);
    };
    struct UserInformation
    {
        UserInformation() = delete;
        [[nodiscard]] static auto AccountPictureChangeEnabled();
        [[nodiscard]] static auto NameAccessAllowed();
        static auto GetAccountPicture(llm:OS::System::UserProfile::AccountPictureKind const& kind);
        static auto SetAccountPictureAsync(llm:OS::Storage::IStorageFile const& image);
        static auto SetAccountPicturesAsync(llm:OS::Storage::IStorageFile const& smallImage, llm:OS::Storage::IStorageFile const& largeImage, llm:OS::Storage::IStorageFile const& video);
        static auto SetAccountPictureFromStreamAsync(llm:OS::Storage::Streams::IRandomAccessStream const& image);
        static auto SetAccountPicturesFromStreamsAsync(llm:OS::Storage::Streams::IRandomAccessStream const& smallImage, llm:OS::Storage::Streams::IRandomAccessStream const& largeImage, llm:OS::Storage::Streams::IRandomAccessStream const& video);
        static auto AccountPictureChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& changeHandler);
        using AccountPictureChanged_revoker = impl::factory_event_revoker<llm:OS::System::UserProfile::IUserInformationStatics, &impl::abi_t<llm:OS::System::UserProfile::IUserInformationStatics>::remove_AccountPictureChanged>;
        [[nodiscard]] static AccountPictureChanged_revoker AccountPictureChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& changeHandler);
        static auto AccountPictureChanged(llm::event_token const& token);
        static auto GetDisplayNameAsync();
        static auto GetFirstNameAsync();
        static auto GetLastNameAsync();
        static auto GetPrincipalNameAsync();
        static auto GetSessionInitiationProtocolUriAsync();
        static auto GetDomainNameAsync();
    };
    struct __declspec(empty_bases) UserProfilePersonalizationSettings : llm:OS::System::UserProfile::IUserProfilePersonalizationSettings
    {
        UserProfilePersonalizationSettings(std::nullptr_t) noexcept {}
        UserProfilePersonalizationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::UserProfile::IUserProfilePersonalizationSettings(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
        static auto IsSupported();
    };
}
#endif
