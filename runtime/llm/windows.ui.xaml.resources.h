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
#ifndef LLM_OS_UI_Xaml_Resources_H
#define LLM_OS_UI_Xaml_Resources_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Xaml.h"
#include "llm/impl/Windows.UI.Xaml.Resources.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader) consume_Windows_UI_Xaml_Resources_ICustomXamlResourceLoaderFactory<D>::CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory)->CreateInstance(*(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Resources_ICustomXamlResourceLoaderOverrides<D>::GetResource(param::hstring const& resourceId, param::hstring const& objectType, param::hstring const& propertyName, param::hstring const& propertyType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides)->GetResource(*(void**)(&resourceId), *(void**)(&objectType), *(void**)(&propertyName), *(void**)(&propertyType), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader) consume_Windows_UI_Xaml_Resources_ICustomXamlResourceLoaderStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics)->get_Current(&value));
        return llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Resources_ICustomXamlResourceLoaderStatics<D>::Current(llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics)->put_Current(*(void**)(&value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoader> : produce_base<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoader>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory> : produce_base<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory>
    {
        int32_t __stdcall CreateInstance(void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides> : produce_base<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
    {
        int32_t __stdcall GetResource(void* resourceId, void* objectType, void* propertyName, void* propertyType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetResource(*reinterpret_cast<hstring const*>(&resourceId), *reinterpret_cast<hstring const*>(&objectType), *reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<hstring const*>(&propertyType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics> : produce_base<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Current(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Current(*reinterpret_cast<llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
{
    auto GetResource(hstring const& resourceId, hstring const& objectType, hstring const& propertyName, hstring const& propertyType)
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetResource(resourceId, objectType, propertyName, propertyType);
        }

        return this->shim().GetResource(resourceId, objectType, propertyName, propertyType);
    }
};
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Resources
{
    inline CustomXamlResourceLoader::CustomXamlResourceLoader()
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderFactory>([&](ICustomXamlResourceLoaderFactory const& f) { return f.CreateInstance(baseInterface, innerInterface); });
    }
    inline auto CustomXamlResourceLoader::Current()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader(*)(ICustomXamlResourceLoaderStatics const&), CustomXamlResourceLoader, ICustomXamlResourceLoaderStatics>([](ICustomXamlResourceLoaderStatics const& f) { return f.Current(); });
    }
    inline auto CustomXamlResourceLoader::Current(llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader const& value)
    {
        impl::call_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderStatics>([&](ICustomXamlResourceLoaderStatics const& f) { return f.Current(value); });
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) ICustomXamlResourceLoaderOverridesT<D>::GetResource(param::hstring const& resourceId, param::hstring const& objectType, param::hstring const& propertyName, param::hstring const& propertyType) const
    {
        return shim().template try_as<ICustomXamlResourceLoaderOverrides>().GetResource(resourceId, objectType, propertyName, propertyType);
    }
    template <typename D, typename... Interfaces>
    struct CustomXamlResourceLoaderT :
        implements<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoader>,
        impl::base<D, CustomXamlResourceLoader>,
        llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverridesT<D>
    {
        using composable = CustomXamlResourceLoader;
    protected:
        CustomXamlResourceLoaderT()
        {
            impl::call_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderFactory>([&](ICustomXamlResourceLoaderFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstance(*this, this->m_inner); });
        }
    };
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
