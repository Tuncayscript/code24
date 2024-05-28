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
#ifndef LLM_OS_Phone_UI_Core_H
#define LLM_OS_Phone_UI_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Phone.UI.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Phone_UI_Core_ICoreSelectionChangedEventArgs<D>::Start() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreSelectionChangedEventArgs)->get_Start(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Phone_UI_Core_ICoreSelectionChangedEventArgs<D>::Length() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreSelectionChangedEventArgs)->get_Length(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Phone_UI_Core_ICoreTextChangedEventArgs<D>::Start() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreTextChangedEventArgs)->get_Start(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Phone_UI_Core_ICoreTextChangedEventArgs<D>::OldLength() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreTextChangedEventArgs)->get_OldLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Phone_UI_Core_ICoreTextChangedEventArgs<D>::NewText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreTextChangedEventArgs)->get_NewText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Phone_UI_Core_ICoreWindowKeyboardInput<D>::IsKeyboardInputEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreWindowKeyboardInput)->get_IsKeyboardInputEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_ICoreWindowKeyboardInput<D>::IsKeyboardInputEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreWindowKeyboardInput)->put_IsKeyboardInputEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::UI::Core::KeyboardInputBuffer) consume_Windows_Phone_UI_Core_ICoreWindowKeyboardInput<D>::KeyboardInputBuffer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreWindowKeyboardInput)->get_KeyboardInputBuffer(&value));
        return llm::OS::Phone::UI::Core::KeyboardInputBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_ICoreWindowKeyboardInput<D>::KeyboardInputBuffer(llm::OS::Phone::UI::Core::KeyboardInputBuffer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::ICoreWindowKeyboardInput)->put_KeyboardInputBuffer(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::Text(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->put_Text(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::SelectionStart() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->get_SelectionStart(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::SelectionLength() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->get_SelectionLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::Select(uint32_t start, uint32_t length) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->Select(start, length));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::SelectFromTap(uint32_t characterIndex) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->SelectFromTap(characterIndex));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::UI::Core::CoreInputScope) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::InputScope() const
    {
        llm::OS::Phone::UI::Core::CoreInputScope value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->get_InputScope(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::InputScope(llm::OS::Phone::UI::Core::CoreInputScope const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->put_InputScope(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::TextChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::UI::Core::KeyboardInputBuffer, llm::OS::Phone::UI::Core::CoreTextChangedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->add_TextChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::TextChanged_revoker consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::TextChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::UI::Core::KeyboardInputBuffer, llm::OS::Phone::UI::Core::CoreTextChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TextChanged_revoker>(this, TextChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::TextChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->remove_TextChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::SelectionChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::UI::Core::KeyboardInputBuffer, llm::OS::Phone::UI::Core::CoreSelectionChangedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->add_SelectionChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::SelectionChanged_revoker consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::SelectionChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::UI::Core::KeyboardInputBuffer, llm::OS::Phone::UI::Core::CoreSelectionChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SelectionChanged_revoker>(this, SelectionChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_UI_Core_IKeyboardInputBuffer<D>::SelectionChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::UI::Core::IKeyboardInputBuffer)->remove_SelectionChanged(impl::bind_in(cookie));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::UI::Core::ICoreSelectionChangedEventArgs> : produce_base<D, llm::OS::Phone::UI::Core::ICoreSelectionChangedEventArgs>
    {
        int32_t __stdcall get_Start(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Start());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Length(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Length());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::UI::Core::ICoreTextChangedEventArgs> : produce_base<D, llm::OS::Phone::UI::Core::ICoreTextChangedEventArgs>
    {
        int32_t __stdcall get_Start(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Start());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OldLength(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().OldLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NewText());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Phone::UI::Core::ICoreWindowKeyboardInput> : produce_base<D, llm::OS::Phone::UI::Core::ICoreWindowKeyboardInput>
    {
        int32_t __stdcall get_IsKeyboardInputEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsKeyboardInputEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsKeyboardInputEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsKeyboardInputEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyboardInputBuffer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Phone::UI::Core::KeyboardInputBuffer>(this->shim().KeyboardInputBuffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_KeyboardInputBuffer(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyboardInputBuffer(*reinterpret_cast<llm::OS::Phone::UI::Core::KeyboardInputBuffer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::UI::Core::IKeyboardInputBuffer> : produce_base<D, llm::OS::Phone::UI::Core::IKeyboardInputBuffer>
    {
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Text(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectionStart(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectionStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectionLength(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectionLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Select(uint32_t start, uint32_t length) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Select(start, length);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SelectFromTap(uint32_t characterIndex) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectFromTap(characterIndex);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InputScope(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Phone::UI::Core::CoreInputScope>(this->shim().InputScope());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InputScope(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputScope(*reinterpret_cast<llm::OS::Phone::UI::Core::CoreInputScope const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_TextChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().TextChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::UI::Core::KeyboardInputBuffer, llm::OS::Phone::UI::Core::CoreTextChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TextChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_SelectionChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().SelectionChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::UI::Core::KeyboardInputBuffer, llm::OS::Phone::UI::Core::CoreSelectionChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SelectionChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Phone::UI::Core
{
    inline KeyboardInputBuffer::KeyboardInputBuffer() :
        KeyboardInputBuffer(impl::call_factory_cast<KeyboardInputBuffer(*)(llm::OS::Foundation::IActivationFactory const&), KeyboardInputBuffer>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<KeyboardInputBuffer>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Phone::UI::Core::ICoreSelectionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::UI::Core::ICoreTextChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::UI::Core::ICoreWindowKeyboardInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::UI::Core::IKeyboardInputBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::UI::Core::CoreSelectionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::UI::Core::CoreTextChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::UI::Core::KeyboardInputBuffer> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
