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
#ifndef LLM_OS_UI_UIAutomation_Core_H
#define LLM_OS_UI_UIAutomation_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.UIAutomation.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.UIAutomation.2.h"
#include "llm/impl/Windows.UI.UIAutomation.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationStatus) consume_Windows_UI_UIAutomation_Core_IAutomationRemoteOperationResult<D>::Status() const
    {
        llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_UI_UIAutomation_Core_IAutomationRemoteOperationResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_UIAutomation_Core_IAutomationRemoteOperationResult<D>::ErrorLocation() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult)->get_ErrorLocation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_UIAutomation_Core_IAutomationRemoteOperationResult<D>::HasOperand(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& operandId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult)->HasOperand(impl::bind_in(operandId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_UIAutomation_Core_IAutomationRemoteOperationResult<D>::GetOperand(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& operandId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult)->GetOperand(impl::bind_in(operandId), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_UIAutomation_Core_ICoreAutomationConnectionBoundObjectProvider<D>::IsComThreadingRequired() const noexcept
    {
        bool value{};
        LLM_VERIFY_(0, LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationConnectionBoundObjectProvider)->get_IsComThreadingRequired(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRegistrarStatics<D>::RegisterAnnotationType(llm::guid const& guid) const
    {
        llm::OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRegistrarStatics)->RegisterAnnotationType(impl::bind_in(guid), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRegistrarStatics<D>::UnregisterAnnotationType(llm::OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration const& registration) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRegistrarStatics)->UnregisterAnnotationType(impl::bind_in(registration)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperation<D>::IsOpcodeSupported(uint32_t opcode) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation)->IsOpcodeSupported(opcode, &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperation<D>::ImportElement(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& operandId, llm::OS::UI::UIAutomation::AutomationElement const& element) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation)->ImportElement(impl::bind_in(operandId), *(void**)(&element)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperation<D>::ImportTextRange(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& operandId, llm::OS::UI::UIAutomation::AutomationTextRange const& textRange) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation)->ImportTextRange(impl::bind_in(operandId), *(void**)(&textRange)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperation<D>::AddToResults(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& operandId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation)->AddToResults(impl::bind_in(operandId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationResult) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperation<D>::Execute(array_view<uint8_t const> bytecodeBuffer) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation)->Execute(bytecodeBuffer.size(), get_abi(bytecodeBuffer), &result));
        return llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperation2<D>::ImportConnectionBoundObject(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& operandId, llm::OS::UI::UIAutomation::AutomationConnectionBoundObject const& connectionBoundObject) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation2)->ImportConnectionBoundObject(impl::bind_in(operandId), *(void**)(&connectionBoundObject)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperationContext<D>::GetOperand(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext)->GetOperand(impl::bind_in(id), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperationContext<D>::SetOperand(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& id, llm::OS::Foundation::IInspectable const& operand) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext)->SetOperand(impl::bind_in(id), *(void**)(&operand)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperationContext<D>::SetOperand(llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const& id, llm::OS::Foundation::IInspectable const& operand, llm::guid const& operandInterfaceId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext)->SetOperand2(impl::bind_in(id), *(void**)(&operand), impl::bind_in(operandInterfaceId)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperationExtensionProvider<D>::CallExtension(llm::guid const& extensionId, llm::OS::UI::UIAutomation::Core::CoreAutomationRemoteOperationContext const& context, array_view<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const> operandIds) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationExtensionProvider)->CallExtension(impl::bind_in(extensionId), *(void**)(&context), operandIds.size(), get_abi(operandIds)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_UIAutomation_Core_ICoreAutomationRemoteOperationExtensionProvider<D>::IsExtensionSupported(llm::guid const& extensionId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationExtensionProvider)->IsExtensionSupported(impl::bind_in(extensionId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::UIAutomation::Core::RemoteAutomationWindow>) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::CreateWindowAsync(uint64_t remoteWindowId, uint32_t remoteProcessId, llm::OS::Foundation::IInspectable const& parentAutomationElement) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->CreateWindowAsync(remoteWindowId, remoteProcessId, *(void**)(&parentAutomationElement), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::UIAutomation::Core::RemoteAutomationWindow>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::SessionId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->get_SessionId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::ConnectionRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession, llm::OS::UI::UIAutomation::Core::RemoteAutomationConnectionRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->add_ConnectionRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::ConnectionRequested_revoker consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::ConnectionRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession, llm::OS::UI::UIAutomation::Core::RemoteAutomationConnectionRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ConnectionRequested_revoker>(this, ConnectionRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::ConnectionRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->remove_ConnectionRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::Disconnected(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession, llm::OS::UI::UIAutomation::Core::RemoteAutomationDisconnectedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->add_Disconnected(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::Disconnected_revoker consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::Disconnected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession, llm::OS::UI::UIAutomation::Core::RemoteAutomationDisconnectedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Disconnected_revoker>(this, Disconnected(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSession<D>::Disconnected(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession)->remove_Disconnected(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSessionFactory<D>::CreateInstance(param::hstring const& name) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSessionFactory)->CreateInstance(*(void**)(&name), &value));
        return llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationClientSessionFactory<D>::CreateInstance2(param::hstring const& name, llm::guid const& sessionId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSessionFactory)->CreateInstance2(*(void**)(&name), impl::bind_in(sessionId), &value));
        return llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationConnectionRequestedEventArgs<D>::LocalPipeName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs)->get_LocalPipeName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationConnectionRequestedEventArgs<D>::RemoteProcessId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs)->get_RemoteProcessId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationDisconnectedEventArgs<D>::LocalPipeName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs)->get_LocalPipeName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationServerStatics<D>::ReportSession(llm::guid const& sessionId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationServerStatics)->ReportSession(impl::bind_in(sessionId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationWindow<D>::AutomationProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationWindow)->get_AutomationProvider(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_UIAutomation_Core_IRemoteAutomationWindow<D>::UnregisterAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::Core::IRemoteAutomationWindow)->UnregisterAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult> : produce_base<D, llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorLocation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ErrorLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HasOperand(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId operandId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().HasOperand(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&operandId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOperand(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId operandId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetOperand(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&operandId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationConnectionBoundObjectProvider> : produce_base<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationConnectionBoundObjectProvider>
    {
        int32_t __stdcall get_IsComThreadingRequired(bool* value) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsComThreadingRequired());
            return 0;
        }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRegistrarStatics> : produce_base<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRegistrarStatics>
    {
        int32_t __stdcall RegisterAnnotationType(llm::guid guid, struct struct_Windows_UI_UIAutomation_Core_AutomationAnnotationTypeRegistration* result) noexcept final try
        {
            zero_abi<llm::OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration>(this->shim().RegisterAnnotationType(*reinterpret_cast<llm::guid const*>(&guid)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterAnnotationType(struct struct_Windows_UI_UIAutomation_Core_AutomationAnnotationTypeRegistration registration) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterAnnotationType(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration const*>(&registration));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation> : produce_base<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation>
    {
        int32_t __stdcall IsOpcodeSupported(uint32_t opcode, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsOpcodeSupported(opcode));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ImportElement(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId operandId, void* element) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImportElement(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&operandId), *reinterpret_cast<llm::OS::UI::UIAutomation::AutomationElement const*>(&element));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ImportTextRange(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId operandId, void* textRange) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImportTextRange(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&operandId), *reinterpret_cast<llm::OS::UI::UIAutomation::AutomationTextRange const*>(&textRange));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddToResults(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId operandId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToResults(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&operandId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Execute(uint32_t __bytecodeBufferSize, uint8_t* bytecodeBuffer, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationResult>(this->shim().Execute(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(bytecodeBuffer), reinterpret_cast<uint8_t const *>(bytecodeBuffer) + __bytecodeBufferSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation2> : produce_base<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation2>
    {
        int32_t __stdcall ImportConnectionBoundObject(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId operandId, void* connectionBoundObject) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImportConnectionBoundObject(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&operandId), *reinterpret_cast<llm::OS::UI::UIAutomation::AutomationConnectionBoundObject const*>(&connectionBoundObject));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext> : produce_base<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext>
    {
        int32_t __stdcall GetOperand(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetOperand(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetOperand(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId id, void* operand) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetOperand(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&id), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&operand));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetOperand2(struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId id, void* operand, llm::guid operandInterfaceId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetOperand(*reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const*>(&id), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&operand), *reinterpret_cast<llm::guid const*>(&operandInterfaceId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationExtensionProvider> : produce_base<D, llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationExtensionProvider>
    {
        int32_t __stdcall CallExtension(llm::guid extensionId, void* context, uint32_t __operandIdsSize, struct struct_Windows_UI_UIAutomation_Core_AutomationRemoteOperationOperandId* operandIds) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallExtension(*reinterpret_cast<llm::guid const*>(&extensionId), *reinterpret_cast<llm::OS::UI::UIAutomation::Core::CoreAutomationRemoteOperationContext const*>(&context), array_view<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const>(reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const *>(operandIds), reinterpret_cast<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationOperandId const *>(operandIds) + __operandIdsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsExtensionSupported(llm::guid extensionId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsExtensionSupported(*reinterpret_cast<llm::guid const*>(&extensionId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession> : produce_base<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession>
    {
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWindowAsync(uint64_t remoteWindowId, uint32_t remoteProcessId, void* parentAutomationElement, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::UIAutomation::Core::RemoteAutomationWindow>>(this->shim().CreateWindowAsync(remoteWindowId, remoteProcessId, *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&parentAutomationElement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SessionId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().SessionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ConnectionRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ConnectionRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession, llm::OS::UI::UIAutomation::Core::RemoteAutomationConnectionRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ConnectionRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConnectionRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Disconnected(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Disconnected(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession, llm::OS::UI::UIAutomation::Core::RemoteAutomationDisconnectedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Disconnected(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disconnected(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSessionFactory> : produce_base<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSessionFactory>
    {
        int32_t __stdcall CreateInstance(void* name, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession>(this->shim().CreateInstance(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInstance2(void* name, llm::guid sessionId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession>(this->shim().CreateInstance2(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::guid const*>(&sessionId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs> : produce_base<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs>
    {
        int32_t __stdcall get_LocalPipeName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LocalPipeName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteProcessId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().RemoteProcessId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs> : produce_base<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs>
    {
        int32_t __stdcall get_LocalPipeName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LocalPipeName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationServerStatics> : produce_base<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationServerStatics>
    {
        int32_t __stdcall ReportSession(llm::guid sessionId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportSession(*reinterpret_cast<llm::guid const*>(&sessionId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationWindow> : produce_base<D, llm::OS::UI::UIAutomation::Core::IRemoteAutomationWindow>
    {
        int32_t __stdcall get_AutomationProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().AutomationProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UnregisterAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::UIAutomation::Core
{
    inline auto CoreAutomationRegistrar::RegisterAnnotationType(llm::guid const& guid)
    {
        return impl::call_factory<CoreAutomationRegistrar, ICoreAutomationRegistrarStatics>([&](ICoreAutomationRegistrarStatics const& f) { return f.RegisterAnnotationType(guid); });
    }
    inline auto CoreAutomationRegistrar::UnregisterAnnotationType(llm::OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration const& registration)
    {
        impl::call_factory<CoreAutomationRegistrar, ICoreAutomationRegistrarStatics>([&](ICoreAutomationRegistrarStatics const& f) { return f.UnregisterAnnotationType(registration); });
    }
    inline CoreAutomationRemoteOperation::CoreAutomationRemoteOperation() :
        CoreAutomationRemoteOperation(impl::call_factory_cast<CoreAutomationRemoteOperation(*)(llm::OS::Foundation::IActivationFactory const&), CoreAutomationRemoteOperation>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CoreAutomationRemoteOperation>(); }))
    {
    }
    inline RemoteAutomationClientSession::RemoteAutomationClientSession(param::hstring const& name) :
        RemoteAutomationClientSession(impl::call_factory<RemoteAutomationClientSession, IRemoteAutomationClientSessionFactory>([&](IRemoteAutomationClientSessionFactory const& f) { return f.CreateInstance(name); }))
    {
    }
    inline RemoteAutomationClientSession::RemoteAutomationClientSession(param::hstring const& name, llm::guid const& sessionId) :
        RemoteAutomationClientSession(impl::call_factory<RemoteAutomationClientSession, IRemoteAutomationClientSessionFactory>([&](IRemoteAutomationClientSessionFactory const& f) { return f.CreateInstance2(name, sessionId); }))
    {
    }
    inline auto RemoteAutomationServer::ReportSession(llm::guid const& sessionId)
    {
        impl::call_factory<RemoteAutomationServer, IRemoteAutomationServerStatics>([&](IRemoteAutomationServerStatics const& f) { return f.ReportSession(sessionId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::ICoreAutomationConnectionBoundObjectProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::ICoreAutomationRegistrarStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationExtensionProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::IRemoteAutomationClientSessionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::IRemoteAutomationServerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::IRemoteAutomationWindow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::AutomationRemoteOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::CoreAutomationRegistrar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::CoreAutomationRemoteOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::CoreAutomationRemoteOperationContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::RemoteAutomationClientSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::RemoteAutomationConnectionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::RemoteAutomationDisconnectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::RemoteAutomationServer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::Core::RemoteAutomationWindow> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
