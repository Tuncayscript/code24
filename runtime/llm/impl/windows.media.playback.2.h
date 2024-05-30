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
#ifndef LLM_OS_Media_Playback_2_H
#define LLM_OS_Media_Playback_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Media.Core.1.h"
#include "llm/impl/Windows.Media.Playback.1.h"
LLM_EXPORT namespace llm:OS::Media::Playback
{
    struct BackgroundMediaPlayer
    {
        BackgroundMediaPlayer() = delete;
        [[nodiscard]] static auto Current();
        static auto MessageReceivedFromBackground(llm:OS::Foundation::EventHandler<llm:OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value);
        using MessageReceivedFromBackground_revoker = impl::factory_event_revoker<llm:OS::Media::Playback::IBackgroundMediaPlayerStatics, &impl::abi_t<llm:OS::Media::Playback::IBackgroundMediaPlayerStatics>::remove_MessageReceivedFromBackground>;
        [[nodiscard]] static MessageReceivedFromBackground_revoker MessageReceivedFromBackground(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value);
        static auto MessageReceivedFromBackground(llm::event_token const& token);
        static auto MessageReceivedFromForeground(llm:OS::Foundation::EventHandler<llm:OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value);
        using MessageReceivedFromForeground_revoker = impl::factory_event_revoker<llm:OS::Media::Playback::IBackgroundMediaPlayerStatics, &impl::abi_t<llm:OS::Media::Playback::IBackgroundMediaPlayerStatics>::remove_MessageReceivedFromForeground>;
        [[nodiscard]] static MessageReceivedFromForeground_revoker MessageReceivedFromForeground(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Media::Playback::MediaPlayerDataReceivedEventArgs> const& value);
        static auto MessageReceivedFromForeground(llm::event_token const& token);
        static auto SendMessageToBackground(llm:OS::Foundation::Collections::ValueSet const& value);
        static auto SendMessageToForeground(llm:OS::Foundation::Collections::ValueSet const& value);
        static auto IsMediaPlaying();
        static auto Shutdown();
    };
    struct __declspec(empty_bases) CurrentMediaPlaybackItemChangedEventArgs : llm:OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs,
        impl::require<CurrentMediaPlaybackItemChangedEventArgs, llm:OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs2>
    {
        CurrentMediaPlaybackItemChangedEventArgs(std::nullptr_t) noexcept {}
        CurrentMediaPlaybackItemChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaBreak : llm:OS::Media::Playback::IMediaBreak
    {
        MediaBreak(std::nullptr_t) noexcept {}
        MediaBreak(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaBreak(ptr, take_ownership_from_abi) {}
        explicit MediaBreak(llm:OS::Media::Playback::MediaBreakInsertionMethod const& insertionMethod);
        MediaBreak(llm:OS::Media::Playback::MediaBreakInsertionMethod const& insertionMethod, llm:OS::Foundation::TimeSpan const& presentationPosition);
    };
    struct __declspec(empty_bases) MediaBreakEndedEventArgs : llm:OS::Media::Playback::IMediaBreakEndedEventArgs
    {
        MediaBreakEndedEventArgs(std::nullptr_t) noexcept {}
        MediaBreakEndedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaBreakEndedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaBreakManager : llm:OS::Media::Playback::IMediaBreakManager
    {
        MediaBreakManager(std::nullptr_t) noexcept {}
        MediaBreakManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaBreakManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaBreakSchedule : llm:OS::Media::Playback::IMediaBreakSchedule
    {
        MediaBreakSchedule(std::nullptr_t) noexcept {}
        MediaBreakSchedule(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaBreakSchedule(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaBreakSeekedOverEventArgs : llm:OS::Media::Playback::IMediaBreakSeekedOverEventArgs
    {
        MediaBreakSeekedOverEventArgs(std::nullptr_t) noexcept {}
        MediaBreakSeekedOverEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaBreakSeekedOverEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaBreakSkippedEventArgs : llm:OS::Media::Playback::IMediaBreakSkippedEventArgs
    {
        MediaBreakSkippedEventArgs(std::nullptr_t) noexcept {}
        MediaBreakSkippedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaBreakSkippedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaBreakStartedEventArgs : llm:OS::Media::Playback::IMediaBreakStartedEventArgs
    {
        MediaBreakStartedEventArgs(std::nullptr_t) noexcept {}
        MediaBreakStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaBreakStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaItemDisplayProperties : llm:OS::Media::Playback::IMediaItemDisplayProperties
    {
        MediaItemDisplayProperties(std::nullptr_t) noexcept {}
        MediaItemDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaItemDisplayProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackAudioTrackList : llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Core::AudioTrack>,
        impl::require<MediaPlaybackAudioTrackList, llm:OS::Media::Core::ISingleSelectMediaTrackList>
    {
        MediaPlaybackAudioTrackList(std::nullptr_t) noexcept {}
        MediaPlaybackAudioTrackList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Core::AudioTrack>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManager : llm:OS::Media::Playback::IMediaPlaybackCommandManager
    {
        MediaPlaybackCommandManager(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs
    {
        MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerCommandBehavior : llm:OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior
    {
        MediaPlaybackCommandManagerCommandBehavior(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerCommandBehavior(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerFastForwardReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs
    {
        MediaPlaybackCommandManagerFastForwardReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerFastForwardReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerNextReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs
    {
        MediaPlaybackCommandManagerNextReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerNextReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerPauseReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs
    {
        MediaPlaybackCommandManagerPauseReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerPauseReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerPlayReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs
    {
        MediaPlaybackCommandManagerPlayReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerPlayReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerPositionReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs
    {
        MediaPlaybackCommandManagerPositionReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerPositionReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerPreviousReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs
    {
        MediaPlaybackCommandManagerPreviousReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerPreviousReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerRateReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs
    {
        MediaPlaybackCommandManagerRateReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerRateReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerRewindReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs
    {
        MediaPlaybackCommandManagerRewindReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerRewindReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackCommandManagerShuffleReceivedEventArgs : llm:OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs
    {
        MediaPlaybackCommandManagerShuffleReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackCommandManagerShuffleReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackItem : llm:OS::Media::Playback::IMediaPlaybackItem,
        impl::require<MediaPlaybackItem, llm:OS::Media::Playback::IMediaPlaybackItem2, llm:OS::Media::Playback::IMediaPlaybackItem3>
    {
        MediaPlaybackItem(std::nullptr_t) noexcept {}
        MediaPlaybackItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackItem(ptr, take_ownership_from_abi) {}
        explicit MediaPlaybackItem(llm:OS::Media::Core::MediaSource const& source);
        MediaPlaybackItem(llm:OS::Media::Core::MediaSource const& source, llm:OS::Foundation::TimeSpan const& startTime);
        MediaPlaybackItem(llm:OS::Media::Core::MediaSource const& source, llm:OS::Foundation::TimeSpan const& startTime, llm:OS::Foundation::TimeSpan const& durationLimit);
        static auto FindFromMediaSource(llm:OS::Media::Core::MediaSource const& source);
    };
    struct __declspec(empty_bases) MediaPlaybackItemError : llm:OS::Media::Playback::IMediaPlaybackItemError
    {
        MediaPlaybackItemError(std::nullptr_t) noexcept {}
        MediaPlaybackItemError(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackItemError(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackItemFailedEventArgs : llm:OS::Media::Playback::IMediaPlaybackItemFailedEventArgs
    {
        MediaPlaybackItemFailedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackItemFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackItemFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackItemOpenedEventArgs : llm:OS::Media::Playback::IMediaPlaybackItemOpenedEventArgs
    {
        MediaPlaybackItemOpenedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackItemOpenedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackItemOpenedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackList : llm:OS::Media::Playback::IMediaPlaybackList,
        impl::require<MediaPlaybackList, llm:OS::Media::Playback::IMediaPlaybackList2, llm:OS::Media::Playback::IMediaPlaybackList3>
    {
        MediaPlaybackList(std::nullptr_t) noexcept {}
        MediaPlaybackList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackList(ptr, take_ownership_from_abi) {}
        MediaPlaybackList();
    };
    struct __declspec(empty_bases) MediaPlaybackSession : llm:OS::Media::Playback::IMediaPlaybackSession,
        impl::require<MediaPlaybackSession, llm:OS::Media::Playback::IMediaPlaybackSession2, llm:OS::Media::Playback::IMediaPlaybackSession3>
    {
        MediaPlaybackSession(std::nullptr_t) noexcept {}
        MediaPlaybackSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackSessionBufferingStartedEventArgs : llm:OS::Media::Playback::IMediaPlaybackSessionBufferingStartedEventArgs
    {
        MediaPlaybackSessionBufferingStartedEventArgs(std::nullptr_t) noexcept {}
        MediaPlaybackSessionBufferingStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackSessionBufferingStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackSessionOutputDegradationPolicyState : llm:OS::Media::Playback::IMediaPlaybackSessionOutputDegradationPolicyState
    {
        MediaPlaybackSessionOutputDegradationPolicyState(std::nullptr_t) noexcept {}
        MediaPlaybackSessionOutputDegradationPolicyState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackSessionOutputDegradationPolicyState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackSphericalVideoProjection : llm:OS::Media::Playback::IMediaPlaybackSphericalVideoProjection
    {
        MediaPlaybackSphericalVideoProjection(std::nullptr_t) noexcept {}
        MediaPlaybackSphericalVideoProjection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlaybackSphericalVideoProjection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackTimedMetadataTrackList : llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Core::TimedMetadataTrack>,
        impl::require<MediaPlaybackTimedMetadataTrackList, llm:OS::Media::Playback::IMediaPlaybackTimedMetadataTrackList>
    {
        MediaPlaybackTimedMetadataTrackList(std::nullptr_t) noexcept {}
        MediaPlaybackTimedMetadataTrackList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Core::TimedMetadataTrack>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlaybackVideoTrackList : llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Core::VideoTrack>,
        impl::require<MediaPlaybackVideoTrackList, llm:OS::Media::Core::ISingleSelectMediaTrackList>
    {
        MediaPlaybackVideoTrackList(std::nullptr_t) noexcept {}
        MediaPlaybackVideoTrackList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Core::VideoTrack>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlayer : llm:OS::Media::Playback::IMediaPlayer,
        impl::require<MediaPlayer, llm:OS::Media::Playback::IMediaPlayerSource, llm:OS::Media::Playback::IMediaPlayerSource2, llm:OS::Media::Playback::IMediaPlayer2, llm:OS::Media::Playback::IMediaPlayerEffects, llm:OS::Foundation::IClosable, llm:OS::Media::Playback::IMediaPlayer3, llm:OS::Media::Playback::IMediaPlayer4, llm:OS::Media::Playback::IMediaPlayerEffects2, llm:OS::Media::Playback::IMediaPlayer5, llm:OS::Media::Playback::IMediaPlayer6, llm:OS::Media::Playback::IMediaPlayer7>
    {
        MediaPlayer(std::nullptr_t) noexcept {}
        MediaPlayer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlayer(ptr, take_ownership_from_abi) {}
        MediaPlayer();
    };
    struct __declspec(empty_bases) MediaPlayerDataReceivedEventArgs : llm:OS::Media::Playback::IMediaPlayerDataReceivedEventArgs
    {
        MediaPlayerDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MediaPlayerDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlayerDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlayerFailedEventArgs : llm:OS::Media::Playback::IMediaPlayerFailedEventArgs
    {
        MediaPlayerFailedEventArgs(std::nullptr_t) noexcept {}
        MediaPlayerFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlayerFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlayerRateChangedEventArgs : llm:OS::Media::Playback::IMediaPlayerRateChangedEventArgs
    {
        MediaPlayerRateChangedEventArgs(std::nullptr_t) noexcept {}
        MediaPlayerRateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlayerRateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPlayerSurface : llm:OS::Media::Playback::IMediaPlayerSurface,
        impl::require<MediaPlayerSurface, llm:OS::Foundation::IClosable>
    {
        MediaPlayerSurface(std::nullptr_t) noexcept {}
        MediaPlayerSurface(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IMediaPlayerSurface(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlaybackMediaMarker : llm:OS::Media::Playback::IPlaybackMediaMarker
    {
        PlaybackMediaMarker(std::nullptr_t) noexcept {}
        PlaybackMediaMarker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IPlaybackMediaMarker(ptr, take_ownership_from_abi) {}
        explicit PlaybackMediaMarker(llm:OS::Foundation::TimeSpan const& value);
        PlaybackMediaMarker(llm:OS::Foundation::TimeSpan const& value, param::hstring const& mediaMarketType, param::hstring const& text);
    };
    struct __declspec(empty_bases) PlaybackMediaMarkerReachedEventArgs : llm:OS::Media::Playback::IPlaybackMediaMarkerReachedEventArgs
    {
        PlaybackMediaMarkerReachedEventArgs(std::nullptr_t) noexcept {}
        PlaybackMediaMarkerReachedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IPlaybackMediaMarkerReachedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlaybackMediaMarkerSequence : llm:OS::Media::Playback::IPlaybackMediaMarkerSequence
    {
        PlaybackMediaMarkerSequence(std::nullptr_t) noexcept {}
        PlaybackMediaMarkerSequence(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::IPlaybackMediaMarkerSequence(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TimedMetadataPresentationModeChangedEventArgs : llm:OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs
    {
        TimedMetadataPresentationModeChangedEventArgs(std::nullptr_t) noexcept {}
        TimedMetadataPresentationModeChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
