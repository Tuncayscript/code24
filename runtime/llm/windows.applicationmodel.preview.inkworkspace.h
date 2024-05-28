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
#ifndef LLM_OS_ApplicationModel_Preview_InkWorkspace_H
#define LLM_OS_ApplicationModel_Preview_InkWorkspace_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.ApplicationModel.Preview.InkWorkspace.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManager<D>::SetThumbnailAsync(llm::OS::Graphics::Imaging::SoftwareBitmap const& bitmap) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager)->SetThumbnailAsync(*(void**)(&bitmap), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager) consume_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManagerStatics<D>::GetForCurrentApp() const
    {
        void* current{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics)->GetForCurrentApp(&current));
        return llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager{ current, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager> : produce_base<D, llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager>
    {
        int32_t __stdcall SetThumbnailAsync(void* bitmap, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetThumbnailAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&bitmap)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics>
    {
        int32_t __stdcall GetForCurrentApp(void** current) noexcept final try
        {
            clear_abi(current);
            typename D::abi_guard guard(this->shim());
            *current = detach_from<llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager>(this->shim().GetForCurrentApp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::InkWorkspace
{
    inline auto InkWorkspaceHostedAppManager::GetForCurrentApp()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager(*)(IInkWorkspaceHostedAppManagerStatics const&), InkWorkspaceHostedAppManager, IInkWorkspaceHostedAppManagerStatics>([](IInkWorkspaceHostedAppManagerStatics const& f) { return f.GetForCurrentApp(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
