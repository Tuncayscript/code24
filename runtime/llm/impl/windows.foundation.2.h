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
#ifndef LLM_OS_Foundation_2_H
#define LLM_OS_Foundation_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Foundation.1.h"
LLM_EXPORT namespace llm::OS::Foundation
{
    struct AsyncActionCompletedHandler : llm::OS::Foundation::IUnknown
    {
        AsyncActionCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        AsyncActionCompletedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> AsyncActionCompletedHandler(L lambda);
        template <typename F> AsyncActionCompletedHandler(F* function);
        template <typename O, typename M> AsyncActionCompletedHandler(O* object, M method);
        template <typename O, typename M> AsyncActionCompletedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> AsyncActionCompletedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IAsyncAction const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const;
    };
    template <typename TProgress>
    struct AsyncActionProgressHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<TProgress>, "TProgress must be WinRT type.");
        AsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
        AsyncActionProgressHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> AsyncActionProgressHandler(L lambda);
        template <typename F> AsyncActionProgressHandler(F* function);
        template <typename O, typename M> AsyncActionProgressHandler(O* object, M method);
        template <typename O, typename M> AsyncActionProgressHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> AsyncActionProgressHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IAsyncActionWithProgress<TProgress> const& asyncInfo, impl::param_type<TProgress> const& progressInfo) const;
    };
    template <typename TProgress>
    struct AsyncActionWithProgressCompletedHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<TProgress>, "TProgress must be WinRT type.");
        AsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        AsyncActionWithProgressCompletedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> AsyncActionWithProgressCompletedHandler(L lambda);
        template <typename F> AsyncActionWithProgressCompletedHandler(F* function);
        template <typename O, typename M> AsyncActionWithProgressCompletedHandler(O* object, M method);
        template <typename O, typename M> AsyncActionWithProgressCompletedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> AsyncActionWithProgressCompletedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IAsyncActionWithProgress<TProgress> const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const;
    };
    template <typename TResult>
    struct AsyncOperationCompletedHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<TResult>, "TResult must be WinRT type.");
        AsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        AsyncOperationCompletedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> AsyncOperationCompletedHandler(L lambda);
        template <typename F> AsyncOperationCompletedHandler(F* function);
        template <typename O, typename M> AsyncOperationCompletedHandler(O* object, M method);
        template <typename O, typename M> AsyncOperationCompletedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> AsyncOperationCompletedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IAsyncOperation<TResult> const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const;
    };
    template <typename TResult, typename TProgress>
    struct AsyncOperationProgressHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<TResult>, "TResult must be WinRT type.");
        static_assert(impl::has_category_v<TProgress>, "TProgress must be WinRT type.");
        AsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
        AsyncOperationProgressHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> AsyncOperationProgressHandler(L lambda);
        template <typename F> AsyncOperationProgressHandler(F* function);
        template <typename O, typename M> AsyncOperationProgressHandler(O* object, M method);
        template <typename O, typename M> AsyncOperationProgressHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> AsyncOperationProgressHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const& asyncInfo, impl::param_type<TProgress> const& progressInfo) const;
    };
    template <typename TResult, typename TProgress>
    struct AsyncOperationWithProgressCompletedHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<TResult>, "TResult must be WinRT type.");
        static_assert(impl::has_category_v<TProgress>, "TProgress must be WinRT type.");
        AsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        AsyncOperationWithProgressCompletedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> AsyncOperationWithProgressCompletedHandler(L lambda);
        template <typename F> AsyncOperationWithProgressCompletedHandler(F* function);
        template <typename O, typename M> AsyncOperationWithProgressCompletedHandler(O* object, M method);
        template <typename O, typename M> AsyncOperationWithProgressCompletedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> AsyncOperationWithProgressCompletedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const;
    };
    struct DeferralCompletedHandler : llm::OS::Foundation::IUnknown
    {
        DeferralCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        DeferralCompletedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DeferralCompletedHandler(L lambda);
        template <typename F> DeferralCompletedHandler(F* function);
        template <typename O, typename M> DeferralCompletedHandler(O* object, M method);
        template <typename O, typename M> DeferralCompletedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DeferralCompletedHandler(weak_ref<O>&& object, M method);
        auto operator()() const;
    };
    template <typename T>
    struct EventHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        EventHandler(std::nullptr_t = nullptr) noexcept {}
        EventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> EventHandler(L lambda);
        template <typename F> EventHandler(F* function);
        template <typename O, typename M> EventHandler(O* object, M method);
        template <typename O, typename M> EventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> EventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, impl::param_type<T> const& args) const;
    };
    template <typename TSender, typename TResult>
    struct TypedEventHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<TSender>, "TSender must be WinRT type.");
        static_assert(impl::has_category_v<TResult>, "TResult must be WinRT type.");
        TypedEventHandler(std::nullptr_t = nullptr) noexcept {}
        TypedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> TypedEventHandler(L lambda);
        template <typename F> TypedEventHandler(F* function);
        template <typename O, typename M> TypedEventHandler(O* object, M method);
        template <typename O, typename M> TypedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> TypedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(impl::param_type<TSender> const& sender, impl::param_type<TResult> const& args) const;
    };
    struct __declspec(empty_bases) Deferral : llm::OS::Foundation::IDeferral
    {
        Deferral(std::nullptr_t) noexcept {}
        Deferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IDeferral(ptr, take_ownership_from_abi) {}
        explicit Deferral(llm::OS::Foundation::DeferralCompletedHandler const& handler);
    };
    struct GuidHelper
    {
        GuidHelper() = delete;
        static auto CreateNewGuid();
        [[nodiscard]] static auto Empty();
        static auto Equals(llm::guid const& target, llm::guid const& value);
    };
    struct __declspec(empty_bases) MemoryBuffer : llm::OS::Foundation::IMemoryBuffer
    {
        MemoryBuffer(std::nullptr_t) noexcept {}
        MemoryBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IMemoryBuffer(ptr, take_ownership_from_abi) {}
        explicit MemoryBuffer(uint32_t capacity);
    };
    struct PropertyValue
    {
        PropertyValue() = delete;
        static auto CreateEmpty();
        static auto CreateUInt8(uint8_t value);
        static auto CreateInt16(int16_t value);
        static auto CreateUInt16(uint16_t value);
        static auto CreateInt32(int32_t value);
        static auto CreateUInt32(uint32_t value);
        static auto CreateInt64(int64_t value);
        static auto CreateUInt64(uint64_t value);
        static auto CreateSingle(float value);
        static auto CreateDouble(double value);
        static auto CreateChar16(char16_t value);
        static auto CreateBoolean(bool value);
        static auto CreateString(param::hstring const& value);
        static auto CreateInspectable(llm::OS::Foundation::IInspectable const& value);
        static auto CreateGuid(llm::guid const& value);
        static auto CreateDateTime(llm::OS::Foundation::DateTime const& value);
        static auto CreateTimeSpan(llm::OS::Foundation::TimeSpan const& value);
        static auto CreatePoint(llm::OS::Foundation::Point const& value);
        static auto CreateSize(llm::OS::Foundation::Size const& value);
        static auto CreateRect(llm::OS::Foundation::Rect const& value);
        static auto CreateUInt8Array(array_view<uint8_t const> value);
        static auto CreateInt16Array(array_view<int16_t const> value);
        static auto CreateUInt16Array(array_view<uint16_t const> value);
        static auto CreateInt32Array(array_view<int32_t const> value);
        static auto CreateUInt32Array(array_view<uint32_t const> value);
        static auto CreateInt64Array(array_view<int64_t const> value);
        static auto CreateUInt64Array(array_view<uint64_t const> value);
        static auto CreateSingleArray(array_view<float const> value);
        static auto CreateDoubleArray(array_view<double const> value);
        static auto CreateChar16Array(array_view<char16_t const> value);
        static auto CreateBooleanArray(array_view<bool const> value);
        static auto CreateStringArray(array_view<hstring const> value);
        static auto CreateInspectableArray(array_view<llm::OS::Foundation::IInspectable const> value);
        static auto CreateGuidArray(array_view<llm::guid const> value);
        static auto CreateDateTimeArray(array_view<llm::OS::Foundation::DateTime const> value);
        static auto CreateTimeSpanArray(array_view<llm::OS::Foundation::TimeSpan const> value);
        static auto CreatePointArray(array_view<llm::OS::Foundation::Point const> value);
        static auto CreateSizeArray(array_view<llm::OS::Foundation::Size const> value);
        static auto CreateRectArray(array_view<llm::OS::Foundation::Rect const> value);
    };
    struct __declspec(empty_bases) Uri : llm::OS::Foundation::IUriRuntimeClass,
        impl::require<Uri, llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri, llm::OS::Foundation::IStringable>
    {
        Uri(std::nullptr_t) noexcept {}
        Uri(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUriRuntimeClass(ptr, take_ownership_from_abi) {}
        explicit Uri(param::hstring const& uri);
        Uri(param::hstring const& baseUri, param::hstring const& relativeUri);
        static auto UnescapeComponent(param::hstring const& toUnescape);
        static auto EscapeComponent(param::hstring const& toEscape);
    };
    struct __declspec(empty_bases) WwwFormUrlDecoder : llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass
    {
        WwwFormUrlDecoder(std::nullptr_t) noexcept {}
        WwwFormUrlDecoder(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass(ptr, take_ownership_from_abi) {}
        explicit WwwFormUrlDecoder(param::hstring const& query);
    };
    struct __declspec(empty_bases) WwwFormUrlDecoderEntry : llm::OS::Foundation::IWwwFormUrlDecoderEntry
    {
        WwwFormUrlDecoderEntry(std::nullptr_t) noexcept {}
        WwwFormUrlDecoderEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IWwwFormUrlDecoderEntry(ptr, take_ownership_from_abi) {}
    };
}
#endif
