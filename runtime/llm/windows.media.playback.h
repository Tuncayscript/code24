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
#ifndef LLM_OS_Media_Playback_H
#define LLM_OS_Media_Playback_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Media.2.h"
#include "llm/impl/Windows.Media.Audio.2.h"
#include "llm/impl/Windows.Media.Casting.2.h"
#include "llm/impl/Windows.Media.Core.2.h"
#include "llm/impl/Windows.Media.MediaProperties.2.h"
#include "llm/impl/Windows.Media.Protection.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.Media.Playback.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayer) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::Current() const
    {
        void* player{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->get_Current(&player));
        return llm::OS::Media::Playback::MediaPlayer{ player, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromBackground(llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->add_MessageReceivedFromBackground(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromBackground_revoker consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromBackground(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value) const
    {
        return impl::make_event_revoker<D, MessageReceivedFromBackground_revoker>(this, MessageReceivedFromBackground(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromBackground(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->remove_MessageReceivedFromBackground(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromForeground(llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->add_MessageReceivedFromForeground(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromForeground_revoker consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromForeground(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value) const
    {
        return impl::make_event_revoker<D, MessageReceivedFromForeground_revoker>(this, MessageReceivedFromForeground(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromForeground(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->remove_MessageReceivedFromForeground(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::SendMessageToBackground(llm::OS::Foundation::Collections::ValueSet const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->SendMessageToBackground(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::SendMessageToForeground(llm::OS::Foundation::Collections::ValueSet const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->SendMessageToForeground(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::IsMediaPlaying() const
    {
        bool isMediaPlaying{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->IsMediaPlaying(&isMediaPlaying));
        return isMediaPlaying;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IBackgroundMediaPlayerStatics<D>::Shutdown() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IBackgroundMediaPlayerStatics)->Shutdown());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_ICurrentMediaPlaybackItemChangedEventArgs<D>::NewItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs)->get_NewItem(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_ICurrentMediaPlaybackItemChangedEventArgs<D>::OldItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs)->get_OldItem(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItemChangedReason) consume_Windows_Media_Playback_ICurrentMediaPlaybackItemChangedEventArgs2<D>::Reason() const
    {
        llm::OS::Media::Playback::MediaPlaybackItemChangedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs2)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackList) consume_Windows_Media_Playback_IMediaBreak<D>::PlaybackList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreak)->get_PlaybackList(&value));
        return llm::OS::Media::Playback::MediaPlaybackList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Playback_IMediaBreak<D>::PresentationPosition() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreak)->get_PresentationPosition(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreakInsertionMethod) consume_Windows_Media_Playback_IMediaBreak<D>::InsertionMethod() const
    {
        llm::OS::Media::Playback::MediaBreakInsertionMethod value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreak)->get_InsertionMethod(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Media_Playback_IMediaBreak<D>::CustomProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreak)->get_CustomProperties(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaBreak<D>::CanStart() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreak)->get_CanStart(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreak<D>::CanStart(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreak)->put_CanStart(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakEndedEventArgs<D>::MediaBreak() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakEndedEventArgs)->get_MediaBreak(&value));
        return llm::OS::Media::Playback::MediaBreak{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakFactory<D>::Create(llm::OS::Media::Playback::MediaBreakInsertionMethod const& insertionMethod) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakFactory)->Create(static_cast<int32_t>(insertionMethod), &result));
        return llm::OS::Media::Playback::MediaBreak{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakFactory<D>::CreateWithPresentationPosition(llm::OS::Media::Playback::MediaBreakInsertionMethod const& insertionMethod, llm::OS::Foundation::TimeSpan const& presentationPosition) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakFactory)->CreateWithPresentationPosition(static_cast<int32_t>(insertionMethod), impl::bind_in(presentationPosition), &result));
        return llm::OS::Media::Playback::MediaBreak{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreaksSeekedOver(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakSeekedOverEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->add_BreaksSeekedOver(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaBreakManager<D>::BreaksSeekedOver_revoker consume_Windows_Media_Playback_IMediaBreakManager<D>::BreaksSeekedOver(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakSeekedOverEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, BreaksSeekedOver_revoker>(this, BreaksSeekedOver(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreaksSeekedOver(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->remove_BreaksSeekedOver(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakStarted(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakStartedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->add_BreakStarted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakStarted_revoker consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakStarted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakStartedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, BreakStarted_revoker>(this, BreakStarted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakStarted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->remove_BreakStarted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakEnded(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakEndedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->add_BreakEnded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakEnded_revoker consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakEnded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakEndedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, BreakEnded_revoker>(this, BreakEnded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakEnded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->remove_BreakEnded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakSkipped(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakSkippedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->add_BreakSkipped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakSkipped_revoker consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakSkipped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakSkippedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, BreakSkipped_revoker>(this, BreakSkipped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakManager<D>::BreakSkipped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->remove_BreakSkipped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakManager<D>::CurrentBreak() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->get_CurrentBreak(&value));
        return llm::OS::Media::Playback::MediaBreak{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackSession) consume_Windows_Media_Playback_IMediaBreakManager<D>::PlaybackSession() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->get_PlaybackSession(&value));
        return llm::OS::Media::Playback::MediaPlaybackSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakManager<D>::PlayBreak(llm::OS::Media::Playback::MediaBreak const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->PlayBreak(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakManager<D>::SkipCurrentBreak() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakManager)->SkipCurrentBreak());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::ScheduleChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakSchedule, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->add_ScheduleChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaBreakSchedule<D>::ScheduleChanged_revoker consume_Windows_Media_Playback_IMediaBreakSchedule<D>::ScheduleChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakSchedule, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ScheduleChanged_revoker>(this, ScheduleChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::ScheduleChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->remove_ScheduleChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::InsertMidrollBreak(llm::OS::Media::Playback::MediaBreak const& mediaBreak) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->InsertMidrollBreak(*(void**)(&mediaBreak)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::RemoveMidrollBreak(llm::OS::Media::Playback::MediaBreak const& mediaBreak) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->RemoveMidrollBreak(*(void**)(&mediaBreak)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaBreak>) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::MidrollBreaks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->get_MidrollBreaks(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaBreak>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::PrerollBreak(llm::OS::Media::Playback::MediaBreak const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->put_PrerollBreak(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::PrerollBreak() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->get_PrerollBreak(&value));
        return llm::OS::Media::Playback::MediaBreak{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::PostrollBreak(llm::OS::Media::Playback::MediaBreak const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->put_PostrollBreak(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::PostrollBreak() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->get_PostrollBreak(&value));
        return llm::OS::Media::Playback::MediaBreak{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaBreakSchedule<D>::PlaybackItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSchedule)->get_PlaybackItem(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaBreak>) consume_Windows_Media_Playback_IMediaBreakSeekedOverEventArgs<D>::SeekedOverBreaks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSeekedOverEventArgs)->get_SeekedOverBreaks(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaBreak>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaBreakSeekedOverEventArgs<D>::OldPosition() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSeekedOverEventArgs)->get_OldPosition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaBreakSeekedOverEventArgs<D>::NewPosition() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSeekedOverEventArgs)->get_NewPosition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakSkippedEventArgs<D>::MediaBreak() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakSkippedEventArgs)->get_MediaBreak(&value));
        return llm::OS::Media::Playback::MediaBreak{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreak) consume_Windows_Media_Playback_IMediaBreakStartedEventArgs<D>::MediaBreak() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaBreakStartedEventArgs)->get_MediaBreak(&value));
        return llm::OS::Media::Playback::MediaBreak{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaEnginePlaybackSource<D>::CurrentItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaEnginePlaybackSource)->get_CurrentItem(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaEnginePlaybackSource<D>::SetPlaybackSource(llm::OS::Media::Playback::IMediaPlaybackSource const& source) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaEnginePlaybackSource)->SetPlaybackSource(*(void**)(&source)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaPlaybackType) consume_Windows_Media_Playback_IMediaItemDisplayProperties<D>::Type() const
    {
        llm::OS::Media::MediaPlaybackType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaItemDisplayProperties)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaItemDisplayProperties<D>::Type(llm::OS::Media::MediaPlaybackType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaItemDisplayProperties)->put_Type(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MusicDisplayProperties) consume_Windows_Media_Playback_IMediaItemDisplayProperties<D>::MusicProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaItemDisplayProperties)->get_MusicProperties(&value));
        return llm::OS::Media::MusicDisplayProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoDisplayProperties) consume_Windows_Media_Playback_IMediaItemDisplayProperties<D>::VideoProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaItemDisplayProperties)->get_VideoProperties(&value));
        return llm::OS::Media::VideoDisplayProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) consume_Windows_Media_Playback_IMediaItemDisplayProperties<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaItemDisplayProperties)->get_Thumbnail(&value));
        return llm::OS::Storage::Streams::RandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaItemDisplayProperties<D>::Thumbnail(llm::OS::Storage::Streams::RandomAccessStreamReference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaItemDisplayProperties)->put_Thumbnail(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaItemDisplayProperties<D>::ClearAll() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaItemDisplayProperties)->ClearAll());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayer) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::MediaPlayer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_MediaPlayer(&value));
        return llm::OS::Media::Playback::MediaPlayer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PlayBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_PlayBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PauseBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_PauseBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::NextBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_NextBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PreviousBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_PreviousBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::FastForwardBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_FastForwardBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RewindBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_RewindBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::ShuffleBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_ShuffleBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::AutoRepeatModeBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_AutoRepeatModeBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PositionBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_PositionBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RateBehavior() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->get_RateBehavior(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PlayReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_PlayReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PlayReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PlayReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PlayReceived_revoker>(this, PlayReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PlayReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_PlayReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PauseReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_PauseReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PauseReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PauseReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PauseReceived_revoker>(this, PauseReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PauseReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_PauseReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::NextReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_NextReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::NextReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::NextReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, NextReceived_revoker>(this, NextReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::NextReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_NextReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PreviousReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_PreviousReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PreviousReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PreviousReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PreviousReceived_revoker>(this, PreviousReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PreviousReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_PreviousReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::FastForwardReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_FastForwardReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::FastForwardReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::FastForwardReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FastForwardReceived_revoker>(this, FastForwardReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::FastForwardReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_FastForwardReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RewindReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_RewindReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RewindReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RewindReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RewindReceived_revoker>(this, RewindReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RewindReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_RewindReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::ShuffleReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_ShuffleReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::ShuffleReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::ShuffleReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ShuffleReceived_revoker>(this, ShuffleReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::ShuffleReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_ShuffleReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::AutoRepeatModeReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_AutoRepeatModeReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::AutoRepeatModeReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::AutoRepeatModeReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AutoRepeatModeReceived_revoker>(this, AutoRepeatModeReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::AutoRepeatModeReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_AutoRepeatModeReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PositionReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_PositionReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PositionReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PositionReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PositionReceived_revoker>(this, PositionReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::PositionReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_PositionReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RateReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->add_RateReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RateReceived_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RateReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RateReceived_revoker>(this, RateReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManager<D>::RateReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManager)->remove_RateReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaPlaybackAutoRepeatMode) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::AutoRepeatMode() const
    {
        llm::OS::Media::MediaPlaybackAutoRepeatMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->get_AutoRepeatMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManager) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::CommandManager() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior)->get_CommandManager(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaCommandEnablingRule) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::EnablingRule() const
    {
        llm::OS::Media::Playback::MediaCommandEnablingRule value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior)->get_EnablingRule(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::EnablingRule(llm::OS::Media::Playback::MediaCommandEnablingRule const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior)->put_EnablingRule(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabledChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior)->add_IsEnabledChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabledChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabledChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsEnabledChanged_revoker>(this, IsEnabledChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabledChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior)->remove_IsEnabledChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerNextReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerNextReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerNextReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPauseReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPauseReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPauseReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPlayReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPlayReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPlayReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::Position() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPreviousReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPreviousReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerPreviousReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::PlaybackRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs)->get_PlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerRewindReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerRewindReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerRewindReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::IsShuffleRequested() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->get_IsShuffleRequested(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Media_Playback_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::AudioTracksChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->add_AudioTracksChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackItem<D>::AudioTracksChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackItem<D>::AudioTracksChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AudioTracksChanged_revoker>(this, AudioTracksChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::AudioTracksChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->remove_AudioTracksChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::VideoTracksChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->add_VideoTracksChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackItem<D>::VideoTracksChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackItem<D>::VideoTracksChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, VideoTracksChanged_revoker>(this, VideoTracksChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::VideoTracksChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->remove_VideoTracksChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::TimedMetadataTracksChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->add_TimedMetadataTracksChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackItem<D>::TimedMetadataTracksChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackItem<D>::TimedMetadataTracksChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TimedMetadataTracksChanged_revoker>(this, TimedMetadataTracksChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::TimedMetadataTracksChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->remove_TimedMetadataTracksChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Core::MediaSource) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->get_Source(&value));
        return llm::OS::Media::Core::MediaSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackAudioTrackList) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::AudioTracks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->get_AudioTracks(&value));
        return llm::OS::Media::Playback::MediaPlaybackAudioTrackList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackVideoTrackList) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::VideoTracks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->get_VideoTracks(&value));
        return llm::OS::Media::Playback::MediaPlaybackVideoTrackList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackTimedMetadataTrackList) consume_Windows_Media_Playback_IMediaPlaybackItem<D>::TimedMetadataTracks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem)->get_TimedMetadataTracks(&value));
        return llm::OS::Media::Playback::MediaPlaybackTimedMetadataTrackList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreakSchedule) consume_Windows_Media_Playback_IMediaPlaybackItem2<D>::BreakSchedule() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem2)->get_BreakSchedule(&value));
        return llm::OS::Media::Playback::MediaBreakSchedule{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaPlaybackItem2<D>::StartTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem2)->get_StartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Playback_IMediaPlaybackItem2<D>::DurationLimit() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem2)->get_DurationLimit(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackItem2<D>::CanSkip() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem2)->get_CanSkip(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackItem2<D>::CanSkip(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem2)->put_CanSkip(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaItemDisplayProperties) consume_Windows_Media_Playback_IMediaPlaybackItem2<D>::GetDisplayProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem2)->GetDisplayProperties(&value));
        return llm::OS::Media::Playback::MediaItemDisplayProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackItem2<D>::ApplyDisplayProperties(llm::OS::Media::Playback::MediaItemDisplayProperties const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem2)->ApplyDisplayProperties(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackItem3<D>::IsDisabledInPlaybackList() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem3)->get_IsDisabledInPlaybackList(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackItem3<D>::IsDisabledInPlaybackList(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem3)->put_IsDisabledInPlaybackList(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlaybackItem3<D>::TotalDownloadProgress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem3)->get_TotalDownloadProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::AutoLoadedDisplayPropertyKind) consume_Windows_Media_Playback_IMediaPlaybackItem3<D>::AutoLoadedDisplayProperties() const
    {
        llm::OS::Media::Playback::AutoLoadedDisplayPropertyKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem3)->get_AutoLoadedDisplayProperties(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackItem3<D>::AutoLoadedDisplayProperties(llm::OS::Media::Playback::AutoLoadedDisplayPropertyKind const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItem3)->put_AutoLoadedDisplayProperties(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItemErrorCode) consume_Windows_Media_Playback_IMediaPlaybackItemError<D>::ErrorCode() const
    {
        llm::OS::Media::Playback::MediaPlaybackItemErrorCode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemError)->get_ErrorCode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Media_Playback_IMediaPlaybackItemError<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemError)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackItemFactory<D>::Create(llm::OS::Media::Core::MediaSource const& source) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemFactory)->Create(*(void**)(&source), &value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackItemFactory2<D>::CreateWithStartTime(llm::OS::Media::Core::MediaSource const& source, llm::OS::Foundation::TimeSpan const& startTime) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemFactory2)->CreateWithStartTime(*(void**)(&source), impl::bind_in(startTime), &result));
        return llm::OS::Media::Playback::MediaPlaybackItem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackItemFactory2<D>::CreateWithStartTimeAndDurationLimit(llm::OS::Media::Core::MediaSource const& source, llm::OS::Foundation::TimeSpan const& startTime, llm::OS::Foundation::TimeSpan const& durationLimit) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemFactory2)->CreateWithStartTimeAndDurationLimit(*(void**)(&source), impl::bind_in(startTime), impl::bind_in(durationLimit), &result));
        return llm::OS::Media::Playback::MediaPlaybackItem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackItemFailedEventArgs<D>::Item() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemFailedEventArgs)->get_Item(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItemError) consume_Windows_Media_Playback_IMediaPlaybackItemFailedEventArgs<D>::Error() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemFailedEventArgs)->get_Error(&value));
        return llm::OS::Media::Playback::MediaPlaybackItemError{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackItemOpenedEventArgs<D>::Item() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemOpenedEventArgs)->get_Item(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackItemStatics<D>::FindFromMediaSource(llm::OS::Media::Core::MediaSource const& source) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackItemStatics)->FindFromMediaSource(*(void**)(&source), &value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemFailed(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::MediaPlaybackItemFailedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->add_ItemFailed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemFailed_revoker consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemFailed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::MediaPlaybackItemFailedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ItemFailed_revoker>(this, ItemFailed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemFailed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->remove_ItemFailed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackList<D>::CurrentItemChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->add_CurrentItemChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackList<D>::CurrentItemChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackList<D>::CurrentItemChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CurrentItemChanged_revoker>(this, CurrentItemChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList<D>::CurrentItemChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->remove_CurrentItemChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemOpened(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::MediaPlaybackItemOpenedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->add_ItemOpened(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemOpened_revoker consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemOpened(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::MediaPlaybackItemOpenedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ItemOpened_revoker>(this, ItemOpened(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList<D>::ItemOpened(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->remove_ItemOpened(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IObservableVector<llm::OS::Media::Playback::MediaPlaybackItem>) consume_Windows_Media_Playback_IMediaPlaybackList<D>::Items() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->get_Items(&value));
        return llm::OS::Foundation::Collections::IObservableVector<llm::OS::Media::Playback::MediaPlaybackItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackList<D>::AutoRepeatEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->get_AutoRepeatEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList<D>::AutoRepeatEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->put_AutoRepeatEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackList<D>::ShuffleEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->get_ShuffleEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList<D>::ShuffleEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->put_ShuffleEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackList<D>::CurrentItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->get_CurrentItem(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Playback_IMediaPlaybackList<D>::CurrentItemIndex() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->get_CurrentItemIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackList<D>::MoveNext() const
    {
        void* item{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->MoveNext(&item));
        return llm::OS::Media::Playback::MediaPlaybackItem{ item, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackList<D>::MovePrevious() const
    {
        void* item{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->MovePrevious(&item));
        return llm::OS::Media::Playback::MediaPlaybackItem{ item, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackList<D>::MoveTo(uint32_t itemIndex) const
    {
        void* item{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList)->MoveTo(itemIndex, &item));
        return llm::OS::Media::Playback::MediaPlaybackItem{ item, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Playback_IMediaPlaybackList2<D>::MaxPrefetchTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList2)->get_MaxPrefetchTime(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList2<D>::MaxPrefetchTime(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList2)->put_MaxPrefetchTime(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackItem) consume_Windows_Media_Playback_IMediaPlaybackList2<D>::StartingItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList2)->get_StartingItem(&value));
        return llm::OS::Media::Playback::MediaPlaybackItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList2<D>::StartingItem(llm::OS::Media::Playback::MediaPlaybackItem const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList2)->put_StartingItem(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaPlaybackItem>) consume_Windows_Media_Playback_IMediaPlaybackList2<D>::ShuffledItems() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList2)->get_ShuffledItems(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaPlaybackItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList2<D>::SetShuffledItems(param::iterable<llm::OS::Media::Playback::MediaPlaybackItem> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList2)->SetShuffledItems(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Playback_IMediaPlaybackList3<D>::MaxPlayedItemsToKeepOpen() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList3)->get_MaxPlayedItemsToKeepOpen(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackList3<D>::MaxPlayedItemsToKeepOpen(llm::OS::Foundation::IReference<uint32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackList3)->put_MaxPlayedItemsToKeepOpen(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_PlaybackStateChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackStateChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, PlaybackStateChanged_revoker>(this, PlaybackStateChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_PlaybackStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackRateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_PlaybackRateChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackRateChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackRateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, PlaybackRateChanged_revoker>(this, PlaybackRateChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackRateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_PlaybackRateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::SeekCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_SeekCompleted(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::SeekCompleted_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::SeekCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, SeekCompleted_revoker>(this, SeekCompleted(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::SeekCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_SeekCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingStarted(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_BufferingStarted(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingStarted_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingStarted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, BufferingStarted_revoker>(this, BufferingStarted(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingStarted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_BufferingStarted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingEnded(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_BufferingEnded(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingEnded_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingEnded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, BufferingEnded_revoker>(this, BufferingEnded(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingEnded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_BufferingEnded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingProgressChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_BufferingProgressChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingProgressChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingProgressChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, BufferingProgressChanged_revoker>(this, BufferingProgressChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingProgressChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_BufferingProgressChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::DownloadProgressChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_DownloadProgressChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::DownloadProgressChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::DownloadProgressChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, DownloadProgressChanged_revoker>(this, DownloadProgressChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::DownloadProgressChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_DownloadProgressChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalDurationChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_NaturalDurationChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalDurationChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalDurationChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, NaturalDurationChanged_revoker>(this, NaturalDurationChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalDurationChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_NaturalDurationChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PositionChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_PositionChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PositionChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PositionChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, PositionChanged_revoker>(this, PositionChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PositionChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_PositionChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalVideoSizeChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->add_NaturalVideoSizeChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalVideoSizeChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalVideoSizeChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, NaturalVideoSizeChanged_revoker>(this, NaturalVideoSizeChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalVideoSizeChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->remove_NaturalVideoSizeChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayer) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::MediaPlayer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_MediaPlayer(&value));
        return llm::OS::Media::Playback::MediaPlayer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_NaturalDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::Position() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::Position(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->put_Position(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackState) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackState() const
    {
        llm::OS::Media::Playback::MediaPlaybackState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_PlaybackState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::CanSeek() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_CanSeek(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::CanPause() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_CanPause(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::IsProtected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_IsProtected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_PlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::PlaybackRate(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->put_PlaybackRate(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::BufferingProgress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_BufferingProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::DownloadProgress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_DownloadProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalVideoHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_NaturalVideoHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NaturalVideoWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_NaturalVideoWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NormalizedSourceRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_NormalizedSourceRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::NormalizedSourceRect(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->put_NormalizedSourceRect(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::StereoscopicVideoPackingMode) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::StereoscopicVideoPackingMode() const
    {
        llm::OS::Media::MediaProperties::StereoscopicVideoPackingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->get_StereoscopicVideoPackingMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession<D>::StereoscopicVideoPackingMode(llm::OS::Media::MediaProperties::StereoscopicVideoPackingMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession)->put_StereoscopicVideoPackingMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::BufferedRangesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->add_BufferedRangesChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::BufferedRangesChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::BufferedRangesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, BufferedRangesChanged_revoker>(this, BufferedRangesChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::BufferedRangesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->remove_BufferedRangesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::PlayedRangesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->add_PlayedRangesChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::PlayedRangesChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::PlayedRangesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, PlayedRangesChanged_revoker>(this, PlayedRangesChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::PlayedRangesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->remove_PlayedRangesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SeekableRangesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->add_SeekableRangesChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SeekableRangesChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SeekableRangesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, SeekableRangesChanged_revoker>(this, SeekableRangesChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SeekableRangesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->remove_SeekableRangesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SupportedPlaybackRatesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->add_SupportedPlaybackRatesChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SupportedPlaybackRatesChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SupportedPlaybackRatesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, SupportedPlaybackRatesChanged_revoker>(this, SupportedPlaybackRatesChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SupportedPlaybackRatesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->remove_SupportedPlaybackRatesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackSphericalVideoProjection) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::SphericalVideoProjection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->get_SphericalVideoProjection(&value));
        return llm::OS::Media::Playback::MediaPlaybackSphericalVideoProjection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::IsMirroring() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->get_IsMirroring(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::IsMirroring(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->put_IsMirroring(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::GetBufferedRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->GetBufferedRanges(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::GetPlayedRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->GetPlayedRanges(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::GetSeekableRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->GetSeekableRanges(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackSession2<D>::IsSupportedPlaybackRateRange(double rate1, double rate2) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession2)->IsSupportedPlaybackRateRange(rate1, rate2, &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::MediaRotation) consume_Windows_Media_Playback_IMediaPlaybackSession3<D>::PlaybackRotation() const
    {
        llm::OS::Media::MediaProperties::MediaRotation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession3)->get_PlaybackRotation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSession3<D>::PlaybackRotation(llm::OS::Media::MediaProperties::MediaRotation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession3)->put_PlaybackRotation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackSessionOutputDegradationPolicyState) consume_Windows_Media_Playback_IMediaPlaybackSession3<D>::GetOutputDegradationPolicyState() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSession3)->GetOutputDegradationPolicyState(&value));
        return llm::OS::Media::Playback::MediaPlaybackSessionOutputDegradationPolicyState{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackSessionBufferingStartedEventArgs<D>::IsPlaybackInterruption() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSessionBufferingStartedEventArgs)->get_IsPlaybackInterruption(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackSessionVideoConstrictionReason) consume_Windows_Media_Playback_IMediaPlaybackSessionOutputDegradationPolicyState<D>::VideoConstrictionReason() const
    {
        llm::OS::Media::Playback::MediaPlaybackSessionVideoConstrictionReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSessionOutputDegradationPolicyState)->get_VideoConstrictionReason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::SphericalVideoFrameFormat) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::FrameFormat() const
    {
        llm::OS::Media::MediaProperties::SphericalVideoFrameFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->get_FrameFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::FrameFormat(llm::OS::Media::MediaProperties::SphericalVideoFrameFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->put_FrameFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::HorizontalFieldOfViewInDegrees() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->get_HorizontalFieldOfViewInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::HorizontalFieldOfViewInDegrees(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->put_HorizontalFieldOfViewInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::ViewOrientation() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->get_ViewOrientation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::ViewOrientation(llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->put_ViewOrientation(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::SphericalVideoProjectionMode) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::ProjectionMode() const
    {
        llm::OS::Media::Playback::SphericalVideoProjectionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->get_ProjectionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackSphericalVideoProjection<D>::ProjectionMode(llm::OS::Media::Playback::SphericalVideoProjectionMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection)->put_ProjectionMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlaybackTimedMetadataTrackList<D>::PresentationModeChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackTimedMetadataTrackList, llm::OS::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList)->add_PresentationModeChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlaybackTimedMetadataTrackList<D>::PresentationModeChanged_revoker consume_Windows_Media_Playback_IMediaPlaybackTimedMetadataTrackList<D>::PresentationModeChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackTimedMetadataTrackList, llm::OS::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PresentationModeChanged_revoker>(this, PresentationModeChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackTimedMetadataTrackList<D>::PresentationModeChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList)->remove_PresentationModeChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::TimedMetadataTrackPresentationMode) consume_Windows_Media_Playback_IMediaPlaybackTimedMetadataTrackList<D>::GetPresentationMode(uint32_t index) const
    {
        llm::OS::Media::Playback::TimedMetadataTrackPresentationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList)->GetPresentationMode(index, reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlaybackTimedMetadataTrackList<D>::SetPresentationMode(uint32_t index, llm::OS::Media::Playback::TimedMetadataTrackPresentationMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList)->SetPresentationMode(index, static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer<D>::AutoPlay() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_AutoPlay(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::AutoPlay(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->put_AutoPlay(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaPlayer<D>::NaturalDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_NaturalDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaPlayer<D>::Position() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::Position(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->put_Position(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingProgress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_BufferingProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayerState) consume_Windows_Media_Playback_IMediaPlayer<D>::CurrentState() const
    {
        llm::OS::Media::Playback::MediaPlayerState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_CurrentState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer<D>::CanSeek() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_CanSeek(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer<D>::CanPause() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_CanPause(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer<D>::IsLoopingEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_IsLoopingEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::IsLoopingEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->put_IsLoopingEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer<D>::IsProtected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_IsProtected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer<D>::IsMuted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_IsMuted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::IsMuted(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->put_IsMuted(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlayer<D>::PlaybackRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_PlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::PlaybackRate(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->put_PlaybackRate(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlayer<D>::Volume() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_Volume(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::Volume(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->put_Volume(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::PlaybackMediaMarkerSequence) consume_Windows_Media_Playback_IMediaPlayer<D>::PlaybackMediaMarkers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->get_PlaybackMediaMarkers(&value));
        return llm::OS::Media::Playback::PlaybackMediaMarkerSequence{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaOpened(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_MediaOpened(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::MediaOpened_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::MediaOpened(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, MediaOpened_revoker>(this, MediaOpened(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaOpened(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_MediaOpened(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaEnded(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_MediaEnded(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::MediaEnded_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::MediaEnded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, MediaEnded_revoker>(this, MediaEnded(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaEnded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_MediaEnded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaFailed(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::MediaPlayerFailedEventArgs> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_MediaFailed(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::MediaFailed_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::MediaFailed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::MediaPlayerFailedEventArgs> const& value) const
    {
        return impl::make_event_revoker<D, MediaFailed_revoker>(this, MediaFailed(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaFailed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_MediaFailed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::CurrentStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_CurrentStateChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::CurrentStateChanged_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::CurrentStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, CurrentStateChanged_revoker>(this, CurrentStateChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::CurrentStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_CurrentStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::PlaybackMediaMarkerReached(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::PlaybackMediaMarkerReachedEventArgs> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_PlaybackMediaMarkerReached(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::PlaybackMediaMarkerReached_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::PlaybackMediaMarkerReached(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::PlaybackMediaMarkerReachedEventArgs> const& value) const
    {
        return impl::make_event_revoker<D, PlaybackMediaMarkerReached_revoker>(this, PlaybackMediaMarkerReached(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::PlaybackMediaMarkerReached(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_PlaybackMediaMarkerReached(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaPlayerRateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::MediaPlayerRateChangedEventArgs> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_MediaPlayerRateChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::MediaPlayerRateChanged_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::MediaPlayerRateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::MediaPlayerRateChangedEventArgs> const& value) const
    {
        return impl::make_event_revoker<D, MediaPlayerRateChanged_revoker>(this, MediaPlayerRateChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::MediaPlayerRateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_MediaPlayerRateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::VolumeChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_VolumeChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::VolumeChanged_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::VolumeChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, VolumeChanged_revoker>(this, VolumeChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::VolumeChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_VolumeChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::SeekCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_SeekCompleted(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::SeekCompleted_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::SeekCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, SeekCompleted_revoker>(this, SeekCompleted(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::SeekCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_SeekCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingStarted(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_BufferingStarted(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingStarted_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingStarted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, BufferingStarted_revoker>(this, BufferingStarted(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingStarted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_BufferingStarted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingEnded(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->add_BufferingEnded(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingEnded_revoker consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingEnded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, BufferingEnded_revoker>(this, BufferingEnded(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::BufferingEnded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->remove_BufferingEnded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::Play() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->Play());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::Pause() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->Pause());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer<D>::SetUriSource(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer)->SetUriSource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SystemMediaTransportControls) consume_Windows_Media_Playback_IMediaPlayer2<D>::SystemMediaTransportControls() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer2)->get_SystemMediaTransportControls(&value));
        return llm::OS::Media::SystemMediaTransportControls{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayerAudioCategory) consume_Windows_Media_Playback_IMediaPlayer2<D>::AudioCategory() const
    {
        llm::OS::Media::Playback::MediaPlayerAudioCategory value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer2)->get_AudioCategory(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer2<D>::AudioCategory(llm::OS::Media::Playback::MediaPlayerAudioCategory const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer2)->put_AudioCategory(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayerAudioDeviceType) consume_Windows_Media_Playback_IMediaPlayer2<D>::AudioDeviceType() const
    {
        llm::OS::Media::Playback::MediaPlayerAudioDeviceType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer2)->get_AudioDeviceType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer2<D>::AudioDeviceType(llm::OS::Media::Playback::MediaPlayerAudioDeviceType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer2)->put_AudioDeviceType(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer3<D>::IsMutedChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->add_IsMutedChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer3<D>::IsMutedChanged_revoker consume_Windows_Media_Playback_IMediaPlayer3<D>::IsMutedChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, IsMutedChanged_revoker>(this, IsMutedChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::IsMutedChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->remove_IsMutedChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer3<D>::SourceChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->add_SourceChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer3<D>::SourceChanged_revoker consume_Windows_Media_Playback_IMediaPlayer3<D>::SourceChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, SourceChanged_revoker>(this, SourceChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::SourceChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->remove_SourceChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlayer3<D>::AudioBalance() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_AudioBalance(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::AudioBalance(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->put_AudioBalance(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer3<D>::RealTimePlayback() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_RealTimePlayback(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::RealTimePlayback(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->put_RealTimePlayback(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::StereoscopicVideoRenderMode) consume_Windows_Media_Playback_IMediaPlayer3<D>::StereoscopicVideoRenderMode() const
    {
        llm::OS::Media::Playback::StereoscopicVideoRenderMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_StereoscopicVideoRenderMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::StereoscopicVideoRenderMode(llm::OS::Media::Playback::StereoscopicVideoRenderMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->put_StereoscopicVideoRenderMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaBreakManager) consume_Windows_Media_Playback_IMediaPlayer3<D>::BreakManager() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_BreakManager(&value));
        return llm::OS::Media::Playback::MediaBreakManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackCommandManager) consume_Windows_Media_Playback_IMediaPlayer3<D>::CommandManager() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_CommandManager(&value));
        return llm::OS::Media::Playback::MediaPlaybackCommandManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Media_Playback_IMediaPlayer3<D>::AudioDevice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_AudioDevice(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::AudioDevice(llm::OS::Devices::Enumeration::DeviceInformation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->put_AudioDevice(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaTimelineController) consume_Windows_Media_Playback_IMediaPlayer3<D>::TimelineController() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_TimelineController(&value));
        return llm::OS::Media::MediaTimelineController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::TimelineController(llm::OS::Media::MediaTimelineController const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->put_TimelineController(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IMediaPlayer3<D>::TimelineControllerPositionOffset() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_TimelineControllerPositionOffset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::TimelineControllerPositionOffset(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->put_TimelineControllerPositionOffset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlaybackSession) consume_Windows_Media_Playback_IMediaPlayer3<D>::PlaybackSession() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->get_PlaybackSession(&value));
        return llm::OS::Media::Playback::MediaPlaybackSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::StepForwardOneFrame() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->StepForwardOneFrame());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer3<D>::StepBackwardOneFrame() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->StepBackwardOneFrame());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingSource) consume_Windows_Media_Playback_IMediaPlayer3<D>::GetAsCastingSource() const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer3)->GetAsCastingSource(&returnValue));
        return llm::OS::Media::Casting::CastingSource{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer4<D>::SetSurfaceSize(llm::OS::Foundation::Size const& size) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer4)->SetSurfaceSize(impl::bind_in(size)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayerSurface) consume_Windows_Media_Playback_IMediaPlayer4<D>::GetSurface(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer4)->GetSurface(*(void**)(&compositor), &result));
        return llm::OS::Media::Playback::MediaPlayerSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer5<D>::VideoFrameAvailable(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer5)->add_VideoFrameAvailable(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer5<D>::VideoFrameAvailable_revoker consume_Windows_Media_Playback_IMediaPlayer5<D>::VideoFrameAvailable(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, VideoFrameAvailable_revoker>(this, VideoFrameAvailable(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer5<D>::VideoFrameAvailable(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer5)->remove_VideoFrameAvailable(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer5<D>::IsVideoFrameServerEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer5)->get_IsVideoFrameServerEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer5<D>::IsVideoFrameServerEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer5)->put_IsVideoFrameServerEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer5<D>::CopyFrameToVideoSurface(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& destination) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer5)->CopyFrameToVideoSurface(*(void**)(&destination)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer5<D>::CopyFrameToVideoSurface(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& destination, llm::OS::Foundation::Rect const& targetRectangle) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer5)->CopyFrameToVideoSurfaceWithTargetRectangle(*(void**)(&destination), impl::bind_in(targetRectangle)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer5<D>::CopyFrameToStereoscopicVideoSurfaces(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& destinationLeftEye, llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& destinationRightEye) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer5)->CopyFrameToStereoscopicVideoSurfaces(*(void**)(&destinationLeftEye), *(void**)(&destinationRightEye)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Playback_IMediaPlayer6<D>::SubtitleFrameChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer6)->add_SubtitleFrameChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Playback_IMediaPlayer6<D>::SubtitleFrameChanged_revoker consume_Windows_Media_Playback_IMediaPlayer6<D>::SubtitleFrameChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, SubtitleFrameChanged_revoker>(this, SubtitleFrameChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayer6<D>::SubtitleFrameChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer6)->remove_SubtitleFrameChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer6<D>::RenderSubtitlesToSurface(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& destination) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer6)->RenderSubtitlesToSurface(*(void**)(&destination), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Playback_IMediaPlayer6<D>::RenderSubtitlesToSurface(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& destination, llm::OS::Foundation::Rect const& targetRectangle) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer6)->RenderSubtitlesToSurfaceWithTargetRectangle(*(void**)(&destination), impl::bind_in(targetRectangle), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Audio::AudioStateMonitor) consume_Windows_Media_Playback_IMediaPlayer7<D>::AudioStateMonitor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayer7)->get_AudioStateMonitor(&value));
        return llm::OS::Media::Audio::AudioStateMonitor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Media_Playback_IMediaPlayerDataReceivedEventArgs<D>::Data() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerDataReceivedEventArgs)->get_Data(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerEffects<D>::AddAudioEffect(param::hstring const& activatableClassId, bool effectOptional, llm::OS::Foundation::Collections::IPropertySet const& configuration) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerEffects)->AddAudioEffect(*(void**)(&activatableClassId), effectOptional, *(void**)(&configuration)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerEffects<D>::RemoveAllEffects() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerEffects)->RemoveAllEffects());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerEffects2<D>::AddVideoEffect(param::hstring const& activatableClassId, bool effectOptional, llm::OS::Foundation::Collections::IPropertySet const& effectConfiguration) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerEffects2)->AddVideoEffect(*(void**)(&activatableClassId), effectOptional, *(void**)(&effectConfiguration)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayerError) consume_Windows_Media_Playback_IMediaPlayerFailedEventArgs<D>::Error() const
    {
        llm::OS::Media::Playback::MediaPlayerError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerFailedEventArgs)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Media_Playback_IMediaPlayerFailedEventArgs<D>::ExtendedErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerFailedEventArgs)->get_ExtendedErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Playback_IMediaPlayerFailedEventArgs<D>::ErrorMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerFailedEventArgs)->get_ErrorMessage(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Playback_IMediaPlayerRateChangedEventArgs<D>::NewRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerRateChangedEventArgs)->get_NewRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Protection::MediaProtectionManager) consume_Windows_Media_Playback_IMediaPlayerSource<D>::ProtectionManager() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSource)->get_ProtectionManager(&value));
        return llm::OS::Media::Protection::MediaProtectionManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerSource<D>::ProtectionManager(llm::OS::Media::Protection::MediaProtectionManager const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSource)->put_ProtectionManager(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerSource<D>::SetFileSource(llm::OS::Storage::IStorageFile const& file) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSource)->SetFileSource(*(void**)(&file)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerSource<D>::SetStreamSource(llm::OS::Storage::Streams::IRandomAccessStream const& stream) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSource)->SetStreamSource(*(void**)(&stream)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerSource<D>::SetMediaSource(llm::OS::Media::Core::IMediaSource const& source) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSource)->SetMediaSource(*(void**)(&source)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::IMediaPlaybackSource) consume_Windows_Media_Playback_IMediaPlayerSource2<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSource2)->get_Source(&value));
        return llm::OS::Media::Playback::IMediaPlaybackSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IMediaPlayerSource2<D>::Source(llm::OS::Media::Playback::IMediaPlaybackSource const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSource2)->put_Source(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ICompositionSurface) consume_Windows_Media_Playback_IMediaPlayerSurface<D>::CompositionSurface() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSurface)->get_CompositionSurface(&value));
        return llm::OS::UI::Composition::ICompositionSurface{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Compositor) consume_Windows_Media_Playback_IMediaPlayerSurface<D>::Compositor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSurface)->get_Compositor(&value));
        return llm::OS::UI::Composition::Compositor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::MediaPlayer) consume_Windows_Media_Playback_IMediaPlayerSurface<D>::MediaPlayer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IMediaPlayerSurface)->get_MediaPlayer(&value));
        return llm::OS::Media::Playback::MediaPlayer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Playback_IPlaybackMediaMarker<D>::Time() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarker)->get_Time(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Playback_IPlaybackMediaMarker<D>::MediaMarkerType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarker)->get_MediaMarkerType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Playback_IPlaybackMediaMarker<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarker)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::PlaybackMediaMarker) consume_Windows_Media_Playback_IPlaybackMediaMarkerFactory<D>::CreateFromTime(llm::OS::Foundation::TimeSpan const& value) const
    {
        void* marker{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarkerFactory)->CreateFromTime(impl::bind_in(value), &marker));
        return llm::OS::Media::Playback::PlaybackMediaMarker{ marker, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::PlaybackMediaMarker) consume_Windows_Media_Playback_IPlaybackMediaMarkerFactory<D>::Create(llm::OS::Foundation::TimeSpan const& value, param::hstring const& mediaMarketType, param::hstring const& text) const
    {
        void* marker{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarkerFactory)->Create(impl::bind_in(value), *(void**)(&mediaMarketType), *(void**)(&text), &marker));
        return llm::OS::Media::Playback::PlaybackMediaMarker{ marker, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::PlaybackMediaMarker) consume_Windows_Media_Playback_IPlaybackMediaMarkerReachedEventArgs<D>::PlaybackMediaMarker() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarkerReachedEventArgs)->get_PlaybackMediaMarker(&value));
        return llm::OS::Media::Playback::PlaybackMediaMarker{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Playback_IPlaybackMediaMarkerSequence<D>::Size() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarkerSequence)->get_Size(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IPlaybackMediaMarkerSequence<D>::Insert(llm::OS::Media::Playback::PlaybackMediaMarker const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarkerSequence)->Insert(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Playback_IPlaybackMediaMarkerSequence<D>::Clear() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::IPlaybackMediaMarkerSequence)->Clear());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Core::TimedMetadataTrack) consume_Windows_Media_Playback_ITimedMetadataPresentationModeChangedEventArgs<D>::Track() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs)->get_Track(&value));
        return llm::OS::Media::Core::TimedMetadataTrack{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::TimedMetadataTrackPresentationMode) consume_Windows_Media_Playback_ITimedMetadataPresentationModeChangedEventArgs<D>::OldPresentationMode() const
    {
        llm::OS::Media::Playback::TimedMetadataTrackPresentationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs)->get_OldPresentationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::TimedMetadataTrackPresentationMode) consume_Windows_Media_Playback_ITimedMetadataPresentationModeChangedEventArgs<D>::NewPresentationMode() const
    {
        llm::OS::Media::Playback::TimedMetadataTrackPresentationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs)->get_NewPresentationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IBackgroundMediaPlayerStatics> : produce_base<D, llm::OS::Media::Playback::IBackgroundMediaPlayerStatics>
    {
        int32_t __stdcall get_Current(void** player) noexcept final try
        {
            clear_abi(player);
            typename D::abi_guard guard(this->shim());
            *player = detach_from<llm::OS::Media::Playback::MediaPlayer>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_MessageReceivedFromBackground(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MessageReceivedFromBackground(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MessageReceivedFromBackground(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceivedFromBackground(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_MessageReceivedFromForeground(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MessageReceivedFromForeground(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MessageReceivedFromForeground(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceivedFromForeground(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall SendMessageToBackground(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendMessageToBackground(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendMessageToForeground(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendMessageToForeground(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsMediaPlaying(bool* isMediaPlaying) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *isMediaPlaying = detach_from<bool>(this->shim().IsMediaPlaying());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Shutdown() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Shutdown();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs> : produce_base<D, llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs>
    {
        int32_t __stdcall get_NewItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().NewItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OldItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().OldItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs2> : produce_base<D, llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs2>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItemChangedReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreak> : produce_base<D, llm::OS::Media::Playback::IMediaBreak>
    {
        int32_t __stdcall get_PlaybackList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackList>(this->shim().PlaybackList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PresentationPosition(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().PresentationPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InsertionMethod(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreakInsertionMethod>(this->shim().InsertionMethod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().CustomProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanStart(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CanStart(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanStart(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreakEndedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaBreakEndedEventArgs>
    {
        int32_t __stdcall get_MediaBreak(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().MediaBreak());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreakFactory> : produce_base<D, llm::OS::Media::Playback::IMediaBreakFactory>
    {
        int32_t __stdcall Create(int32_t insertionMethod, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().Create(*reinterpret_cast<llm::OS::Media::Playback::MediaBreakInsertionMethod const*>(&insertionMethod)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithPresentationPosition(int32_t insertionMethod, int64_t presentationPosition, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().CreateWithPresentationPosition(*reinterpret_cast<llm::OS::Media::Playback::MediaBreakInsertionMethod const*>(&insertionMethod), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&presentationPosition)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreakManager> : produce_base<D, llm::OS::Media::Playback::IMediaBreakManager>
    {
        int32_t __stdcall add_BreaksSeekedOver(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BreaksSeekedOver(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakSeekedOverEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BreaksSeekedOver(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreaksSeekedOver(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BreakStarted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BreakStarted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakStartedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BreakStarted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakStarted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BreakEnded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BreakEnded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakEndedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BreakEnded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakEnded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BreakSkipped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BreakSkipped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakManager, llm::OS::Media::Playback::MediaBreakSkippedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BreakSkipped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakSkipped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_CurrentBreak(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().CurrentBreak());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackSession(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackSession>(this->shim().PlaybackSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PlayBreak(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayBreak(*reinterpret_cast<llm::OS::Media::Playback::MediaBreak const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SkipCurrentBreak() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SkipCurrentBreak();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreakSchedule> : produce_base<D, llm::OS::Media::Playback::IMediaBreakSchedule>
    {
        int32_t __stdcall add_ScheduleChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ScheduleChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaBreakSchedule, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ScheduleChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScheduleChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall InsertMidrollBreak(void* mediaBreak) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertMidrollBreak(*reinterpret_cast<llm::OS::Media::Playback::MediaBreak const*>(&mediaBreak));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveMidrollBreak(void* mediaBreak) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveMidrollBreak(*reinterpret_cast<llm::OS::Media::Playback::MediaBreak const*>(&mediaBreak));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MidrollBreaks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaBreak>>(this->shim().MidrollBreaks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PrerollBreak(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrerollBreak(*reinterpret_cast<llm::OS::Media::Playback::MediaBreak const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrerollBreak(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().PrerollBreak());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PostrollBreak(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PostrollBreak(*reinterpret_cast<llm::OS::Media::Playback::MediaBreak const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PostrollBreak(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().PostrollBreak());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().PlaybackItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreakSeekedOverEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaBreakSeekedOverEventArgs>
    {
        int32_t __stdcall get_SeekedOverBreaks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaBreak>>(this->shim().SeekedOverBreaks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OldPosition(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().OldPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewPosition(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().NewPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreakSkippedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaBreakSkippedEventArgs>
    {
        int32_t __stdcall get_MediaBreak(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().MediaBreak());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaBreakStartedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaBreakStartedEventArgs>
    {
        int32_t __stdcall get_MediaBreak(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreak>(this->shim().MediaBreak());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaEnginePlaybackSource> : produce_base<D, llm::OS::Media::Playback::IMediaEnginePlaybackSource>
    {
        int32_t __stdcall get_CurrentItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().CurrentItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPlaybackSource(void* source) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPlaybackSource(*reinterpret_cast<llm::OS::Media::Playback::IMediaPlaybackSource const*>(&source));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaItemDisplayProperties> : produce_base<D, llm::OS::Media::Playback::IMediaItemDisplayProperties>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaPlaybackType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Type(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(*reinterpret_cast<llm::OS::Media::MediaPlaybackType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MusicProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MusicDisplayProperties>(this->shim().MusicProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoDisplayProperties>(this->shim().VideoProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::RandomAccessStreamReference>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Thumbnail(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<llm::OS::Storage::Streams::RandomAccessStreamReference const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearAll() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearAll();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManager> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManager>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MediaPlayer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlayer>(this->shim().MediaPlayer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlayBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().PlayBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PauseBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().PauseBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NextBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().NextBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreviousBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().PreviousBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FastForwardBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().FastForwardBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RewindBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().RewindBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShuffleBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().ShuffleBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoRepeatModeBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().AutoRepeatModeBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PositionBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().PositionBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RateBehavior(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>(this->shim().RateBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_PlayReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PlayReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PlayReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PauseReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PauseReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PauseReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PauseReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_NextReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().NextReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NextReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NextReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PreviousReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PreviousReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PreviousReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreviousReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_FastForwardReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FastForwardReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FastForwardReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FastForwardReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RewindReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RewindReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RewindReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RewindReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ShuffleReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ShuffleReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ShuffleReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShuffleReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AutoRepeatModeReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AutoRepeatModeReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AutoRepeatModeReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRepeatModeReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PositionReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PositionReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PositionReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RateReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RateReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManager, llm::OS::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RateReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RateReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoRepeatMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaPlaybackAutoRepeatMode>(this->shim().AutoRepeatMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>
    {
        int32_t __stdcall get_CommandManager(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManager>(this->shim().CommandManager());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnablingRule(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaCommandEnablingRule>(this->shim().EnablingRule());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EnablingRule(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnablingRule(*reinterpret_cast<llm::OS::Media::Playback::MediaCommandEnablingRule const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsEnabledChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsEnabledChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsEnabledChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabledChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().PlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsShuffleRequested(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsShuffleRequested());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItem> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItem>
    {
        int32_t __stdcall add_AudioTracksChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AudioTracksChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AudioTracksChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioTracksChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_VideoTracksChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VideoTracksChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VideoTracksChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoTracksChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TimedMetadataTracksChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TimedMetadataTracksChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackItem, llm::OS::Foundation::Collections::IVectorChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TimedMetadataTracksChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimedMetadataTracksChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Core::MediaSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioTracks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackAudioTrackList>(this->shim().AudioTracks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoTracks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackVideoTrackList>(this->shim().VideoTracks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimedMetadataTracks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackTimedMetadataTrackList>(this->shim().TimedMetadataTracks());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItem2> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItem2>
    {
        int32_t __stdcall get_BreakSchedule(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreakSchedule>(this->shim().BreakSchedule());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().StartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DurationLimit(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().DurationLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanSkip(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanSkip());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CanSkip(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanSkip(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDisplayProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaItemDisplayProperties>(this->shim().GetDisplayProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApplyDisplayProperties(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplyDisplayProperties(*reinterpret_cast<llm::OS::Media::Playback::MediaItemDisplayProperties const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItem3> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItem3>
    {
        int32_t __stdcall get_IsDisabledInPlaybackList(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDisabledInPlaybackList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsDisabledInPlaybackList(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDisabledInPlaybackList(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalDownloadProgress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().TotalDownloadProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoLoadedDisplayProperties(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::AutoLoadedDisplayPropertyKind>(this->shim().AutoLoadedDisplayProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoLoadedDisplayProperties(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoLoadedDisplayProperties(*reinterpret_cast<llm::OS::Media::Playback::AutoLoadedDisplayPropertyKind const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItemError> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItemError>
    {
        int32_t __stdcall get_ErrorCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItemErrorCode>(this->shim().ErrorCode());
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItemFactory> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItemFactory>
    {
        int32_t __stdcall Create(void* source, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().Create(*reinterpret_cast<llm::OS::Media::Core::MediaSource const*>(&source)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItemFactory2> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItemFactory2>
    {
        int32_t __stdcall CreateWithStartTime(void* source, int64_t startTime, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().CreateWithStartTime(*reinterpret_cast<llm::OS::Media::Core::MediaSource const*>(&source), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&startTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithStartTimeAndDurationLimit(void* source, int64_t startTime, int64_t durationLimit, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().CreateWithStartTimeAndDurationLimit(*reinterpret_cast<llm::OS::Media::Core::MediaSource const*>(&source), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&startTime), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&durationLimit)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItemFailedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItemFailedEventArgs>
    {
        int32_t __stdcall get_Item(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().Item());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Error(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItemError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItemOpenedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItemOpenedEventArgs>
    {
        int32_t __stdcall get_Item(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().Item());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackItemStatics> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackItemStatics>
    {
        int32_t __stdcall FindFromMediaSource(void* source, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().FindFromMediaSource(*reinterpret_cast<llm::OS::Media::Core::MediaSource const*>(&source)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackList> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackList>
    {
        int32_t __stdcall add_ItemFailed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ItemFailed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::MediaPlaybackItemFailedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ItemFailed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemFailed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CurrentItemChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CurrentItemChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CurrentItemChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentItemChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ItemOpened(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ItemOpened(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackList, llm::OS::Media::Playback::MediaPlaybackItemOpenedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ItemOpened(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemOpened(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Items(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IObservableVector<llm::OS::Media::Playback::MediaPlaybackItem>>(this->shim().Items());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoRepeatEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AutoRepeatEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoRepeatEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRepeatEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShuffleEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShuffleEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShuffleEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShuffleEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().CurrentItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentItemIndex(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().CurrentItemIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MoveNext(void** item) noexcept final try
        {
            clear_abi(item);
            typename D::abi_guard guard(this->shim());
            *item = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().MoveNext());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MovePrevious(void** item) noexcept final try
        {
            clear_abi(item);
            typename D::abi_guard guard(this->shim());
            *item = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().MovePrevious());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MoveTo(uint32_t itemIndex, void** item) noexcept final try
        {
            clear_abi(item);
            typename D::abi_guard guard(this->shim());
            *item = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().MoveTo(itemIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackList2> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackList2>
    {
        int32_t __stdcall get_MaxPrefetchTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().MaxPrefetchTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxPrefetchTime(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPrefetchTime(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartingItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackItem>(this->shim().StartingItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StartingItem(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartingItem(*reinterpret_cast<llm::OS::Media::Playback::MediaPlaybackItem const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShuffledItems(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Playback::MediaPlaybackItem>>(this->shim().ShuffledItems());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetShuffledItems(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetShuffledItems(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Media::Playback::MediaPlaybackItem> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackList3> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackList3>
    {
        int32_t __stdcall get_MaxPlayedItemsToKeepOpen(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().MaxPlayedItemsToKeepOpen());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxPlayedItemsToKeepOpen(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPlayedItemsToKeepOpen(*reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackSession> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackSession>
    {
        int32_t __stdcall add_PlaybackStateChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PlaybackStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PlaybackStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PlaybackRateChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PlaybackRateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PlaybackRateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SeekCompleted(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SeekCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SeekCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SeekCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BufferingStarted(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BufferingStarted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BufferingStarted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingStarted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BufferingEnded(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BufferingEnded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BufferingEnded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingEnded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BufferingProgressChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BufferingProgressChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BufferingProgressChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingProgressChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DownloadProgressChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DownloadProgressChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DownloadProgressChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadProgressChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_NaturalDurationChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().NaturalDurationChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NaturalDurationChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NaturalDurationChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PositionChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PositionChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PositionChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_NaturalVideoSizeChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().NaturalVideoSizeChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NaturalVideoSizeChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NaturalVideoSizeChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_MediaPlayer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlayer>(this->shim().MediaPlayer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NaturalDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().NaturalDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Position(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackState>(this->shim().PlaybackState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanSeek(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanSeek());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanPause(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanPause());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsProtected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsProtected());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().PlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PlaybackRate(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BufferingProgress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().BufferingProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DownloadProgress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DownloadProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NaturalVideoHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NaturalVideoHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NaturalVideoWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NaturalVideoWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NormalizedSourceRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().NormalizedSourceRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NormalizedSourceRect(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NormalizedSourceRect(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StereoscopicVideoPackingMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::StereoscopicVideoPackingMode>(this->shim().StereoscopicVideoPackingMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StereoscopicVideoPackingMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoscopicVideoPackingMode(*reinterpret_cast<llm::OS::Media::MediaProperties::StereoscopicVideoPackingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackSession2> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackSession2>
    {
        int32_t __stdcall add_BufferedRangesChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BufferedRangesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BufferedRangesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferedRangesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PlayedRangesChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PlayedRangesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PlayedRangesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayedRangesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SeekableRangesChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SeekableRangesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SeekableRangesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SeekableRangesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SupportedPlaybackRatesChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SupportedPlaybackRatesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackSession, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SupportedPlaybackRatesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportedPlaybackRatesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_SphericalVideoProjection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackSphericalVideoProjection>(this->shim().SphericalVideoProjection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMirroring(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMirroring());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsMirroring(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMirroring(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBufferedRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>>(this->shim().GetBufferedRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPlayedRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>>(this->shim().GetPlayedRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSeekableRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaTimeRange>>(this->shim().GetSeekableRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsSupportedPlaybackRateRange(double rate1, double rate2, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupportedPlaybackRateRange(rate1, rate2));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackSession3> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackSession3>
    {
        int32_t __stdcall get_PlaybackRotation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::MediaRotation>(this->shim().PlaybackRotation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PlaybackRotation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRotation(*reinterpret_cast<llm::OS::Media::MediaProperties::MediaRotation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOutputDegradationPolicyState(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackSessionOutputDegradationPolicyState>(this->shim().GetOutputDegradationPolicyState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackSessionBufferingStartedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackSessionBufferingStartedEventArgs>
    {
        int32_t __stdcall get_IsPlaybackInterruption(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPlaybackInterruption());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackSessionOutputDegradationPolicyState> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackSessionOutputDegradationPolicyState>
    {
        int32_t __stdcall get_VideoConstrictionReason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackSessionVideoConstrictionReason>(this->shim().VideoConstrictionReason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackSource> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackSource>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::SphericalVideoFrameFormat>(this->shim().FrameFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FrameFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameFormat(*reinterpret_cast<llm::OS::Media::MediaProperties::SphericalVideoFrameFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HorizontalFieldOfViewInDegrees(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().HorizontalFieldOfViewInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_HorizontalFieldOfViewInDegrees(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HorizontalFieldOfViewInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ViewOrientation(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().ViewOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewOrientation(llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewOrientation(*reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProjectionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::SphericalVideoProjectionMode>(this->shim().ProjectionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProjectionMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProjectionMode(*reinterpret_cast<llm::OS::Media::Playback::SphericalVideoProjectionMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList> : produce_base<D, llm::OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList>
    {
        int32_t __stdcall add_PresentationModeChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PresentationModeChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlaybackTimedMetadataTrackList, llm::OS::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PresentationModeChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PresentationModeChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetPresentationMode(uint32_t index, int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::TimedMetadataTrackPresentationMode>(this->shim().GetPresentationMode(index));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPresentationMode(uint32_t index, int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPresentationMode(index, *reinterpret_cast<llm::OS::Media::Playback::TimedMetadataTrackPresentationMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayer> : produce_base<D, llm::OS::Media::Playback::IMediaPlayer>
    {
        int32_t __stdcall get_AutoPlay(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AutoPlay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoPlay(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoPlay(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NaturalDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().NaturalDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Position(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BufferingProgress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().BufferingProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlayerState>(this->shim().CurrentState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanSeek(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanSeek());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanPause(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanPause());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsLoopingEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsLoopingEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsLoopingEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsLoopingEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsProtected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsProtected());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMuted(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMuted());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsMuted(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMuted(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().PlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PlaybackRate(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Volume(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Volume());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Volume(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackMediaMarkers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::PlaybackMediaMarkerSequence>(this->shim().PlaybackMediaMarkers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_MediaOpened(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MediaOpened(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MediaOpened(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaOpened(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_MediaEnded(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MediaEnded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MediaEnded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaEnded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_MediaFailed(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MediaFailed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::MediaPlayerFailedEventArgs> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MediaFailed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaFailed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CurrentStateChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CurrentStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CurrentStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PlaybackMediaMarkerReached(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PlaybackMediaMarkerReached(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::PlaybackMediaMarkerReachedEventArgs> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PlaybackMediaMarkerReached(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackMediaMarkerReached(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_MediaPlayerRateChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MediaPlayerRateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Media::Playback::MediaPlayerRateChangedEventArgs> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MediaPlayerRateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaPlayerRateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_VolumeChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VolumeChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VolumeChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VolumeChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SeekCompleted(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SeekCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SeekCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SeekCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BufferingStarted(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BufferingStarted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BufferingStarted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingStarted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BufferingEnded(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BufferingEnded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BufferingEnded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingEnded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall Play() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Play();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Pause() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetUriSource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetUriSource(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayer2> : produce_base<D, llm::OS::Media::Playback::IMediaPlayer2>
    {
        int32_t __stdcall get_SystemMediaTransportControls(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SystemMediaTransportControls>(this->shim().SystemMediaTransportControls());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioCategory(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlayerAudioCategory>(this->shim().AudioCategory());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioCategory(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioCategory(*reinterpret_cast<llm::OS::Media::Playback::MediaPlayerAudioCategory const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioDeviceType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlayerAudioDeviceType>(this->shim().AudioDeviceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioDeviceType(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioDeviceType(*reinterpret_cast<llm::OS::Media::Playback::MediaPlayerAudioDeviceType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayer3> : produce_base<D, llm::OS::Media::Playback::IMediaPlayer3>
    {
        int32_t __stdcall add_IsMutedChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsMutedChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsMutedChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMutedChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SourceChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SourceChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_AudioBalance(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().AudioBalance());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioBalance(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioBalance(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RealTimePlayback(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RealTimePlayback());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RealTimePlayback(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RealTimePlayback(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StereoscopicVideoRenderMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::StereoscopicVideoRenderMode>(this->shim().StereoscopicVideoRenderMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StereoscopicVideoRenderMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoscopicVideoRenderMode(*reinterpret_cast<llm::OS::Media::Playback::StereoscopicVideoRenderMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BreakManager(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaBreakManager>(this->shim().BreakManager());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CommandManager(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackCommandManager>(this->shim().CommandManager());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioDevice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().AudioDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioDevice(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioDevice(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimelineController(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaTimelineController>(this->shim().TimelineController());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TimelineController(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimelineController(*reinterpret_cast<llm::OS::Media::MediaTimelineController const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimelineControllerPositionOffset(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TimelineControllerPositionOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TimelineControllerPositionOffset(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimelineControllerPositionOffset(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaybackSession(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlaybackSession>(this->shim().PlaybackSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StepForwardOneFrame() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StepForwardOneFrame();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StepBackwardOneFrame() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StepBackwardOneFrame();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAsCastingSource(void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Media::Casting::CastingSource>(this->shim().GetAsCastingSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayer4> : produce_base<D, llm::OS::Media::Playback::IMediaPlayer4>
    {
        int32_t __stdcall SetSurfaceSize(llm::OS::Foundation::Size size) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSurfaceSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&size));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSurface(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Playback::MediaPlayerSurface>(this->shim().GetSurface(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayer5> : produce_base<D, llm::OS::Media::Playback::IMediaPlayer5>
    {
        int32_t __stdcall add_VideoFrameAvailable(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VideoFrameAvailable(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VideoFrameAvailable(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoFrameAvailable(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_IsVideoFrameServerEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVideoFrameServerEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsVideoFrameServerEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVideoFrameServerEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CopyFrameToVideoSurface(void* destination) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyFrameToVideoSurface(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&destination));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CopyFrameToVideoSurfaceWithTargetRectangle(void* destination, llm::OS::Foundation::Rect targetRectangle) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyFrameToVideoSurface(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&destination), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&targetRectangle));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CopyFrameToStereoscopicVideoSurfaces(void* destinationLeftEye, void* destinationRightEye) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyFrameToStereoscopicVideoSurfaces(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&destinationLeftEye), *reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&destinationRightEye));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayer6> : produce_base<D, llm::OS::Media::Playback::IMediaPlayer6>
    {
        int32_t __stdcall add_SubtitleFrameChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SubtitleFrameChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Playback::MediaPlayer, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SubtitleFrameChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SubtitleFrameChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall RenderSubtitlesToSurface(void* destination, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().RenderSubtitlesToSurface(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&destination)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RenderSubtitlesToSurfaceWithTargetRectangle(void* destination, llm::OS::Foundation::Rect targetRectangle, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().RenderSubtitlesToSurface(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&destination), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&targetRectangle)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayer7> : produce_base<D, llm::OS::Media::Playback::IMediaPlayer7>
    {
        int32_t __stdcall get_AudioStateMonitor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Audio::AudioStateMonitor>(this->shim().AudioStateMonitor());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerDataReceivedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerDataReceivedEventArgs>
    {
        int32_t __stdcall get_Data(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Data());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerEffects> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerEffects>
    {
        int32_t __stdcall AddAudioEffect(void* activatableClassId, bool effectOptional, void* configuration) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAudioEffect(*reinterpret_cast<hstring const*>(&activatableClassId), effectOptional, *reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&configuration));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAllEffects() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAllEffects();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerEffects2> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerEffects2>
    {
        int32_t __stdcall AddVideoEffect(void* activatableClassId, bool effectOptional, void* effectConfiguration) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddVideoEffect(*reinterpret_cast<hstring const*>(&activatableClassId), effectOptional, *reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&effectConfiguration));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerFailedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerFailedEventArgs>
    {
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlayerError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ErrorMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerRateChangedEventArgs> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerRateChangedEventArgs>
    {
        int32_t __stdcall get_NewRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().NewRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerSource> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerSource>
    {
        int32_t __stdcall get_ProtectionManager(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Protection::MediaProtectionManager>(this->shim().ProtectionManager());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProtectionManager(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectionManager(*reinterpret_cast<llm::OS::Media::Protection::MediaProtectionManager const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFileSource(void* file) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFileSource(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetStreamSource(void* stream) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStreamSource(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&stream));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetMediaSource(void* source) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMediaSource(*reinterpret_cast<llm::OS::Media::Core::IMediaSource const*>(&source));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerSource2> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerSource2>
    {
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::IMediaPlaybackSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Source(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<llm::OS::Media::Playback::IMediaPlaybackSource const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IMediaPlayerSurface> : produce_base<D, llm::OS::Media::Playback::IMediaPlayerSurface>
    {
        int32_t __stdcall get_CompositionSurface(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::ICompositionSurface>(this->shim().CompositionSurface());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Compositor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Compositor>(this->shim().Compositor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MediaPlayer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::MediaPlayer>(this->shim().MediaPlayer());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IPlaybackMediaMarker> : produce_base<D, llm::OS::Media::Playback::IPlaybackMediaMarker>
    {
        int32_t __stdcall get_Time(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Time());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MediaMarkerType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MediaMarkerType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IPlaybackMediaMarkerFactory> : produce_base<D, llm::OS::Media::Playback::IPlaybackMediaMarkerFactory>
    {
        int32_t __stdcall CreateFromTime(int64_t value, void** marker) noexcept final try
        {
            clear_abi(marker);
            typename D::abi_guard guard(this->shim());
            *marker = detach_from<llm::OS::Media::Playback::PlaybackMediaMarker>(this->shim().CreateFromTime(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Create(int64_t value, void* mediaMarketType, void* text, void** marker) noexcept final try
        {
            clear_abi(marker);
            typename D::abi_guard guard(this->shim());
            *marker = detach_from<llm::OS::Media::Playback::PlaybackMediaMarker>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value), *reinterpret_cast<hstring const*>(&mediaMarketType), *reinterpret_cast<hstring const*>(&text)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IPlaybackMediaMarkerReachedEventArgs> : produce_base<D, llm::OS::Media::Playback::IPlaybackMediaMarkerReachedEventArgs>
    {
        int32_t __stdcall get_PlaybackMediaMarker(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::PlaybackMediaMarker>(this->shim().PlaybackMediaMarker());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::IPlaybackMediaMarkerSequence> : produce_base<D, llm::OS::Media::Playback::IPlaybackMediaMarkerSequence>
    {
        int32_t __stdcall get_Size(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Insert(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Insert(*reinterpret_cast<llm::OS::Media::Playback::PlaybackMediaMarker const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clear() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs> : produce_base<D, llm::OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs>
    {
        int32_t __stdcall get_Track(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Core::TimedMetadataTrack>(this->shim().Track());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OldPresentationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::TimedMetadataTrackPresentationMode>(this->shim().OldPresentationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewPresentationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::TimedMetadataTrackPresentationMode>(this->shim().NewPresentationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Playback
{
    inline auto BackgroundMediaPlayer::Current()
    {
        return impl::call_factory_cast<llm::OS::Media::Playback::MediaPlayer(*)(IBackgroundMediaPlayerStatics const&), BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([](IBackgroundMediaPlayerStatics const& f) { return f.Current(); });
    }
    inline auto BackgroundMediaPlayer::MessageReceivedFromBackground(llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value)
    {
        return impl::call_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([&](IBackgroundMediaPlayerStatics const& f) { return f.MessageReceivedFromBackground(value); });
    }
    inline BackgroundMediaPlayer::MessageReceivedFromBackground_revoker BackgroundMediaPlayer::MessageReceivedFromBackground(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value)
    {
        auto f = get_activation_factory<BackgroundMediaPlayer, llm::OS::Media::Playback::IBackgroundMediaPlayerStatics>();
        return { f, f.MessageReceivedFromBackground(value) };
    }
    inline auto BackgroundMediaPlayer::MessageReceivedFromBackground(llm::event_token const& token)
    {
        impl::call_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([&](IBackgroundMediaPlayerStatics const& f) { return f.MessageReceivedFromBackground(token); });
    }
    inline auto BackgroundMediaPlayer::MessageReceivedFromForeground(llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value)
    {
        return impl::call_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([&](IBackgroundMediaPlayerStatics const& f) { return f.MessageReceivedFromForeground(value); });
    }
    inline BackgroundMediaPlayer::MessageReceivedFromForeground_revoker BackgroundMediaPlayer::MessageReceivedFromForeground(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value)
    {
        auto f = get_activation_factory<BackgroundMediaPlayer, llm::OS::Media::Playback::IBackgroundMediaPlayerStatics>();
        return { f, f.MessageReceivedFromForeground(value) };
    }
    inline auto BackgroundMediaPlayer::MessageReceivedFromForeground(llm::event_token const& token)
    {
        impl::call_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([&](IBackgroundMediaPlayerStatics const& f) { return f.MessageReceivedFromForeground(token); });
    }
    inline auto BackgroundMediaPlayer::SendMessageToBackground(llm::OS::Foundation::Collections::ValueSet const& value)
    {
        impl::call_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([&](IBackgroundMediaPlayerStatics const& f) { return f.SendMessageToBackground(value); });
    }
    inline auto BackgroundMediaPlayer::SendMessageToForeground(llm::OS::Foundation::Collections::ValueSet const& value)
    {
        impl::call_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([&](IBackgroundMediaPlayerStatics const& f) { return f.SendMessageToForeground(value); });
    }
    inline auto BackgroundMediaPlayer::IsMediaPlaying()
    {
        return impl::call_factory_cast<bool(*)(IBackgroundMediaPlayerStatics const&), BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([](IBackgroundMediaPlayerStatics const& f) { return f.IsMediaPlaying(); });
    }
    inline auto BackgroundMediaPlayer::Shutdown()
    {
        impl::call_factory_cast<void(*)(IBackgroundMediaPlayerStatics const&), BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>([](IBackgroundMediaPlayerStatics const& f) { return f.Shutdown(); });
    }
    inline MediaBreak::MediaBreak(llm::OS::Media::Playback::MediaBreakInsertionMethod const& insertionMethod) :
        MediaBreak(impl::call_factory<MediaBreak, IMediaBreakFactory>([&](IMediaBreakFactory const& f) { return f.Create(insertionMethod); }))
    {
    }
    inline MediaBreak::MediaBreak(llm::OS::Media::Playback::MediaBreakInsertionMethod const& insertionMethod, llm::OS::Foundation::TimeSpan const& presentationPosition) :
        MediaBreak(impl::call_factory<MediaBreak, IMediaBreakFactory>([&](IMediaBreakFactory const& f) { return f.CreateWithPresentationPosition(insertionMethod, presentationPosition); }))
    {
    }
    inline MediaPlaybackItem::MediaPlaybackItem(llm::OS::Media::Core::MediaSource const& source) :
        MediaPlaybackItem(impl::call_factory<MediaPlaybackItem, IMediaPlaybackItemFactory>([&](IMediaPlaybackItemFactory const& f) { return f.Create(source); }))
    {
    }
    inline MediaPlaybackItem::MediaPlaybackItem(llm::OS::Media::Core::MediaSource const& source, llm::OS::Foundation::TimeSpan const& startTime) :
        MediaPlaybackItem(impl::call_factory<MediaPlaybackItem, IMediaPlaybackItemFactory2>([&](IMediaPlaybackItemFactory2 const& f) { return f.CreateWithStartTime(source, startTime); }))
    {
    }
    inline MediaPlaybackItem::MediaPlaybackItem(llm::OS::Media::Core::MediaSource const& source, llm::OS::Foundation::TimeSpan const& startTime, llm::OS::Foundation::TimeSpan const& durationLimit) :
        MediaPlaybackItem(impl::call_factory<MediaPlaybackItem, IMediaPlaybackItemFactory2>([&](IMediaPlaybackItemFactory2 const& f) { return f.CreateWithStartTimeAndDurationLimit(source, startTime, durationLimit); }))
    {
    }
    inline auto MediaPlaybackItem::FindFromMediaSource(llm::OS::Media::Core::MediaSource const& source)
    {
        return impl::call_factory<MediaPlaybackItem, IMediaPlaybackItemStatics>([&](IMediaPlaybackItemStatics const& f) { return f.FindFromMediaSource(source); });
    }
    inline MediaPlaybackList::MediaPlaybackList() :
        MediaPlaybackList(impl::call_factory_cast<MediaPlaybackList(*)(llm::OS::Foundation::IActivationFactory const&), MediaPlaybackList>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MediaPlaybackList>(); }))
    {
    }
    inline MediaPlayer::MediaPlayer() :
        MediaPlayer(impl::call_factory_cast<MediaPlayer(*)(llm::OS::Foundation::IActivationFactory const&), MediaPlayer>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MediaPlayer>(); }))
    {
    }
    inline PlaybackMediaMarker::PlaybackMediaMarker(llm::OS::Foundation::TimeSpan const& value) :
        PlaybackMediaMarker(impl::call_factory<PlaybackMediaMarker, IPlaybackMediaMarkerFactory>([&](IPlaybackMediaMarkerFactory const& f) { return f.CreateFromTime(value); }))
    {
    }
    inline PlaybackMediaMarker::PlaybackMediaMarker(llm::OS::Foundation::TimeSpan const& value, param::hstring const& mediaMarketType, param::hstring const& text) :
        PlaybackMediaMarker(impl::call_factory<PlaybackMediaMarker, IPlaybackMediaMarkerFactory>([&](IPlaybackMediaMarkerFactory const& f) { return f.Create(value, mediaMarketType, text); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Playback::IBackgroundMediaPlayerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreak> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreakEndedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreakFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreakManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreakSchedule> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreakSeekedOverEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreakSkippedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaBreakStartedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaEnginePlaybackSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaItemDisplayProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItem2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItem3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItemError> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItemFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItemFactory2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItemFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItemOpenedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackItemStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackList2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackList3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackSession2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackSession3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackSessionBufferingStartedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackSessionOutputDegradationPolicyState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackSphericalVideoProjection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayer2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayer3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayer4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayer5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayer6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayer7> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerDataReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerEffects> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerEffects2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerRateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IMediaPlayerSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IPlaybackMediaMarker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IPlaybackMediaMarkerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IPlaybackMediaMarkerReachedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::IPlaybackMediaMarkerSequence> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::BackgroundMediaPlayer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaBreak> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaBreakEndedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaBreakManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaBreakSchedule> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaBreakSeekedOverEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaBreakSkippedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaBreakStartedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaItemDisplayProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackAudioTrackList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerCommandBehavior> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackItemError> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackItemFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackItemOpenedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackSessionBufferingStartedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackSessionOutputDegradationPolicyState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackSphericalVideoProjection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackTimedMetadataTrackList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlaybackVideoTrackList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlayer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlayerDataReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlayerFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlayerRateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::MediaPlayerSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::PlaybackMediaMarker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::PlaybackMediaMarkerReachedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::PlaybackMediaMarkerSequence> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
