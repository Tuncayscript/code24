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
#ifndef LLM_OS_Media_ClosedCaptioning_H
#define LLM_OS_Media_ClosedCaptioning_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.Media.ClosedCaptioning.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionColor) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::FontColor() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionColor value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_FontColor(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::ComputedFontColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_ComputedFontColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::FontOpacity() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_FontOpacity(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionSize) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::FontSize() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionSize value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_FontSize(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionStyle) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::FontStyle() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionStyle value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_FontStyle(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionEdgeEffect) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::FontEffect() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionEdgeEffect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_FontEffect(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionColor) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::BackgroundColor() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionColor value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_BackgroundColor(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::ComputedBackgroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_ComputedBackgroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::BackgroundOpacity() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_BackgroundOpacity(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionColor) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::RegionColor() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionColor value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_RegionColor(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::ComputedRegionColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_ComputedRegionColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>::RegionOpacity() const
    {
        llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics)->get_RegionOpacity(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics2<D>::PropertiesChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2)->add_PropertiesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics2<D>::PropertiesChanged_revoker consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics2<D>::PropertiesChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, PropertiesChanged_revoker>(this, PropertiesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics2<D>::PropertiesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2)->remove_PropertiesChanged(impl::bind_in(token));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics> : produce_base<D, llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics>
    {
        int32_t __stdcall get_FontColor(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionColor>(this->shim().FontColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ComputedFontColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().ComputedFontColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FontOpacity(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity>(this->shim().FontOpacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FontSize(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionSize>(this->shim().FontSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FontStyle(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionStyle>(this->shim().FontStyle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FontEffect(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionEdgeEffect>(this->shim().FontEffect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionColor>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ComputedBackgroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().ComputedBackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundOpacity(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity>(this->shim().BackgroundOpacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegionColor(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionColor>(this->shim().RegionColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ComputedRegionColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().ComputedRegionColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegionOpacity(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity>(this->shim().RegionOpacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2> : produce_base<D, llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>
    {
        int32_t __stdcall add_PropertiesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PropertiesChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PropertiesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::ClosedCaptioning
{
    inline auto ClosedCaptionProperties::FontColor()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionColor(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.FontColor(); });
    }
    inline auto ClosedCaptionProperties::ComputedFontColor()
    {
        return impl::call_factory_cast<llm::OS::UI::Color(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.ComputedFontColor(); });
    }
    inline auto ClosedCaptionProperties::FontOpacity()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.FontOpacity(); });
    }
    inline auto ClosedCaptionProperties::FontSize()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionSize(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.FontSize(); });
    }
    inline auto ClosedCaptionProperties::FontStyle()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionStyle(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.FontStyle(); });
    }
    inline auto ClosedCaptionProperties::FontEffect()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionEdgeEffect(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.FontEffect(); });
    }
    inline auto ClosedCaptionProperties::BackgroundColor()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionColor(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.BackgroundColor(); });
    }
    inline auto ClosedCaptionProperties::ComputedBackgroundColor()
    {
        return impl::call_factory_cast<llm::OS::UI::Color(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.ComputedBackgroundColor(); });
    }
    inline auto ClosedCaptionProperties::BackgroundOpacity()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.BackgroundOpacity(); });
    }
    inline auto ClosedCaptionProperties::RegionColor()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionColor(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.RegionColor(); });
    }
    inline auto ClosedCaptionProperties::ComputedRegionColor()
    {
        return impl::call_factory_cast<llm::OS::UI::Color(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.ComputedRegionColor(); });
    }
    inline auto ClosedCaptionProperties::RegionOpacity()
    {
        return impl::call_factory_cast<llm::OS::Media::ClosedCaptioning::ClosedCaptionOpacity(*)(IClosedCaptionPropertiesStatics const&), ClosedCaptionProperties, IClosedCaptionPropertiesStatics>([](IClosedCaptionPropertiesStatics const& f) { return f.RegionOpacity(); });
    }
    inline auto ClosedCaptionProperties::PropertiesChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics2>([&](IClosedCaptionPropertiesStatics2 const& f) { return f.PropertiesChanged(handler); });
    }
    inline ClosedCaptionProperties::PropertiesChanged_revoker ClosedCaptionProperties::PropertiesChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<ClosedCaptionProperties, llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>();
        return { f, f.PropertiesChanged(handler) };
    }
    inline auto ClosedCaptionProperties::PropertiesChanged(llm::event_token const& token)
    {
        impl::call_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics2>([&](IClosedCaptionPropertiesStatics2 const& f) { return f.PropertiesChanged(token); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ClosedCaptioning::ClosedCaptionProperties> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
