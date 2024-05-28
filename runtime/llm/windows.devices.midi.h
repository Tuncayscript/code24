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
#ifndef LLM_OS_Devices_Midi_H
#define LLM_OS_Devices_Midi_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.Midi.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiChannelPressureMessage<D>::Channel() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiChannelPressureMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiChannelPressureMessage<D>::Pressure() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiChannelPressureMessage)->get_Pressure(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiChannelPressureMessage) consume_Windows_Devices_Midi_IMidiChannelPressureMessageFactory<D>::CreateMidiChannelPressureMessage(uint8_t channel, uint8_t pressure) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiChannelPressureMessageFactory)->CreateMidiChannelPressureMessage(channel, pressure, &value));
        return llm::OS::Devices::Midi::MidiChannelPressureMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiControlChangeMessage<D>::Channel() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiControlChangeMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiControlChangeMessage<D>::Controller() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiControlChangeMessage)->get_Controller(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiControlChangeMessage<D>::ControlValue() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiControlChangeMessage)->get_ControlValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiControlChangeMessage) consume_Windows_Devices_Midi_IMidiControlChangeMessageFactory<D>::CreateMidiControlChangeMessage(uint8_t channel, uint8_t controller, uint8_t controlValue) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiControlChangeMessageFactory)->CreateMidiControlChangeMessage(channel, controller, controlValue, &value));
        return llm::OS::Devices::Midi::MidiControlChangeMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Midi_IMidiInPort<D>::MessageReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Midi::MidiInPort, llm::OS::Devices::Midi::MidiMessageReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiInPort)->add_MessageReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Midi_IMidiInPort<D>::MessageReceived_revoker consume_Windows_Devices_Midi_IMidiInPort<D>::MessageReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Midi::MidiInPort, llm::OS::Devices::Midi::MidiMessageReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, MessageReceived_revoker>(this, MessageReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Midi_IMidiInPort<D>::MessageReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiInPort)->remove_MessageReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Midi_IMidiInPort<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiInPort)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiInPort>) consume_Windows_Devices_Midi_IMidiInPortStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiInPortStatics)->FromIdAsync(*(void**)(&deviceId), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiInPort>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Midi_IMidiInPortStatics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiInPortStatics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Midi_IMidiMessage<D>::Timestamp() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiMessage)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_Midi_IMidiMessage<D>::RawData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiMessage)->get_RawData(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiMessageType) consume_Windows_Devices_Midi_IMidiMessage<D>::Type() const
    {
        llm::OS::Devices::Midi::MidiMessageType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiMessage)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::IMidiMessage) consume_Windows_Devices_Midi_IMidiMessageReceivedEventArgs<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiMessageReceivedEventArgs)->get_Message(&value));
        return llm::OS::Devices::Midi::IMidiMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiNoteOffMessage<D>::Channel() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOffMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiNoteOffMessage<D>::Note() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOffMessage)->get_Note(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiNoteOffMessage<D>::Velocity() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOffMessage)->get_Velocity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiNoteOffMessage) consume_Windows_Devices_Midi_IMidiNoteOffMessageFactory<D>::CreateMidiNoteOffMessage(uint8_t channel, uint8_t note, uint8_t velocity) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOffMessageFactory)->CreateMidiNoteOffMessage(channel, note, velocity, &value));
        return llm::OS::Devices::Midi::MidiNoteOffMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiNoteOnMessage<D>::Channel() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOnMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiNoteOnMessage<D>::Note() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOnMessage)->get_Note(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiNoteOnMessage<D>::Velocity() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOnMessage)->get_Velocity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiNoteOnMessage) consume_Windows_Devices_Midi_IMidiNoteOnMessageFactory<D>::CreateMidiNoteOnMessage(uint8_t channel, uint8_t note, uint8_t velocity) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiNoteOnMessageFactory)->CreateMidiNoteOnMessage(channel, note, velocity, &value));
        return llm::OS::Devices::Midi::MidiNoteOnMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Midi_IMidiOutPort<D>::SendMessage(llm::OS::Devices::Midi::IMidiMessage const& midiMessage) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiOutPort)->SendMessage(*(void**)(&midiMessage)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Midi_IMidiOutPort<D>::SendBuffer(llm::OS::Storage::Streams::IBuffer const& midiData) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiOutPort)->SendBuffer(*(void**)(&midiData)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Midi_IMidiOutPort<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiOutPort)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::IMidiOutPort>) consume_Windows_Devices_Midi_IMidiOutPortStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiOutPortStatics)->FromIdAsync(*(void**)(&deviceId), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::IMidiOutPort>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Midi_IMidiOutPortStatics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiOutPortStatics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiPitchBendChangeMessage<D>::Channel() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiPitchBendChangeMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Midi_IMidiPitchBendChangeMessage<D>::Bend() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiPitchBendChangeMessage)->get_Bend(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiPitchBendChangeMessage) consume_Windows_Devices_Midi_IMidiPitchBendChangeMessageFactory<D>::CreateMidiPitchBendChangeMessage(uint8_t channel, uint16_t bend) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiPitchBendChangeMessageFactory)->CreateMidiPitchBendChangeMessage(channel, bend, &value));
        return llm::OS::Devices::Midi::MidiPitchBendChangeMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiPolyphonicKeyPressureMessage<D>::Channel() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiPolyphonicKeyPressureMessage<D>::Note() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage)->get_Note(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiPolyphonicKeyPressureMessage<D>::Pressure() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage)->get_Pressure(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiPolyphonicKeyPressureMessage) consume_Windows_Devices_Midi_IMidiPolyphonicKeyPressureMessageFactory<D>::CreateMidiPolyphonicKeyPressureMessage(uint8_t channel, uint8_t note, uint8_t pressure) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory)->CreateMidiPolyphonicKeyPressureMessage(channel, note, pressure, &value));
        return llm::OS::Devices::Midi::MidiPolyphonicKeyPressureMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiProgramChangeMessage<D>::Channel() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiProgramChangeMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiProgramChangeMessage<D>::Program() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiProgramChangeMessage)->get_Program(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiProgramChangeMessage) consume_Windows_Devices_Midi_IMidiProgramChangeMessageFactory<D>::CreateMidiProgramChangeMessage(uint8_t channel, uint8_t program) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiProgramChangeMessageFactory)->CreateMidiProgramChangeMessage(channel, program, &value));
        return llm::OS::Devices::Midi::MidiProgramChangeMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Midi_IMidiSongPositionPointerMessage<D>::Beats() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSongPositionPointerMessage)->get_Beats(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiSongPositionPointerMessage) consume_Windows_Devices_Midi_IMidiSongPositionPointerMessageFactory<D>::CreateMidiSongPositionPointerMessage(uint16_t beats) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSongPositionPointerMessageFactory)->CreateMidiSongPositionPointerMessage(beats, &value));
        return llm::OS::Devices::Midi::MidiSongPositionPointerMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiSongSelectMessage<D>::Song() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSongSelectMessage)->get_Song(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiSongSelectMessage) consume_Windows_Devices_Midi_IMidiSongSelectMessageFactory<D>::CreateMidiSongSelectMessage(uint8_t song) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSongSelectMessageFactory)->CreateMidiSongSelectMessage(song, &value));
        return llm::OS::Devices::Midi::MidiSongSelectMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Devices_Midi_IMidiSynthesizer<D>::AudioDevice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSynthesizer)->get_AudioDevice(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Midi_IMidiSynthesizer<D>::Volume() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSynthesizer)->get_Volume(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Midi_IMidiSynthesizer<D>::Volume(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSynthesizer)->put_Volume(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiSynthesizer>) consume_Windows_Devices_Midi_IMidiSynthesizerStatics<D>::CreateAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSynthesizerStatics)->CreateAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiSynthesizer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiSynthesizer>) consume_Windows_Devices_Midi_IMidiSynthesizerStatics<D>::CreateAsync(llm::OS::Devices::Enumeration::DeviceInformation const& audioDevice) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSynthesizerStatics)->CreateFromAudioDeviceAsync(*(void**)(&audioDevice), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiSynthesizer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Midi_IMidiSynthesizerStatics<D>::IsSynthesizer(llm::OS::Devices::Enumeration::DeviceInformation const& midiDevice) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSynthesizerStatics)->IsSynthesizer(*(void**)(&midiDevice), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiSystemExclusiveMessage) consume_Windows_Devices_Midi_IMidiSystemExclusiveMessageFactory<D>::CreateMidiSystemExclusiveMessage(llm::OS::Storage::Streams::IBuffer const& rawData) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiSystemExclusiveMessageFactory)->CreateMidiSystemExclusiveMessage(*(void**)(&rawData), &value));
        return llm::OS::Devices::Midi::MidiSystemExclusiveMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiTimeCodeMessage<D>::FrameType() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiTimeCodeMessage)->get_FrameType(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_Midi_IMidiTimeCodeMessage<D>::Values() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiTimeCodeMessage)->get_Values(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Midi::MidiTimeCodeMessage) consume_Windows_Devices_Midi_IMidiTimeCodeMessageFactory<D>::CreateMidiTimeCodeMessage(uint8_t frameType, uint8_t values) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Midi::IMidiTimeCodeMessageFactory)->CreateMidiTimeCodeMessage(frameType, values, &value));
        return llm::OS::Devices::Midi::MidiTimeCodeMessage{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiChannelPressureMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiChannelPressureMessage>
    {
        int32_t __stdcall get_Channel(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Pressure(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Pressure());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiChannelPressureMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiChannelPressureMessageFactory>
    {
        int32_t __stdcall CreateMidiChannelPressureMessage(uint8_t channel, uint8_t pressure, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiChannelPressureMessage>(this->shim().CreateMidiChannelPressureMessage(channel, pressure));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiControlChangeMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiControlChangeMessage>
    {
        int32_t __stdcall get_Channel(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Controller(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Controller());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ControlValue(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().ControlValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiControlChangeMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiControlChangeMessageFactory>
    {
        int32_t __stdcall CreateMidiControlChangeMessage(uint8_t channel, uint8_t controller, uint8_t controlValue, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiControlChangeMessage>(this->shim().CreateMidiControlChangeMessage(channel, controller, controlValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiInPort> : produce_base<D, llm::OS::Devices::Midi::IMidiInPort>
    {
        int32_t __stdcall add_MessageReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MessageReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Midi::MidiInPort, llm::OS::Devices::Midi::MidiMessageReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MessageReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiInPortStatics> : produce_base<D, llm::OS::Devices::Midi::IMidiInPortStatics>
    {
        int32_t __stdcall FromIdAsync(void* deviceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiInPort>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiMessage>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().RawData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiMessageType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiMessageReceivedEventArgs> : produce_base<D, llm::OS::Devices::Midi::IMidiMessageReceivedEventArgs>
    {
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::IMidiMessage>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiNoteOffMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiNoteOffMessage>
    {
        int32_t __stdcall get_Channel(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Note(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Note());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Velocity(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Velocity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiNoteOffMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiNoteOffMessageFactory>
    {
        int32_t __stdcall CreateMidiNoteOffMessage(uint8_t channel, uint8_t note, uint8_t velocity, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiNoteOffMessage>(this->shim().CreateMidiNoteOffMessage(channel, note, velocity));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiNoteOnMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiNoteOnMessage>
    {
        int32_t __stdcall get_Channel(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Note(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Note());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Velocity(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Velocity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiNoteOnMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiNoteOnMessageFactory>
    {
        int32_t __stdcall CreateMidiNoteOnMessage(uint8_t channel, uint8_t note, uint8_t velocity, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiNoteOnMessage>(this->shim().CreateMidiNoteOnMessage(channel, note, velocity));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiOutPort> : produce_base<D, llm::OS::Devices::Midi::IMidiOutPort>
    {
        int32_t __stdcall SendMessage(void* midiMessage) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendMessage(*reinterpret_cast<llm::OS::Devices::Midi::IMidiMessage const*>(&midiMessage));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendBuffer(void* midiData) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&midiData));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiOutPortStatics> : produce_base<D, llm::OS::Devices::Midi::IMidiOutPortStatics>
    {
        int32_t __stdcall FromIdAsync(void* deviceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::IMidiOutPort>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiPitchBendChangeMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiPitchBendChangeMessage>
    {
        int32_t __stdcall get_Channel(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bend(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().Bend());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiPitchBendChangeMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiPitchBendChangeMessageFactory>
    {
        int32_t __stdcall CreateMidiPitchBendChangeMessage(uint8_t channel, uint16_t bend, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiPitchBendChangeMessage>(this->shim().CreateMidiPitchBendChangeMessage(channel, bend));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage>
    {
        int32_t __stdcall get_Channel(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Note(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Note());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Pressure(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Pressure());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory>
    {
        int32_t __stdcall CreateMidiPolyphonicKeyPressureMessage(uint8_t channel, uint8_t note, uint8_t pressure, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiPolyphonicKeyPressureMessage>(this->shim().CreateMidiPolyphonicKeyPressureMessage(channel, note, pressure));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiProgramChangeMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiProgramChangeMessage>
    {
        int32_t __stdcall get_Channel(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Program(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Program());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiProgramChangeMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiProgramChangeMessageFactory>
    {
        int32_t __stdcall CreateMidiProgramChangeMessage(uint8_t channel, uint8_t program, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiProgramChangeMessage>(this->shim().CreateMidiProgramChangeMessage(channel, program));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiSongPositionPointerMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiSongPositionPointerMessage>
    {
        int32_t __stdcall get_Beats(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().Beats());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiSongPositionPointerMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiSongPositionPointerMessageFactory>
    {
        int32_t __stdcall CreateMidiSongPositionPointerMessage(uint16_t beats, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiSongPositionPointerMessage>(this->shim().CreateMidiSongPositionPointerMessage(beats));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiSongSelectMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiSongSelectMessage>
    {
        int32_t __stdcall get_Song(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Song());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiSongSelectMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiSongSelectMessageFactory>
    {
        int32_t __stdcall CreateMidiSongSelectMessage(uint8_t song, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiSongSelectMessage>(this->shim().CreateMidiSongSelectMessage(song));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiSynthesizer> : produce_base<D, llm::OS::Devices::Midi::IMidiSynthesizer>
    {
        int32_t __stdcall get_AudioDevice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().AudioDevice());
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiSynthesizerStatics> : produce_base<D, llm::OS::Devices::Midi::IMidiSynthesizerStatics>
    {
        int32_t __stdcall CreateAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiSynthesizer>>(this->shim().CreateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromAudioDeviceAsync(void* audioDevice, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiSynthesizer>>(this->shim().CreateAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&audioDevice)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsSynthesizer(void* midiDevice, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSynthesizer(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&midiDevice)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiSystemExclusiveMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiSystemExclusiveMessageFactory>
    {
        int32_t __stdcall CreateMidiSystemExclusiveMessage(void* rawData, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiSystemExclusiveMessage>(this->shim().CreateMidiSystemExclusiveMessage(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&rawData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiTimeCodeMessage> : produce_base<D, llm::OS::Devices::Midi::IMidiTimeCodeMessage>
    {
        int32_t __stdcall get_FrameType(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().FrameType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Values(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().Values());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Midi::IMidiTimeCodeMessageFactory> : produce_base<D, llm::OS::Devices::Midi::IMidiTimeCodeMessageFactory>
    {
        int32_t __stdcall CreateMidiTimeCodeMessage(uint8_t frameType, uint8_t values, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Midi::MidiTimeCodeMessage>(this->shim().CreateMidiTimeCodeMessage(frameType, values));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Midi
{
    inline MidiActiveSensingMessage::MidiActiveSensingMessage() :
        MidiActiveSensingMessage(impl::call_factory_cast<MidiActiveSensingMessage(*)(llm::OS::Foundation::IActivationFactory const&), MidiActiveSensingMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MidiActiveSensingMessage>(); }))
    {
    }
    inline MidiChannelPressureMessage::MidiChannelPressureMessage(uint8_t channel, uint8_t pressure) :
        MidiChannelPressureMessage(impl::call_factory<MidiChannelPressureMessage, IMidiChannelPressureMessageFactory>([&](IMidiChannelPressureMessageFactory const& f) { return f.CreateMidiChannelPressureMessage(channel, pressure); }))
    {
    }
    inline MidiContinueMessage::MidiContinueMessage() :
        MidiContinueMessage(impl::call_factory_cast<MidiContinueMessage(*)(llm::OS::Foundation::IActivationFactory const&), MidiContinueMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MidiContinueMessage>(); }))
    {
    }
    inline MidiControlChangeMessage::MidiControlChangeMessage(uint8_t channel, uint8_t controller, uint8_t controlValue) :
        MidiControlChangeMessage(impl::call_factory<MidiControlChangeMessage, IMidiControlChangeMessageFactory>([&](IMidiControlChangeMessageFactory const& f) { return f.CreateMidiControlChangeMessage(channel, controller, controlValue); }))
    {
    }
    inline auto MidiInPort::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<MidiInPort, IMidiInPortStatics>([&](IMidiInPortStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto MidiInPort::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IMidiInPortStatics const&), MidiInPort, IMidiInPortStatics>([](IMidiInPortStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline MidiNoteOffMessage::MidiNoteOffMessage(uint8_t channel, uint8_t note, uint8_t velocity) :
        MidiNoteOffMessage(impl::call_factory<MidiNoteOffMessage, IMidiNoteOffMessageFactory>([&](IMidiNoteOffMessageFactory const& f) { return f.CreateMidiNoteOffMessage(channel, note, velocity); }))
    {
    }
    inline MidiNoteOnMessage::MidiNoteOnMessage(uint8_t channel, uint8_t note, uint8_t velocity) :
        MidiNoteOnMessage(impl::call_factory<MidiNoteOnMessage, IMidiNoteOnMessageFactory>([&](IMidiNoteOnMessageFactory const& f) { return f.CreateMidiNoteOnMessage(channel, note, velocity); }))
    {
    }
    inline auto MidiOutPort::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<MidiOutPort, IMidiOutPortStatics>([&](IMidiOutPortStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto MidiOutPort::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IMidiOutPortStatics const&), MidiOutPort, IMidiOutPortStatics>([](IMidiOutPortStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline MidiPitchBendChangeMessage::MidiPitchBendChangeMessage(uint8_t channel, uint16_t bend) :
        MidiPitchBendChangeMessage(impl::call_factory<MidiPitchBendChangeMessage, IMidiPitchBendChangeMessageFactory>([&](IMidiPitchBendChangeMessageFactory const& f) { return f.CreateMidiPitchBendChangeMessage(channel, bend); }))
    {
    }
    inline MidiPolyphonicKeyPressureMessage::MidiPolyphonicKeyPressureMessage(uint8_t channel, uint8_t note, uint8_t pressure) :
        MidiPolyphonicKeyPressureMessage(impl::call_factory<MidiPolyphonicKeyPressureMessage, IMidiPolyphonicKeyPressureMessageFactory>([&](IMidiPolyphonicKeyPressureMessageFactory const& f) { return f.CreateMidiPolyphonicKeyPressureMessage(channel, note, pressure); }))
    {
    }
    inline MidiProgramChangeMessage::MidiProgramChangeMessage(uint8_t channel, uint8_t program) :
        MidiProgramChangeMessage(impl::call_factory<MidiProgramChangeMessage, IMidiProgramChangeMessageFactory>([&](IMidiProgramChangeMessageFactory const& f) { return f.CreateMidiProgramChangeMessage(channel, program); }))
    {
    }
    inline MidiSongPositionPointerMessage::MidiSongPositionPointerMessage(uint16_t beats) :
        MidiSongPositionPointerMessage(impl::call_factory<MidiSongPositionPointerMessage, IMidiSongPositionPointerMessageFactory>([&](IMidiSongPositionPointerMessageFactory const& f) { return f.CreateMidiSongPositionPointerMessage(beats); }))
    {
    }
    inline MidiSongSelectMessage::MidiSongSelectMessage(uint8_t song) :
        MidiSongSelectMessage(impl::call_factory<MidiSongSelectMessage, IMidiSongSelectMessageFactory>([&](IMidiSongSelectMessageFactory const& f) { return f.CreateMidiSongSelectMessage(song); }))
    {
    }
    inline MidiStartMessage::MidiStartMessage() :
        MidiStartMessage(impl::call_factory_cast<MidiStartMessage(*)(llm::OS::Foundation::IActivationFactory const&), MidiStartMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MidiStartMessage>(); }))
    {
    }
    inline MidiStopMessage::MidiStopMessage() :
        MidiStopMessage(impl::call_factory_cast<MidiStopMessage(*)(llm::OS::Foundation::IActivationFactory const&), MidiStopMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MidiStopMessage>(); }))
    {
    }
    inline auto MidiSynthesizer::CreateAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Midi::MidiSynthesizer>(*)(IMidiSynthesizerStatics const&), MidiSynthesizer, IMidiSynthesizerStatics>([](IMidiSynthesizerStatics const& f) { return f.CreateAsync(); });
    }
    inline auto MidiSynthesizer::CreateAsync(llm::OS::Devices::Enumeration::DeviceInformation const& audioDevice)
    {
        return impl::call_factory<MidiSynthesizer, IMidiSynthesizerStatics>([&](IMidiSynthesizerStatics const& f) { return f.CreateAsync(audioDevice); });
    }
    inline auto MidiSynthesizer::IsSynthesizer(llm::OS::Devices::Enumeration::DeviceInformation const& midiDevice)
    {
        return impl::call_factory<MidiSynthesizer, IMidiSynthesizerStatics>([&](IMidiSynthesizerStatics const& f) { return f.IsSynthesizer(midiDevice); });
    }
    inline MidiSystemExclusiveMessage::MidiSystemExclusiveMessage(llm::OS::Storage::Streams::IBuffer const& rawData) :
        MidiSystemExclusiveMessage(impl::call_factory<MidiSystemExclusiveMessage, IMidiSystemExclusiveMessageFactory>([&](IMidiSystemExclusiveMessageFactory const& f) { return f.CreateMidiSystemExclusiveMessage(rawData); }))
    {
    }
    inline MidiSystemResetMessage::MidiSystemResetMessage() :
        MidiSystemResetMessage(impl::call_factory_cast<MidiSystemResetMessage(*)(llm::OS::Foundation::IActivationFactory const&), MidiSystemResetMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MidiSystemResetMessage>(); }))
    {
    }
    inline MidiTimeCodeMessage::MidiTimeCodeMessage(uint8_t frameType, uint8_t values) :
        MidiTimeCodeMessage(impl::call_factory<MidiTimeCodeMessage, IMidiTimeCodeMessageFactory>([&](IMidiTimeCodeMessageFactory const& f) { return f.CreateMidiTimeCodeMessage(frameType, values); }))
    {
    }
    inline MidiTimingClockMessage::MidiTimingClockMessage() :
        MidiTimingClockMessage(impl::call_factory_cast<MidiTimingClockMessage(*)(llm::OS::Foundation::IActivationFactory const&), MidiTimingClockMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MidiTimingClockMessage>(); }))
    {
    }
    inline MidiTuneRequestMessage::MidiTuneRequestMessage() :
        MidiTuneRequestMessage(impl::call_factory_cast<MidiTuneRequestMessage(*)(llm::OS::Foundation::IActivationFactory const&), MidiTuneRequestMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MidiTuneRequestMessage>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Midi::IMidiChannelPressureMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiChannelPressureMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiControlChangeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiControlChangeMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiInPort> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiInPortStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiMessageReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiNoteOffMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiNoteOffMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiNoteOnMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiNoteOnMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiOutPort> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiOutPortStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiPitchBendChangeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiPitchBendChangeMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiProgramChangeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiProgramChangeMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiSongPositionPointerMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiSongPositionPointerMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiSongSelectMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiSongSelectMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiSynthesizer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiSynthesizerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiSystemExclusiveMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiTimeCodeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::IMidiTimeCodeMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiActiveSensingMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiChannelPressureMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiContinueMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiControlChangeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiInPort> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiMessageReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiNoteOffMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiNoteOnMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiOutPort> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiPitchBendChangeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiPolyphonicKeyPressureMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiProgramChangeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiSongPositionPointerMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiSongSelectMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiStartMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiStopMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiSynthesizer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiSystemExclusiveMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiSystemResetMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiTimeCodeMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiTimingClockMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Midi::MidiTuneRequestMessage> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
