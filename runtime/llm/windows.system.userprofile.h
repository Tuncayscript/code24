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
#ifndef LLM_OS_System_UserProfile_H
#define LLM_OS_System_UserProfile_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Globalization.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.System.UserProfile.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_UserProfile_IAdvertisingManagerForUser<D>::AdvertisingId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAdvertisingManagerForUser)->get_AdvertisingId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_UserProfile_IAdvertisingManagerForUser<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAdvertisingManagerForUser)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_UserProfile_IAdvertisingManagerStatics<D>::AdvertisingId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAdvertisingManagerStatics)->get_AdvertisingId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::AdvertisingManagerForUser) consume_Windows_System_UserProfile_IAdvertisingManagerStatics2<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAdvertisingManagerStatics2)->GetForUser(*(void**)(&user), &value));
        return llm::OS::System::UserProfile::AdvertisingManagerForUser{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IAssignedAccessSettings<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAssignedAccessSettings)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IAssignedAccessSettings<D>::IsSingleAppKioskMode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAssignedAccessSettings)->get_IsSingleAppKioskMode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_UserProfile_IAssignedAccessSettings<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAssignedAccessSettings)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::AssignedAccessSettings) consume_Windows_System_UserProfile_IAssignedAccessSettingsStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAssignedAccessSettingsStatics)->GetDefault(&result));
        return llm::OS::System::UserProfile::AssignedAccessSettings{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::AssignedAccessSettings) consume_Windows_System_UserProfile_IAssignedAccessSettingsStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IAssignedAccessSettingsStatics)->GetForUser(*(void**)(&user), &result));
        return llm::OS::System::UserProfile::AssignedAccessSettings{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IDiagnosticsSettings<D>::CanUseDiagnosticsToTailorExperiences() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IDiagnosticsSettings)->get_CanUseDiagnosticsToTailorExperiences(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_UserProfile_IDiagnosticsSettings<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IDiagnosticsSettings)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::DiagnosticsSettings) consume_Windows_System_UserProfile_IDiagnosticsSettingsStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IDiagnosticsSettingsStatics)->GetDefault(&value));
        return llm::OS::System::UserProfile::DiagnosticsSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::DiagnosticsSettings) consume_Windows_System_UserProfile_IDiagnosticsSettingsStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IDiagnosticsSettingsStatics)->GetForUser(*(void**)(&user), &value));
        return llm::OS::System::UserProfile::DiagnosticsSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::FirstSignInSettings) consume_Windows_System_UserProfile_IFirstSignInSettingsStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IFirstSignInSettingsStatics)->GetDefault(&result));
        return llm::OS::System::UserProfile::FirstSignInSettings{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_UserProfile_IGlobalizationPreferencesForUser<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesForUser)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesForUser<D>::Calendars() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesForUser)->get_Calendars(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesForUser<D>::Clocks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesForUser)->get_Clocks(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesForUser<D>::Currencies() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesForUser)->get_Currencies(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesForUser<D>::Languages() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesForUser)->get_Languages(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_UserProfile_IGlobalizationPreferencesForUser<D>::HomeGeographicRegion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesForUser)->get_HomeGeographicRegion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DayOfWeek) consume_Windows_System_UserProfile_IGlobalizationPreferencesForUser<D>::WeekStartsOn() const
    {
        llm::OS::Globalization::DayOfWeek value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesForUser)->get_WeekStartsOn(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics<D>::Calendars() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics)->get_Calendars(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics<D>::Clocks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics)->get_Clocks(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics<D>::Currencies() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics)->get_Currencies(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics<D>::Languages() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics)->get_Languages(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics<D>::HomeGeographicRegion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics)->get_HomeGeographicRegion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DayOfWeek) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics<D>::WeekStartsOn() const
    {
        llm::OS::Globalization::DayOfWeek value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics)->get_WeekStartsOn(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics2<D>::TrySetHomeGeographicRegion(param::hstring const& region) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics2)->TrySetHomeGeographicRegion(*(void**)(&region), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics2<D>::TrySetLanguages(param::iterable<hstring> const& languageTags) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics2)->TrySetLanguages(*(void**)(&languageTags), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::GlobalizationPreferencesForUser) consume_Windows_System_UserProfile_IGlobalizationPreferencesStatics3<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IGlobalizationPreferencesStatics3)->GetForUser(*(void**)(&user), &value));
        return llm::OS::System::UserProfile::GlobalizationPreferencesForUser{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetImageFeedResult>) consume_Windows_System_UserProfile_ILockScreenImageFeedStatics<D>::RequestSetImageFeedAsync(llm::OS::Foundation::Uri const& syndicationFeedUri) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::ILockScreenImageFeedStatics)->RequestSetImageFeedAsync(*(void**)(&syndicationFeedUri), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetImageFeedResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_ILockScreenImageFeedStatics<D>::TryRemoveImageFeed() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::ILockScreenImageFeedStatics)->TryRemoveImageFeed(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_System_UserProfile_ILockScreenStatics<D>::OriginalImageFile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::ILockScreenStatics)->get_OriginalImageFile(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_System_UserProfile_ILockScreenStatics<D>::GetImageStream() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::ILockScreenStatics)->GetImageStream(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_UserProfile_ILockScreenStatics<D>::SetImageFileAsync(llm::OS::Storage::IStorageFile const& value) const
    {
        void* Operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::ILockScreenStatics)->SetImageFileAsync(*(void**)(&value), &Operation));
        return llm::OS::Foundation::IAsyncAction{ Operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_UserProfile_ILockScreenStatics<D>::SetImageStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& value) const
    {
        void* Operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::ILockScreenStatics)->SetImageStreamAsync(*(void**)(&value), &Operation));
        return llm::OS::Foundation::IAsyncAction{ Operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IUserInformationStatics<D>::AccountPictureChangeEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->get_AccountPictureChangeEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IUserInformationStatics<D>::NameAccessAllowed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->get_NameAccessAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::IStorageFile) consume_Windows_System_UserProfile_IUserInformationStatics<D>::GetAccountPicture(llm::OS::System::UserProfile::AccountPictureKind const& kind) const
    {
        void* storageFile{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->GetAccountPicture(static_cast<int32_t>(kind), &storageFile));
        return llm::OS::Storage::IStorageFile{ storageFile, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::SetAccountPictureAsync(llm::OS::Storage::IStorageFile const& image) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->SetAccountPictureAsync(*(void**)(&image), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::SetAccountPicturesAsync(llm::OS::Storage::IStorageFile const& smallImage, llm::OS::Storage::IStorageFile const& largeImage, llm::OS::Storage::IStorageFile const& video) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->SetAccountPicturesAsync(*(void**)(&smallImage), *(void**)(&largeImage), *(void**)(&video), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::SetAccountPictureFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& image) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->SetAccountPictureFromStreamAsync(*(void**)(&image), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::SetAccountPicturesFromStreamsAsync(llm::OS::Storage::Streams::IRandomAccessStream const& smallImage, llm::OS::Storage::Streams::IRandomAccessStream const& largeImage, llm::OS::Storage::Streams::IRandomAccessStream const& video) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->SetAccountPicturesFromStreamsAsync(*(void**)(&smallImage), *(void**)(&largeImage), *(void**)(&video), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_UserProfile_IUserInformationStatics<D>::AccountPictureChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& changeHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->add_AccountPictureChanged(*(void**)(&changeHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_UserProfile_IUserInformationStatics<D>::AccountPictureChanged_revoker consume_Windows_System_UserProfile_IUserInformationStatics<D>::AccountPictureChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& changeHandler) const
    {
        return impl::make_event_revoker<D, AccountPictureChanged_revoker>(this, AccountPictureChanged(changeHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_UserProfile_IUserInformationStatics<D>::AccountPictureChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->remove_AccountPictureChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::GetDisplayNameAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->GetDisplayNameAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::GetFirstNameAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->GetFirstNameAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::GetLastNameAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->GetLastNameAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::GetPrincipalNameAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->GetPrincipalNameAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Uri>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::GetSessionInitiationProtocolUriAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->GetSessionInitiationProtocolUriAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Uri>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_System_UserProfile_IUserInformationStatics<D>::GetDomainNameAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserInformationStatics)->GetDomainNameAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_UserProfile_IUserProfilePersonalizationSettings<D>::TrySetLockScreenImageAsync(llm::OS::Storage::StorageFile const& imageFile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserProfilePersonalizationSettings)->TrySetLockScreenImageAsync(*(void**)(&imageFile), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_UserProfile_IUserProfilePersonalizationSettings<D>::TrySetWallpaperImageAsync(llm::OS::Storage::StorageFile const& imageFile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserProfilePersonalizationSettings)->TrySetWallpaperImageAsync(*(void**)(&imageFile), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserProfile::UserProfilePersonalizationSettings) consume_Windows_System_UserProfile_IUserProfilePersonalizationSettingsStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserProfilePersonalizationSettingsStatics)->get_Current(&value));
        return llm::OS::System::UserProfile::UserProfilePersonalizationSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_UserProfile_IUserProfilePersonalizationSettingsStatics<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::UserProfile::IUserProfilePersonalizationSettingsStatics)->IsSupported(&result));
        return result;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IAdvertisingManagerForUser> : produce_base<D, llm::OS::System::UserProfile::IAdvertisingManagerForUser>
    {
        int32_t __stdcall get_AdvertisingId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AdvertisingId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IAdvertisingManagerStatics> : produce_base<D, llm::OS::System::UserProfile::IAdvertisingManagerStatics>
    {
        int32_t __stdcall get_AdvertisingId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AdvertisingId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IAdvertisingManagerStatics2> : produce_base<D, llm::OS::System::UserProfile::IAdvertisingManagerStatics2>
    {
        int32_t __stdcall GetForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserProfile::AdvertisingManagerForUser>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IAssignedAccessSettings> : produce_base<D, llm::OS::System::UserProfile::IAssignedAccessSettings>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSingleAppKioskMode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSingleAppKioskMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IAssignedAccessSettingsStatics> : produce_base<D, llm::OS::System::UserProfile::IAssignedAccessSettingsStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::UserProfile::AssignedAccessSettings>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::UserProfile::AssignedAccessSettings>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IDiagnosticsSettings> : produce_base<D, llm::OS::System::UserProfile::IDiagnosticsSettings>
    {
        int32_t __stdcall get_CanUseDiagnosticsToTailorExperiences(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanUseDiagnosticsToTailorExperiences());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IDiagnosticsSettingsStatics> : produce_base<D, llm::OS::System::UserProfile::IDiagnosticsSettingsStatics>
    {
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserProfile::DiagnosticsSettings>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserProfile::DiagnosticsSettings>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IFirstSignInSettings> : produce_base<D, llm::OS::System::UserProfile::IFirstSignInSettings>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IFirstSignInSettingsStatics> : produce_base<D, llm::OS::System::UserProfile::IFirstSignInSettingsStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::UserProfile::FirstSignInSettings>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IGlobalizationPreferencesForUser> : produce_base<D, llm::OS::System::UserProfile::IGlobalizationPreferencesForUser>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Calendars(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Calendars());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Clocks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Clocks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Currencies(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Currencies());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Languages(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Languages());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HomeGeographicRegion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HomeGeographicRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WeekStartsOn(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DayOfWeek>(this->shim().WeekStartsOn());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IGlobalizationPreferencesStatics> : produce_base<D, llm::OS::System::UserProfile::IGlobalizationPreferencesStatics>
    {
        int32_t __stdcall get_Calendars(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Calendars());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Clocks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Clocks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Currencies(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Currencies());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Languages(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Languages());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HomeGeographicRegion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HomeGeographicRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WeekStartsOn(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DayOfWeek>(this->shim().WeekStartsOn());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IGlobalizationPreferencesStatics2> : produce_base<D, llm::OS::System::UserProfile::IGlobalizationPreferencesStatics2>
    {
        int32_t __stdcall TrySetHomeGeographicRegion(void* region, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TrySetHomeGeographicRegion(*reinterpret_cast<hstring const*>(&region)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetLanguages(void* languageTags, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TrySetLanguages(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&languageTags)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IGlobalizationPreferencesStatics3> : produce_base<D, llm::OS::System::UserProfile::IGlobalizationPreferencesStatics3>
    {
        int32_t __stdcall GetForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserProfile::GlobalizationPreferencesForUser>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::ILockScreenImageFeedStatics> : produce_base<D, llm::OS::System::UserProfile::ILockScreenImageFeedStatics>
    {
        int32_t __stdcall RequestSetImageFeedAsync(void* syndicationFeedUri, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetImageFeedResult>>(this->shim().RequestSetImageFeedAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&syndicationFeedUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryRemoveImageFeed(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryRemoveImageFeed());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::ILockScreenStatics> : produce_base<D, llm::OS::System::UserProfile::ILockScreenStatics>
    {
        int32_t __stdcall get_OriginalImageFile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().OriginalImageFile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetImageStream(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().GetImageStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetImageFileAsync(void* value, void** Operation) noexcept final try
        {
            clear_abi(Operation);
            typename D::abi_guard guard(this->shim());
            *Operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetImageFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetImageStreamAsync(void* value, void** Operation) noexcept final try
        {
            clear_abi(Operation);
            typename D::abi_guard guard(this->shim());
            *Operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetImageStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IUserInformationStatics> : produce_base<D, llm::OS::System::UserProfile::IUserInformationStatics>
    {
        int32_t __stdcall get_AccountPictureChangeEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AccountPictureChangeEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NameAccessAllowed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().NameAccessAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccountPicture(int32_t kind, void** storageFile) noexcept final try
        {
            clear_abi(storageFile);
            typename D::abi_guard guard(this->shim());
            *storageFile = detach_from<llm::OS::Storage::IStorageFile>(this->shim().GetAccountPicture(*reinterpret_cast<llm::OS::System::UserProfile::AccountPictureKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAccountPictureAsync(void* image, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>>(this->shim().SetAccountPictureAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&image)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAccountPicturesAsync(void* smallImage, void* largeImage, void* video, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>>(this->shim().SetAccountPicturesAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&smallImage), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&largeImage), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&video)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAccountPictureFromStreamAsync(void* image, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>>(this->shim().SetAccountPictureFromStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&image)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAccountPicturesFromStreamsAsync(void* smallImage, void* largeImage, void* video, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserProfile::SetAccountPictureResult>>(this->shim().SetAccountPicturesFromStreamsAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&smallImage), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&largeImage), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&video)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AccountPictureChanged(void* changeHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AccountPictureChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&changeHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AccountPictureChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountPictureChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetDisplayNameAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetDisplayNameAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFirstNameAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetFirstNameAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLastNameAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetLastNameAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPrincipalNameAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetPrincipalNameAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSessionInitiationProtocolUriAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Uri>>(this->shim().GetSessionInitiationProtocolUriAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDomainNameAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetDomainNameAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IUserProfilePersonalizationSettings> : produce_base<D, llm::OS::System::UserProfile::IUserProfilePersonalizationSettings>
    {
        int32_t __stdcall TrySetLockScreenImageAsync(void* imageFile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TrySetLockScreenImageAsync(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&imageFile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetWallpaperImageAsync(void* imageFile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TrySetWallpaperImageAsync(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&imageFile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::UserProfile::IUserProfilePersonalizationSettingsStatics> : produce_base<D, llm::OS::System::UserProfile::IUserProfilePersonalizationSettingsStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserProfile::UserProfilePersonalizationSettings>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::UserProfile
{
    inline auto AdvertisingManager::AdvertisingId()
    {
        return impl::call_factory_cast<hstring(*)(IAdvertisingManagerStatics const&), AdvertisingManager, IAdvertisingManagerStatics>([](IAdvertisingManagerStatics const& f) { return f.AdvertisingId(); });
    }
    inline auto AdvertisingManager::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<AdvertisingManager, IAdvertisingManagerStatics2>([&](IAdvertisingManagerStatics2 const& f) { return f.GetForUser(user); });
    }
    inline auto AssignedAccessSettings::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::System::UserProfile::AssignedAccessSettings(*)(IAssignedAccessSettingsStatics const&), AssignedAccessSettings, IAssignedAccessSettingsStatics>([](IAssignedAccessSettingsStatics const& f) { return f.GetDefault(); });
    }
    inline auto AssignedAccessSettings::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<AssignedAccessSettings, IAssignedAccessSettingsStatics>([&](IAssignedAccessSettingsStatics const& f) { return f.GetForUser(user); });
    }
    inline auto DiagnosticsSettings::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::System::UserProfile::DiagnosticsSettings(*)(IDiagnosticsSettingsStatics const&), DiagnosticsSettings, IDiagnosticsSettingsStatics>([](IDiagnosticsSettingsStatics const& f) { return f.GetDefault(); });
    }
    inline auto DiagnosticsSettings::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<DiagnosticsSettings, IDiagnosticsSettingsStatics>([&](IDiagnosticsSettingsStatics const& f) { return f.GetForUser(user); });
    }
    inline auto FirstSignInSettings::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::System::UserProfile::FirstSignInSettings(*)(IFirstSignInSettingsStatics const&), FirstSignInSettings, IFirstSignInSettingsStatics>([](IFirstSignInSettingsStatics const& f) { return f.GetDefault(); });
    }
    inline auto GlobalizationPreferences::Calendars()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<hstring>(*)(IGlobalizationPreferencesStatics const&), GlobalizationPreferences, IGlobalizationPreferencesStatics>([](IGlobalizationPreferencesStatics const& f) { return f.Calendars(); });
    }
    inline auto GlobalizationPreferences::Clocks()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<hstring>(*)(IGlobalizationPreferencesStatics const&), GlobalizationPreferences, IGlobalizationPreferencesStatics>([](IGlobalizationPreferencesStatics const& f) { return f.Clocks(); });
    }
    inline auto GlobalizationPreferences::Currencies()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<hstring>(*)(IGlobalizationPreferencesStatics const&), GlobalizationPreferences, IGlobalizationPreferencesStatics>([](IGlobalizationPreferencesStatics const& f) { return f.Currencies(); });
    }
    inline auto GlobalizationPreferences::Languages()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<hstring>(*)(IGlobalizationPreferencesStatics const&), GlobalizationPreferences, IGlobalizationPreferencesStatics>([](IGlobalizationPreferencesStatics const& f) { return f.Languages(); });
    }
    inline auto GlobalizationPreferences::HomeGeographicRegion()
    {
        return impl::call_factory_cast<hstring(*)(IGlobalizationPreferencesStatics const&), GlobalizationPreferences, IGlobalizationPreferencesStatics>([](IGlobalizationPreferencesStatics const& f) { return f.HomeGeographicRegion(); });
    }
    inline auto GlobalizationPreferences::WeekStartsOn()
    {
        return impl::call_factory_cast<llm::OS::Globalization::DayOfWeek(*)(IGlobalizationPreferencesStatics const&), GlobalizationPreferences, IGlobalizationPreferencesStatics>([](IGlobalizationPreferencesStatics const& f) { return f.WeekStartsOn(); });
    }
    inline auto GlobalizationPreferences::TrySetHomeGeographicRegion(param::hstring const& region)
    {
        return impl::call_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics2>([&](IGlobalizationPreferencesStatics2 const& f) { return f.TrySetHomeGeographicRegion(region); });
    }
    inline auto GlobalizationPreferences::TrySetLanguages(param::iterable<hstring> const& languageTags)
    {
        return impl::call_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics2>([&](IGlobalizationPreferencesStatics2 const& f) { return f.TrySetLanguages(languageTags); });
    }
    inline auto GlobalizationPreferences::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics3>([&](IGlobalizationPreferencesStatics3 const& f) { return f.GetForUser(user); });
    }
    inline auto LockScreen::RequestSetImageFeedAsync(llm::OS::Foundation::Uri const& syndicationFeedUri)
    {
        return impl::call_factory<LockScreen, ILockScreenImageFeedStatics>([&](ILockScreenImageFeedStatics const& f) { return f.RequestSetImageFeedAsync(syndicationFeedUri); });
    }
    inline auto LockScreen::TryRemoveImageFeed()
    {
        return impl::call_factory_cast<bool(*)(ILockScreenImageFeedStatics const&), LockScreen, ILockScreenImageFeedStatics>([](ILockScreenImageFeedStatics const& f) { return f.TryRemoveImageFeed(); });
    }
    inline auto LockScreen::OriginalImageFile()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Uri(*)(ILockScreenStatics const&), LockScreen, ILockScreenStatics>([](ILockScreenStatics const& f) { return f.OriginalImageFile(); });
    }
    inline auto LockScreen::GetImageStream()
    {
        return impl::call_factory_cast<llm::OS::Storage::Streams::IRandomAccessStream(*)(ILockScreenStatics const&), LockScreen, ILockScreenStatics>([](ILockScreenStatics const& f) { return f.GetImageStream(); });
    }
    inline auto LockScreen::SetImageFileAsync(llm::OS::Storage::IStorageFile const& value)
    {
        return impl::call_factory<LockScreen, ILockScreenStatics>([&](ILockScreenStatics const& f) { return f.SetImageFileAsync(value); });
    }
    inline auto LockScreen::SetImageStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& value)
    {
        return impl::call_factory<LockScreen, ILockScreenStatics>([&](ILockScreenStatics const& f) { return f.SetImageStreamAsync(value); });
    }
    inline auto UserInformation::AccountPictureChangeEnabled()
    {
        return impl::call_factory_cast<bool(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.AccountPictureChangeEnabled(); });
    }
    inline auto UserInformation::NameAccessAllowed()
    {
        return impl::call_factory_cast<bool(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.NameAccessAllowed(); });
    }
    inline auto UserInformation::GetAccountPicture(llm::OS::System::UserProfile::AccountPictureKind const& kind)
    {
        return impl::call_factory<UserInformation, IUserInformationStatics>([&](IUserInformationStatics const& f) { return f.GetAccountPicture(kind); });
    }
    inline auto UserInformation::SetAccountPictureAsync(llm::OS::Storage::IStorageFile const& image)
    {
        return impl::call_factory<UserInformation, IUserInformationStatics>([&](IUserInformationStatics const& f) { return f.SetAccountPictureAsync(image); });
    }
    inline auto UserInformation::SetAccountPicturesAsync(llm::OS::Storage::IStorageFile const& smallImage, llm::OS::Storage::IStorageFile const& largeImage, llm::OS::Storage::IStorageFile const& video)
    {
        return impl::call_factory<UserInformation, IUserInformationStatics>([&](IUserInformationStatics const& f) { return f.SetAccountPicturesAsync(smallImage, largeImage, video); });
    }
    inline auto UserInformation::SetAccountPictureFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& image)
    {
        return impl::call_factory<UserInformation, IUserInformationStatics>([&](IUserInformationStatics const& f) { return f.SetAccountPictureFromStreamAsync(image); });
    }
    inline auto UserInformation::SetAccountPicturesFromStreamsAsync(llm::OS::Storage::Streams::IRandomAccessStream const& smallImage, llm::OS::Storage::Streams::IRandomAccessStream const& largeImage, llm::OS::Storage::Streams::IRandomAccessStream const& video)
    {
        return impl::call_factory<UserInformation, IUserInformationStatics>([&](IUserInformationStatics const& f) { return f.SetAccountPicturesFromStreamsAsync(smallImage, largeImage, video); });
    }
    inline auto UserInformation::AccountPictureChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& changeHandler)
    {
        return impl::call_factory<UserInformation, IUserInformationStatics>([&](IUserInformationStatics const& f) { return f.AccountPictureChanged(changeHandler); });
    }
    inline UserInformation::AccountPictureChanged_revoker UserInformation::AccountPictureChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& changeHandler)
    {
        auto f = get_activation_factory<UserInformation, llm::OS::System::UserProfile::IUserInformationStatics>();
        return { f, f.AccountPictureChanged(changeHandler) };
    }
    inline auto UserInformation::AccountPictureChanged(llm::event_token const& token)
    {
        impl::call_factory<UserInformation, IUserInformationStatics>([&](IUserInformationStatics const& f) { return f.AccountPictureChanged(token); });
    }
    inline auto UserInformation::GetDisplayNameAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<hstring>(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.GetDisplayNameAsync(); });
    }
    inline auto UserInformation::GetFirstNameAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<hstring>(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.GetFirstNameAsync(); });
    }
    inline auto UserInformation::GetLastNameAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<hstring>(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.GetLastNameAsync(); });
    }
    inline auto UserInformation::GetPrincipalNameAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<hstring>(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.GetPrincipalNameAsync(); });
    }
    inline auto UserInformation::GetSessionInitiationProtocolUriAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Uri>(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.GetSessionInitiationProtocolUriAsync(); });
    }
    inline auto UserInformation::GetDomainNameAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<hstring>(*)(IUserInformationStatics const&), UserInformation, IUserInformationStatics>([](IUserInformationStatics const& f) { return f.GetDomainNameAsync(); });
    }
    inline auto UserProfilePersonalizationSettings::Current()
    {
        return impl::call_factory_cast<llm::OS::System::UserProfile::UserProfilePersonalizationSettings(*)(IUserProfilePersonalizationSettingsStatics const&), UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>([](IUserProfilePersonalizationSettingsStatics const& f) { return f.Current(); });
    }
    inline auto UserProfilePersonalizationSettings::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IUserProfilePersonalizationSettingsStatics const&), UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>([](IUserProfilePersonalizationSettingsStatics const& f) { return f.IsSupported(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::UserProfile::IAdvertisingManagerForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IAdvertisingManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IAdvertisingManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IAssignedAccessSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IAssignedAccessSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IDiagnosticsSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IDiagnosticsSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IFirstSignInSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IFirstSignInSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IGlobalizationPreferencesForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IGlobalizationPreferencesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IGlobalizationPreferencesStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IGlobalizationPreferencesStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::ILockScreenImageFeedStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::ILockScreenStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IUserInformationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IUserProfilePersonalizationSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::IUserProfilePersonalizationSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::AdvertisingManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::AdvertisingManagerForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::AssignedAccessSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::DiagnosticsSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::FirstSignInSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::GlobalizationPreferences> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::GlobalizationPreferencesForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::LockScreen> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::UserInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserProfile::UserProfilePersonalizationSettings> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
