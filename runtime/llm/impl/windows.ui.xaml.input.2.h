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
#ifndef LLM_OS_UI_Xaml_Input_2_H
#define LLM_OS_UI_Xaml_Input_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Input.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Input
{
    struct DoubleTappedEventHandler : llm::OS::Foundation::IUnknown
    {
        DoubleTappedEventHandler(std::nullptr_t = nullptr) noexcept {}
        DoubleTappedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DoubleTappedEventHandler(L lambda);
        template <typename F> DoubleTappedEventHandler(F* function);
        template <typename O, typename M> DoubleTappedEventHandler(O* object, M method);
        template <typename O, typename M> DoubleTappedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DoubleTappedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::DoubleTappedRoutedEventArgs const& e) const;
    };
    struct HoldingEventHandler : llm::OS::Foundation::IUnknown
    {
        HoldingEventHandler(std::nullptr_t = nullptr) noexcept {}
        HoldingEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> HoldingEventHandler(L lambda);
        template <typename F> HoldingEventHandler(F* function);
        template <typename O, typename M> HoldingEventHandler(O* object, M method);
        template <typename O, typename M> HoldingEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> HoldingEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::HoldingRoutedEventArgs const& e) const;
    };
    struct KeyEventHandler : llm::OS::Foundation::IUnknown
    {
        KeyEventHandler(std::nullptr_t = nullptr) noexcept {}
        KeyEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> KeyEventHandler(L lambda);
        template <typename F> KeyEventHandler(F* function);
        template <typename O, typename M> KeyEventHandler(O* object, M method);
        template <typename O, typename M> KeyEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> KeyEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::KeyRoutedEventArgs const& e) const;
    };
    struct ManipulationCompletedEventHandler : llm::OS::Foundation::IUnknown
    {
        ManipulationCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
        ManipulationCompletedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ManipulationCompletedEventHandler(L lambda);
        template <typename F> ManipulationCompletedEventHandler(F* function);
        template <typename O, typename M> ManipulationCompletedEventHandler(O* object, M method);
        template <typename O, typename M> ManipulationCompletedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ManipulationCompletedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs const& e) const;
    };
    struct ManipulationDeltaEventHandler : llm::OS::Foundation::IUnknown
    {
        ManipulationDeltaEventHandler(std::nullptr_t = nullptr) noexcept {}
        ManipulationDeltaEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ManipulationDeltaEventHandler(L lambda);
        template <typename F> ManipulationDeltaEventHandler(F* function);
        template <typename O, typename M> ManipulationDeltaEventHandler(O* object, M method);
        template <typename O, typename M> ManipulationDeltaEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ManipulationDeltaEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs const& e) const;
    };
    struct ManipulationInertiaStartingEventHandler : llm::OS::Foundation::IUnknown
    {
        ManipulationInertiaStartingEventHandler(std::nullptr_t = nullptr) noexcept {}
        ManipulationInertiaStartingEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ManipulationInertiaStartingEventHandler(L lambda);
        template <typename F> ManipulationInertiaStartingEventHandler(F* function);
        template <typename O, typename M> ManipulationInertiaStartingEventHandler(O* object, M method);
        template <typename O, typename M> ManipulationInertiaStartingEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ManipulationInertiaStartingEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs const& e) const;
    };
    struct ManipulationStartedEventHandler : llm::OS::Foundation::IUnknown
    {
        ManipulationStartedEventHandler(std::nullptr_t = nullptr) noexcept {}
        ManipulationStartedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ManipulationStartedEventHandler(L lambda);
        template <typename F> ManipulationStartedEventHandler(F* function);
        template <typename O, typename M> ManipulationStartedEventHandler(O* object, M method);
        template <typename O, typename M> ManipulationStartedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ManipulationStartedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::ManipulationStartedRoutedEventArgs const& e) const;
    };
    struct ManipulationStartingEventHandler : llm::OS::Foundation::IUnknown
    {
        ManipulationStartingEventHandler(std::nullptr_t = nullptr) noexcept {}
        ManipulationStartingEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ManipulationStartingEventHandler(L lambda);
        template <typename F> ManipulationStartingEventHandler(F* function);
        template <typename O, typename M> ManipulationStartingEventHandler(O* object, M method);
        template <typename O, typename M> ManipulationStartingEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ManipulationStartingEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::ManipulationStartingRoutedEventArgs const& e) const;
    };
    struct PointerEventHandler : llm::OS::Foundation::IUnknown
    {
        PointerEventHandler(std::nullptr_t = nullptr) noexcept {}
        PointerEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PointerEventHandler(L lambda);
        template <typename F> PointerEventHandler(F* function);
        template <typename O, typename M> PointerEventHandler(O* object, M method);
        template <typename O, typename M> PointerEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> PointerEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::PointerRoutedEventArgs const& e) const;
    };
    struct RightTappedEventHandler : llm::OS::Foundation::IUnknown
    {
        RightTappedEventHandler(std::nullptr_t = nullptr) noexcept {}
        RightTappedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> RightTappedEventHandler(L lambda);
        template <typename F> RightTappedEventHandler(F* function);
        template <typename O, typename M> RightTappedEventHandler(O* object, M method);
        template <typename O, typename M> RightTappedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> RightTappedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::RightTappedRoutedEventArgs const& e) const;
    };
    struct TappedEventHandler : llm::OS::Foundation::IUnknown
    {
        TappedEventHandler(std::nullptr_t = nullptr) noexcept {}
        TappedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> TappedEventHandler(L lambda);
        template <typename F> TappedEventHandler(F* function);
        template <typename O, typename M> TappedEventHandler(O* object, M method);
        template <typename O, typename M> TappedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> TappedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Input::TappedRoutedEventArgs const& e) const;
    };
    struct __declspec(empty_bases) AccessKeyDisplayDismissedEventArgs : llm::OS::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs
    {
        AccessKeyDisplayDismissedEventArgs(std::nullptr_t) noexcept {}
        AccessKeyDisplayDismissedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs(ptr, take_ownership_from_abi) {}
        AccessKeyDisplayDismissedEventArgs();
    };
    struct __declspec(empty_bases) AccessKeyDisplayRequestedEventArgs : llm::OS::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs
    {
        AccessKeyDisplayRequestedEventArgs(std::nullptr_t) noexcept {}
        AccessKeyDisplayRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs(ptr, take_ownership_from_abi) {}
        AccessKeyDisplayRequestedEventArgs();
    };
    struct __declspec(empty_bases) AccessKeyInvokedEventArgs : llm::OS::UI::Xaml::Input::IAccessKeyInvokedEventArgs
    {
        AccessKeyInvokedEventArgs(std::nullptr_t) noexcept {}
        AccessKeyInvokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IAccessKeyInvokedEventArgs(ptr, take_ownership_from_abi) {}
        AccessKeyInvokedEventArgs();
    };
    struct __declspec(empty_bases) AccessKeyManager : llm::OS::UI::Xaml::Input::IAccessKeyManager
    {
        AccessKeyManager(std::nullptr_t) noexcept {}
        AccessKeyManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IAccessKeyManager(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto IsDisplayModeEnabled();
        static auto IsDisplayModeEnabledChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::Foundation::IInspectable> const& handler);
        using IsDisplayModeEnabledChanged_revoker = impl::factory_event_revoker<llm::OS::UI::Xaml::Input::IAccessKeyManagerStatics, &impl::abi_t<llm::OS::UI::Xaml::Input::IAccessKeyManagerStatics>::remove_IsDisplayModeEnabledChanged>;
        [[nodiscard]] static IsDisplayModeEnabledChanged_revoker IsDisplayModeEnabledChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::Foundation::IInspectable> const& handler);
        static auto IsDisplayModeEnabledChanged(llm::event_token const& token);
        static auto ExitDisplayMode();
        [[nodiscard]] static auto AreKeyTipsEnabled();
        static auto AreKeyTipsEnabled(bool value);
    };
    struct __declspec(empty_bases) CanExecuteRequestedEventArgs : llm::OS::UI::Xaml::Input::ICanExecuteRequestedEventArgs
    {
        CanExecuteRequestedEventArgs(std::nullptr_t) noexcept {}
        CanExecuteRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::ICanExecuteRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CharacterReceivedRoutedEventArgs : llm::OS::UI::Xaml::Input::ICharacterReceivedRoutedEventArgs,
        impl::base<CharacterReceivedRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<CharacterReceivedRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        CharacterReceivedRoutedEventArgs(std::nullptr_t) noexcept {}
        CharacterReceivedRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::ICharacterReceivedRoutedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContextRequestedEventArgs : llm::OS::UI::Xaml::Input::IContextRequestedEventArgs,
        impl::base<ContextRequestedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ContextRequestedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ContextRequestedEventArgs(std::nullptr_t) noexcept {}
        ContextRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IContextRequestedEventArgs(ptr, take_ownership_from_abi) {}
        ContextRequestedEventArgs();
    };
    struct __declspec(empty_bases) DoubleTappedRoutedEventArgs : llm::OS::UI::Xaml::Input::IDoubleTappedRoutedEventArgs,
        impl::base<DoubleTappedRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<DoubleTappedRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        DoubleTappedRoutedEventArgs(std::nullptr_t) noexcept {}
        DoubleTappedRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IDoubleTappedRoutedEventArgs(ptr, take_ownership_from_abi) {}
        DoubleTappedRoutedEventArgs();
    };
    struct __declspec(empty_bases) ExecuteRequestedEventArgs : llm::OS::UI::Xaml::Input::IExecuteRequestedEventArgs
    {
        ExecuteRequestedEventArgs(std::nullptr_t) noexcept {}
        ExecuteRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IExecuteRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FindNextElementOptions : llm::OS::UI::Xaml::Input::IFindNextElementOptions
    {
        FindNextElementOptions(std::nullptr_t) noexcept {}
        FindNextElementOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IFindNextElementOptions(ptr, take_ownership_from_abi) {}
        FindNextElementOptions();
    };
    struct __declspec(empty_bases) FocusManager : llm::OS::UI::Xaml::Input::IFocusManager
    {
        FocusManager(std::nullptr_t) noexcept {}
        FocusManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IFocusManager(ptr, take_ownership_from_abi) {}
        static auto GetFocusedElement();
        static auto TryMoveFocus(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection);
        static auto FindNextFocusableElement(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection);
        static auto FindNextFocusableElement(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection, llm::OS::Foundation::Rect const& hintRect);
        static auto TryMoveFocus(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection, llm::OS::UI::Xaml::Input::FindNextElementOptions const& focusNavigationOptions);
        static auto FindNextElement(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection);
        static auto FindFirstFocusableElement(llm::OS::UI::Xaml::DependencyObject const& searchScope);
        static auto FindLastFocusableElement(llm::OS::UI::Xaml::DependencyObject const& searchScope);
        static auto FindNextElement(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection, llm::OS::UI::Xaml::Input::FindNextElementOptions const& focusNavigationOptions);
        static auto TryFocusAsync(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FocusState const& value);
        static auto TryMoveFocusAsync(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection);
        static auto TryMoveFocusAsync(llm::OS::UI::Xaml::Input::FocusNavigationDirection const& focusNavigationDirection, llm::OS::UI::Xaml::Input::FindNextElementOptions const& focusNavigationOptions);
        static auto GotFocus(llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::FocusManagerGotFocusEventArgs> const& handler);
        using GotFocus_revoker = impl::factory_event_revoker<llm::OS::UI::Xaml::Input::IFocusManagerStatics6, &impl::abi_t<llm::OS::UI::Xaml::Input::IFocusManagerStatics6>::remove_GotFocus>;
        [[nodiscard]] static GotFocus_revoker GotFocus(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::FocusManagerGotFocusEventArgs> const& handler);
        static auto GotFocus(llm::event_token const& token);
        static auto LostFocus(llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::FocusManagerLostFocusEventArgs> const& handler);
        using LostFocus_revoker = impl::factory_event_revoker<llm::OS::UI::Xaml::Input::IFocusManagerStatics6, &impl::abi_t<llm::OS::UI::Xaml::Input::IFocusManagerStatics6>::remove_LostFocus>;
        [[nodiscard]] static LostFocus_revoker LostFocus(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::FocusManagerLostFocusEventArgs> const& handler);
        static auto LostFocus(llm::event_token const& token);
        static auto GettingFocus(llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::GettingFocusEventArgs> const& handler);
        using GettingFocus_revoker = impl::factory_event_revoker<llm::OS::UI::Xaml::Input::IFocusManagerStatics6, &impl::abi_t<llm::OS::UI::Xaml::Input::IFocusManagerStatics6>::remove_GettingFocus>;
        [[nodiscard]] static GettingFocus_revoker GettingFocus(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::GettingFocusEventArgs> const& handler);
        static auto GettingFocus(llm::event_token const& token);
        static auto LosingFocus(llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::LosingFocusEventArgs> const& handler);
        using LosingFocus_revoker = impl::factory_event_revoker<llm::OS::UI::Xaml::Input::IFocusManagerStatics6, &impl::abi_t<llm::OS::UI::Xaml::Input::IFocusManagerStatics6>::remove_LosingFocus>;
        [[nodiscard]] static LosingFocus_revoker LosingFocus(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::Xaml::Input::LosingFocusEventArgs> const& handler);
        static auto LosingFocus(llm::event_token const& token);
        static auto GetFocusedElement(llm::OS::UI::Xaml::XamlRoot const& xamlRoot);
    };
    struct __declspec(empty_bases) FocusManagerGotFocusEventArgs : llm::OS::UI::Xaml::Input::IFocusManagerGotFocusEventArgs
    {
        FocusManagerGotFocusEventArgs(std::nullptr_t) noexcept {}
        FocusManagerGotFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IFocusManagerGotFocusEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FocusManagerLostFocusEventArgs : llm::OS::UI::Xaml::Input::IFocusManagerLostFocusEventArgs
    {
        FocusManagerLostFocusEventArgs(std::nullptr_t) noexcept {}
        FocusManagerLostFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IFocusManagerLostFocusEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FocusMovementResult : llm::OS::UI::Xaml::Input::IFocusMovementResult
    {
        FocusMovementResult(std::nullptr_t) noexcept {}
        FocusMovementResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IFocusMovementResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GettingFocusEventArgs : llm::OS::UI::Xaml::Input::IGettingFocusEventArgs,
        impl::base<GettingFocusEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<GettingFocusEventArgs, llm::OS::UI::Xaml::Input::IGettingFocusEventArgs2, llm::OS::UI::Xaml::Input::IGettingFocusEventArgs3, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        GettingFocusEventArgs(std::nullptr_t) noexcept {}
        GettingFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IGettingFocusEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HoldingRoutedEventArgs : llm::OS::UI::Xaml::Input::IHoldingRoutedEventArgs,
        impl::base<HoldingRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<HoldingRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        HoldingRoutedEventArgs(std::nullptr_t) noexcept {}
        HoldingRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IHoldingRoutedEventArgs(ptr, take_ownership_from_abi) {}
        HoldingRoutedEventArgs();
    };
    struct __declspec(empty_bases) InertiaExpansionBehavior : llm::OS::UI::Xaml::Input::IInertiaExpansionBehavior
    {
        InertiaExpansionBehavior(std::nullptr_t) noexcept {}
        InertiaExpansionBehavior(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IInertiaExpansionBehavior(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InertiaRotationBehavior : llm::OS::UI::Xaml::Input::IInertiaRotationBehavior
    {
        InertiaRotationBehavior(std::nullptr_t) noexcept {}
        InertiaRotationBehavior(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IInertiaRotationBehavior(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InertiaTranslationBehavior : llm::OS::UI::Xaml::Input::IInertiaTranslationBehavior
    {
        InertiaTranslationBehavior(std::nullptr_t) noexcept {}
        InertiaTranslationBehavior(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IInertiaTranslationBehavior(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InputScope : llm::OS::UI::Xaml::Input::IInputScope,
        impl::base<InputScope, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<InputScope, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        InputScope(std::nullptr_t) noexcept {}
        InputScope(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IInputScope(ptr, take_ownership_from_abi) {}
        InputScope();
    };
    struct __declspec(empty_bases) InputScopeName : llm::OS::UI::Xaml::Input::IInputScopeName,
        impl::base<InputScopeName, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<InputScopeName, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        InputScopeName(std::nullptr_t) noexcept {}
        InputScopeName(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IInputScopeName(ptr, take_ownership_from_abi) {}
        InputScopeName();
        explicit InputScopeName(llm::OS::UI::Xaml::Input::InputScopeNameValue const& nameValue);
    };
    struct __declspec(empty_bases) KeyRoutedEventArgs : llm::OS::UI::Xaml::Input::IKeyRoutedEventArgs,
        impl::base<KeyRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<KeyRoutedEventArgs, llm::OS::UI::Xaml::Input::IKeyRoutedEventArgs2, llm::OS::UI::Xaml::Input::IKeyRoutedEventArgs3, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        KeyRoutedEventArgs(std::nullptr_t) noexcept {}
        KeyRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IKeyRoutedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) KeyboardAccelerator : llm::OS::UI::Xaml::Input::IKeyboardAccelerator,
        impl::base<KeyboardAccelerator, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<KeyboardAccelerator, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        KeyboardAccelerator(std::nullptr_t) noexcept {}
        KeyboardAccelerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IKeyboardAccelerator(ptr, take_ownership_from_abi) {}
        KeyboardAccelerator();
        [[nodiscard]] static auto KeyProperty();
        [[nodiscard]] static auto ModifiersProperty();
        [[nodiscard]] static auto IsEnabledProperty();
        [[nodiscard]] static auto ScopeOwnerProperty();
    };
    struct __declspec(empty_bases) KeyboardAcceleratorInvokedEventArgs : llm::OS::UI::Xaml::Input::IKeyboardAcceleratorInvokedEventArgs,
        impl::require<KeyboardAcceleratorInvokedEventArgs, llm::OS::UI::Xaml::Input::IKeyboardAcceleratorInvokedEventArgs2>
    {
        KeyboardAcceleratorInvokedEventArgs(std::nullptr_t) noexcept {}
        KeyboardAcceleratorInvokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IKeyboardAcceleratorInvokedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LosingFocusEventArgs : llm::OS::UI::Xaml::Input::ILosingFocusEventArgs,
        impl::base<LosingFocusEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<LosingFocusEventArgs, llm::OS::UI::Xaml::Input::ILosingFocusEventArgs2, llm::OS::UI::Xaml::Input::ILosingFocusEventArgs3, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        LosingFocusEventArgs(std::nullptr_t) noexcept {}
        LosingFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::ILosingFocusEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ManipulationCompletedRoutedEventArgs : llm::OS::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs,
        impl::base<ManipulationCompletedRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ManipulationCompletedRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ManipulationCompletedRoutedEventArgs(std::nullptr_t) noexcept {}
        ManipulationCompletedRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs(ptr, take_ownership_from_abi) {}
        ManipulationCompletedRoutedEventArgs();
    };
    struct __declspec(empty_bases) ManipulationDeltaRoutedEventArgs : llm::OS::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs,
        impl::base<ManipulationDeltaRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ManipulationDeltaRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ManipulationDeltaRoutedEventArgs(std::nullptr_t) noexcept {}
        ManipulationDeltaRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs(ptr, take_ownership_from_abi) {}
        ManipulationDeltaRoutedEventArgs();
    };
    struct __declspec(empty_bases) ManipulationInertiaStartingRoutedEventArgs : llm::OS::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs,
        impl::base<ManipulationInertiaStartingRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ManipulationInertiaStartingRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ManipulationInertiaStartingRoutedEventArgs(std::nullptr_t) noexcept {}
        ManipulationInertiaStartingRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs(ptr, take_ownership_from_abi) {}
        ManipulationInertiaStartingRoutedEventArgs();
    };
    struct __declspec(empty_bases) ManipulationPivot : llm::OS::UI::Xaml::Input::IManipulationPivot
    {
        ManipulationPivot(std::nullptr_t) noexcept {}
        ManipulationPivot(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IManipulationPivot(ptr, take_ownership_from_abi) {}
        ManipulationPivot();
        ManipulationPivot(llm::OS::Foundation::Point const& center, double radius);
    };
    struct __declspec(empty_bases) ManipulationStartedRoutedEventArgs : llm::OS::UI::Xaml::Input::IManipulationStartedRoutedEventArgs,
        impl::base<ManipulationStartedRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ManipulationStartedRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ManipulationStartedRoutedEventArgs(std::nullptr_t) noexcept {}
        ManipulationStartedRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IManipulationStartedRoutedEventArgs(ptr, take_ownership_from_abi) {}
        ManipulationStartedRoutedEventArgs();
    };
    struct __declspec(empty_bases) ManipulationStartingRoutedEventArgs : llm::OS::UI::Xaml::Input::IManipulationStartingRoutedEventArgs,
        impl::base<ManipulationStartingRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ManipulationStartingRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ManipulationStartingRoutedEventArgs(std::nullptr_t) noexcept {}
        ManipulationStartingRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IManipulationStartingRoutedEventArgs(ptr, take_ownership_from_abi) {}
        ManipulationStartingRoutedEventArgs();
    };
    struct __declspec(empty_bases) NoFocusCandidateFoundEventArgs : llm::OS::UI::Xaml::Input::INoFocusCandidateFoundEventArgs,
        impl::base<NoFocusCandidateFoundEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<NoFocusCandidateFoundEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        NoFocusCandidateFoundEventArgs(std::nullptr_t) noexcept {}
        NoFocusCandidateFoundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::INoFocusCandidateFoundEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Pointer : llm::OS::UI::Xaml::Input::IPointer
    {
        Pointer(std::nullptr_t) noexcept {}
        Pointer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IPointer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PointerRoutedEventArgs : llm::OS::UI::Xaml::Input::IPointerRoutedEventArgs,
        impl::base<PointerRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<PointerRoutedEventArgs, llm::OS::UI::Xaml::Input::IPointerRoutedEventArgs2, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        PointerRoutedEventArgs(std::nullptr_t) noexcept {}
        PointerRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IPointerRoutedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessKeyboardAcceleratorEventArgs : llm::OS::UI::Xaml::Input::IProcessKeyboardAcceleratorEventArgs
    {
        ProcessKeyboardAcceleratorEventArgs(std::nullptr_t) noexcept {}
        ProcessKeyboardAcceleratorEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IProcessKeyboardAcceleratorEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RightTappedRoutedEventArgs : llm::OS::UI::Xaml::Input::IRightTappedRoutedEventArgs,
        impl::base<RightTappedRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<RightTappedRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        RightTappedRoutedEventArgs(std::nullptr_t) noexcept {}
        RightTappedRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IRightTappedRoutedEventArgs(ptr, take_ownership_from_abi) {}
        RightTappedRoutedEventArgs();
    };
    struct __declspec(empty_bases) StandardUICommand : llm::OS::UI::Xaml::Input::IStandardUICommand,
        impl::base<StandardUICommand, llm::OS::UI::Xaml::Input::XamlUICommand, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<StandardUICommand, llm::OS::UI::Xaml::Input::IStandardUICommand2, llm::OS::UI::Xaml::Input::IXamlUICommand, llm::OS::UI::Xaml::Input::ICommand, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        StandardUICommand(std::nullptr_t) noexcept {}
        StandardUICommand(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IStandardUICommand(ptr, take_ownership_from_abi) {}
        StandardUICommand();
        explicit StandardUICommand(llm::OS::UI::Xaml::Input::StandardUICommandKind const& kind);
        using llm::OS::UI::Xaml::Input::IStandardUICommand::Kind;
        using impl::consume_t<StandardUICommand, llm::OS::UI::Xaml::Input::IStandardUICommand2>::Kind;
        [[nodiscard]] static auto KindProperty();
    };
    struct __declspec(empty_bases) TappedRoutedEventArgs : llm::OS::UI::Xaml::Input::ITappedRoutedEventArgs,
        impl::base<TappedRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<TappedRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        TappedRoutedEventArgs(std::nullptr_t) noexcept {}
        TappedRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::ITappedRoutedEventArgs(ptr, take_ownership_from_abi) {}
        TappedRoutedEventArgs();
    };
    struct __declspec(empty_bases) XamlUICommand : llm::OS::UI::Xaml::Input::IXamlUICommand,
        impl::base<XamlUICommand, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<XamlUICommand, llm::OS::UI::Xaml::Input::ICommand, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        XamlUICommand(std::nullptr_t) noexcept {}
        XamlUICommand(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Input::IXamlUICommand(ptr, take_ownership_from_abi) {}
        XamlUICommand();
        [[nodiscard]] static auto LabelProperty();
        [[nodiscard]] static auto IconSourceProperty();
        [[nodiscard]] static auto KeyboardAcceleratorsProperty();
        [[nodiscard]] static auto AccessKeyProperty();
        [[nodiscard]] static auto DescriptionProperty();
        [[nodiscard]] static auto CommandProperty();
    };
}
#endif
