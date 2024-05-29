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
#ifndef LLM_OS_Foundation_1_H
#define LLM_OS_Foundation_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.Foundation.0.h"
LLM_EXPORT namespace llm::OS::Foundation
{
    struct __declspec(empty_bases) IAsyncAction :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAsyncAction>,
        impl::require<llm::OS::Foundation::IAsyncAction, llm::OS::Foundation::IAsyncInfo>
    {
        IAsyncAction(std::nullptr_t = nullptr) noexcept {}
        IAsyncAction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename TProgress>
    struct __declspec(empty_bases) IAsyncActionWithProgress :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>,
        impl::require<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>, llm::OS::Foundation::IAsyncInfo>
    {
        static_assert(impl::has_category_v<TProgress>, "TProgress must be WinRT type.");
        IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
        IAsyncActionWithProgress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAsyncInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAsyncInfo>
    {
        IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
        IAsyncInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename TResult, typename TProgress>
    struct __declspec(empty_bases) IAsyncOperationWithProgress :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>,
        impl::require<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>, llm::OS::Foundation::IAsyncInfo>
    {
        static_assert(impl::has_category_v<TResult>, "TResult must be WinRT type.");
        static_assert(impl::has_category_v<TProgress>, "TProgress must be WinRT type.");
        IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
        IAsyncOperationWithProgress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename TResult>
    struct __declspec(empty_bases) IAsyncOperation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::IAsyncOperation<TResult>>,
        impl::require<llm::OS::Foundation::IAsyncOperation<TResult>, llm::OS::Foundation::IAsyncInfo>
    {
        static_assert(impl::has_category_v<TResult>, "TResult must be WinRT type.");
        IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
        IAsyncOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClosable :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClosable>
    {
        IClosable(std::nullptr_t = nullptr) noexcept {}
        IClosable(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeferral>,
        impl::require<llm::OS::Foundation::IDeferral, llm::OS::Foundation::IClosable>
    {
        IDeferral(std::nullptr_t = nullptr) noexcept {}
        IDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeferralFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeferralFactory>
    {
        IDeferralFactory(std::nullptr_t = nullptr) noexcept {}
        IDeferralFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGetActivationFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGetActivationFactory>
    {
        IGetActivationFactory(std::nullptr_t = nullptr) noexcept {}
        IGetActivationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidHelperStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGuidHelperStatics>
    {
        IGuidHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IGuidHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMemoryBuffer :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMemoryBuffer>,
        impl::require<llm::OS::Foundation::IMemoryBuffer, llm::OS::Foundation::IClosable>
    {
        IMemoryBuffer(std::nullptr_t = nullptr) noexcept {}
        IMemoryBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMemoryBufferFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMemoryBufferFactory>
    {
        IMemoryBufferFactory(std::nullptr_t = nullptr) noexcept {}
        IMemoryBufferFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMemoryBufferReference :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMemoryBufferReference>,
        impl::require<llm::OS::Foundation::IMemoryBufferReference, llm::OS::Foundation::IClosable>
    {
        IMemoryBufferReference(std::nullptr_t = nullptr) noexcept {}
        IMemoryBufferReference(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPropertyValue :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPropertyValue>
    {
        IPropertyValue(std::nullptr_t = nullptr) noexcept {}
        IPropertyValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPropertyValueStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPropertyValueStatics>
    {
        IPropertyValueStatics(std::nullptr_t = nullptr) noexcept {}
        IPropertyValueStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename T>
    struct __declspec(empty_bases) IReferenceArray :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::IReferenceArray<T>>,
        impl::require<llm::OS::Foundation::IReferenceArray<T>, llm::OS::Foundation::IPropertyValue>
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        IReferenceArray(std::nullptr_t = nullptr) noexcept {}
        IReferenceArray(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename T>
    struct __declspec(empty_bases) IReference :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::IReference<T>>,
        impl::require<llm::OS::Foundation::IReference<T>, llm::OS::Foundation::IPropertyValue>
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        IReference(std::nullptr_t = nullptr) noexcept {}
        IReference(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IReference(T const& value) : IReference(impl::reference_traits<T>::make(value))
        {
        }
        IReference(std::optional<T> const& value) : IReference(value ? IReference(value.value()) : nullptr)
        {
        }
        operator std::optional<T>() const
        {
            if (*this)
            {
                return this->Value();
            }
            else
            {
                return std::nullopt;
            }
        }
    private:
        IReference(IInspectable const& value) : IReference(value.as<IReference>())
        {
        }
    };
    struct __declspec(empty_bases) IStringable :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStringable>
    {
        IStringable(std::nullptr_t = nullptr) noexcept {}
        IStringable(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUriEscapeStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUriEscapeStatics>
    {
        IUriEscapeStatics(std::nullptr_t = nullptr) noexcept {}
        IUriEscapeStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUriRuntimeClass :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUriRuntimeClass>
    {
        IUriRuntimeClass(std::nullptr_t = nullptr) noexcept {}
        IUriRuntimeClass(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUriRuntimeClassFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUriRuntimeClassFactory>
    {
        IUriRuntimeClassFactory(std::nullptr_t = nullptr) noexcept {}
        IUriRuntimeClassFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUriRuntimeClassWithAbsoluteCanonicalUri :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUriRuntimeClassWithAbsoluteCanonicalUri>
    {
        IUriRuntimeClassWithAbsoluteCanonicalUri(std::nullptr_t = nullptr) noexcept {}
        IUriRuntimeClassWithAbsoluteCanonicalUri(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWwwFormUrlDecoderEntry :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWwwFormUrlDecoderEntry>
    {
        IWwwFormUrlDecoderEntry(std::nullptr_t = nullptr) noexcept {}
        IWwwFormUrlDecoderEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWwwFormUrlDecoderRuntimeClass :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWwwFormUrlDecoderRuntimeClass>,
        impl::require<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::IWwwFormUrlDecoderEntry>, llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::IWwwFormUrlDecoderEntry>>
    {
        IWwwFormUrlDecoderRuntimeClass(std::nullptr_t = nullptr) noexcept {}
        IWwwFormUrlDecoderRuntimeClass(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWwwFormUrlDecoderRuntimeClassFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWwwFormUrlDecoderRuntimeClassFactory>
    {
        IWwwFormUrlDecoderRuntimeClassFactory(std::nullptr_t = nullptr) noexcept {}
        IWwwFormUrlDecoderRuntimeClassFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}

LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename T>
    bool operator==(IReference<T> const& left, IReference<T> const& right);

    template <typename T>
    bool operator!=(IReference<T> const& left, IReference<T> const& right);
}

#ifdef __cpp_lib_format
template <>
struct std::formatter<llm::OS::Foundation::IStringable, wchar_t> : std::formatter<llm::hstring, wchar_t>
{
    template <typename FormatContext>
    auto format(llm::OS::Foundation::IStringable const& obj, FormatContext& fc);
};
#endif
#endif
