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
#ifndef LLM_OS_Phone_StartScreen_H
#define LLM_OS_Phone_StartScreen_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.Notifications.2.h"
#include "llm/impl/Windows.Phone.StartScreen.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_StartScreen_IDualSimTile<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTile)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Phone_StartScreen_IDualSimTile<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTile)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Phone_StartScreen_IDualSimTile<D>::IsPinnedToStart() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTile)->get_IsPinnedToStart(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Phone_StartScreen_IDualSimTile<D>::CreateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTile)->CreateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Phone_StartScreen_IDualSimTile<D>::UpdateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTile)->UpdateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Phone_StartScreen_IDualSimTile<D>::DeleteAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTile)->DeleteAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::StartScreen::DualSimTile) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::GetTileForSim2() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->GetTileForSim2(&result));
        return llm::OS::Phone::StartScreen::DualSimTile{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::UpdateDisplayNameForSim1Async(param::hstring const& name) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->UpdateDisplayNameForSim1Async(*(void**)(&name), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::TileUpdater) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::CreateTileUpdaterForSim1() const
    {
        void* updater{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->CreateTileUpdaterForSim1(&updater));
        return llm::OS::UI::Notifications::TileUpdater{ updater, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::TileUpdater) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::CreateTileUpdaterForSim2() const
    {
        void* updater{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->CreateTileUpdaterForSim2(&updater));
        return llm::OS::UI::Notifications::TileUpdater{ updater, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::BadgeUpdater) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::CreateBadgeUpdaterForSim1() const
    {
        void* updater{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->CreateBadgeUpdaterForSim1(&updater));
        return llm::OS::UI::Notifications::BadgeUpdater{ updater, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::BadgeUpdater) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::CreateBadgeUpdaterForSim2() const
    {
        void* updater{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->CreateBadgeUpdaterForSim2(&updater));
        return llm::OS::UI::Notifications::BadgeUpdater{ updater, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::ToastNotifier) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::CreateToastNotifierForSim1() const
    {
        void* notifier{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->CreateToastNotifierForSim1(&notifier));
        return llm::OS::UI::Notifications::ToastNotifier{ notifier, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::ToastNotifier) consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>::CreateToastNotifierForSim2() const
    {
        void* notifier{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IDualSimTileStatics)->CreateToastNotifierForSim2(&notifier));
        return llm::OS::UI::Notifications::ToastNotifier{ notifier, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::ToastNotifier) consume_Windows_Phone_StartScreen_IToastNotificationManagerStatics3<D>::CreateToastNotifierForSecondaryTile(param::hstring const& tileId) const
    {
        void* notifier{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::StartScreen::IToastNotificationManagerStatics3)->CreateToastNotifierForSecondaryTile(*(void**)(&tileId), &notifier));
        return llm::OS::UI::Notifications::ToastNotifier{ notifier, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::StartScreen::IDualSimTile> : produce_base<D, llm::OS::Phone::StartScreen::IDualSimTile>
    {
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPinnedToStart(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPinnedToStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().CreateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().UpdateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().DeleteAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::StartScreen::IDualSimTileStatics> : produce_base<D, llm::OS::Phone::StartScreen::IDualSimTileStatics>
    {
        int32_t __stdcall GetTileForSim2(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Phone::StartScreen::DualSimTile>(this->shim().GetTileForSim2());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateDisplayNameForSim1Async(void* name, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().UpdateDisplayNameForSim1Async(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTileUpdaterForSim1(void** updater) noexcept final try
        {
            clear_abi(updater);
            typename D::abi_guard guard(this->shim());
            *updater = detach_from<llm::OS::UI::Notifications::TileUpdater>(this->shim().CreateTileUpdaterForSim1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTileUpdaterForSim2(void** updater) noexcept final try
        {
            clear_abi(updater);
            typename D::abi_guard guard(this->shim());
            *updater = detach_from<llm::OS::UI::Notifications::TileUpdater>(this->shim().CreateTileUpdaterForSim2());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBadgeUpdaterForSim1(void** updater) noexcept final try
        {
            clear_abi(updater);
            typename D::abi_guard guard(this->shim());
            *updater = detach_from<llm::OS::UI::Notifications::BadgeUpdater>(this->shim().CreateBadgeUpdaterForSim1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBadgeUpdaterForSim2(void** updater) noexcept final try
        {
            clear_abi(updater);
            typename D::abi_guard guard(this->shim());
            *updater = detach_from<llm::OS::UI::Notifications::BadgeUpdater>(this->shim().CreateBadgeUpdaterForSim2());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateToastNotifierForSim1(void** notifier) noexcept final try
        {
            clear_abi(notifier);
            typename D::abi_guard guard(this->shim());
            *notifier = detach_from<llm::OS::UI::Notifications::ToastNotifier>(this->shim().CreateToastNotifierForSim1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateToastNotifierForSim2(void** notifier) noexcept final try
        {
            clear_abi(notifier);
            typename D::abi_guard guard(this->shim());
            *notifier = detach_from<llm::OS::UI::Notifications::ToastNotifier>(this->shim().CreateToastNotifierForSim2());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Phone::StartScreen::IToastNotificationManagerStatics3> : produce_base<D, llm::OS::Phone::StartScreen::IToastNotificationManagerStatics3>
    {
        int32_t __stdcall CreateToastNotifierForSecondaryTile(void* tileId, void** notifier) noexcept final try
        {
            clear_abi(notifier);
            typename D::abi_guard guard(this->shim());
            *notifier = detach_from<llm::OS::UI::Notifications::ToastNotifier>(this->shim().CreateToastNotifierForSecondaryTile(*reinterpret_cast<hstring const*>(&tileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::Phone::StartScreen
{
    inline DualSimTile::DualSimTile() :
        DualSimTile(impl::call_factory_cast<DualSimTile(*)(llm::OS::Foundation::IActivationFactory const&), DualSimTile>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DualSimTile>(); }))
    {
    }
    inline auto DualSimTile::GetTileForSim2()
    {
        return impl::call_factory_cast<llm::OS::Phone::StartScreen::DualSimTile(*)(IDualSimTileStatics const&), DualSimTile, IDualSimTileStatics>([](IDualSimTileStatics const& f) { return f.GetTileForSim2(); });
    }
    inline auto DualSimTile::UpdateDisplayNameForSim1Async(param::hstring const& name)
    {
        return impl::call_factory<DualSimTile, IDualSimTileStatics>([&](IDualSimTileStatics const& f) { return f.UpdateDisplayNameForSim1Async(name); });
    }
    inline auto DualSimTile::CreateTileUpdaterForSim1()
    {
        return impl::call_factory_cast<llm::OS::UI::Notifications::TileUpdater(*)(IDualSimTileStatics const&), DualSimTile, IDualSimTileStatics>([](IDualSimTileStatics const& f) { return f.CreateTileUpdaterForSim1(); });
    }
    inline auto DualSimTile::CreateTileUpdaterForSim2()
    {
        return impl::call_factory_cast<llm::OS::UI::Notifications::TileUpdater(*)(IDualSimTileStatics const&), DualSimTile, IDualSimTileStatics>([](IDualSimTileStatics const& f) { return f.CreateTileUpdaterForSim2(); });
    }
    inline auto DualSimTile::CreateBadgeUpdaterForSim1()
    {
        return impl::call_factory_cast<llm::OS::UI::Notifications::BadgeUpdater(*)(IDualSimTileStatics const&), DualSimTile, IDualSimTileStatics>([](IDualSimTileStatics const& f) { return f.CreateBadgeUpdaterForSim1(); });
    }
    inline auto DualSimTile::CreateBadgeUpdaterForSim2()
    {
        return impl::call_factory_cast<llm::OS::UI::Notifications::BadgeUpdater(*)(IDualSimTileStatics const&), DualSimTile, IDualSimTileStatics>([](IDualSimTileStatics const& f) { return f.CreateBadgeUpdaterForSim2(); });
    }
    inline auto DualSimTile::CreateToastNotifierForSim1()
    {
        return impl::call_factory_cast<llm::OS::UI::Notifications::ToastNotifier(*)(IDualSimTileStatics const&), DualSimTile, IDualSimTileStatics>([](IDualSimTileStatics const& f) { return f.CreateToastNotifierForSim1(); });
    }
    inline auto DualSimTile::CreateToastNotifierForSim2()
    {
        return impl::call_factory_cast<llm::OS::UI::Notifications::ToastNotifier(*)(IDualSimTileStatics const&), DualSimTile, IDualSimTileStatics>([](IDualSimTileStatics const& f) { return f.CreateToastNotifierForSim2(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Phone::StartScreen::IDualSimTile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::StartScreen::IDualSimTileStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::StartScreen::IToastNotificationManagerStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::StartScreen::DualSimTile> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
