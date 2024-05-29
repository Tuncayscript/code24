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
#ifndef LLM_OS_Devices_Midi_2_H
#define LLM_OS_Devices_Midi_2_H
#include "llm/impl/Windows.Devices.Enumeration.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.Midi.1.h"
LLM_EXPORT namespace llm::OS::Devices::Midi
{
    struct __declspec(empty_bases) MidiActiveSensingMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiActiveSensingMessage(std::nullptr_t) noexcept {}
        MidiActiveSensingMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        MidiActiveSensingMessage();
    };
    struct __declspec(empty_bases) MidiChannelPressureMessage : llm::OS::Devices::Midi::IMidiChannelPressureMessage
    {
        MidiChannelPressureMessage(std::nullptr_t) noexcept {}
        MidiChannelPressureMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiChannelPressureMessage(ptr, take_ownership_from_abi) {}
        MidiChannelPressureMessage(uint8_t channel, uint8_t pressure);
    };
    struct __declspec(empty_bases) MidiContinueMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiContinueMessage(std::nullptr_t) noexcept {}
        MidiContinueMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        MidiContinueMessage();
    };
    struct __declspec(empty_bases) MidiControlChangeMessage : llm::OS::Devices::Midi::IMidiControlChangeMessage
    {
        MidiControlChangeMessage(std::nullptr_t) noexcept {}
        MidiControlChangeMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiControlChangeMessage(ptr, take_ownership_from_abi) {}
        MidiControlChangeMessage(uint8_t channel, uint8_t controller, uint8_t controlValue);
    };
    struct __declspec(empty_bases) MidiInPort : llm::OS::Devices::Midi::IMidiInPort
    {
        MidiInPort(std::nullptr_t) noexcept {}
        MidiInPort(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiInPort(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
    };
    struct __declspec(empty_bases) MidiMessageReceivedEventArgs : llm::OS::Devices::Midi::IMidiMessageReceivedEventArgs
    {
        MidiMessageReceivedEventArgs(std::nullptr_t) noexcept {}
        MidiMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessageReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MidiNoteOffMessage : llm::OS::Devices::Midi::IMidiNoteOffMessage
    {
        MidiNoteOffMessage(std::nullptr_t) noexcept {}
        MidiNoteOffMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiNoteOffMessage(ptr, take_ownership_from_abi) {}
        MidiNoteOffMessage(uint8_t channel, uint8_t note, uint8_t velocity);
    };
    struct __declspec(empty_bases) MidiNoteOnMessage : llm::OS::Devices::Midi::IMidiNoteOnMessage
    {
        MidiNoteOnMessage(std::nullptr_t) noexcept {}
        MidiNoteOnMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiNoteOnMessage(ptr, take_ownership_from_abi) {}
        MidiNoteOnMessage(uint8_t channel, uint8_t note, uint8_t velocity);
    };
    struct __declspec(empty_bases) MidiOutPort : llm::OS::Devices::Midi::IMidiOutPort
    {
        MidiOutPort(std::nullptr_t) noexcept {}
        MidiOutPort(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiOutPort(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
    };
    struct __declspec(empty_bases) MidiPitchBendChangeMessage : llm::OS::Devices::Midi::IMidiPitchBendChangeMessage
    {
        MidiPitchBendChangeMessage(std::nullptr_t) noexcept {}
        MidiPitchBendChangeMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiPitchBendChangeMessage(ptr, take_ownership_from_abi) {}
        MidiPitchBendChangeMessage(uint8_t channel, uint16_t bend);
    };
    struct __declspec(empty_bases) MidiPolyphonicKeyPressureMessage : llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage
    {
        MidiPolyphonicKeyPressureMessage(std::nullptr_t) noexcept {}
        MidiPolyphonicKeyPressureMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage(ptr, take_ownership_from_abi) {}
        MidiPolyphonicKeyPressureMessage(uint8_t channel, uint8_t note, uint8_t pressure);
    };
    struct __declspec(empty_bases) MidiProgramChangeMessage : llm::OS::Devices::Midi::IMidiProgramChangeMessage
    {
        MidiProgramChangeMessage(std::nullptr_t) noexcept {}
        MidiProgramChangeMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiProgramChangeMessage(ptr, take_ownership_from_abi) {}
        MidiProgramChangeMessage(uint8_t channel, uint8_t program);
    };
    struct __declspec(empty_bases) MidiSongPositionPointerMessage : llm::OS::Devices::Midi::IMidiSongPositionPointerMessage
    {
        MidiSongPositionPointerMessage(std::nullptr_t) noexcept {}
        MidiSongPositionPointerMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiSongPositionPointerMessage(ptr, take_ownership_from_abi) {}
        explicit MidiSongPositionPointerMessage(uint16_t beats);
    };
    struct __declspec(empty_bases) MidiSongSelectMessage : llm::OS::Devices::Midi::IMidiSongSelectMessage
    {
        MidiSongSelectMessage(std::nullptr_t) noexcept {}
        MidiSongSelectMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiSongSelectMessage(ptr, take_ownership_from_abi) {}
        explicit MidiSongSelectMessage(uint8_t song);
    };
    struct __declspec(empty_bases) MidiStartMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiStartMessage(std::nullptr_t) noexcept {}
        MidiStartMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        MidiStartMessage();
    };
    struct __declspec(empty_bases) MidiStopMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiStopMessage(std::nullptr_t) noexcept {}
        MidiStopMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        MidiStopMessage();
    };
    struct __declspec(empty_bases) MidiSynthesizer : llm::OS::Devices::Midi::IMidiSynthesizer
    {
        MidiSynthesizer(std::nullptr_t) noexcept {}
        MidiSynthesizer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiSynthesizer(ptr, take_ownership_from_abi) {}
        static auto CreateAsync();
        static auto CreateAsync(llm::OS::Devices::Enumeration::DeviceInformation const& audioDevice);
        static auto IsSynthesizer(llm::OS::Devices::Enumeration::DeviceInformation const& midiDevice);
    };
    struct __declspec(empty_bases) MidiSystemExclusiveMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiSystemExclusiveMessage(std::nullptr_t) noexcept {}
        MidiSystemExclusiveMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        explicit MidiSystemExclusiveMessage(llm::OS::Storage::Streams::IBuffer const& rawData);
    };
    struct __declspec(empty_bases) MidiSystemResetMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiSystemResetMessage(std::nullptr_t) noexcept {}
        MidiSystemResetMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        MidiSystemResetMessage();
    };
    struct __declspec(empty_bases) MidiTimeCodeMessage : llm::OS::Devices::Midi::IMidiTimeCodeMessage
    {
        MidiTimeCodeMessage(std::nullptr_t) noexcept {}
        MidiTimeCodeMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiTimeCodeMessage(ptr, take_ownership_from_abi) {}
        MidiTimeCodeMessage(uint8_t frameType, uint8_t values);
    };
    struct __declspec(empty_bases) MidiTimingClockMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiTimingClockMessage(std::nullptr_t) noexcept {}
        MidiTimingClockMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        MidiTimingClockMessage();
    };
    struct __declspec(empty_bases) MidiTuneRequestMessage : llm::OS::Devices::Midi::IMidiMessage
    {
        MidiTuneRequestMessage(std::nullptr_t) noexcept {}
        MidiTuneRequestMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Midi::IMidiMessage(ptr, take_ownership_from_abi) {}
        MidiTuneRequestMessage();
    };
}
#endif
