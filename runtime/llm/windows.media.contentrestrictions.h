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
#ifndef LLM_OS_Media_ContentRestrictions_H
#define LLM_OS_Media_ContentRestrictions_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Media.ContentRestrictions.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_ContentRestrictions_IContentRestrictionsBrowsePolicy<D>::GeographicRegion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy)->get_GeographicRegion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_ContentRestrictions_IContentRestrictionsBrowsePolicy<D>::MaxBrowsableAgeRating() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy)->get_MaxBrowsableAgeRating(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_ContentRestrictions_IContentRestrictionsBrowsePolicy<D>::PreferredAgeRating() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy)->get_PreferredAgeRating(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Id(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->put_Id(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Image() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->get_Image(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Image(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->put_Image(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ContentRestrictions::RatedContentCategory) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Category() const
    {
        llm::OS::Media::ContentRestrictions::RatedContentCategory value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->get_Category(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Category(llm::OS::Media::ContentRestrictions::RatedContentCategory const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->put_Category(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Ratings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->get_Ratings(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>::Ratings(param::vector<hstring> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescription)->put_Ratings(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ContentRestrictions::RatedContentDescription) consume_Windows_Media_ContentRestrictions_IRatedContentDescriptionFactory<D>::Create(param::hstring const& id, param::hstring const& title, llm::OS::Media::ContentRestrictions::RatedContentCategory const& category) const
    {
        void* RatedContentDescription{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentDescriptionFactory)->Create(*(void**)(&id), *(void**)(&title), static_cast<int32_t>(category), &RatedContentDescription));
        return llm::OS::Media::ContentRestrictions::RatedContentDescription{ RatedContentDescription, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy>) consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>::GetBrowsePolicyAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentRestrictions)->GetBrowsePolicyAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::ContentRestrictions::ContentAccessRestrictionLevel>) consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>::GetRestrictionLevelAsync(llm::OS::Media::ContentRestrictions::RatedContentDescription const& RatedContentDescription) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentRestrictions)->GetRestrictionLevelAsync(*(void**)(&RatedContentDescription), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::ContentRestrictions::ContentAccessRestrictionLevel>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>::RequestContentAccessAsync(llm::OS::Media::ContentRestrictions::RatedContentDescription const& RatedContentDescription) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentRestrictions)->RequestContentAccessAsync(*(void**)(&RatedContentDescription), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>::RestrictionsChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentRestrictions)->add_RestrictionsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>::RestrictionsChanged_revoker consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>::RestrictionsChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, RestrictionsChanged_revoker>(this, RestrictionsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>::RestrictionsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentRestrictions)->remove_RestrictionsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::ContentRestrictions::RatedContentRestrictions) consume_Windows_Media_ContentRestrictions_IRatedContentRestrictionsFactory<D>::CreateWithMaxAgeRating(uint32_t maxAgeRating) const
    {
        void* ratedContentRestrictions{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory)->CreateWithMaxAgeRating(maxAgeRating, &ratedContentRestrictions));
        return llm::OS::Media::ContentRestrictions::RatedContentRestrictions{ ratedContentRestrictions, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy> : produce_base<D, llm::OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>
    {
        int32_t __stdcall get_GeographicRegion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GeographicRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxBrowsableAgeRating(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().MaxBrowsableAgeRating());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredAgeRating(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().PreferredAgeRating());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::ContentRestrictions::IRatedContentDescription> : produce_base<D, llm::OS::Media::ContentRestrictions::IRatedContentDescription>
    {
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
        int32_t __stdcall get_Image(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().Image());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Image(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Image(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Category(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::ContentRestrictions::RatedContentCategory>(this->shim().Category());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Category(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Category(*reinterpret_cast<llm::OS::Media::ContentRestrictions::RatedContentCategory const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Ratings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Ratings());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Ratings(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ratings(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<hstring> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::ContentRestrictions::IRatedContentDescriptionFactory> : produce_base<D, llm::OS::Media::ContentRestrictions::IRatedContentDescriptionFactory>
    {
        int32_t __stdcall Create(void* id, void* title, int32_t category, void** RatedContentDescription) noexcept final try
        {
            clear_abi(RatedContentDescription);
            typename D::abi_guard guard(this->shim());
            *RatedContentDescription = detach_from<llm::OS::Media::ContentRestrictions::RatedContentDescription>(this->shim().Create(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<hstring const*>(&title), *reinterpret_cast<llm::OS::Media::ContentRestrictions::RatedContentCategory const*>(&category)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::ContentRestrictions::IRatedContentRestrictions> : produce_base<D, llm::OS::Media::ContentRestrictions::IRatedContentRestrictions>
    {
        int32_t __stdcall GetBrowsePolicyAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy>>(this->shim().GetBrowsePolicyAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRestrictionLevelAsync(void* RatedContentDescription, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::ContentRestrictions::ContentAccessRestrictionLevel>>(this->shim().GetRestrictionLevelAsync(*reinterpret_cast<llm::OS::Media::ContentRestrictions::RatedContentDescription const*>(&RatedContentDescription)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestContentAccessAsync(void* RatedContentDescription, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestContentAccessAsync(*reinterpret_cast<llm::OS::Media::ContentRestrictions::RatedContentDescription const*>(&RatedContentDescription)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RestrictionsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RestrictionsChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RestrictionsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RestrictionsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory> : produce_base<D, llm::OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory>
    {
        int32_t __stdcall CreateWithMaxAgeRating(uint32_t maxAgeRating, void** ratedContentRestrictions) noexcept final try
        {
            clear_abi(ratedContentRestrictions);
            typename D::abi_guard guard(this->shim());
            *ratedContentRestrictions = detach_from<llm::OS::Media::ContentRestrictions::RatedContentRestrictions>(this->shim().CreateWithMaxAgeRating(maxAgeRating));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::ContentRestrictions
{
    inline RatedContentDescription::RatedContentDescription(param::hstring const& id, param::hstring const& title, llm::OS::Media::ContentRestrictions::RatedContentCategory const& category) :
        RatedContentDescription(impl::call_factory<RatedContentDescription, IRatedContentDescriptionFactory>([&](IRatedContentDescriptionFactory const& f) { return f.Create(id, title, category); }))
    {
    }
    inline RatedContentRestrictions::RatedContentRestrictions() :
        RatedContentRestrictions(impl::call_factory_cast<RatedContentRestrictions(*)(llm::OS::Foundation::IActivationFactory const&), RatedContentRestrictions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<RatedContentRestrictions>(); }))
    {
    }
    inline RatedContentRestrictions::RatedContentRestrictions(uint32_t maxAgeRating) :
        RatedContentRestrictions(impl::call_factory<RatedContentRestrictions, IRatedContentRestrictionsFactory>([&](IRatedContentRestrictionsFactory const& f) { return f.CreateWithMaxAgeRating(maxAgeRating); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ContentRestrictions::IRatedContentDescription> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ContentRestrictions::IRatedContentDescriptionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ContentRestrictions::IRatedContentRestrictions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ContentRestrictions::RatedContentDescription> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::ContentRestrictions::RatedContentRestrictions> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
