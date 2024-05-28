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
#ifndef LLM_OS_Media_Playlists_H
#define LLM_OS_Media_Playlists_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Media.Playlists.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Storage::StorageFile>) consume_Windows_Media_Playlists_IPlaylist<D>::Files() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playlists::IPlaylist)->get_Files(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Storage::StorageFile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Playlists_IPlaylist<D>::SaveAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playlists::IPlaylist)->SaveAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Media_Playlists_IPlaylist<D>::SaveAsAsync(llm::OS::Storage::IStorageFolder const& saveLocation, param::hstring const& desiredName, llm::OS::Storage::NameCollisionOption const& option) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playlists::IPlaylist)->SaveAsAsync(*(void**)(&saveLocation), *(void**)(&desiredName), static_cast<int32_t>(option), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Media_Playlists_IPlaylist<D>::SaveAsAsync(llm::OS::Storage::IStorageFolder const& saveLocation, param::hstring const& desiredName, llm::OS::Storage::NameCollisionOption const& option, llm::OS::Media::Playlists::PlaylistFormat const& playlistFormat) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playlists::IPlaylist)->SaveAsWithFormatAsync(*(void**)(&saveLocation), *(void**)(&desiredName), static_cast<int32_t>(option), static_cast<int32_t>(playlistFormat), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Playlists::Playlist>) consume_Windows_Media_Playlists_IPlaylistStatics<D>::LoadAsync(llm::OS::Storage::IStorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playlists::IPlaylistStatics)->LoadAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Playlists::Playlist>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playlists::IPlaylist> : produce_base<D, llm::OS::Media::Playlists::IPlaylist>
    {
        int32_t __stdcall get_Files(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Storage::StorageFile>>(this->shim().Files());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsAsync(void* saveLocation, void* desiredName, int32_t option, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().SaveAsAsync(*reinterpret_cast<llm::OS::Storage::IStorageFolder const*>(&saveLocation), *reinterpret_cast<hstring const*>(&desiredName), *reinterpret_cast<llm::OS::Storage::NameCollisionOption const*>(&option)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsWithFormatAsync(void* saveLocation, void* desiredName, int32_t option, int32_t playlistFormat, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().SaveAsAsync(*reinterpret_cast<llm::OS::Storage::IStorageFolder const*>(&saveLocation), *reinterpret_cast<hstring const*>(&desiredName), *reinterpret_cast<llm::OS::Storage::NameCollisionOption const*>(&option), *reinterpret_cast<llm::OS::Media::Playlists::PlaylistFormat const*>(&playlistFormat)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playlists::IPlaylistStatics> : produce_base<D, llm::OS::Media::Playlists::IPlaylistStatics>
    {
        int32_t __stdcall LoadAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Playlists::Playlist>>(this->shim().LoadAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Playlists
{
    inline Playlist::Playlist() :
        Playlist(impl::call_factory_cast<Playlist(*)(llm::OS::Foundation::IActivationFactory const&), Playlist>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Playlist>(); }))
    {
    }
    inline auto Playlist::LoadAsync(llm::OS::Storage::IStorageFile const& file)
    {
        return impl::call_factory<Playlist, IPlaylistStatics>([&](IPlaylistStatics const& f) { return f.LoadAsync(file); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Playlists::IPlaylist> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playlists::IPlaylistStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playlists::Playlist> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
