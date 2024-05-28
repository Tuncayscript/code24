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
#ifndef LLM_OS_ApplicationModel_DataTransfer_ShareTarget_H
#define LLM_OS_ApplicationModel_DataTransfer_ShareTarget_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.DataTransfer.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.2.h"
#include "llm/impl/Windows.ApplicationModel.DataTransfer.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.DataTransfer.ShareTarget.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->get_Thumbnail(&value));
        return llm::OS::Storage::Streams::RandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::Thumbnail(llm::OS::Storage::Streams::RandomAccessStreamReference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->put_Thumbnail(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::Id(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->put_Id(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::SupportedDataFormats() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->get_SupportedDataFormats(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IQuickLink<D>::SupportedFileTypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink)->get_SupportedFileTypes(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageView) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::Data() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->get_Data(&value));
        return llm::OS::ApplicationModel::DataTransfer::DataPackageView{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::QuickLinkId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->get_QuickLinkId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::RemoveThisQuickLink() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->RemoveThisQuickLink());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::ReportStarted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->ReportStarted());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::ReportDataRetrieved() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->ReportDataRetrieved());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::ReportSubmittedBackgroundTask() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->ReportSubmittedBackgroundTask());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::ReportCompleted(llm::OS::ApplicationModel::DataTransfer::ShareTarget::QuickLink const& quicklink) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->ReportCompletedWithQuickLink(*(void**)(&quicklink)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::ReportCompleted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->ReportCompleted());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation<D>::ReportError(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation)->ReportError(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation2<D>::DismissUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2)->DismissUI());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::Contact>) consume_Windows_ApplicationModel_DataTransfer_ShareTarget_IShareOperation3<D>::Contacts() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation3)->get_Contacts(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::Contact>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink> : produce_base<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>
    {
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::RandomAccessStreamReference>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Thumbnail(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<llm::OS::Storage::Streams::RandomAccessStreamReference const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Id(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedDataFormats(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().SupportedDataFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedFileTypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().SupportedFileTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation> : produce_base<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>
    {
        int32_t __stdcall get_Data(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::DataTransfer::DataPackageView>(this->shim().Data());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QuickLinkId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().QuickLinkId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveThisQuickLink() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveThisQuickLink();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportStarted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportStarted();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportDataRetrieved() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportDataRetrieved();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportSubmittedBackgroundTask() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportSubmittedBackgroundTask();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompletedWithQuickLink(void* quicklink) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<llm::OS::ApplicationModel::DataTransfer::ShareTarget::QuickLink const*>(&quicklink));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportError(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2> : produce_base<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2>
    {
        int32_t __stdcall DismissUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation3> : produce_base<D, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation3>
    {
        int32_t __stdcall get_Contacts(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::Contact>>(this->shim().Contacts());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer::ShareTarget
{
    inline QuickLink::QuickLink() :
        QuickLink(impl::call_factory_cast<QuickLink(*)(llm::OS::Foundation::IActivationFactory const&), QuickLink>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<QuickLink>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::DataTransfer::ShareTarget::QuickLink> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::DataTransfer::ShareTarget::ShareOperation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
