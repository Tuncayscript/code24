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
#ifndef LLM_OS_Foundation_H
#define LLM_OS_Foundation_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncAction<D>::Completed(llm::OS::Foundation::AsyncActionCompletedHandler const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncAction)->put_Completed(*(void**)(&handler)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::AsyncActionCompletedHandler) consume_Windows_Foundation_IAsyncAction<D>::Completed() const
    {
        void* handler{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncAction)->get_Completed(&handler));
        return llm::OS::Foundation::AsyncActionCompletedHandler{ handler, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncAction<D>::GetResults() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncAction)->GetResults());
    }
    template <typename D, typename TProgress> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>::Progress(llm::OS::Foundation::AsyncActionProgressHandler<TProgress> const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncActionWithProgress<TProgress>)->put_Progress(*(void**)(&handler)));
    }
    template <typename D, typename TProgress> LLM_IMPL_AUTO(llm::OS::Foundation::AsyncActionProgressHandler<TProgress>) consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>::Progress() const
    {
        void* llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncActionWithProgress<TProgress>)->get_Progress(&llm_impl_result));
        return llm::OS::Foundation::AsyncActionProgressHandler<TProgress>{ llm_impl_result, take_ownership_from_abi };
    }
    template <typename D, typename TProgress> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>::Completed(llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncActionWithProgress<TProgress>)->put_Completed(*(void**)(&handler)));
    }
    template <typename D, typename TProgress> LLM_IMPL_AUTO(llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>) consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>::Completed() const
    {
        void* llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncActionWithProgress<TProgress>)->get_Completed(&llm_impl_result));
        return llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>{ llm_impl_result, take_ownership_from_abi };
    }
    template <typename D, typename TProgress> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>::GetResults() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncActionWithProgress<TProgress>)->GetResults());
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Foundation_IAsyncInfo<D>::Id() const
    {
        uint32_t llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncInfo)->get_Id(&llm_impl_result));
        return llm_impl_result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::AsyncStatus) consume_Windows_Foundation_IAsyncInfo<D>::Status() const
    {
        llm::OS::Foundation::AsyncStatus llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncInfo)->get_Status(reinterpret_cast<int32_t*>(&llm_impl_result)));
        return llm_impl_result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Foundation_IAsyncInfo<D>::ErrorCode() const
    {
        llm::hresult llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncInfo)->get_ErrorCode(put_abi(llm_impl_result)));
        return llm_impl_result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncInfo<D>::Cancel() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncInfo)->Cancel());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncInfo<D>::Close() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncInfo)->Close());
    }
    template <typename D, typename TResult, typename TProgress> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress(llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress> const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>)->put_Progress(*(void**)(&handler)));
    }
    template <typename D, typename TResult, typename TProgress> LLM_IMPL_AUTO(llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>) consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress() const
    {
        void* llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>)->get_Progress(&llm_impl_result));
        return llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>{ llm_impl_result, take_ownership_from_abi };
    }
    template <typename D, typename TResult, typename TProgress> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed(llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>)->put_Completed(*(void**)(&handler)));
    }
    template <typename D, typename TResult, typename TProgress> LLM_IMPL_AUTO(llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>) consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed() const
    {
        void* llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>)->get_Completed(&llm_impl_result));
        return llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>{ llm_impl_result, take_ownership_from_abi };
    }
    template <typename D, typename TResult, typename TProgress> LLM_IMPL_AUTO(TResult) consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>::GetResults() const
    {
        TResult llm_impl_result{ empty_value<TResult>() };
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>)->GetResults(put_abi(llm_impl_result)));
        return llm_impl_result;
    }
    template <typename D, typename TResult> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IAsyncOperation<D, TResult>::Completed(llm::OS::Foundation::AsyncOperationCompletedHandler<TResult> const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperation<TResult>)->put_Completed(*(void**)(&handler)));
    }
    template <typename D, typename TResult> LLM_IMPL_AUTO(llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>) consume_Windows_Foundation_IAsyncOperation<D, TResult>::Completed() const
    {
        void* llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperation<TResult>)->get_Completed(&llm_impl_result));
        return llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>{ llm_impl_result, take_ownership_from_abi };
    }
    template <typename D, typename TResult> LLM_IMPL_AUTO(TResult) consume_Windows_Foundation_IAsyncOperation<D, TResult>::GetResults() const
    {
        TResult llm_impl_result{ empty_value<TResult>() };
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IAsyncOperation<TResult>)->GetResults(put_abi(llm_impl_result)));
        return llm_impl_result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IClosable<D>::Close() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IClosable)->Close());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Foundation_IDeferralFactory<D>::Create(llm::OS::Foundation::DeferralCompletedHandler const& handler) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IDeferralFactory)->Create(*(void**)(&handler), &result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IGetActivationFactory<D>::GetActivationFactory(param::hstring const& activatableClassId) const
    {
        void* factory{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IGetActivationFactory)->GetActivationFactory(*(void**)(&activatableClassId), &factory));
        return llm::OS::Foundation::IInspectable{ factory, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Foundation_IGuidHelperStatics<D>::CreateNewGuid() const
    {
        llm::guid result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IGuidHelperStatics)->CreateNewGuid(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Foundation_IGuidHelperStatics<D>::Empty() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IGuidHelperStatics)->get_Empty(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Foundation_IGuidHelperStatics<D>::Equals(llm::guid const& target, llm::guid const& value) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IGuidHelperStatics)->Equals(impl::bind_in(target), impl::bind_in(value), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IMemoryBufferReference) consume_Windows_Foundation_IMemoryBuffer<D>::CreateReference() const
    {
        void* reference{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IMemoryBuffer)->CreateReference(&reference));
        return llm::OS::Foundation::IMemoryBufferReference{ reference, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::MemoryBuffer) consume_Windows_Foundation_IMemoryBufferFactory<D>::Create(uint32_t capacity) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IMemoryBufferFactory)->Create(capacity, &value));
        return llm::OS::Foundation::MemoryBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Foundation_IMemoryBufferReference<D>::Capacity() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IMemoryBufferReference)->get_Capacity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Foundation_IMemoryBufferReference<D>::Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IMemoryBufferReference, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IMemoryBufferReference)->add_Closed(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Foundation_IMemoryBufferReference<D>::Closed_revoker consume_Windows_Foundation_IMemoryBufferReference<D>::Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IMemoryBufferReference, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Closed_revoker>(this, Closed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IMemoryBufferReference<D>::Closed(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Foundation::IMemoryBufferReference)->remove_Closed(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::PropertyType) consume_Windows_Foundation_IPropertyValue<D>::Type() const
    {
        llm::OS::Foundation::PropertyType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Foundation_IPropertyValue<D>::IsNumericScalar() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->get_IsNumericScalar(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Foundation_IPropertyValue<D>::GetUInt8() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt8(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int16_t) consume_Windows_Foundation_IPropertyValue<D>::GetInt16() const
    {
        int16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetInt16(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Foundation_IPropertyValue<D>::GetUInt16() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt16(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Foundation_IPropertyValue<D>::GetInt32() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetInt32(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Foundation_IPropertyValue<D>::GetUInt32() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt32(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int64_t) consume_Windows_Foundation_IPropertyValue<D>::GetInt64() const
    {
        int64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetInt64(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Foundation_IPropertyValue<D>::GetUInt64() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt64(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Foundation_IPropertyValue<D>::GetSingle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetSingle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Foundation_IPropertyValue<D>::GetDouble() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetDouble(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(char16_t) consume_Windows_Foundation_IPropertyValue<D>::GetChar16() const
    {
        char16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetChar16(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Foundation_IPropertyValue<D>::GetBoolean() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetBoolean(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IPropertyValue<D>::GetString() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetString(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Foundation_IPropertyValue<D>::GetGuid() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetGuid(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Foundation_IPropertyValue<D>::GetDateTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetDateTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Foundation_IPropertyValue<D>::GetTimeSpan() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetTimeSpan(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Foundation_IPropertyValue<D>::GetPoint() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Foundation_IPropertyValue<D>::GetSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Foundation_IPropertyValue<D>::GetRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetUInt8Array(com_array<uint8_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt8Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetInt16Array(com_array<int16_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetInt16Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetUInt16Array(com_array<uint16_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt16Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetInt32Array(com_array<int32_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetInt32Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetUInt32Array(com_array<uint32_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt32Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetInt64Array(com_array<int64_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetInt64Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetUInt64Array(com_array<uint64_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetUInt64Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetSingleArray(com_array<float>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetSingleArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetDoubleArray(com_array<double>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetDoubleArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetChar16Array(com_array<char16_t>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetChar16Array(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetBooleanArray(com_array<bool>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetBooleanArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetStringArray(com_array<hstring>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetStringArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetInspectableArray(com_array<llm::OS::Foundation::IInspectable>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetInspectableArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetGuidArray(com_array<llm::guid>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetGuidArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetDateTimeArray(com_array<llm::OS::Foundation::DateTime>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetDateTimeArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetTimeSpanArray(com_array<llm::OS::Foundation::TimeSpan>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetTimeSpanArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetPointArray(com_array<llm::OS::Foundation::Point>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetPointArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetSizeArray(com_array<llm::OS::Foundation::Size>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetSizeArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Foundation_IPropertyValue<D>::GetRectArray(com_array<llm::OS::Foundation::Rect>& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValue)->GetRectArray(impl::put_size_abi(value), put_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateEmpty() const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateEmpty(&propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt8(uint8_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt8(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInt16(int16_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInt16(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt16(uint16_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt16(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInt32(int32_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInt32(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt32(uint32_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt32(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInt64(int64_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInt64(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt64(uint64_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt64(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateSingle(float value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateSingle(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateDouble(double value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateDouble(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateChar16(char16_t value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateChar16(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateBoolean(bool value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateBoolean(value, &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateString(param::hstring const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateString(*(void**)(&value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInspectable(llm::OS::Foundation::IInspectable const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInspectable(*(void**)(&value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateGuid(llm::guid const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateGuid(impl::bind_in(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateDateTime(llm::OS::Foundation::DateTime const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateDateTime(impl::bind_in(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateTimeSpan(llm::OS::Foundation::TimeSpan const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateTimeSpan(impl::bind_in(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreatePoint(llm::OS::Foundation::Point const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreatePoint(impl::bind_in(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateSize(llm::OS::Foundation::Size const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateSize(impl::bind_in(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateRect(llm::OS::Foundation::Rect const& value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateRect(impl::bind_in(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt8Array(array_view<uint8_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt8Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInt16Array(array_view<int16_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInt16Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt16Array(array_view<uint16_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt16Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInt32Array(array_view<int32_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInt32Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt32Array(array_view<uint32_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt32Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInt64Array(array_view<int64_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInt64Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateUInt64Array(array_view<uint64_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateUInt64Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateSingleArray(array_view<float const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateSingleArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateDoubleArray(array_view<double const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateDoubleArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateChar16Array(array_view<char16_t const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateChar16Array(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateBooleanArray(array_view<bool const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateBooleanArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateStringArray(array_view<hstring const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateStringArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateInspectableArray(array_view<llm::OS::Foundation::IInspectable const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateInspectableArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateGuidArray(array_view<llm::guid const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateGuidArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateDateTimeArray(array_view<llm::OS::Foundation::DateTime const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateDateTimeArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateTimeSpanArray(array_view<llm::OS::Foundation::TimeSpan const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateTimeSpanArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreatePointArray(array_view<llm::OS::Foundation::Point const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreatePointArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateSizeArray(array_view<llm::OS::Foundation::Size const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateSizeArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Foundation_IPropertyValueStatics<D>::CreateRectArray(array_view<llm::OS::Foundation::Rect const> value) const
    {
        void* propertyValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IPropertyValueStatics)->CreateRectArray(value.size(), get_abi(value), &propertyValue));
        return llm::OS::Foundation::IInspectable{ propertyValue, take_ownership_from_abi };
    }
    template <typename D, typename T> LLM_IMPL_AUTO(com_array<T>) consume_Windows_Foundation_IReferenceArray<D, T>::Value() const
    {
        uint32_t llm_impl_result_impl_size{};
        T* llm_impl_result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IReferenceArray<T>)->get_Value(&llm_impl_result_impl_size, &llm_impl_result));
        return com_array<T>{ llm_impl_result, llm_impl_result_impl_size, take_ownership_from_abi };
    }
    template <typename D, typename T> LLM_IMPL_AUTO(T) consume_Windows_Foundation_IReference<D, T>::Value() const
    {
        T llm_impl_result{ empty_value<T>() };
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IReference<T>)->get_Value(put_abi(llm_impl_result)));
        return llm_impl_result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IStringable<D>::ToString() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IStringable)->ToString(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriEscapeStatics<D>::UnescapeComponent(param::hstring const& toUnescape) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriEscapeStatics)->UnescapeComponent(*(void**)(&toUnescape), &value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriEscapeStatics<D>::EscapeComponent(param::hstring const& toEscape) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriEscapeStatics)->EscapeComponent(*(void**)(&toEscape), &value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::AbsoluteUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_AbsoluteUri(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::DisplayUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_DisplayUri(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::Domain() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Domain(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::Extension() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Extension(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::Fragment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Fragment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::Host() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Host(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::Password() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Password(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::Path() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Path(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::Query() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Query(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::WwwFormUrlDecoder) consume_Windows_Foundation_IUriRuntimeClass<D>::QueryParsed() const
    {
        void* ppWwwFormUrlDecoder{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_QueryParsed(&ppWwwFormUrlDecoder));
        return llm::OS::Foundation::WwwFormUrlDecoder{ ppWwwFormUrlDecoder, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::RawUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_RawUri(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::SchemeName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_SchemeName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClass<D>::UserName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_UserName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Foundation_IUriRuntimeClass<D>::Port() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Port(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Foundation_IUriRuntimeClass<D>::Suspicious() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->get_Suspicious(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Foundation_IUriRuntimeClass<D>::Equals(llm::OS::Foundation::Uri const& pUri) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->Equals(*(void**)(&pUri), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Foundation_IUriRuntimeClass<D>::CombineUri(param::hstring const& relativeUri) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClass)->CombineUri(*(void**)(&relativeUri), &instance));
        return llm::OS::Foundation::Uri{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Foundation_IUriRuntimeClassFactory<D>::CreateUri(param::hstring const& uri) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClassFactory)->CreateUri(*(void**)(&uri), &instance));
        return llm::OS::Foundation::Uri{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Foundation_IUriRuntimeClassFactory<D>::CreateWithRelativeUri(param::hstring const& baseUri, param::hstring const& relativeUri) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClassFactory)->CreateWithRelativeUri(*(void**)(&baseUri), *(void**)(&relativeUri), &instance));
        return llm::OS::Foundation::Uri{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClassWithAbsoluteCanonicalUri<D>::AbsoluteCanonicalUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri)->get_AbsoluteCanonicalUri(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IUriRuntimeClassWithAbsoluteCanonicalUri<D>::DisplayIri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri)->get_DisplayIri(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IWwwFormUrlDecoderEntry<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IWwwFormUrlDecoderEntry)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IWwwFormUrlDecoderEntry<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IWwwFormUrlDecoderEntry)->get_Value(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Foundation_IWwwFormUrlDecoderRuntimeClass<D>::GetFirstValueByName(param::hstring const& name) const
    {
        void* phstrValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass)->GetFirstValueByName(*(void**)(&name), &phstrValue));
        return hstring{ phstrValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::WwwFormUrlDecoder) consume_Windows_Foundation_IWwwFormUrlDecoderRuntimeClassFactory<D>::CreateWwwFormUrlDecoder(param::hstring const& query) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory)->CreateWwwFormUrlDecoder(*(void**)(&query), &instance));
        return llm::OS::Foundation::WwwFormUrlDecoder{ instance, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::Foundation::AsyncActionCompletedHandler, H> final : implements_delegate<llm::OS::Foundation::AsyncActionCompletedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::AsyncActionCompletedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* asyncInfo, int32_t asyncStatus) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IAsyncAction const*>(&asyncInfo), *reinterpret_cast<llm::OS::Foundation::AsyncStatus const*>(&asyncStatus));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H, typename TProgress> struct delegate<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>, H> final : implements_delegate<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* asyncInfo, arg_in<TProgress> progressInfo) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IAsyncActionWithProgress<TProgress> const*>(&asyncInfo), *reinterpret_cast<TProgress const*>(&progressInfo));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H, typename TProgress> struct delegate<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>, H> final : implements_delegate<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* asyncInfo, int32_t asyncStatus) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IAsyncActionWithProgress<TProgress> const*>(&asyncInfo), *reinterpret_cast<llm::OS::Foundation::AsyncStatus const*>(&asyncStatus));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H, typename TResult> struct delegate<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>, H> final : implements_delegate<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* asyncInfo, int32_t asyncStatus) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IAsyncOperation<TResult> const*>(&asyncInfo), *reinterpret_cast<llm::OS::Foundation::AsyncStatus const*>(&asyncStatus));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H, typename TResult, typename TProgress> struct delegate<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>, H> final : implements_delegate<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* asyncInfo, arg_in<TProgress> progressInfo) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const*>(&asyncInfo), *reinterpret_cast<TProgress const*>(&progressInfo));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H, typename TResult, typename TProgress> struct delegate<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>, H> final : implements_delegate<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* asyncInfo, int32_t asyncStatus) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const*>(&asyncInfo), *reinterpret_cast<llm::OS::Foundation::AsyncStatus const*>(&asyncStatus));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::Foundation::DeferralCompletedHandler, H> final : implements_delegate<llm::OS::Foundation::DeferralCompletedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::DeferralCompletedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke() noexcept final try
        {
            (*this)();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H, typename T> struct delegate<llm::OS::Foundation::EventHandler<T>, H> final : implements_delegate<llm::OS::Foundation::EventHandler<T>, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::EventHandler<T>, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, arg_in<T> args) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<T const*>(&args));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H, typename TSender, typename TResult> struct delegate<llm::OS::Foundation::TypedEventHandler<TSender, TResult>, H> final : implements_delegate<llm::OS::Foundation::TypedEventHandler<TSender, TResult>, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Foundation::TypedEventHandler<TSender, TResult>, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(arg_in<TSender> sender, arg_in<TResult> args) noexcept final try
        {
            (*this)(*reinterpret_cast<TSender const*>(&sender), *reinterpret_cast<TResult const*>(&args));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Foundation::IAsyncAction> : produce_base<D, llm::OS::Foundation::IAsyncAction>
    {
        int32_t __stdcall put_Completed(void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::AsyncActionCompletedHandler const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Completed(void** handler) noexcept final try
        {
            clear_abi(handler);
            typename D::abi_guard guard(this->shim());
            *handler = detach_from<llm::OS::Foundation::AsyncActionCompletedHandler>(this->shim().Completed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResults() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetResults();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D, typename TProgress>
    struct produce<D, llm::OS::Foundation::IAsyncActionWithProgress<TProgress>> : produce_base<D, llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        int32_t __stdcall put_Progress(void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(*reinterpret_cast<llm::OS::Foundation::AsyncActionProgressHandler<TProgress> const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(void** llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Completed(void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Completed(void** llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>(this->shim().Completed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResults() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetResults();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Foundation::IAsyncInfo> : produce_base<D, llm::OS::Foundation::IAsyncInfo>
    {
        int32_t __stdcall get_Id(uint32_t* llm_impl_result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<uint32_t>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* llm_impl_result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<llm::OS::Foundation::AsyncStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorCode(llm::hresult* llm_impl_result) noexcept final try
        {
            zero_abi<llm::hresult>(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<llm::hresult>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Cancel() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Close() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D, typename TResult, typename TProgress>
    struct produce<D, llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> : produce_base<D, llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        int32_t __stdcall put_Progress(void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(*reinterpret_cast<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress> const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(void** llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Completed(void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Completed(void** llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(this->shim().Completed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResults(arg_out<TResult> llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<TResult>(this->shim().GetResults());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D, typename TResult>
    struct produce<D, llm::OS::Foundation::IAsyncOperation<TResult>> : produce_base<D, llm::OS::Foundation::IAsyncOperation<TResult>>
    {
        int32_t __stdcall put_Completed(void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult> const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Completed(void** llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>>(this->shim().Completed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResults(arg_out<TResult> llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<TResult>(this->shim().GetResults());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Foundation::IClosable> : produce_base<D, llm::OS::Foundation::IClosable>
    {
        int32_t __stdcall Close() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IDeferral> : produce_base<D, llm::OS::Foundation::IDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IDeferralFactory> : produce_base<D, llm::OS::Foundation::IDeferralFactory>
    {
        int32_t __stdcall Create(void* handler, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Deferral>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::DeferralCompletedHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Foundation::IGetActivationFactory> : produce_base<D, llm::OS::Foundation::IGetActivationFactory>
    {
        int32_t __stdcall GetActivationFactory(void* activatableClassId, void** factory) noexcept final try
        {
            clear_abi(factory);
            typename D::abi_guard guard(this->shim());
            *factory = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetActivationFactory(*reinterpret_cast<hstring const*>(&activatableClassId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IGuidHelperStatics> : produce_base<D, llm::OS::Foundation::IGuidHelperStatics>
    {
        int32_t __stdcall CreateNewGuid(llm::guid* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::guid>(this->shim().CreateNewGuid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Empty(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().Empty());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Equals(llm::guid const& target, llm::guid const& value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().Equals(*reinterpret_cast<llm::guid const*>(&target), *reinterpret_cast<llm::guid const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Foundation::IMemoryBuffer> : produce_base<D, llm::OS::Foundation::IMemoryBuffer>
    {
        int32_t __stdcall CreateReference(void** reference) noexcept final try
        {
            clear_abi(reference);
            typename D::abi_guard guard(this->shim());
            *reference = detach_from<llm::OS::Foundation::IMemoryBufferReference>(this->shim().CreateReference());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IMemoryBufferFactory> : produce_base<D, llm::OS::Foundation::IMemoryBufferFactory>
    {
        int32_t __stdcall Create(uint32_t capacity, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::MemoryBuffer>(this->shim().Create(capacity));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Foundation::IMemoryBufferReference> : produce_base<D, llm::OS::Foundation::IMemoryBufferReference>
    {
        int32_t __stdcall get_Capacity(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Capacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Closed(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Closed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IMemoryBufferReference, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Closed(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
    template <typename D>
    struct produce<D, llm::OS::Foundation::IPropertyValue> : produce_base<D, llm::OS::Foundation::IPropertyValue>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::PropertyType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsNumericScalar(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsNumericScalar());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt8(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().GetUInt8());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInt16(int16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int16_t>(this->shim().GetInt16());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt16(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().GetUInt16());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInt32(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().GetInt32());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt32(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().GetUInt32());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInt64(int64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int64_t>(this->shim().GetInt64());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt64(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().GetUInt64());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSingle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().GetSingle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDouble(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().GetDouble());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetChar16(char16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<char16_t>(this->shim().GetChar16());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBoolean(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().GetBoolean());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetString(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetString());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGuid(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().GetGuid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDateTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().GetDateTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTimeSpan(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().GetTimeSpan());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPoint(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().GetPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().GetSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().GetRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt8Array(uint32_t* __valueSize, uint8_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetUInt8Array(detach_abi<uint8_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInt16Array(uint32_t* __valueSize, int16_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetInt16Array(detach_abi<int16_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt16Array(uint32_t* __valueSize, uint16_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetUInt16Array(detach_abi<uint16_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInt32Array(uint32_t* __valueSize, int32_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetInt32Array(detach_abi<int32_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt32Array(uint32_t* __valueSize, uint32_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetUInt32Array(detach_abi<uint32_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInt64Array(uint32_t* __valueSize, int64_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetInt64Array(detach_abi<int64_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUInt64Array(uint32_t* __valueSize, uint64_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetUInt64Array(detach_abi<uint64_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSingleArray(uint32_t* __valueSize, float** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetSingleArray(detach_abi<float>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDoubleArray(uint32_t* __valueSize, double** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetDoubleArray(detach_abi<double>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetChar16Array(uint32_t* __valueSize, char16_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetChar16Array(detach_abi<char16_t>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBooleanArray(uint32_t* __valueSize, bool** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetBooleanArray(detach_abi<bool>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStringArray(uint32_t* __valueSize, void*** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetStringArray(detach_abi<hstring>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInspectableArray(uint32_t* __valueSize, void*** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetInspectableArray(detach_abi<llm::OS::Foundation::IInspectable>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGuidArray(uint32_t* __valueSize, llm::guid** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetGuidArray(detach_abi<llm::guid>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDateTimeArray(uint32_t* __valueSize, int64_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetDateTimeArray(detach_abi<llm::OS::Foundation::DateTime>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTimeSpanArray(uint32_t* __valueSize, int64_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetTimeSpanArray(detach_abi<llm::OS::Foundation::TimeSpan>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPointArray(uint32_t* __valueSize, llm::OS::Foundation::Point** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetPointArray(detach_abi<llm::OS::Foundation::Point>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSizeArray(uint32_t* __valueSize, llm::OS::Foundation::Size** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetSizeArray(detach_abi<llm::OS::Foundation::Size>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRectArray(uint32_t* __valueSize, llm::OS::Foundation::Rect** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            this->shim().GetRectArray(detach_abi<llm::OS::Foundation::Rect>(__valueSize, value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IPropertyValueStatics> : produce_base<D, llm::OS::Foundation::IPropertyValueStatics>
    {
        int32_t __stdcall CreateEmpty(void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateEmpty());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt8(uint8_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt8(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInt16(int16_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInt16(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt16(uint16_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt16(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInt32(int32_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInt32(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt32(uint32_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt32(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInt64(int64_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInt64(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt64(uint64_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt64(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSingle(float value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateSingle(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDouble(double value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateDouble(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateChar16(char16_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateChar16(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBoolean(bool value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateBoolean(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateString(void* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateString(*reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInspectable(void* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInspectable(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateGuid(llm::guid value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateGuid(*reinterpret_cast<llm::guid const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTime(int64_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateDateTime(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTimeSpan(int64_t value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateTimeSpan(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePoint(llm::OS::Foundation::Point value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreatePoint(*reinterpret_cast<llm::OS::Foundation::Point const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSize(llm::OS::Foundation::Size value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRect(llm::OS::Foundation::Rect value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateRect(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt8Array(uint32_t __valueSize, uint8_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt8Array(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(value), reinterpret_cast<uint8_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInt16Array(uint32_t __valueSize, int16_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInt16Array(array_view<int16_t const>(reinterpret_cast<int16_t const *>(value), reinterpret_cast<int16_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt16Array(uint32_t __valueSize, uint16_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt16Array(array_view<uint16_t const>(reinterpret_cast<uint16_t const *>(value), reinterpret_cast<uint16_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInt32Array(uint32_t __valueSize, int32_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInt32Array(array_view<int32_t const>(reinterpret_cast<int32_t const *>(value), reinterpret_cast<int32_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt32Array(uint32_t __valueSize, uint32_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt32Array(array_view<uint32_t const>(reinterpret_cast<uint32_t const *>(value), reinterpret_cast<uint32_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInt64Array(uint32_t __valueSize, int64_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInt64Array(array_view<int64_t const>(reinterpret_cast<int64_t const *>(value), reinterpret_cast<int64_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUInt64Array(uint32_t __valueSize, uint64_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateUInt64Array(array_view<uint64_t const>(reinterpret_cast<uint64_t const *>(value), reinterpret_cast<uint64_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSingleArray(uint32_t __valueSize, float* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateSingleArray(array_view<float const>(reinterpret_cast<float const *>(value), reinterpret_cast<float const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDoubleArray(uint32_t __valueSize, double* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateDoubleArray(array_view<double const>(reinterpret_cast<double const *>(value), reinterpret_cast<double const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateChar16Array(uint32_t __valueSize, char16_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateChar16Array(array_view<char16_t const>(reinterpret_cast<char16_t const *>(value), reinterpret_cast<char16_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBooleanArray(uint32_t __valueSize, bool* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateBooleanArray(array_view<bool const>(reinterpret_cast<bool const *>(value), reinterpret_cast<bool const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStringArray(uint32_t __valueSize, void** value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateStringArray(array_view<hstring const>(reinterpret_cast<hstring const *>(value), reinterpret_cast<hstring const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInspectableArray(uint32_t __valueSize, void** value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateInspectableArray(array_view<llm::OS::Foundation::IInspectable const>(reinterpret_cast<llm::OS::Foundation::IInspectable const *>(value), reinterpret_cast<llm::OS::Foundation::IInspectable const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateGuidArray(uint32_t __valueSize, llm::guid* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateGuidArray(array_view<llm::guid const>(reinterpret_cast<llm::guid const *>(value), reinterpret_cast<llm::guid const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTimeArray(uint32_t __valueSize, int64_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateDateTimeArray(array_view<llm::OS::Foundation::DateTime const>(reinterpret_cast<llm::OS::Foundation::DateTime const *>(value), reinterpret_cast<llm::OS::Foundation::DateTime const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTimeSpanArray(uint32_t __valueSize, int64_t* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateTimeSpanArray(array_view<llm::OS::Foundation::TimeSpan const>(reinterpret_cast<llm::OS::Foundation::TimeSpan const *>(value), reinterpret_cast<llm::OS::Foundation::TimeSpan const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePointArray(uint32_t __valueSize, llm::OS::Foundation::Point* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreatePointArray(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(value), reinterpret_cast<llm::OS::Foundation::Point const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSizeArray(uint32_t __valueSize, llm::OS::Foundation::Size* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateSizeArray(array_view<llm::OS::Foundation::Size const>(reinterpret_cast<llm::OS::Foundation::Size const *>(value), reinterpret_cast<llm::OS::Foundation::Size const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRectArray(uint32_t __valueSize, llm::OS::Foundation::Rect* value, void** propertyValue) noexcept final try
        {
            clear_abi(propertyValue);
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateRectArray(array_view<llm::OS::Foundation::Rect const>(reinterpret_cast<llm::OS::Foundation::Rect const *>(value), reinterpret_cast<llm::OS::Foundation::Rect const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D, typename T>
    struct produce<D, llm::OS::Foundation::IReferenceArray<T>> : produce_base<D, llm::OS::Foundation::IReferenceArray<T>>
    {
        int32_t __stdcall get_Value(uint32_t* __llm_impl_resultSize, T** llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__llm_impl_resultSize, *llm_impl_result) = detach_abi(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D, typename T>
    struct produce<D, llm::OS::Foundation::IReference<T>> : produce_base<D, llm::OS::Foundation::IReference<T>>
    {
        int32_t __stdcall get_Value(arg_out<T> llm_impl_result) noexcept final try
        {
            clear_abi(llm_impl_result);
            typename D::abi_guard guard(this->shim());
            *llm_impl_result = detach_from<T>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Foundation::IStringable> : produce_base<D, llm::OS::Foundation::IStringable>
    {
        int32_t __stdcall ToString(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ToString());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IUriEscapeStatics> : produce_base<D, llm::OS::Foundation::IUriEscapeStatics>
    {
        int32_t __stdcall UnescapeComponent(void* toUnescape, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UnescapeComponent(*reinterpret_cast<hstring const*>(&toUnescape)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EscapeComponent(void* toEscape, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EscapeComponent(*reinterpret_cast<hstring const*>(&toEscape)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IUriRuntimeClass> : produce_base<D, llm::OS::Foundation::IUriRuntimeClass>
    {
        int32_t __stdcall get_AbsoluteUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AbsoluteUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Domain(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Domain());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Extension(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Extension());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Fragment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Fragment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Host(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Host());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Password(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Password());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Path(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Path());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Query(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Query());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QueryParsed(void** ppWwwFormUrlDecoder) noexcept final try
        {
            clear_abi(ppWwwFormUrlDecoder);
            typename D::abi_guard guard(this->shim());
            *ppWwwFormUrlDecoder = detach_from<llm::OS::Foundation::WwwFormUrlDecoder>(this->shim().QueryParsed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RawUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SchemeName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SchemeName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Port(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Port());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Suspicious(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Suspicious());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Equals(void* pUri, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Equals(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&pUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CombineUri(void* relativeUri, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::Foundation::Uri>(this->shim().CombineUri(*reinterpret_cast<hstring const*>(&relativeUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IUriRuntimeClassFactory> : produce_base<D, llm::OS::Foundation::IUriRuntimeClassFactory>
    {
        int32_t __stdcall CreateUri(void* uri, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::Foundation::Uri>(this->shim().CreateUri(*reinterpret_cast<hstring const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithRelativeUri(void* baseUri, void* relativeUri, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::Foundation::Uri>(this->shim().CreateWithRelativeUri(*reinterpret_cast<hstring const*>(&baseUri), *reinterpret_cast<hstring const*>(&relativeUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri> : produce_base<D, llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
    {
        int32_t __stdcall get_AbsoluteCanonicalUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AbsoluteCanonicalUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayIri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayIri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Foundation::IWwwFormUrlDecoderEntry> : produce_base<D, llm::OS::Foundation::IWwwFormUrlDecoderEntry>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass> : produce_base<D, llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass>
    {
        int32_t __stdcall GetFirstValueByName(void* name, void** phstrValue) noexcept final try
        {
            clear_abi(phstrValue);
            typename D::abi_guard guard(this->shim());
            *phstrValue = detach_from<hstring>(this->shim().GetFirstValueByName(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> : produce_base<D, llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>
    {
        int32_t __stdcall CreateWwwFormUrlDecoder(void* query, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::Foundation::WwwFormUrlDecoder>(this->shim().CreateWwwFormUrlDecoder(*reinterpret_cast<hstring const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Foundation
{
    inline Deferral::Deferral(llm::OS::Foundation::DeferralCompletedHandler const& handler) :
        Deferral(impl::call_factory<Deferral, IDeferralFactory>([&](IDeferralFactory const& f) { return f.Create(handler); }))
    {
    }
    inline auto GuidHelper::CreateNewGuid()
    {
        return impl::call_factory_cast<llm::guid(*)(IGuidHelperStatics const&), GuidHelper, IGuidHelperStatics>([](IGuidHelperStatics const& f) { return f.CreateNewGuid(); });
    }
    inline auto GuidHelper::Empty()
    {
        return impl::call_factory_cast<llm::guid(*)(IGuidHelperStatics const&), GuidHelper, IGuidHelperStatics>([](IGuidHelperStatics const& f) { return f.Empty(); });
    }
    inline auto GuidHelper::Equals(llm::guid const& target, llm::guid const& value)
    {
        return impl::call_factory<GuidHelper, IGuidHelperStatics>([&](IGuidHelperStatics const& f) { return f.Equals(target, value); });
    }
    inline MemoryBuffer::MemoryBuffer(uint32_t capacity) :
        MemoryBuffer(impl::call_factory<MemoryBuffer, IMemoryBufferFactory>([&](IMemoryBufferFactory const& f) { return f.Create(capacity); }))
    {
    }
    inline auto PropertyValue::CreateEmpty()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IInspectable(*)(IPropertyValueStatics const&), PropertyValue, IPropertyValueStatics>([](IPropertyValueStatics const& f) { return f.CreateEmpty(); });
    }
    inline auto PropertyValue::CreateUInt8(uint8_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt8(value); });
    }
    inline auto PropertyValue::CreateInt16(int16_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInt16(value); });
    }
    inline auto PropertyValue::CreateUInt16(uint16_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt16(value); });
    }
    inline auto PropertyValue::CreateInt32(int32_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInt32(value); });
    }
    inline auto PropertyValue::CreateUInt32(uint32_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt32(value); });
    }
    inline auto PropertyValue::CreateInt64(int64_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInt64(value); });
    }
    inline auto PropertyValue::CreateUInt64(uint64_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt64(value); });
    }
    inline auto PropertyValue::CreateSingle(float value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateSingle(value); });
    }
    inline auto PropertyValue::CreateDouble(double value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateDouble(value); });
    }
    inline auto PropertyValue::CreateChar16(char16_t value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateChar16(value); });
    }
    inline auto PropertyValue::CreateBoolean(bool value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateBoolean(value); });
    }
    inline auto PropertyValue::CreateString(param::hstring const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateString(value); });
    }
    inline auto PropertyValue::CreateInspectable(llm::OS::Foundation::IInspectable const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInspectable(value); });
    }
    inline auto PropertyValue::CreateGuid(llm::guid const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateGuid(value); });
    }
    inline auto PropertyValue::CreateDateTime(llm::OS::Foundation::DateTime const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateDateTime(value); });
    }
    inline auto PropertyValue::CreateTimeSpan(llm::OS::Foundation::TimeSpan const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateTimeSpan(value); });
    }
    inline auto PropertyValue::CreatePoint(llm::OS::Foundation::Point const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreatePoint(value); });
    }
    inline auto PropertyValue::CreateSize(llm::OS::Foundation::Size const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateSize(value); });
    }
    inline auto PropertyValue::CreateRect(llm::OS::Foundation::Rect const& value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateRect(value); });
    }
    inline auto PropertyValue::CreateUInt8Array(array_view<uint8_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt8Array(value); });
    }
    inline auto PropertyValue::CreateInt16Array(array_view<int16_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInt16Array(value); });
    }
    inline auto PropertyValue::CreateUInt16Array(array_view<uint16_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt16Array(value); });
    }
    inline auto PropertyValue::CreateInt32Array(array_view<int32_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInt32Array(value); });
    }
    inline auto PropertyValue::CreateUInt32Array(array_view<uint32_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt32Array(value); });
    }
    inline auto PropertyValue::CreateInt64Array(array_view<int64_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInt64Array(value); });
    }
    inline auto PropertyValue::CreateUInt64Array(array_view<uint64_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateUInt64Array(value); });
    }
    inline auto PropertyValue::CreateSingleArray(array_view<float const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateSingleArray(value); });
    }
    inline auto PropertyValue::CreateDoubleArray(array_view<double const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateDoubleArray(value); });
    }
    inline auto PropertyValue::CreateChar16Array(array_view<char16_t const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateChar16Array(value); });
    }
    inline auto PropertyValue::CreateBooleanArray(array_view<bool const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateBooleanArray(value); });
    }
    inline auto PropertyValue::CreateStringArray(array_view<hstring const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateStringArray(value); });
    }
    inline auto PropertyValue::CreateInspectableArray(array_view<llm::OS::Foundation::IInspectable const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateInspectableArray(value); });
    }
    inline auto PropertyValue::CreateGuidArray(array_view<llm::guid const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateGuidArray(value); });
    }
    inline auto PropertyValue::CreateDateTimeArray(array_view<llm::OS::Foundation::DateTime const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateDateTimeArray(value); });
    }
    inline auto PropertyValue::CreateTimeSpanArray(array_view<llm::OS::Foundation::TimeSpan const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateTimeSpanArray(value); });
    }
    inline auto PropertyValue::CreatePointArray(array_view<llm::OS::Foundation::Point const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreatePointArray(value); });
    }
    inline auto PropertyValue::CreateSizeArray(array_view<llm::OS::Foundation::Size const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateSizeArray(value); });
    }
    inline auto PropertyValue::CreateRectArray(array_view<llm::OS::Foundation::Rect const> value)
    {
        return impl::call_factory<PropertyValue, IPropertyValueStatics>([&](IPropertyValueStatics const& f) { return f.CreateRectArray(value); });
    }
    inline auto Uri::UnescapeComponent(param::hstring const& toUnescape)
    {
        return impl::call_factory<Uri, IUriEscapeStatics>([&](IUriEscapeStatics const& f) { return f.UnescapeComponent(toUnescape); });
    }
    inline auto Uri::EscapeComponent(param::hstring const& toEscape)
    {
        return impl::call_factory<Uri, IUriEscapeStatics>([&](IUriEscapeStatics const& f) { return f.EscapeComponent(toEscape); });
    }
    inline Uri::Uri(param::hstring const& uri) :
        Uri(impl::call_factory<Uri, IUriRuntimeClassFactory>([&](IUriRuntimeClassFactory const& f) { return f.CreateUri(uri); }))
    {
    }
    inline Uri::Uri(param::hstring const& baseUri, param::hstring const& relativeUri) :
        Uri(impl::call_factory<Uri, IUriRuntimeClassFactory>([&](IUriRuntimeClassFactory const& f) { return f.CreateWithRelativeUri(baseUri, relativeUri); }))
    {
    }
    inline WwwFormUrlDecoder::WwwFormUrlDecoder(param::hstring const& query) :
        WwwFormUrlDecoder(impl::call_factory<WwwFormUrlDecoder, IWwwFormUrlDecoderRuntimeClassFactory>([&](IWwwFormUrlDecoderRuntimeClassFactory const& f) { return f.CreateWwwFormUrlDecoder(query); }))
    {
    }
    template <typename L> AsyncActionCompletedHandler::AsyncActionCompletedHandler(L handler) :
        AsyncActionCompletedHandler(impl::make_delegate<AsyncActionCompletedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> AsyncActionCompletedHandler::AsyncActionCompletedHandler(F* handler) :
        AsyncActionCompletedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> AsyncActionCompletedHandler::AsyncActionCompletedHandler(O* object, M method) :
        AsyncActionCompletedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> AsyncActionCompletedHandler::AsyncActionCompletedHandler(com_ptr<O>&& object, M method) :
        AsyncActionCompletedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> AsyncActionCompletedHandler::AsyncActionCompletedHandler(weak_ref<O>&& object, M method) :
        AsyncActionCompletedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto AsyncActionCompletedHandler::operator()(llm::OS::Foundation::IAsyncAction const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const
    {
        check_hresult((*(impl::abi_t<AsyncActionCompletedHandler>**)this)->Invoke(*(void**)(&asyncInfo), static_cast<int32_t>(asyncStatus)));
    }
    template <typename TProgress> template <typename L> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(L handler) :
        AsyncActionProgressHandler(impl::make_delegate<AsyncActionProgressHandler<TProgress>>(std::forward<L>(handler)))
    {
    }
    template <typename TProgress> template <typename F> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(F* handler) :
        AsyncActionProgressHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename TProgress> template <typename O, typename M> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(O* object, M method) :
        AsyncActionProgressHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename TProgress> template <typename O, typename M> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(com_ptr<O>&& object, M method) :
        AsyncActionProgressHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename TProgress> template <typename O, typename M> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(weak_ref<O>&& object, M method) :
        AsyncActionProgressHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    template <typename TProgress> auto AsyncActionProgressHandler<TProgress>::operator()(llm::OS::Foundation::IAsyncActionWithProgress<TProgress> const& asyncInfo, impl::param_type<TProgress> const& progressInfo) const
    {
        check_hresult((*(impl::abi_t<AsyncActionProgressHandler<TProgress>>**)this)->Invoke(*(void**)(&asyncInfo), impl::bind_in(progressInfo)));
    }
    template <typename TProgress> template <typename L> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(L handler) :
        AsyncActionWithProgressCompletedHandler(impl::make_delegate<AsyncActionWithProgressCompletedHandler<TProgress>>(std::forward<L>(handler)))
    {
    }
    template <typename TProgress> template <typename F> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(F* handler) :
        AsyncActionWithProgressCompletedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename TProgress> template <typename O, typename M> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(O* object, M method) :
        AsyncActionWithProgressCompletedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename TProgress> template <typename O, typename M> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(com_ptr<O>&& object, M method) :
        AsyncActionWithProgressCompletedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename TProgress> template <typename O, typename M> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(weak_ref<O>&& object, M method) :
        AsyncActionWithProgressCompletedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    template <typename TProgress> auto AsyncActionWithProgressCompletedHandler<TProgress>::operator()(llm::OS::Foundation::IAsyncActionWithProgress<TProgress> const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const
    {
        check_hresult((*(impl::abi_t<AsyncActionWithProgressCompletedHandler<TProgress>>**)this)->Invoke(*(void**)(&asyncInfo), static_cast<int32_t>(asyncStatus)));
    }
    template <typename TResult> template <typename L> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(L handler) :
        AsyncOperationCompletedHandler(impl::make_delegate<AsyncOperationCompletedHandler<TResult>>(std::forward<L>(handler)))
    {
    }
    template <typename TResult> template <typename F> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(F* handler) :
        AsyncOperationCompletedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename TResult> template <typename O, typename M> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(O* object, M method) :
        AsyncOperationCompletedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename TResult> template <typename O, typename M> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(com_ptr<O>&& object, M method) :
        AsyncOperationCompletedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename TResult> template <typename O, typename M> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(weak_ref<O>&& object, M method) :
        AsyncOperationCompletedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    template <typename TResult> auto AsyncOperationCompletedHandler<TResult>::operator()(llm::OS::Foundation::IAsyncOperation<TResult> const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const
    {
        check_hresult((*(impl::abi_t<AsyncOperationCompletedHandler<TResult>>**)this)->Invoke(*(void**)(&asyncInfo), static_cast<int32_t>(asyncStatus)));
    }
    template <typename TResult, typename TProgress> template <typename L> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(L handler) :
        AsyncOperationProgressHandler(impl::make_delegate<AsyncOperationProgressHandler<TResult, TProgress>>(std::forward<L>(handler)))
    {
    }
    template <typename TResult, typename TProgress> template <typename F> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(F* handler) :
        AsyncOperationProgressHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(O* object, M method) :
        AsyncOperationProgressHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(com_ptr<O>&& object, M method) :
        AsyncOperationProgressHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(weak_ref<O>&& object, M method) :
        AsyncOperationProgressHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    template <typename TResult, typename TProgress> auto AsyncOperationProgressHandler<TResult, TProgress>::operator()(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const& asyncInfo, impl::param_type<TProgress> const& progressInfo) const
    {
        check_hresult((*(impl::abi_t<AsyncOperationProgressHandler<TResult, TProgress>>**)this)->Invoke(*(void**)(&asyncInfo), impl::bind_in(progressInfo)));
    }
    template <typename TResult, typename TProgress> template <typename L> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(L handler) :
        AsyncOperationWithProgressCompletedHandler(impl::make_delegate<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(std::forward<L>(handler)))
    {
    }
    template <typename TResult, typename TProgress> template <typename F> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(F* handler) :
        AsyncOperationWithProgressCompletedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(O* object, M method) :
        AsyncOperationWithProgressCompletedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(com_ptr<O>&& object, M method) :
        AsyncOperationWithProgressCompletedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(weak_ref<O>&& object, M method) :
        AsyncOperationWithProgressCompletedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    template <typename TResult, typename TProgress> auto AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::operator()(llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const& asyncInfo, llm::OS::Foundation::AsyncStatus const& asyncStatus) const
    {
        check_hresult((*(impl::abi_t<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>**)this)->Invoke(*(void**)(&asyncInfo), static_cast<int32_t>(asyncStatus)));
    }
    template <typename L> DeferralCompletedHandler::DeferralCompletedHandler(L handler) :
        DeferralCompletedHandler(impl::make_delegate<DeferralCompletedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> DeferralCompletedHandler::DeferralCompletedHandler(F* handler) :
        DeferralCompletedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> DeferralCompletedHandler::DeferralCompletedHandler(O* object, M method) :
        DeferralCompletedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> DeferralCompletedHandler::DeferralCompletedHandler(com_ptr<O>&& object, M method) :
        DeferralCompletedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> DeferralCompletedHandler::DeferralCompletedHandler(weak_ref<O>&& object, M method) :
        DeferralCompletedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto DeferralCompletedHandler::operator()() const
    {
        check_hresult((*(impl::abi_t<DeferralCompletedHandler>**)this)->Invoke());
    }
    template <typename T> template <typename L> EventHandler<T>::EventHandler(L handler) :
        EventHandler(impl::make_delegate<EventHandler<T>>(std::forward<L>(handler)))
    {
    }
    template <typename T> template <typename F> EventHandler<T>::EventHandler(F* handler) :
        EventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename T> template <typename O, typename M> EventHandler<T>::EventHandler(O* object, M method) :
        EventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename T> template <typename O, typename M> EventHandler<T>::EventHandler(com_ptr<O>&& object, M method) :
        EventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename T> template <typename O, typename M> EventHandler<T>::EventHandler(weak_ref<O>&& object, M method) :
        EventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    template <typename T> auto EventHandler<T>::operator()(llm::OS::Foundation::IInspectable const& sender, impl::param_type<T> const& args) const
    {
        check_hresult((*(impl::abi_t<EventHandler<T>>**)this)->Invoke(*(void**)(&sender), impl::bind_in(args)));
    }
    template <typename TSender, typename TResult> template <typename L> TypedEventHandler<TSender, TResult>::TypedEventHandler(L handler) :
        TypedEventHandler(impl::make_delegate<TypedEventHandler<TSender, TResult>>(std::forward<L>(handler)))
    {
    }
    template <typename TSender, typename TResult> template <typename F> TypedEventHandler<TSender, TResult>::TypedEventHandler(F* handler) :
        TypedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename TSender, typename TResult> template <typename O, typename M> TypedEventHandler<TSender, TResult>::TypedEventHandler(O* object, M method) :
        TypedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename TSender, typename TResult> template <typename O, typename M> TypedEventHandler<TSender, TResult>::TypedEventHandler(com_ptr<O>&& object, M method) :
        TypedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename TSender, typename TResult> template <typename O, typename M> TypedEventHandler<TSender, TResult>::TypedEventHandler(weak_ref<O>&& object, M method) :
        TypedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    template <typename TSender, typename TResult> auto TypedEventHandler<TSender, TResult>::operator()(impl::param_type<TSender> const& sender, impl::param_type<TResult> const& args) const
    {
        check_hresult((*(impl::abi_t<TypedEventHandler<TSender, TResult>>**)this)->Invoke(impl::bind_in(sender), impl::bind_in(args)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Foundation::IAsyncAction> : llm::impl::hash_base {};
    template<typename TProgress> struct hash<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IAsyncInfo> : llm::impl::hash_base {};
    template<typename TResult, typename TProgress> struct hash<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> : llm::impl::hash_base {};
    template<typename TResult> struct hash<llm::OS::Foundation::IAsyncOperation<TResult>> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IClosable> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IDeferralFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IGetActivationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IGuidHelperStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IMemoryBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IMemoryBufferFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IMemoryBufferReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IPropertyValue> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IPropertyValueStatics> : llm::impl::hash_base {};
    template<typename T> struct hash<llm::OS::Foundation::IReferenceArray<T>> : llm::impl::hash_base {};
    template<typename T> struct hash<llm::OS::Foundation::IReference<T>> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IStringable> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IUriEscapeStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IUriRuntimeClass> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IUriRuntimeClassFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IWwwFormUrlDecoderEntry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::Deferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::GuidHelper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::MemoryBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::PropertyValue> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::Uri> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::WwwFormUrlDecoder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Foundation::WwwFormUrlDecoderEntry> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
    template<> struct formatter<llm::OS::Foundation::Uri, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
#endif
}

namespace llm::impl
{
    template <typename T>
    struct reference : implements<reference<T>, Windows::Foundation::IReference<T>, Windows::Foundation::IPropertyValue>
    {
        reference(T const& value) : m_value(value)
        {
        }

        T Value() const
        {
            return m_value;
        }

        Windows::Foundation::PropertyType Type() const noexcept
        {
            return Windows::Foundation::PropertyType::OtherType;
        }

        static constexpr bool IsNumericScalar() noexcept
        {
            return std::is_arithmetic_v<T> || std::is_enum_v<T>;
        }

        uint8_t GetUInt8() const
        {
            return to_scalar<uint8_t>();
        }

        int16_t GetInt16() const
        {
            return to_scalar<int16_t>();
        }

        uint16_t GetUInt16() const
        {
            return to_scalar<uint16_t>();
        }

        int32_t GetInt32() const
        {
            return to_scalar<int32_t>();
        }

        uint32_t GetUInt32() const
        {
            return to_scalar<uint32_t>();
        }

        int64_t GetInt64() const
        {
            return to_scalar<int64_t>();
        }

        uint64_t GetUInt64() const
        {
            return to_scalar<uint64_t>();
        }

        float GetSingle() { throw hresult_not_implemented(); }
        double GetDouble() { throw hresult_not_implemented(); }
        char16_t GetChar16() { throw hresult_not_implemented(); }
        bool GetBoolean() { throw hresult_not_implemented(); }
        hstring GetString() { throw hresult_not_implemented(); }
        guid GetGuid() { throw hresult_not_implemented(); }
        Windows::Foundation::DateTime GetDateTime() { throw hresult_not_implemented(); }
        Windows::Foundation::TimeSpan GetTimeSpan() { throw hresult_not_implemented(); }
        Windows::Foundation::Point GetPoint() { throw hresult_not_implemented(); }
        Windows::Foundation::Size GetSize() { throw hresult_not_implemented(); }
        Windows::Foundation::Rect GetRect() { throw hresult_not_implemented(); }
        void GetUInt8Array(com_array<uint8_t> &) { throw hresult_not_implemented(); }
        void GetInt16Array(com_array<int16_t> &) { throw hresult_not_implemented(); }
        void GetUInt16Array(com_array<uint16_t> &) { throw hresult_not_implemented(); }
        void GetInt32Array(com_array<int32_t> &) { throw hresult_not_implemented(); }
        void GetUInt32Array(com_array<uint32_t> &) { throw hresult_not_implemented(); }
        void GetInt64Array(com_array<int64_t> &) { throw hresult_not_implemented(); }
        void GetUInt64Array(com_array<uint64_t> &) { throw hresult_not_implemented(); }
        void GetSingleArray(com_array<float> &) { throw hresult_not_implemented(); }
        void GetDoubleArray(com_array<double> &) { throw hresult_not_implemented(); }
        void GetChar16Array(com_array<char16_t> &) { throw hresult_not_implemented(); }
        void GetBooleanArray(com_array<bool> &) { throw hresult_not_implemented(); }
        void GetStringArray(com_array<hstring> &) { throw hresult_not_implemented(); }
        void GetInspectableArray(com_array<Windows::Foundation::IInspectable> &) { throw hresult_not_implemented(); }
        void GetGuidArray(com_array<guid> &) { throw hresult_not_implemented(); }
        void GetDateTimeArray(com_array<Windows::Foundation::DateTime> &) { throw hresult_not_implemented(); }
        void GetTimeSpanArray(com_array<Windows::Foundation::TimeSpan> &) { throw hresult_not_implemented(); }
        void GetPointArray(com_array<Windows::Foundation::Point> &) { throw hresult_not_implemented(); }
        void GetSizeArray(com_array<Windows::Foundation::Size> &) { throw hresult_not_implemented(); }
        void GetRectArray(com_array<Windows::Foundation::Rect> &) { throw hresult_not_implemented(); }

    private:

        template <typename To>
        To to_scalar() const
        {
            if constexpr (IsNumericScalar())
            {
                return static_cast<To>(m_value);
            }
            else
            {
                throw hresult_not_implemented();
            }
        }

        T m_value;
    };

    template <typename T>
    struct reference_traits
    {
        static auto make(T const& value) { return llm::make<impl::reference<T>>(value); }
        using itf = Windows::Foundation::IReference<T>;
    };

    template <>
    struct reference_traits<uint8_t>
    {
        static auto make(uint8_t value) { return Windows::Foundation::PropertyValue::CreateUInt8(value); }
        using itf = Windows::Foundation::IReference<uint8_t>;
    };

    template <>
    struct reference_traits<uint16_t>
    {
        static auto make(uint16_t value) { return Windows::Foundation::PropertyValue::CreateUInt16(value); }
        using itf = Windows::Foundation::IReference<uint16_t>;
    };

    template <>
    struct reference_traits<int16_t>
    {
        static auto make(int16_t value) { return Windows::Foundation::PropertyValue::CreateInt16(value); }
        using itf = Windows::Foundation::IReference<int16_t>;
    };

    template <>
    struct reference_traits<uint32_t>
    {
        static auto make(uint32_t value) { return Windows::Foundation::PropertyValue::CreateUInt32(value); }
        using itf = Windows::Foundation::IReference<uint32_t>;
    };

    template <>
    struct reference_traits<int32_t>
    {
        static auto make(int32_t value) { return Windows::Foundation::PropertyValue::CreateInt32(value); }
        using itf = Windows::Foundation::IReference<int32_t>;
    };

    template <>
    struct reference_traits<uint64_t>
    {
        static auto make(uint64_t value) { return Windows::Foundation::PropertyValue::CreateUInt64(value); }
        using itf = Windows::Foundation::IReference<uint64_t>;
    };

    template <>
    struct reference_traits<int64_t>
    {
        static auto make(int64_t value) { return Windows::Foundation::PropertyValue::CreateInt64(value); }
        using itf = Windows::Foundation::IReference<int64_t>;
    };

    template <>
    struct reference_traits<float>
    {
        static auto make(float value) { return Windows::Foundation::PropertyValue::CreateSingle(value); }
        using itf = Windows::Foundation::IReference<float>;
    };

    template <>
    struct reference_traits<double>
    {
        static auto make(double value) { return Windows::Foundation::PropertyValue::CreateDouble(value); }
        using itf = Windows::Foundation::IReference<double>;
    };

    template <>
    struct reference_traits<char16_t>
    {
        static auto make(char16_t value) { return Windows::Foundation::PropertyValue::CreateChar16(value); }
        using itf = Windows::Foundation::IReference<char16_t>;
    };

    template <>
    struct reference_traits<bool>
    {
        static auto make(bool value) { return Windows::Foundation::PropertyValue::CreateBoolean(value); }
        using itf = Windows::Foundation::IReference<bool>;
    };

    template <>
    struct reference_traits<hstring>
    {
        static auto make(hstring const& value) { return Windows::Foundation::PropertyValue::CreateString(value); }
        using itf = Windows::Foundation::IReference<hstring>;
    };

    template <>
    struct reference_traits<Windows::Foundation::IInspectable>
    {
        static auto make(Windows::Foundation::IInspectable const& value) { return Windows::Foundation::PropertyValue::CreateInspectable(value); }
        using itf = Windows::Foundation::IInspectable;
    };

    template <>
    struct reference_traits<guid>
    {
        static auto make(guid const& value) { return Windows::Foundation::PropertyValue::CreateGuid(value); }
        using itf = Windows::Foundation::IReference<guid>;
    };

    template <>
    struct reference_traits<GUID>
    {
        static auto make(GUID const& value) { return Windows::Foundation::PropertyValue::CreateGuid(reinterpret_cast<guid const&>(value)); }
        using itf = Windows::Foundation::IReference<guid>;
    };

    template <>
    struct reference_traits<Windows::Foundation::DateTime>
    {
        static auto make(Windows::Foundation::DateTime value) { return Windows::Foundation::PropertyValue::CreateDateTime(value); }
        using itf = Windows::Foundation::IReference<Windows::Foundation::DateTime>;
    };

    template <>
    struct reference_traits<Windows::Foundation::TimeSpan>
    {
        static auto make(Windows::Foundation::TimeSpan value) { return Windows::Foundation::PropertyValue::CreateTimeSpan(value); }
        using itf = Windows::Foundation::IReference<Windows::Foundation::TimeSpan>;
    };

    template <>
    struct reference_traits<Windows::Foundation::Point>
    {
        static auto make(Windows::Foundation::Point const& value) { return Windows::Foundation::PropertyValue::CreatePoint(value); }
        using itf = Windows::Foundation::IReference<Windows::Foundation::Point>;
    };

    template <>
    struct reference_traits<Windows::Foundation::Size>
    {
        static auto make(Windows::Foundation::Size const& value) { return Windows::Foundation::PropertyValue::CreateSize(value); }
        using itf = Windows::Foundation::IReference<Windows::Foundation::Size>;
    };

    template <>
    struct reference_traits<Windows::Foundation::Rect>
    {
        static auto make(Windows::Foundation::Rect const& value) { return Windows::Foundation::PropertyValue::CreateRect(value); }
        using itf = Windows::Foundation::IReference<Windows::Foundation::Rect>;
    };

    template <>
    struct reference_traits<com_array<uint8_t>>
    {
        static auto make(array_view<uint8_t const> const& value) { return Windows::Foundation::PropertyValue::CreateUInt8Array(value); }
        using itf = Windows::Foundation::IReferenceArray<uint8_t>;
    };

    template <>
    struct reference_traits<com_array<int16_t>>
    {
        static auto make(array_view<int16_t const> const& value) { return Windows::Foundation::PropertyValue::CreateInt16Array(value); }
        using itf = Windows::Foundation::IReferenceArray<int16_t>;
    };

    template <>
    struct reference_traits<com_array<uint16_t>>
    {
        static auto make(array_view<uint16_t const> const& value) { return Windows::Foundation::PropertyValue::CreateUInt16Array(value); }
        using itf = Windows::Foundation::IReferenceArray<uint16_t>;
    };

    template <>
    struct reference_traits<com_array<int32_t>>
    {
        static auto make(array_view<int32_t const> const& value) { return Windows::Foundation::PropertyValue::CreateInt32Array(value); }
        using itf = Windows::Foundation::IReferenceArray<int32_t>;
    };

    template <>
    struct reference_traits<com_array<uint32_t>>
    {
        static auto make(com_array<uint32_t> const& value) { return Windows::Foundation::PropertyValue::CreateUInt32Array(value); }
        using itf = Windows::Foundation::IReferenceArray<uint32_t>;
    };

    template <>
    struct reference_traits<com_array<int64_t>>
    {
        static auto make(array_view<int64_t const> const& value) { return Windows::Foundation::PropertyValue::CreateInt64Array(value); }
        using itf = Windows::Foundation::IReferenceArray<int64_t>;
    };

    template <>
    struct reference_traits<com_array<uint64_t>>
    {
        static auto make(array_view<uint64_t const> const& value) { return Windows::Foundation::PropertyValue::CreateUInt64Array(value); }
        using itf = Windows::Foundation::IReferenceArray<uint64_t>;
    };

    template <>
    struct reference_traits<com_array<float>>
    {
        static auto make(array_view<float const> const& value) { return Windows::Foundation::PropertyValue::CreateSingleArray(value); }
        using itf = Windows::Foundation::IReferenceArray<float>;
    };

    template <>
    struct reference_traits<com_array<double>>
    {
        static auto make(array_view<double const> const& value) { return Windows::Foundation::PropertyValue::CreateDoubleArray(value); }
        using itf = Windows::Foundation::IReferenceArray<double>;
    };

    template <>
    struct reference_traits<com_array<char16_t>>
    {
        static auto make(array_view<char16_t const> const& value) { return Windows::Foundation::PropertyValue::CreateChar16Array(value); }
        using itf = Windows::Foundation::IReferenceArray<char16_t>;
    };

    template <>
    struct reference_traits<com_array<bool>>
    {
        static auto make(array_view<bool const> const& value) { return Windows::Foundation::PropertyValue::CreateBooleanArray(value); }
        using itf = Windows::Foundation::IReferenceArray<bool>;
    };

    template <>
    struct reference_traits<com_array<hstring>>
    {
        static auto make(array_view<hstring const> const& value) { return Windows::Foundation::PropertyValue::CreateStringArray(value); }
        using itf = Windows::Foundation::IReferenceArray<hstring>;
    };

    template <>
    struct reference_traits<com_array<Windows::Foundation::IInspectable>>
    {
        static auto make(array_view<Windows::Foundation::IInspectable const> const& value) { return Windows::Foundation::PropertyValue::CreateInspectableArray(value); }
        using itf = Windows::Foundation::IReferenceArray<Windows::Foundation::IInspectable>;
    };

    template <>
    struct reference_traits<com_array<guid>>
    {
        static auto make(array_view<guid const> const& value) { return Windows::Foundation::PropertyValue::CreateGuidArray(value); }
        using itf = Windows::Foundation::IReferenceArray<guid>;
    };

    template <>
    struct reference_traits<com_array<GUID>>
    {
        static auto make(array_view<GUID const> const& value) { return Windows::Foundation::PropertyValue::CreateGuidArray(reinterpret_cast<array_view<guid const> const&>(value)); }
        using itf = Windows::Foundation::IReferenceArray<guid>;
    };

    template <>
    struct reference_traits<com_array<Windows::Foundation::DateTime>>
    {
        static auto make(array_view<Windows::Foundation::DateTime const> const& value) { return Windows::Foundation::PropertyValue::CreateDateTimeArray(value); }
        using itf = Windows::Foundation::IReferenceArray<Windows::Foundation::DateTime>;
    };

    template <>
    struct reference_traits<com_array<Windows::Foundation::TimeSpan>>
    {
        static auto make(array_view<Windows::Foundation::TimeSpan const> const& value) { return Windows::Foundation::PropertyValue::CreateTimeSpanArray(value); }
        using itf = Windows::Foundation::IReferenceArray<Windows::Foundation::TimeSpan>;
    };

    template <>
    struct reference_traits<com_array<Windows::Foundation::Point>>
    {
        static auto make(array_view<Windows::Foundation::Point const> const& value) { return Windows::Foundation::PropertyValue::CreatePointArray(value); }
        using itf = Windows::Foundation::IReferenceArray<Windows::Foundation::Point>;
    };

    template <>
    struct reference_traits<com_array<Windows::Foundation::Size>>
    {
        static auto make(array_view<Windows::Foundation::Size const> const& value) { return Windows::Foundation::PropertyValue::CreateSizeArray(value); }
        using itf = Windows::Foundation::IReferenceArray<Windows::Foundation::Size>;
    };

    template <>
    struct reference_traits<com_array<Windows::Foundation::Rect>>
    {
        static auto make(array_view<Windows::Foundation::Rect const> const& value) { return Windows::Foundation::PropertyValue::CreateRectArray(value); }
        using itf = Windows::Foundation::IReferenceArray<Windows::Foundation::Rect>;
    };
}

LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename T>
    bool operator==(IReference<T> const& left, IReference<T> const& right)
    {
        if (get_abi(left) == get_abi(right))
        {
            return true;
        }

        if (!left || !right)
        {
            return false;
        }

        return left.Value() == right.Value();
    }

    template <typename T>
    bool operator!=(IReference<T> const& left, IReference<T> const& right)
    {
        return !(left == right);
    }
}

namespace llm::impl
{
    template <typename T, typename From>
    T unbox_value_type(From&& value)
    {
        if (!value)
        {
            throw hresult_no_interface();
        }
        if constexpr (std::is_enum_v<T>)
        {
            if (auto temp = value.template try_as<Windows::Foundation::IReference<T>>())
            {
                return temp.Value();
            }
            else
            {
                return static_cast<T>(value.template as<Windows::Foundation::IReference<std::underlying_type_t<T>>>().Value());
            }
        }
        else if constexpr (std::is_same_v<T, com_array<GUID>>)
        {
            T result;
            reinterpret_cast<com_array<guid>&>(result) = value.template as<typename impl::reference_traits<T>::itf>().Value();
            return result;
        }
        else
        {
            return value.template as<typename impl::reference_traits<T>::itf>().Value();
        }
    }

    template <typename T, typename Ret = T, typename From, typename U>
    Ret unbox_value_type_or(From&& value, U&& default_value)
    {
        if constexpr (std::is_enum_v<T>)
        {
            if (auto temp = value.template try_as<Windows::Foundation::IReference<T>>())
            {
                return temp.Value();
            }

            if (auto temp = value.template try_as<Windows::Foundation::IReference<std::underlying_type_t<T>>>())
            {
                return static_cast<T>(temp.Value());
            }
        }
        else if constexpr (std::is_same_v<T, com_array<GUID>>)
        {
            if (auto temp = value.template try_as<typename impl::reference_traits<T>::itf>())
            {
                T result;
                reinterpret_cast<com_array<guid>&>(result) = temp.Value();
                return result;
            }
        }
        else
        {
            if (auto temp = value.template try_as<typename impl::reference_traits<T>::itf>())
            {
                return temp.Value();
            }
        }
        return default_value;
    }

    template <typename To, typename From, std::enable_if_t<!is_com_interface_v<To>, int>>
    auto as(From* ptr)
    {
        if constexpr (impl::is_com_interface_v<From>)
        {
            return unbox_value_type<To>(reinterpret_cast<Windows::Foundation::IUnknown const&>(ptr));
        }
        else
        {
            return unbox_value_type<To>(reinterpret_cast<com_ptr<From> const&>(ptr));
        }
    }

    template <typename To, typename From, std::enable_if_t<!is_com_interface_v<To>, int>>
    auto try_as(From* ptr) noexcept
    {
        using type = std::conditional_t<impl::is_com_interface_v<From>, Windows::Foundation::IUnknown, com_ptr<From>>;
        return unbox_value_type_or<To, std::optional<To>>(reinterpret_cast<type const&>(ptr), std::nullopt);
    }
}

LLM_EXPORT namespace winrt
{
    inline Windows::Foundation::IInspectable box_value(param::hstring const& value)
    {
        return Windows::Foundation::IReference<hstring>(*(hstring*)(&value));
    }

    template <typename T, std::enable_if_t<!std::is_convertible_v<T, param::hstring>, int> = 0>
    Windows::Foundation::IInspectable box_value(T const& value)
    {
        if constexpr (std::is_base_of_v<Windows::Foundation::IInspectable, T>)
        {
            return value;
        }
        else
        {
            return impl::reference_traits<T>::make(value);
        }
    }

    template <typename T>
    T unbox_value(Windows::Foundation::IInspectable const& value)
    {
        if constexpr (std::is_base_of_v<Windows::Foundation::IInspectable, T>)
        {
            return value.as<T>();
        }
        else
        {
            return impl::unbox_value_type<T>(value);
        }
    }

    template <typename T = hstring, std::enable_if_t<std::is_same_v<T, hstring>, int> = 0>
    hstring unbox_value_or(Windows::Foundation::IInspectable const& value, param::hstring const& default_value)
    {
        if (value)
        {
            if (auto temp = value.try_as<Windows::Foundation::IReference<hstring>>())
            {
                return temp.Value();
            }
        }

        return *(hstring*)(&default_value);
    }

    template <typename T, std::enable_if_t<!std::is_same_v<T, hstring>, int> = 0>
    T unbox_value_or(Windows::Foundation::IInspectable const& value, T const& default_value)
    {
        if (value)
        {
            if constexpr (std::is_base_of_v<Windows::Foundation::IInspectable, T>)
            {
                if (auto temp = value.try_as<T>())
                {
                    return temp;
                }
            }
            else
            {
                return impl::unbox_value_type_or<T>(value, default_value);
            }
        }
        return default_value;
    }

    template <typename T>
    using optional = typename impl::reference_traits<T>::itf;
}

LLM_EXPORT namespace winrt
{
#ifdef LLM_IMPL_COROUTINES
    template<typename D>
    struct deferrable_event_args
    {
        Windows::Foundation::Deferral GetDeferral()
        {
            slim_lock_guard const guard(m_lock);

            if (m_handle)
            {
                // Cannot ask for deferral after the event handler returned.
                throw hresult_illegal_method_call();
            }

            Windows::Foundation::Deferral deferral{ {static_cast<D&>(*this).get_strong(), &deferrable_event_args::one_deferral_completed } };
            ++m_outstanding_deferrals;
            return deferral;
        }

        [[nodiscard]] Windows::Foundation::IAsyncAction wait_for_deferrals()
        {
            struct awaitable : impl::suspend_always
            {
                bool await_suspend(coroutine_handle handle)
                {
                    return m_deferrable.await_suspend(handle);
                }

                deferrable_event_args& m_deferrable;
            };

            co_await awaitable{ {}, *this };
        }

    private:

        using coroutine_handle = impl::coroutine_handle<>;

        void one_deferral_completed()
        {
            coroutine_handle resume = nullptr;
            {
                slim_lock_guard const guard(m_lock);

                if (m_outstanding_deferrals <= 0)
                {
                    throw hresult_illegal_method_call();
                }

                if (--m_outstanding_deferrals == 0)
                {
                    resume = m_handle;
                }
            }

            if (resume)
            {
                impl::resume_background(resume);
            }
        }

        bool await_suspend(coroutine_handle handle) noexcept
        {
            slim_lock_guard const guard(m_lock);
            m_handle = handle;
            return m_outstanding_deferrals > 0;
        }

        slim_mutex m_lock;
        int32_t m_outstanding_deferrals = 0;
        coroutine_handle m_handle = nullptr;
    };
#endif
}

namespace llm::impl
{
    template <typename Async>
    struct async_completed_handler;

    template <typename Async>
    using async_completed_handler_t = typename async_completed_handler<Async>::type;

    template <>
    struct async_completed_handler<Windows::Foundation::IAsyncAction>
    {
        using type = Windows::Foundation::AsyncActionCompletedHandler;
    };

    template <typename TProgress>
    struct async_completed_handler<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        using type = Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>;
    };

    template <typename TResult>
    struct async_completed_handler<Windows::Foundation::IAsyncOperation<TResult>>
    {
        using type = Windows::Foundation::AsyncOperationCompletedHandler<TResult>;
    };

    template <typename TResult, typename TProgress>
    struct async_completed_handler<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        using type = Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>;
    };

    inline void check_sta_blocking_wait() noexcept
    {
        // Note: A blocking wait on the UI thread for an asynchronous operation can cause a deadlock.
        // See https://docs.microsoft.com/windows/uwp/cpp-and-winrt-apis/concurrency#block-the-calling-thread
        LLM_ASSERT(!is_sta_thread());
    }

    template <typename T, typename H>
    std::pair<T, H*> make_delegate_with_shared_state(H&& handler)
    {
        auto d = make_delegate<T, H>(std::forward<H>(handler));
        return { std::move(d), reinterpret_cast<delegate<T, H>*>(get_abi(d)) };
    }

    template <typename Async>
    auto wait_for_completed(Async const& async, uint32_t const timeout)
    {
        struct shared_type
        {
            handle event{ check_pointer(LLM_IMPL_CreateEventW(nullptr, true, false, nullptr)) };
            Windows::Foundation::AsyncStatus status{ Windows::Foundation::AsyncStatus::Started };

            void operator()(Async const&, Windows::Foundation::AsyncStatus operation_status) noexcept
            {
                status = operation_status;
                LLM_VERIFY(LLM_IMPL_SetEvent(event.get()));
            }
        };

        auto [delegate, shared] = make_delegate_with_shared_state<async_completed_handler_t<Async>>(shared_type{});
        async.Completed(delegate);
        LLM_IMPL_WaitForSingleObject(shared->event.get(), timeout);
        return shared->status;
    }

    template <typename Async>
    auto wait_for(Async const& async, Windows::Foundation::TimeSpan const& timeout)
    {
        check_sta_blocking_wait();
        auto const milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeout).count();
        LLM_ASSERT((milliseconds >= 0) && (static_cast<uint64_t>(milliseconds) < 0xFFFFFFFFull)); // Within uint32_t range and not INFINITE
        return wait_for_completed(async, static_cast<uint32_t>(milliseconds));
    }

    inline void check_status_canceled(Windows::Foundation::AsyncStatus status)
    {
        if (status == Windows::Foundation::AsyncStatus::Canceled)
        {
            throw hresult_canceled();
        }
    }

    template <typename Async>
    auto wait_get(Async const& async)
    {
        check_sta_blocking_wait();

        auto status = async.Status();
        if (status == Windows::Foundation::AsyncStatus::Started)
        {
            status = wait_for_completed(async, 0xFFFFFFFF); // INFINITE
        }
        check_status_canceled(status);

        return async.GetResults();
    }

    template<typename Awaiter>
    struct disconnect_aware_handler
    {
        disconnect_aware_handler(Awaiter* awaiter, coroutine_handle<> handle) noexcept
            : m_awaiter(awaiter), m_handle(handle) { }

        disconnect_aware_handler(disconnect_aware_handler&& other) noexcept
            : m_context(std::move(other.m_context))
            , m_awaiter(std::exchange(other.m_awaiter, {}))
            , m_handle(std::exchange(other.m_handle, {})) { }

        ~disconnect_aware_handler()
        {
            if (m_handle) Complete();
        }

        template<typename Async>
        void operator()(Async&&, Windows::Foundation::AsyncStatus status)
        {
            m_awaiter->status = status;
            Complete();
        }

    private:
        resume_apartment_context m_context;
        Awaiter* m_awaiter;
        coroutine_handle<> m_handle;

        void Complete()
        {
            if (m_awaiter->suspending.exchange(false, std::memory_order_release))
            {
                m_handle = nullptr; // resumption deferred to await_suspend
            }
            else
            {
                resume_apartment(m_context, std::exchange(m_handle, {}), &m_awaiter->failure);
            }

        }
    };

#ifdef LLM_IMPL_COROUTINES
    template <typename Async>
    struct await_adapter : enable_await_cancellation
    {
        await_adapter(Async const& async) : async(async) { }

        Async const& async;
        Windows::Foundation::AsyncStatus status = Windows::Foundation::AsyncStatus::Started;
        int32_t failure = 0;
        std::atomic<bool> suspending{ true };

        void enable_cancellation(cancellable_promise* promise)
        {
            promise->set_canceller([](void* parameter)
            {
                cancel_asynchronously(reinterpret_cast<await_adapter*>(parameter)->async);
            }, this);
        }

        bool await_ready() const noexcept
        {
            return false;
        }

        auto await_suspend(coroutine_handle<> handle)
        {
            auto extend_lifetime = async;
            async.Completed(disconnect_aware_handler(this, handle));
#ifdef _RESUMABLE_FUNCTIONS_SUPPORTED
            if (!suspending.exchange(false, std::memory_order_acquire))
            {
                handle.resume();
            }
#else
            return suspending.exchange(false, std::memory_order_acquire);
#endif
        }

        auto await_resume() const
        {
            check_hresult(failure);
            check_status_canceled(status);
            return async.GetResults();
        }

    private:
        static fire_and_forget cancel_asynchronously(Async async)
        {
            co_await llm::resume_background();
            try
            {
                async.Cancel();
            }
            catch (hresult_error const&)
            {
            }
        }
    };
#endif

    template <typename D>
    auto consume_Windows_Foundation_IAsyncAction<D>::get() const
    {
        impl::wait_get(static_cast<Windows::Foundation::IAsyncAction const&>(static_cast<D const&>(*this)));
    }
    template <typename D>
    auto consume_Windows_Foundation_IAsyncAction<D>::wait_for(Windows::Foundation::TimeSpan const& timeout) const
    {
        return impl::wait_for(static_cast<Windows::Foundation::IAsyncAction const&>(static_cast<D const&>(*this)), timeout);
    }

    template <typename D, typename TResult>
    auto consume_Windows_Foundation_IAsyncOperation<D, TResult>::get() const
    {
        return impl::wait_get(static_cast<Windows::Foundation::IAsyncOperation<TResult> const&>(static_cast<D const&>(*this)));
    }
    template <typename D, typename TResult>
    auto consume_Windows_Foundation_IAsyncOperation<D, TResult>::wait_for(Windows::Foundation::TimeSpan const& timeout) const
    {
        return impl::wait_for(static_cast<Windows::Foundation::IAsyncOperation<TResult> const&>(static_cast<D const&>(*this)), timeout);
    }

    template <typename D, typename TProgress>
    auto consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>::get() const
    {
        impl::wait_get(static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)));
    }
    template <typename D, typename TProgress>
    auto consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>::wait_for(Windows::Foundation::TimeSpan const& timeout) const
    {
        return impl::wait_for(static_cast<Windows::Foundation::IAsyncActionWithProgress<TProgress> const&>(static_cast<D const&>(*this)), timeout);
    }

    template <typename D, typename TResult, typename TProgress>
    auto consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>::get() const
    {
        return impl::wait_get(static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)));
    }
    template <typename D, typename TResult, typename TProgress>
    auto consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>::wait_for(Windows::Foundation::TimeSpan const& timeout) const
    {
        return impl::wait_for(static_cast<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const&>(static_cast<D const&>(*this)), timeout);
    }
}

#ifdef LLM_IMPL_COROUTINES
LLM_EXPORT namespace llm::OS::Foundation
{
    inline impl::await_adapter<IAsyncAction> operator co_await(IAsyncAction const& async)
    {
        return{ async };
    }

    template <typename TProgress>
    impl::await_adapter<IAsyncActionWithProgress<TProgress>> operator co_await(IAsyncActionWithProgress<TProgress> const& async)
    {
        return{ async };
    }

    template <typename TResult>
    impl::await_adapter<IAsyncOperation<TResult>> operator co_await(IAsyncOperation<TResult> const& async)
    {
        return{ async };
    }

    template <typename TResult, typename TProgress>
    impl::await_adapter<IAsyncOperationWithProgress<TResult, TProgress>> operator co_await(IAsyncOperationWithProgress<TResult, TProgress> const& async)
    {
        return{ async };
    }
}
#endif

LLM_EXPORT namespace winrt
{
    struct get_progress_token_t {};

    inline get_progress_token_t get_progress_token() noexcept
    {
        return{};
    }

    struct get_cancellation_token_t {};

    inline get_cancellation_token_t get_cancellation_token() noexcept
    {
        return{};
    }
}

namespace llm::impl
{
    template <typename Promise>
    struct cancellation_token
    {
        cancellation_token(Promise* promise) noexcept : m_promise(promise)
        {
        }

        bool await_ready() const noexcept
        {
            return true;
        }

        void await_suspend(coroutine_handle<>) const noexcept
        {
        }

        cancellation_token<Promise> await_resume() const noexcept
        {
            return *this;
        }

        bool operator()() const noexcept
        {
            return m_promise->Status() == Windows::Foundation::AsyncStatus::Canceled;
        }

        void callback(llm::delegate<>&& cancel) const noexcept
        {
            m_promise->cancellation_callback(std::move(cancel));
        }

        bool enable_propagation(bool value = true) const noexcept
        {
            return m_promise->enable_cancellation_propagation(value);
        }

    private:

        Promise* m_promise;
    };

    template <typename Promise, typename Progress>
    struct progress_token
    {
        progress_token(Promise* promise) noexcept :
            m_promise(promise)
        {
        }

        bool await_ready() const noexcept
        {
            return true;
        }

        void await_suspend(coroutine_handle<>) const noexcept
        {
        }

        progress_token<Promise, Progress> await_resume() const noexcept
        {
            return *this;
        }

        void operator()(Progress const& result) const
        {
            m_promise->set_progress(result);
        }

        template<typename T>
        void set_result(T&& value) const
        {
            static_assert(!std::is_same_v<Progress, void>, "Setting preliminary results requires IAsync...WithProgress");
            m_promise->return_value(std::forward<T>(value));
        }

    private:

        Promise* m_promise;
    };

    template <typename Derived, typename AsyncInterface, typename TProgress = void>
    struct promise_base : implements<Derived, AsyncInterface, Windows::Foundation::IAsyncInfo>
    {
        using AsyncStatus = Windows::Foundation::AsyncStatus;

        unsigned long __stdcall Release() noexcept
        {
            uint32_t const remaining = this->subtract_reference();

            if (remaining == 0)
            {
                std::atomic_thread_fence(std::memory_order_acquire);
                coroutine_handle<Derived>::from_promise(*static_cast<Derived*>(this)).destroy();
            }

            return remaining;
        }

        void Completed(async_completed_handler_t<AsyncInterface> const& handler)
        {
            AsyncStatus status;

            {
                slim_lock_guard const guard(m_lock);

                if (m_completed_assigned)
                {
                    throw hresult_illegal_delegate_assignment();
                }

                m_completed_assigned = true;

                status = m_status.load(std::memory_order_relaxed);
                if (status == AsyncStatus::Started)
                {
                    m_completed = make_agile_delegate(handler);
                    return;
                }
            }

            if (handler)
            {
                invoke(handler, *this, status);
            }
        }

        auto Completed() noexcept
        {
            slim_lock_guard const guard(m_lock);
            return m_completed;
        }

        uint32_t Id() const noexcept
        {
            return 1;
        }

        AsyncStatus Status() noexcept
        {
            // It's okay to race against another thread that is changing the
            // status. In the case where the promise was published from another
            // thread, we need acquire in order to preserve causality.
            return m_status.load(std::memory_order_acquire);
        }

        hresult ErrorCode() noexcept
        {
            try
            {
                slim_lock_guard const guard(m_lock);
                rethrow_if_failed(m_status.load(std::memory_order_relaxed));
                return 0;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        void Cancel() noexcept
        {
            llm::delegate<> cancel;

            {
                slim_lock_guard const guard(m_lock);

                if (m_status.load(std::memory_order_relaxed) == AsyncStatus::Started)
                {
                    m_status.store(AsyncStatus::Canceled, std::memory_order_relaxed);
                    m_exception = std::make_exception_ptr(hresult_canceled());
                    cancel = std::move(m_cancel);
                }
            }

            if (cancel)
            {
                cancel();
            }

            m_cancellable.cancel();
        }

        void Close() const noexcept
        {
        }

        auto GetResults()
        {
            slim_lock_guard const guard(m_lock);

            auto status = m_status.load(std::memory_order_relaxed);

            if constexpr (std::is_same_v<TProgress, void>)
            {
                if (status == AsyncStatus::Completed)
                {
                    return static_cast<Derived*>(this)->get_return_value();
                }
                rethrow_if_failed(status);
                LLM_ASSERT(status == AsyncStatus::Started);
                throw hresult_illegal_method_call();
            }
            else
            {
                if (status == AsyncStatus::Completed || status == AsyncStatus::Started)
                {
                    return static_cast<Derived*>(this)->copy_return_value();
                }
                LLM_ASSERT(status == AsyncStatus::Error || status == AsyncStatus::Canceled);
                std::rethrow_exception(m_exception);
            }

        }

        AsyncInterface get_return_object() const noexcept
        {
            return *this;
        }

        void get_return_value() const noexcept
        {
        }

        void copy_return_value() const noexcept
        {
        }

        void set_completed() noexcept
        {
            async_completed_handler_t<AsyncInterface> handler;
            AsyncStatus status;

            {
                slim_lock_guard const guard(m_lock);

                status = m_status.load(std::memory_order_relaxed);
                if (status == AsyncStatus::Started)
                {
                    status = AsyncStatus::Completed;
                    m_status.store(status, std::memory_order_relaxed);
                }

                handler = std::move(this->m_completed);
            }

            if (handler)
            {
                invoke(handler, *this, status);
            }
        }

        suspend_never initial_suspend() const noexcept
        {
            return{};
        }

        struct final_suspend_awaiter
        {
            promise_base* promise;

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_resume() const noexcept
            {
            }

            bool await_suspend(coroutine_handle<>) const noexcept
            {
                promise->set_completed();
                uint32_t const remaining = promise->subtract_reference();

                if (remaining == 0)
                {
                    std::atomic_thread_fence(std::memory_order_acquire);
                }

                return remaining > 0;
            }
        };

        auto final_suspend() noexcept
        {
            if (llm_suspend_handler)
            {
                llm_suspend_handler(this);
            }

            return final_suspend_awaiter{ this };
        }

        void unhandled_exception() noexcept
        {
            slim_lock_guard const guard(m_lock);
            LLM_ASSERT(m_status.load(std::memory_order_relaxed) == AsyncStatus::Started || m_status.load(std::memory_order_relaxed) == AsyncStatus::Canceled);
            m_exception = std::current_exception();

            try
            {
                std::rethrow_exception(m_exception);
            }
            catch (hresult_canceled const&)
            {
                m_status.store(AsyncStatus::Canceled, std::memory_order_relaxed);
            }
            catch (...)
            {
                m_status.store(AsyncStatus::Error, std::memory_order_relaxed);
            }
        }

        template <typename Expression>
        auto await_transform(Expression&& expression)
        {
            if (Status() == AsyncStatus::Canceled)
            {
                throw llm::hresult_canceled();
            }

            return notify_awaiter<Expression>{ static_cast<Expression&&>(expression), m_propagate_cancellation ? &m_cancellable : nullptr };
        }

        cancellation_token<Derived> await_transform(get_cancellation_token_t) noexcept
        {
            return{ static_cast<Derived*>(this) };
        }

        progress_token<Derived, TProgress> await_transform(get_progress_token_t) noexcept
        {
            return{ static_cast<Derived*>(this) };
        }

        void cancellation_callback(llm::delegate<>&& cancel) noexcept
        {
            {
                slim_lock_guard const guard(m_lock);

                if (m_status.load(std::memory_order_relaxed) != AsyncStatus::Canceled)
                {
                    m_cancel = std::move(cancel);
                    return;
                }
            }

            if (cancel)
            {
                cancel();
            }
        }

        bool enable_cancellation_propagation(bool value) noexcept
        {
            return std::exchange(m_propagate_cancellation, value);
        }

#if defined(_DEBUG) && !defined(LLM_NO_MAKE_DETECTION)
        void use_make_function_to_create_this_object() final
        {
        }
#endif

    protected:

        void rethrow_if_failed(AsyncStatus status) const
        {
            if (status == AsyncStatus::Error || status == AsyncStatus::Canceled)
            {
                std::rethrow_exception(m_exception);
            }
        }

        std::exception_ptr m_exception{};
        slim_mutex m_lock;
        async_completed_handler_t<AsyncInterface> m_completed;
        llm::delegate<> m_cancel;
        cancellable_promise m_cancellable;
        std::atomic<AsyncStatus> m_status;
        bool m_completed_assigned{ false };
        bool m_propagate_cancellation{ false };
    };
}

#ifdef __cpp_lib_coroutine
namespace std
#else
namespace std::experimental
#endif
{
    template <typename... Args>
    struct coroutine_traits<llm::OS::Foundation::IAsyncAction, Args...>
    {
        struct promise_type final : llm::impl::promise_base<promise_type, llm::OS::Foundation::IAsyncAction>
        {
            void return_void() const noexcept
            {
            }
        };
    };

    template <typename TProgress, typename... Args>
    struct coroutine_traits<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>, Args...>
    {
        struct promise_type final : llm::impl::promise_base<promise_type, llm::OS::Foundation::IAsyncActionWithProgress<TProgress>, TProgress>
        {
            using ProgressHandler = llm::OS::Foundation::AsyncActionProgressHandler<TProgress>;

            void Progress(ProgressHandler const& handler) noexcept
            {
                llm::slim_lock_guard const guard(this->m_lock);
                m_progress = llm::impl::make_agile_delegate(handler);
            }

            ProgressHandler Progress() noexcept
            {
                llm::slim_lock_guard const guard(this->m_lock);
                return m_progress;
            }

            void return_void() const noexcept
            {
            }

            void set_progress(TProgress const& result)
            {
                if (auto handler = Progress())
                {
                    llm::impl::invoke(handler, *this, result);
                }
            }

            ProgressHandler m_progress;
        };
    };

    template <typename TResult, typename... Args>
    struct coroutine_traits<llm::OS::Foundation::IAsyncOperation<TResult>, Args...>
    {
        struct promise_type final : llm::impl::promise_base<promise_type, llm::OS::Foundation::IAsyncOperation<TResult>>
        {
            TResult get_return_value() noexcept
            {
                return std::move(m_result);
            }

            TResult copy_return_value() noexcept
            {
                return m_result;
            }

            void return_value(TResult&& value) noexcept
            {
                m_result = std::move(value);
            }

            void return_value(TResult const& value) noexcept
            {
                m_result = value;
            }

            TResult m_result{ llm::impl::empty_value<TResult>() };
        };
    };

    template <typename TResult, typename TProgress, typename... Args>
    struct coroutine_traits<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>, Args...>
    {
        struct promise_type final : llm::impl::promise_base<promise_type,
            llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>, TProgress>
        {
            using ProgressHandler = llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>;

            void Progress(ProgressHandler const& handler) noexcept
            {
                llm::slim_lock_guard const guard(this->m_lock);
                m_progress = llm::impl::make_agile_delegate(handler);
            }

            ProgressHandler Progress() noexcept
            {
                llm::slim_lock_guard const guard(this->m_lock);
                return m_progress;
            }

            TResult get_return_value() noexcept
            {
                return std::move(m_result);
            }

            TResult copy_return_value() noexcept
            {
                return m_result;
            }

            void return_value(TResult&& value) noexcept
            {
                llm::slim_lock_guard const guard(this->m_lock);
                m_result = std::move(value);
            }

            void return_value(TResult const& value) noexcept
            {
                llm::slim_lock_guard const guard(this->m_lock);
                m_result = value;
            }

            void set_progress(TProgress const& result)
            {
                if (auto handler = Progress())
                {
                    llm::impl::invoke(handler, *this, result);
                }
            }

            TResult m_result{ llm::impl::empty_value<TResult>() };
            ProgressHandler m_progress;
        };
    };
}

LLM_EXPORT namespace winrt
{
#ifdef LLM_IMPL_COROUTINES
    template <typename... T>
    Windows::Foundation::IAsyncAction when_all(T... async)
    {
        (void(co_await async), ...);
        co_return;
    }

    template <typename T, typename... Rest>
    T when_any(T const& first, Rest const& ... rest)
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT async type such as IAsyncAction or IAsyncOperation.");
        static_assert((std::is_same_v<T, Rest> && ...), "All when_any parameters must be the same type.");

        struct shared_type
        {
            handle event{ check_pointer(LLM_IMPL_CreateEventW(nullptr, true, false, nullptr)) };
            Windows::Foundation::AsyncStatus status{ Windows::Foundation::AsyncStatus::Started };
            T result;

            void operator()(T const& sender, Windows::Foundation::AsyncStatus operation_status) noexcept
            {
                auto sender_abi = *(impl::unknown_abi**)&sender;

                if (nullptr == _InterlockedCompareExchangePointer(reinterpret_cast<void**>(&result), sender_abi, nullptr))
                {
                    sender_abi->AddRef();
                    status = operation_status;
                    LLM_VERIFY(LLM_IMPL_SetEvent(event.get()));
                }
            }
        };

        auto [delegate, shared] = impl::make_delegate_with_shared_state<impl::async_completed_handler_t<T>>(shared_type{});

        auto completed = [delegate = std::move(delegate)](T const& async)
        {
            async.Completed(delegate);
        };

        completed(first);
        (completed(rest), ...);
        co_await resume_on_signal(shared->event.get());
        impl::check_status_canceled(shared->status);
        co_return shared->result.GetResults();
    }
#endif
}

#ifdef __cpp_lib_format
template <typename FormatContext>
auto std::formatter<llm::OS::Foundation::IStringable, wchar_t>::format(llm::OS::Foundation::IStringable const& obj, FormatContext& fc)
{
    return std::formatter<llm::hstring, wchar_t>::format(obj.ToString(), fc);
}
#endif
#endif
