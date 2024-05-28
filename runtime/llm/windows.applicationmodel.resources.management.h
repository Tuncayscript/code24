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
#ifndef LLM_OS_ApplicationModel_Resources_Management_H
#define LLM_OS_ApplicationModel_Resources_Management_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Resources.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.ApplicationModel.Resources.Management.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Resources::Management::IndexedResourceType) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceCandidate<D>::Type() const
    {
        llm::OS::ApplicationModel::Resources::Management::IndexedResourceType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceCandidate<D>::Uri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate)->get_Uri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, hstring>) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceCandidate<D>::Metadata() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate)->get_Metadata(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Management::IndexedResourceQualifier>) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceCandidate<D>::Qualifiers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate)->get_Qualifiers(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Management::IndexedResourceQualifier>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceCandidate<D>::ValueAsString() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate)->get_ValueAsString(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceCandidate<D>::GetQualifierValue(param::hstring const& qualifierName) const
    {
        void* qualifierValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate)->GetQualifierValue(*(void**)(&qualifierName), &qualifierValue));
        return hstring{ qualifierValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceQualifier<D>::QualifierName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceQualifier)->get_QualifierName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Resources_Management_IIndexedResourceQualifier<D>::QualifierValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IIndexedResourceQualifier)->get_QualifierValue(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Resources::Management::IndexedResourceCandidate) consume_Windows_ApplicationModel_Resources_Management_IResourceIndexer<D>::IndexFilePath(llm::OS::Foundation::Uri const& filePath) const
    {
        void* candidate{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IResourceIndexer)->IndexFilePath(*(void**)(&filePath), &candidate));
        return llm::OS::ApplicationModel::Resources::Management::IndexedResourceCandidate{ candidate, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Management::IndexedResourceCandidate>>) consume_Windows_ApplicationModel_Resources_Management_IResourceIndexer<D>::IndexFileContentsAsync(llm::OS::Foundation::Uri const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IResourceIndexer)->IndexFileContentsAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Management::IndexedResourceCandidate>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Resources::Management::ResourceIndexer) consume_Windows_ApplicationModel_Resources_Management_IResourceIndexerFactory<D>::CreateResourceIndexer(llm::OS::Foundation::Uri const& projectRoot) const
    {
        void* indexer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory)->CreateResourceIndexer(*(void**)(&projectRoot), &indexer));
        return llm::OS::ApplicationModel::Resources::Management::ResourceIndexer{ indexer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Resources::Management::ResourceIndexer) consume_Windows_ApplicationModel_Resources_Management_IResourceIndexerFactory2<D>::CreateResourceIndexerWithExtension(llm::OS::Foundation::Uri const& projectRoot, llm::OS::Foundation::Uri const& extensionDllPath) const
    {
        void* indexer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory2)->CreateResourceIndexerWithExtension(*(void**)(&projectRoot), *(void**)(&extensionDllPath), &indexer));
        return llm::OS::ApplicationModel::Resources::Management::ResourceIndexer{ indexer, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate> : produce_base<D, llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Resources::Management::IndexedResourceType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Uri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Uri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Metadata(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, hstring>>(this->shim().Metadata());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Qualifiers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Management::IndexedResourceQualifier>>(this->shim().Qualifiers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ValueAsString(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ValueAsString());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetQualifierValue(void* qualifierName, void** qualifierValue) noexcept final try
        {
            clear_abi(qualifierValue);
            typename D::abi_guard guard(this->shim());
            *qualifierValue = detach_from<hstring>(this->shim().GetQualifierValue(*reinterpret_cast<hstring const*>(&qualifierName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Resources::Management::IIndexedResourceQualifier> : produce_base<D, llm::OS::ApplicationModel::Resources::Management::IIndexedResourceQualifier>
    {
        int32_t __stdcall get_QualifierName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().QualifierName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QualifierValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().QualifierValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Resources::Management::IResourceIndexer> : produce_base<D, llm::OS::ApplicationModel::Resources::Management::IResourceIndexer>
    {
        int32_t __stdcall IndexFilePath(void* filePath, void** candidate) noexcept final try
        {
            clear_abi(candidate);
            typename D::abi_guard guard(this->shim());
            *candidate = detach_from<llm::OS::ApplicationModel::Resources::Management::IndexedResourceCandidate>(this->shim().IndexFilePath(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&filePath)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IndexFileContentsAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Management::IndexedResourceCandidate>>>(this->shim().IndexFileContentsAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory> : produce_base<D, llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory>
    {
        int32_t __stdcall CreateResourceIndexer(void* projectRoot, void** indexer) noexcept final try
        {
            clear_abi(indexer);
            typename D::abi_guard guard(this->shim());
            *indexer = detach_from<llm::OS::ApplicationModel::Resources::Management::ResourceIndexer>(this->shim().CreateResourceIndexer(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&projectRoot)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory2> : produce_base<D, llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory2>
    {
        int32_t __stdcall CreateResourceIndexerWithExtension(void* projectRoot, void* extensionDllPath, void** indexer) noexcept final try
        {
            clear_abi(indexer);
            typename D::abi_guard guard(this->shim());
            *indexer = detach_from<llm::OS::ApplicationModel::Resources::Management::ResourceIndexer>(this->shim().CreateResourceIndexerWithExtension(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&projectRoot), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&extensionDllPath)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Resources::Management
{
    inline ResourceIndexer::ResourceIndexer(llm::OS::Foundation::Uri const& projectRoot) :
        ResourceIndexer(impl::call_factory<ResourceIndexer, IResourceIndexerFactory>([&](IResourceIndexerFactory const& f) { return f.CreateResourceIndexer(projectRoot); }))
    {
    }
    inline ResourceIndexer::ResourceIndexer(llm::OS::Foundation::Uri const& projectRoot, llm::OS::Foundation::Uri const& extensionDllPath) :
        ResourceIndexer(impl::call_factory<ResourceIndexer, IResourceIndexerFactory2>([&](IResourceIndexerFactory2 const& f) { return f.CreateResourceIndexerWithExtension(projectRoot, extensionDllPath); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::IIndexedResourceQualifier> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::IResourceIndexer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::IResourceIndexerFactory2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::IndexedResourceCandidate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::IndexedResourceQualifier> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Resources::Management::ResourceIndexer> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
