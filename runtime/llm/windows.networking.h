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
#ifndef LLM_OS_Networking_H
#define LLM_OS_Networking_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Networking.Connectivity.2.h"
#include "llm/impl/Windows.Networking.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Networking_IEndpointPair<D>::LocalHostName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->get_LocalHostName(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_IEndpointPair<D>::LocalHostName(llm::OS::Networking::HostName const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->put_LocalHostName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_IEndpointPair<D>::LocalServiceName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->get_LocalServiceName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_IEndpointPair<D>::LocalServiceName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->put_LocalServiceName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Networking_IEndpointPair<D>::RemoteHostName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->get_RemoteHostName(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_IEndpointPair<D>::RemoteHostName(llm::OS::Networking::HostName const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->put_RemoteHostName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_IEndpointPair<D>::RemoteServiceName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->get_RemoteServiceName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_IEndpointPair<D>::RemoteServiceName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPair)->put_RemoteServiceName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::EndpointPair) consume_Windows_Networking_IEndpointPairFactory<D>::CreateEndpointPair(llm::OS::Networking::HostName const& localHostName, param::hstring const& localServiceName, llm::OS::Networking::HostName const& remoteHostName, param::hstring const& remoteServiceName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IEndpointPairFactory)->CreateEndpointPair(*(void**)(&localHostName), *(void**)(&localServiceName), *(void**)(&remoteHostName), *(void**)(&remoteServiceName), &value));
        return llm::OS::Networking::EndpointPair{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Connectivity::IPInformation) consume_Windows_Networking_IHostName<D>::IPInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostName)->get_IPInformation(&value));
        return llm::OS::Networking::Connectivity::IPInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_IHostName<D>::RawName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostName)->get_RawName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_IHostName<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostName)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_IHostName<D>::CanonicalName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostName)->get_CanonicalName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostNameType) consume_Windows_Networking_IHostName<D>::Type() const
    {
        llm::OS::Networking::HostNameType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostName)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_IHostName<D>::IsEqual(llm::OS::Networking::HostName const& hostName) const
    {
        bool isEqual{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostName)->IsEqual(*(void**)(&hostName), &isEqual));
        return isEqual;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Networking_IHostNameFactory<D>::CreateHostName(param::hstring const& hostName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostNameFactory)->CreateHostName(*(void**)(&hostName), &value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_IHostNameStatics<D>::Compare(param::hstring const& value1, param::hstring const& value2) const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::IHostNameStatics)->Compare(*(void**)(&value1), *(void**)(&value2), &result));
        return result;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::IEndpointPair> : produce_base<D, llm::OS::Networking::IEndpointPair>
    {
        int32_t __stdcall get_LocalHostName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().LocalHostName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LocalHostName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalHostName(*reinterpret_cast<llm::OS::Networking::HostName const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocalServiceName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LocalServiceName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LocalServiceName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalServiceName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteHostName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().RemoteHostName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemoteHostName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteHostName(*reinterpret_cast<llm::OS::Networking::HostName const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteServiceName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoteServiceName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemoteServiceName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteServiceName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::IEndpointPairFactory> : produce_base<D, llm::OS::Networking::IEndpointPairFactory>
    {
        int32_t __stdcall CreateEndpointPair(void* localHostName, void* localServiceName, void* remoteHostName, void* remoteServiceName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::EndpointPair>(this->shim().CreateEndpointPair(*reinterpret_cast<llm::OS::Networking::HostName const*>(&localHostName), *reinterpret_cast<hstring const*>(&localServiceName), *reinterpret_cast<llm::OS::Networking::HostName const*>(&remoteHostName), *reinterpret_cast<hstring const*>(&remoteServiceName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::IHostName> : produce_base<D, llm::OS::Networking::IHostName>
    {
        int32_t __stdcall get_IPInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Connectivity::IPInformation>(this->shim().IPInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RawName());
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
        int32_t __stdcall get_CanonicalName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CanonicalName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostNameType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsEqual(void* hostName, bool* isEqual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *isEqual = detach_from<bool>(this->shim().IsEqual(*reinterpret_cast<llm::OS::Networking::HostName const*>(&hostName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::IHostNameFactory> : produce_base<D, llm::OS::Networking::IHostNameFactory>
    {
        int32_t __stdcall CreateHostName(void* hostName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().CreateHostName(*reinterpret_cast<hstring const*>(&hostName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::IHostNameStatics> : produce_base<D, llm::OS::Networking::IHostNameStatics>
    {
        int32_t __stdcall Compare(void* value1, void* value2, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().Compare(*reinterpret_cast<hstring const*>(&value1), *reinterpret_cast<hstring const*>(&value2)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Networking
{
    constexpr auto operator|(HostNameSortOptions const left, HostNameSortOptions const right) noexcept
    {
        return static_cast<HostNameSortOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(HostNameSortOptions& left, HostNameSortOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(HostNameSortOptions const left, HostNameSortOptions const right) noexcept
    {
        return static_cast<HostNameSortOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(HostNameSortOptions& left, HostNameSortOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(HostNameSortOptions const value) noexcept
    {
        return static_cast<HostNameSortOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(HostNameSortOptions const left, HostNameSortOptions const right) noexcept
    {
        return static_cast<HostNameSortOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(HostNameSortOptions& left, HostNameSortOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline EndpointPair::EndpointPair(llm::OS::Networking::HostName const& localHostName, param::hstring const& localServiceName, llm::OS::Networking::HostName const& remoteHostName, param::hstring const& remoteServiceName) :
        EndpointPair(impl::call_factory<EndpointPair, IEndpointPairFactory>([&](IEndpointPairFactory const& f) { return f.CreateEndpointPair(localHostName, localServiceName, remoteHostName, remoteServiceName); }))
    {
    }
    inline HostName::HostName(param::hstring const& hostName) :
        HostName(impl::call_factory<HostName, IHostNameFactory>([&](IHostNameFactory const& f) { return f.CreateHostName(hostName); }))
    {
    }
    inline auto HostName::Compare(param::hstring const& value1, param::hstring const& value2)
    {
        return impl::call_factory<HostName, IHostNameStatics>([&](IHostNameStatics const& f) { return f.Compare(value1, value2); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Networking::IEndpointPair> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::IEndpointPairFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::IHostName> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::IHostNameFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::IHostNameStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::EndpointPair> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::HostName> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
    template<> struct formatter<llm::OS::Networking::HostName, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
#endif
}
#endif
