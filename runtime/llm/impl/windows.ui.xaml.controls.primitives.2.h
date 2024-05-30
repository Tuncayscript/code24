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
#ifndef LLM_OS_UI_Xaml_Controls_Primitives_2_H
#define LLM_OS_UI_Xaml_Controls_Primitives_2_H
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Controls.1.h"
#include "llm/impl/Windows.UI.Xaml.Data.1.h"
#include "llm/impl/Windows.UI.Xaml.Input.1.h"
#include "llm/impl/Windows.UI.Xaml.Controls.Primitives.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Controls::Primitives
{
    struct DragCompletedEventHandler : llm::OS::Foundation::IUnknown
    {
        DragCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
        DragCompletedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DragCompletedEventHandler(L lambda);
        template <typename F> DragCompletedEventHandler(F* function);
        template <typename O, typename M> DragCompletedEventHandler(O* object, M method);
        template <typename O, typename M> DragCompletedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DragCompletedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Controls::Primitives::DragCompletedEventArgs const& e) const;
    };
    struct DragDeltaEventHandler : llm::OS::Foundation::IUnknown
    {
        DragDeltaEventHandler(std::nullptr_t = nullptr) noexcept {}
        DragDeltaEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DragDeltaEventHandler(L lambda);
        template <typename F> DragDeltaEventHandler(F* function);
        template <typename O, typename M> DragDeltaEventHandler(O* object, M method);
        template <typename O, typename M> DragDeltaEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DragDeltaEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Controls::Primitives::DragDeltaEventArgs const& e) const;
    };
    struct DragStartedEventHandler : llm::OS::Foundation::IUnknown
    {
        DragStartedEventHandler(std::nullptr_t = nullptr) noexcept {}
        DragStartedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DragStartedEventHandler(L lambda);
        template <typename F> DragStartedEventHandler(F* function);
        template <typename O, typename M> DragStartedEventHandler(O* object, M method);
        template <typename O, typename M> DragStartedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DragStartedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Controls::Primitives::DragStartedEventArgs const& e) const;
    };
    struct ItemsChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        ItemsChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        ItemsChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ItemsChangedEventHandler(L lambda);
        template <typename F> ItemsChangedEventHandler(F* function);
        template <typename O, typename M> ItemsChangedEventHandler(O* object, M method);
        template <typename O, typename M> ItemsChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ItemsChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs const& e) const;
    };
    struct RangeBaseValueChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        RangeBaseValueChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        RangeBaseValueChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> RangeBaseValueChangedEventHandler(L lambda);
        template <typename F> RangeBaseValueChangedEventHandler(F* function);
        template <typename O, typename M> RangeBaseValueChangedEventHandler(O* object, M method);
        template <typename O, typename M> RangeBaseValueChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> RangeBaseValueChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e) const;
    };
    struct ScrollEventHandler : llm::OS::Foundation::IUnknown
    {
        ScrollEventHandler(std::nullptr_t = nullptr) noexcept {}
        ScrollEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ScrollEventHandler(L lambda);
        template <typename F> ScrollEventHandler(F* function);
        template <typename O, typename M> ScrollEventHandler(O* object, M method);
        template <typename O, typename M> ScrollEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ScrollEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Controls::Primitives::ScrollEventArgs const& e) const;
    };
    struct GeneratorPosition
    {
        int32_t Index;
        int32_t Offset;
    };
    inline bool operator==(GeneratorPosition const& left, GeneratorPosition const& right) noexcept
    {
        return left.Index == right.Index && left.Offset == right.Offset;
    }
    inline bool operator!=(GeneratorPosition const& left, GeneratorPosition const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AppBarButtonTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IAppBarButtonTemplateSettings,
        impl::base<AppBarButtonTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<AppBarButtonTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        AppBarButtonTemplateSettings(std::nullptr_t) noexcept {}
        AppBarButtonTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IAppBarButtonTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBarTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings,
        impl::base<AppBarTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<AppBarTemplateSettings, llm::OS::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings2, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        AppBarTemplateSettings(std::nullptr_t) noexcept {}
        AppBarTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBarToggleButtonTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IAppBarToggleButtonTemplateSettings,
        impl::base<AppBarToggleButtonTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<AppBarToggleButtonTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        AppBarToggleButtonTemplateSettings(std::nullptr_t) noexcept {}
        AppBarToggleButtonTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IAppBarToggleButtonTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ButtonBase : llm::OS::UI::Xaml::Controls::Primitives::IButtonBase,
        impl::base<ButtonBase, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ButtonBase, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ButtonBase(std::nullptr_t) noexcept {}
        ButtonBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IButtonBase(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto ClickModeProperty();
        [[nodiscard]] static auto IsPointerOverProperty();
        [[nodiscard]] static auto IsPressedProperty();
        [[nodiscard]] static auto CommandProperty();
        [[nodiscard]] static auto CommandParameterProperty();
    };
    struct __declspec(empty_bases) CalendarPanel : llm::OS::UI::Xaml::Controls::Primitives::ICalendarPanel,
        impl::base<CalendarPanel, llm::OS::UI::Xaml::Controls::Panel, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CalendarPanel, llm::OS::UI::Xaml::Controls::IPanel, llm::OS::UI::Xaml::Controls::IPanel2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CalendarPanel(std::nullptr_t) noexcept {}
        CalendarPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ICalendarPanel(ptr, take_ownership_from_abi) {}
        CalendarPanel();
    };
    struct __declspec(empty_bases) CalendarViewTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings,
        impl::base<CalendarViewTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CalendarViewTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CalendarViewTemplateSettings(std::nullptr_t) noexcept {}
        CalendarViewTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CarouselPanel : llm::OS::UI::Xaml::Controls::Primitives::ICarouselPanel,
        impl::base<CarouselPanel, llm::OS::UI::Xaml::Controls::VirtualizingPanel, llm::OS::UI::Xaml::Controls::Panel, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CarouselPanel, llm::OS::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, llm::OS::UI::Xaml::Controls::IVirtualizingPanel, llm::OS::UI::Xaml::Controls::IVirtualizingPanelProtected, llm::OS::UI::Xaml::Controls::IVirtualizingPanelOverrides, llm::OS::UI::Xaml::Controls::IPanel, llm::OS::UI::Xaml::Controls::IPanel2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CarouselPanel(std::nullptr_t) noexcept {}
        CarouselPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ICarouselPanel(ptr, take_ownership_from_abi) {}
        CarouselPanel();
    };
    struct __declspec(empty_bases) ColorPickerSlider : llm::OS::UI::Xaml::Controls::Primitives::IColorPickerSlider,
        impl::base<ColorPickerSlider, llm::OS::UI::Xaml::Controls::Slider, llm::OS::UI::Xaml::Controls::Primitives::RangeBase, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ColorPickerSlider, llm::OS::UI::Xaml::Controls::ISlider, llm::OS::UI::Xaml::Controls::ISlider2, llm::OS::UI::Xaml::Controls::Primitives::IRangeBase, llm::OS::UI::Xaml::Controls::Primitives::IRangeBaseOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ColorPickerSlider(std::nullptr_t) noexcept {}
        ColorPickerSlider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IColorPickerSlider(ptr, take_ownership_from_abi) {}
        ColorPickerSlider();
        [[nodiscard]] static auto ColorChannelProperty();
    };
    struct __declspec(empty_bases) ColorSpectrum : llm::OS::UI::Xaml::Controls::Primitives::IColorSpectrum,
        impl::base<ColorSpectrum, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ColorSpectrum, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ColorSpectrum(std::nullptr_t) noexcept {}
        ColorSpectrum(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IColorSpectrum(ptr, take_ownership_from_abi) {}
        ColorSpectrum();
        [[nodiscard]] static auto ColorProperty();
        [[nodiscard]] static auto HsvColorProperty();
        [[nodiscard]] static auto MinHueProperty();
        [[nodiscard]] static auto MaxHueProperty();
        [[nodiscard]] static auto MinSaturationProperty();
        [[nodiscard]] static auto MaxSaturationProperty();
        [[nodiscard]] static auto MinValueProperty();
        [[nodiscard]] static auto MaxValueProperty();
        [[nodiscard]] static auto ShapeProperty();
        [[nodiscard]] static auto ComponentsProperty();
    };
    struct __declspec(empty_bases) ComboBoxTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings,
        impl::base<ComboBoxTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ComboBoxTemplateSettings, llm::OS::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings2, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ComboBoxTemplateSettings(std::nullptr_t) noexcept {}
        ComboBoxTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CommandBarFlyoutCommandBar : llm::OS::UI::Xaml::Controls::Primitives::ICommandBarFlyoutCommandBar,
        impl::base<CommandBarFlyoutCommandBar, llm::OS::UI::Xaml::Controls::CommandBar, llm::OS::UI::Xaml::Controls::AppBar, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CommandBarFlyoutCommandBar, llm::OS::UI::Xaml::Controls::ICommandBar, llm::OS::UI::Xaml::Controls::ICommandBar2, llm::OS::UI::Xaml::Controls::ICommandBar3, llm::OS::UI::Xaml::Controls::IAppBar, llm::OS::UI::Xaml::Controls::IAppBar2, llm::OS::UI::Xaml::Controls::IAppBar3, llm::OS::UI::Xaml::Controls::IAppBar4, llm::OS::UI::Xaml::Controls::IAppBarOverrides, llm::OS::UI::Xaml::Controls::IAppBarOverrides3, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CommandBarFlyoutCommandBar(std::nullptr_t) noexcept {}
        CommandBarFlyoutCommandBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ICommandBarFlyoutCommandBar(ptr, take_ownership_from_abi) {}
        CommandBarFlyoutCommandBar();
    };
    struct __declspec(empty_bases) CommandBarFlyoutCommandBarTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::ICommandBarFlyoutCommandBarTemplateSettings,
        impl::base<CommandBarFlyoutCommandBarTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CommandBarFlyoutCommandBarTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CommandBarFlyoutCommandBarTemplateSettings(std::nullptr_t) noexcept {}
        CommandBarFlyoutCommandBarTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ICommandBarFlyoutCommandBarTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CommandBarTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings,
        impl::base<CommandBarTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CommandBarTemplateSettings, llm::OS::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings2, llm::OS::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings3, llm::OS::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CommandBarTemplateSettings(std::nullptr_t) noexcept {}
        CommandBarTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DragCompletedEventArgs : llm::OS::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs,
        impl::base<DragCompletedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<DragCompletedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        DragCompletedEventArgs(std::nullptr_t) noexcept {}
        DragCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs(ptr, take_ownership_from_abi) {}
        DragCompletedEventArgs(double horizontalChange, double verticalChange, bool canceled);
    };
    struct __declspec(empty_bases) DragDeltaEventArgs : llm::OS::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs,
        impl::base<DragDeltaEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<DragDeltaEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        DragDeltaEventArgs(std::nullptr_t) noexcept {}
        DragDeltaEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs(ptr, take_ownership_from_abi) {}
        DragDeltaEventArgs(double horizontalChange, double verticalChange);
    };
    struct __declspec(empty_bases) DragStartedEventArgs : llm::OS::UI::Xaml::Controls::Primitives::IDragStartedEventArgs,
        impl::base<DragStartedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<DragStartedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        DragStartedEventArgs(std::nullptr_t) noexcept {}
        DragStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IDragStartedEventArgs(ptr, take_ownership_from_abi) {}
        DragStartedEventArgs(double horizontalOffset, double verticalOffset);
    };
    struct __declspec(empty_bases) FlyoutBase : llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase,
        impl::base<FlyoutBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<FlyoutBase, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase2, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase3, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase4, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase5, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase6, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        FlyoutBase(std::nullptr_t) noexcept {}
        FlyoutBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase(ptr, take_ownership_from_abi) {}
        using llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase::ShowAt;
        using impl::consume_t<FlyoutBase, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase5>::ShowAt;
        [[nodiscard]] static auto PlacementProperty();
        [[nodiscard]] static auto AttachedFlyoutProperty();
        static auto GetAttachedFlyout(llm::OS::UI::Xaml::FrameworkElement const& element);
        static auto SetAttachedFlyout(llm::OS::UI::Xaml::FrameworkElement const& element, llm::OS::UI::Xaml::Controls::Primitives::FlyoutBase const& value);
        static auto ShowAttachedFlyout(llm::OS::UI::Xaml::FrameworkElement const& flyoutOwner);
        [[nodiscard]] static auto AllowFocusOnInteractionProperty();
        [[nodiscard]] static auto LightDismissOverlayModeProperty();
        [[nodiscard]] static auto AllowFocusWhenDisabledProperty();
        [[nodiscard]] static auto ElementSoundModeProperty();
        [[nodiscard]] static auto OverlayInputPassThroughElementProperty();
        [[nodiscard]] static auto TargetProperty();
        [[nodiscard]] static auto ShowModeProperty();
        [[nodiscard]] static auto InputDevicePrefersPrimaryCommandsProperty();
        [[nodiscard]] static auto AreOpenCloseAnimationsEnabledProperty();
        [[nodiscard]] static auto IsOpenProperty();
        [[nodiscard]] static auto ShouldConstrainToRootBoundsProperty();
    };
    struct __declspec(empty_bases) FlyoutBaseClosingEventArgs : llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseClosingEventArgs
    {
        FlyoutBaseClosingEventArgs(std::nullptr_t) noexcept {}
        FlyoutBaseClosingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseClosingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FlyoutShowOptions : llm::OS::UI::Xaml::Controls::Primitives::IFlyoutShowOptions
    {
        FlyoutShowOptions(std::nullptr_t) noexcept {}
        FlyoutShowOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IFlyoutShowOptions(ptr, take_ownership_from_abi) {}
        FlyoutShowOptions();
    };
    struct __declspec(empty_bases) GeneratorPositionHelper : llm::OS::UI::Xaml::Controls::Primitives::IGeneratorPositionHelper
    {
        GeneratorPositionHelper(std::nullptr_t) noexcept {}
        GeneratorPositionHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IGeneratorPositionHelper(ptr, take_ownership_from_abi) {}
        static auto FromIndexAndOffset(int32_t index, int32_t offset);
    };
    struct __declspec(empty_bases) GridViewItemPresenter : llm::OS::UI::Xaml::Controls::Primitives::IGridViewItemPresenter,
        impl::base<GridViewItemPresenter, llm::OS::UI::Xaml::Controls::ContentPresenter, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<GridViewItemPresenter, llm::OS::UI::Xaml::Controls::IContentPresenter, llm::OS::UI::Xaml::Controls::IContentPresenter2, llm::OS::UI::Xaml::Controls::IContentPresenter3, llm::OS::UI::Xaml::Controls::IContentPresenter4, llm::OS::UI::Xaml::Controls::IContentPresenter5, llm::OS::UI::Xaml::Controls::IContentPresenterOverrides, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        GridViewItemPresenter(std::nullptr_t) noexcept {}
        GridViewItemPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IGridViewItemPresenter(ptr, take_ownership_from_abi) {}
        GridViewItemPresenter();
        [[nodiscard]] static auto SelectionCheckMarkVisualEnabledProperty();
        [[nodiscard]] static auto CheckHintBrushProperty();
        [[nodiscard]] static auto CheckSelectingBrushProperty();
        [[nodiscard]] static auto CheckBrushProperty();
        [[nodiscard]] static auto DragBackgroundProperty();
        [[nodiscard]] static auto DragForegroundProperty();
        [[nodiscard]] static auto FocusBorderBrushProperty();
        [[nodiscard]] static auto PlaceholderBackgroundProperty();
        [[nodiscard]] static auto PointerOverBackgroundProperty();
        [[nodiscard]] static auto SelectedBackgroundProperty();
        [[nodiscard]] static auto SelectedForegroundProperty();
        [[nodiscard]] static auto SelectedPointerOverBackgroundProperty();
        [[nodiscard]] static auto SelectedPointerOverBorderBrushProperty();
        [[nodiscard]] static auto SelectedBorderThicknessProperty();
        [[nodiscard]] static auto DisabledOpacityProperty();
        [[nodiscard]] static auto DragOpacityProperty();
        [[nodiscard]] static auto ReorderHintOffsetProperty();
        [[nodiscard]] static auto GridViewItemPresenterHorizontalContentAlignmentProperty();
        [[nodiscard]] static auto GridViewItemPresenterVerticalContentAlignmentProperty();
        [[nodiscard]] static auto GridViewItemPresenterPaddingProperty();
        [[nodiscard]] static auto PointerOverBackgroundMarginProperty();
        [[nodiscard]] static auto ContentMarginProperty();
    };
    struct __declspec(empty_bases) GridViewItemTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IGridViewItemTemplateSettings,
        impl::base<GridViewItemTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<GridViewItemTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        GridViewItemTemplateSettings(std::nullptr_t) noexcept {}
        GridViewItemTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IGridViewItemTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ItemsChangedEventArgs : llm::OS::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs
    {
        ItemsChangedEventArgs(std::nullptr_t) noexcept {}
        ItemsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) JumpListItemBackgroundConverter : llm::OS::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter,
        impl::base<JumpListItemBackgroundConverter, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<JumpListItemBackgroundConverter, llm::OS::UI::Xaml::Data::IValueConverter, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        JumpListItemBackgroundConverter(std::nullptr_t) noexcept {}
        JumpListItemBackgroundConverter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter(ptr, take_ownership_from_abi) {}
        JumpListItemBackgroundConverter();
        [[nodiscard]] static auto EnabledProperty();
        [[nodiscard]] static auto DisabledProperty();
    };
    struct __declspec(empty_bases) JumpListItemForegroundConverter : llm::OS::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter,
        impl::base<JumpListItemForegroundConverter, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<JumpListItemForegroundConverter, llm::OS::UI::Xaml::Data::IValueConverter, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        JumpListItemForegroundConverter(std::nullptr_t) noexcept {}
        JumpListItemForegroundConverter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter(ptr, take_ownership_from_abi) {}
        JumpListItemForegroundConverter();
        [[nodiscard]] static auto EnabledProperty();
        [[nodiscard]] static auto DisabledProperty();
    };
    struct __declspec(empty_bases) LayoutInformation : llm::OS::UI::Xaml::Controls::Primitives::ILayoutInformation
    {
        LayoutInformation(std::nullptr_t) noexcept {}
        LayoutInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ILayoutInformation(ptr, take_ownership_from_abi) {}
        static auto GetLayoutExceptionElement(llm::OS::Foundation::IInspectable const& dispatcher);
        static auto GetLayoutSlot(llm::OS::UI::Xaml::FrameworkElement const& element);
        static auto GetAvailableSize(llm::OS::UI::Xaml::UIElement const& element);
    };
    struct __declspec(empty_bases) ListViewItemPresenter : llm::OS::UI::Xaml::Controls::Primitives::IListViewItemPresenter,
        impl::base<ListViewItemPresenter, llm::OS::UI::Xaml::Controls::ContentPresenter, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ListViewItemPresenter, llm::OS::UI::Xaml::Controls::Primitives::IListViewItemPresenter2, llm::OS::UI::Xaml::Controls::Primitives::IListViewItemPresenter3, llm::OS::UI::Xaml::Controls::Primitives::IListViewItemPresenter4, llm::OS::UI::Xaml::Controls::IContentPresenter, llm::OS::UI::Xaml::Controls::IContentPresenter2, llm::OS::UI::Xaml::Controls::IContentPresenter3, llm::OS::UI::Xaml::Controls::IContentPresenter4, llm::OS::UI::Xaml::Controls::IContentPresenter5, llm::OS::UI::Xaml::Controls::IContentPresenterOverrides, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ListViewItemPresenter(std::nullptr_t) noexcept {}
        ListViewItemPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IListViewItemPresenter(ptr, take_ownership_from_abi) {}
        ListViewItemPresenter();
        [[nodiscard]] static auto SelectionCheckMarkVisualEnabledProperty();
        [[nodiscard]] static auto CheckHintBrushProperty();
        [[nodiscard]] static auto CheckSelectingBrushProperty();
        [[nodiscard]] static auto CheckBrushProperty();
        [[nodiscard]] static auto DragBackgroundProperty();
        [[nodiscard]] static auto DragForegroundProperty();
        [[nodiscard]] static auto FocusBorderBrushProperty();
        [[nodiscard]] static auto PlaceholderBackgroundProperty();
        [[nodiscard]] static auto PointerOverBackgroundProperty();
        [[nodiscard]] static auto SelectedBackgroundProperty();
        [[nodiscard]] static auto SelectedForegroundProperty();
        [[nodiscard]] static auto SelectedPointerOverBackgroundProperty();
        [[nodiscard]] static auto SelectedPointerOverBorderBrushProperty();
        [[nodiscard]] static auto SelectedBorderThicknessProperty();
        [[nodiscard]] static auto DisabledOpacityProperty();
        [[nodiscard]] static auto DragOpacityProperty();
        [[nodiscard]] static auto ReorderHintOffsetProperty();
        [[nodiscard]] static auto ListViewItemPresenterHorizontalContentAlignmentProperty();
        [[nodiscard]] static auto ListViewItemPresenterVerticalContentAlignmentProperty();
        [[nodiscard]] static auto ListViewItemPresenterPaddingProperty();
        [[nodiscard]] static auto PointerOverBackgroundMarginProperty();
        [[nodiscard]] static auto ContentMarginProperty();
        [[nodiscard]] static auto SelectedPressedBackgroundProperty();
        [[nodiscard]] static auto PressedBackgroundProperty();
        [[nodiscard]] static auto CheckBoxBrushProperty();
        [[nodiscard]] static auto FocusSecondaryBorderBrushProperty();
        [[nodiscard]] static auto CheckModeProperty();
        [[nodiscard]] static auto PointerOverForegroundProperty();
        [[nodiscard]] static auto RevealBackgroundProperty();
        [[nodiscard]] static auto RevealBorderBrushProperty();
        [[nodiscard]] static auto RevealBorderThicknessProperty();
        [[nodiscard]] static auto RevealBackgroundShowsAboveContentProperty();
        [[nodiscard]] static auto SelectedDisabledBackgroundProperty();
        [[nodiscard]] static auto CheckPressedBrushProperty();
        [[nodiscard]] static auto CheckDisabledBrushProperty();
        [[nodiscard]] static auto CheckBoxPointerOverBrushProperty();
        [[nodiscard]] static auto CheckBoxPressedBrushProperty();
        [[nodiscard]] static auto CheckBoxDisabledBrushProperty();
        [[nodiscard]] static auto CheckBoxSelectedBrushProperty();
        [[nodiscard]] static auto CheckBoxSelectedPointerOverBrushProperty();
        [[nodiscard]] static auto CheckBoxSelectedPressedBrushProperty();
        [[nodiscard]] static auto CheckBoxSelectedDisabledBrushProperty();
        [[nodiscard]] static auto CheckBoxBorderBrushProperty();
        [[nodiscard]] static auto CheckBoxPointerOverBorderBrushProperty();
        [[nodiscard]] static auto CheckBoxPressedBorderBrushProperty();
        [[nodiscard]] static auto CheckBoxDisabledBorderBrushProperty();
        [[nodiscard]] static auto CheckBoxCornerRadiusProperty();
        [[nodiscard]] static auto SelectionIndicatorCornerRadiusProperty();
        [[nodiscard]] static auto SelectionIndicatorVisualEnabledProperty();
        [[nodiscard]] static auto SelectionIndicatorModeProperty();
        [[nodiscard]] static auto SelectionIndicatorBrushProperty();
        [[nodiscard]] static auto SelectionIndicatorPointerOverBrushProperty();
        [[nodiscard]] static auto SelectionIndicatorPressedBrushProperty();
        [[nodiscard]] static auto SelectionIndicatorDisabledBrushProperty();
        [[nodiscard]] static auto SelectedBorderBrushProperty();
        [[nodiscard]] static auto SelectedPressedBorderBrushProperty();
        [[nodiscard]] static auto SelectedDisabledBorderBrushProperty();
        [[nodiscard]] static auto SelectedInnerBorderBrushProperty();
        [[nodiscard]] static auto PointerOverBorderBrushProperty();
    };
    struct __declspec(empty_bases) ListViewItemTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings,
        impl::base<ListViewItemTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ListViewItemTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ListViewItemTemplateSettings(std::nullptr_t) noexcept {}
        ListViewItemTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LoopingSelector : llm::OS::UI::Xaml::Controls::Primitives::ILoopingSelector,
        impl::base<LoopingSelector, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LoopingSelector, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LoopingSelector(std::nullptr_t) noexcept {}
        LoopingSelector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ILoopingSelector(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto ShouldLoopProperty();
        [[nodiscard]] static auto ItemsProperty();
        [[nodiscard]] static auto SelectedIndexProperty();
        [[nodiscard]] static auto SelectedItemProperty();
        [[nodiscard]] static auto ItemWidthProperty();
        [[nodiscard]] static auto ItemHeightProperty();
        [[nodiscard]] static auto ItemTemplateProperty();
    };
    struct __declspec(empty_bases) LoopingSelectorItem : llm::OS::UI::Xaml::Controls::Primitives::ILoopingSelectorItem,
        impl::base<LoopingSelectorItem, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LoopingSelectorItem, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LoopingSelectorItem(std::nullptr_t) noexcept {}
        LoopingSelectorItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ILoopingSelectorItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LoopingSelectorPanel : llm::OS::UI::Xaml::Controls::Primitives::ILoopingSelectorPanel,
        impl::base<LoopingSelectorPanel, llm::OS::UI::Xaml::Controls::Canvas, llm::OS::UI::Xaml::Controls::Panel, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LoopingSelectorPanel, llm::OS::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, llm::OS::UI::Xaml::Controls::ICanvas, llm::OS::UI::Xaml::Controls::IPanel, llm::OS::UI::Xaml::Controls::IPanel2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LoopingSelectorPanel(std::nullptr_t) noexcept {}
        LoopingSelectorPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ILoopingSelectorPanel(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MenuFlyoutItemTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IMenuFlyoutItemTemplateSettings,
        impl::base<MenuFlyoutItemTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MenuFlyoutItemTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MenuFlyoutItemTemplateSettings(std::nullptr_t) noexcept {}
        MenuFlyoutItemTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IMenuFlyoutItemTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MenuFlyoutPresenterTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IMenuFlyoutPresenterTemplateSettings,
        impl::base<MenuFlyoutPresenterTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MenuFlyoutPresenterTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MenuFlyoutPresenterTemplateSettings(std::nullptr_t) noexcept {}
        MenuFlyoutPresenterTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IMenuFlyoutPresenterTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NavigationViewItemPresenter : llm::OS::UI::Xaml::Controls::Primitives::INavigationViewItemPresenter,
        impl::base<NavigationViewItemPresenter, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<NavigationViewItemPresenter, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        NavigationViewItemPresenter(std::nullptr_t) noexcept {}
        NavigationViewItemPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::INavigationViewItemPresenter(ptr, take_ownership_from_abi) {}
        NavigationViewItemPresenter();
        [[nodiscard]] static auto IconProperty();
    };
    struct __declspec(empty_bases) OrientedVirtualizingPanel : llm::OS::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel,
        impl::base<OrientedVirtualizingPanel, llm::OS::UI::Xaml::Controls::VirtualizingPanel, llm::OS::UI::Xaml::Controls::Panel, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<OrientedVirtualizingPanel, llm::OS::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, llm::OS::UI::Xaml::Controls::IInsertionPanel, llm::OS::UI::Xaml::Controls::IVirtualizingPanel, llm::OS::UI::Xaml::Controls::IVirtualizingPanelProtected, llm::OS::UI::Xaml::Controls::IVirtualizingPanelOverrides, llm::OS::UI::Xaml::Controls::IPanel, llm::OS::UI::Xaml::Controls::IPanel2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        OrientedVirtualizingPanel(std::nullptr_t) noexcept {}
        OrientedVirtualizingPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PickerFlyoutBase : llm::OS::UI::Xaml::Controls::Primitives::IPickerFlyoutBase,
        impl::base<PickerFlyoutBase, llm::OS::UI::Xaml::Controls::Primitives::FlyoutBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PickerFlyoutBase, llm::OS::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase2, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase3, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase4, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase5, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase6, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PickerFlyoutBase(std::nullptr_t) noexcept {}
        PickerFlyoutBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IPickerFlyoutBase(ptr, take_ownership_from_abi) {}
        using impl::consume_t<PickerFlyoutBase, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase>::ShowAt;
        using impl::consume_t<PickerFlyoutBase, llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBase5>::ShowAt;
        [[nodiscard]] static auto TitleProperty();
        static auto GetTitle(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetTitle(llm::OS::UI::Xaml::DependencyObject const& element, param::hstring const& value);
    };
    struct __declspec(empty_bases) PivotHeaderItem : llm::OS::UI::Xaml::Controls::Primitives::IPivotHeaderItem,
        impl::base<PivotHeaderItem, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PivotHeaderItem, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PivotHeaderItem(std::nullptr_t) noexcept {}
        PivotHeaderItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IPivotHeaderItem(ptr, take_ownership_from_abi) {}
        PivotHeaderItem();
    };
    struct __declspec(empty_bases) PivotHeaderPanel : llm::OS::UI::Xaml::Controls::Primitives::IPivotHeaderPanel,
        impl::base<PivotHeaderPanel, llm::OS::UI::Xaml::Controls::Canvas, llm::OS::UI::Xaml::Controls::Panel, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PivotHeaderPanel, llm::OS::UI::Xaml::Controls::ICanvas, llm::OS::UI::Xaml::Controls::IPanel, llm::OS::UI::Xaml::Controls::IPanel2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PivotHeaderPanel(std::nullptr_t) noexcept {}
        PivotHeaderPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IPivotHeaderPanel(ptr, take_ownership_from_abi) {}
        PivotHeaderPanel();
    };
    struct __declspec(empty_bases) PivotPanel : llm::OS::UI::Xaml::Controls::Primitives::IPivotPanel,
        impl::base<PivotPanel, llm::OS::UI::Xaml::Controls::Panel, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PivotPanel, llm::OS::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, llm::OS::UI::Xaml::Controls::IPanel, llm::OS::UI::Xaml::Controls::IPanel2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PivotPanel(std::nullptr_t) noexcept {}
        PivotPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IPivotPanel(ptr, take_ownership_from_abi) {}
        PivotPanel();
    };
    struct __declspec(empty_bases) Popup : llm::OS::UI::Xaml::Controls::Primitives::IPopup,
        impl::base<Popup, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Popup, llm::OS::UI::Xaml::Controls::Primitives::IPopup2, llm::OS::UI::Xaml::Controls::Primitives::IPopup3, llm::OS::UI::Xaml::Controls::Primitives::IPopup4, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Popup(std::nullptr_t) noexcept {}
        Popup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IPopup(ptr, take_ownership_from_abi) {}
        Popup();
        [[nodiscard]] static auto ChildProperty();
        [[nodiscard]] static auto IsOpenProperty();
        [[nodiscard]] static auto HorizontalOffsetProperty();
        [[nodiscard]] static auto VerticalOffsetProperty();
        [[nodiscard]] static auto ChildTransitionsProperty();
        [[nodiscard]] static auto IsLightDismissEnabledProperty();
        [[nodiscard]] static auto LightDismissOverlayModeProperty();
        [[nodiscard]] static auto ShouldConstrainToRootBoundsProperty();
        [[nodiscard]] static auto PlacementTargetProperty();
        [[nodiscard]] static auto DesiredPlacementProperty();
    };
    struct __declspec(empty_bases) ProgressBarTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings,
        impl::base<ProgressBarTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ProgressBarTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ProgressBarTemplateSettings(std::nullptr_t) noexcept {}
        ProgressBarTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProgressRingTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings,
        impl::base<ProgressRingTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ProgressRingTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ProgressRingTemplateSettings(std::nullptr_t) noexcept {}
        ProgressRingTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RangeBase : llm::OS::UI::Xaml::Controls::Primitives::IRangeBase,
        impl::base<RangeBase, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<RangeBase, llm::OS::UI::Xaml::Controls::Primitives::IRangeBaseOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        RangeBase(std::nullptr_t) noexcept {}
        RangeBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IRangeBase(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto MinimumProperty();
        [[nodiscard]] static auto MaximumProperty();
        [[nodiscard]] static auto SmallChangeProperty();
        [[nodiscard]] static auto LargeChangeProperty();
        [[nodiscard]] static auto ValueProperty();
    };
    struct __declspec(empty_bases) RangeBaseValueChangedEventArgs : llm::OS::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs,
        impl::base<RangeBaseValueChangedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<RangeBaseValueChangedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        RangeBaseValueChangedEventArgs(std::nullptr_t) noexcept {}
        RangeBaseValueChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RepeatButton : llm::OS::UI::Xaml::Controls::Primitives::IRepeatButton,
        impl::base<RepeatButton, llm::OS::UI::Xaml::Controls::Primitives::ButtonBase, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<RepeatButton, llm::OS::UI::Xaml::Controls::Primitives::IButtonBase, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        RepeatButton(std::nullptr_t) noexcept {}
        RepeatButton(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IRepeatButton(ptr, take_ownership_from_abi) {}
        RepeatButton();
        [[nodiscard]] static auto DelayProperty();
        [[nodiscard]] static auto IntervalProperty();
    };
    struct __declspec(empty_bases) ScrollBar : llm::OS::UI::Xaml::Controls::Primitives::IScrollBar,
        impl::base<ScrollBar, llm::OS::UI::Xaml::Controls::Primitives::RangeBase, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ScrollBar, llm::OS::UI::Xaml::Controls::Primitives::IRangeBase, llm::OS::UI::Xaml::Controls::Primitives::IRangeBaseOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ScrollBar(std::nullptr_t) noexcept {}
        ScrollBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IScrollBar(ptr, take_ownership_from_abi) {}
        ScrollBar();
        [[nodiscard]] static auto OrientationProperty();
        [[nodiscard]] static auto ViewportSizeProperty();
        [[nodiscard]] static auto IndicatorModeProperty();
    };
    struct __declspec(empty_bases) ScrollEventArgs : llm::OS::UI::Xaml::Controls::Primitives::IScrollEventArgs,
        impl::base<ScrollEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ScrollEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ScrollEventArgs(std::nullptr_t) noexcept {}
        ScrollEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IScrollEventArgs(ptr, take_ownership_from_abi) {}
        ScrollEventArgs();
    };
    struct __declspec(empty_bases) Selector : llm::OS::UI::Xaml::Controls::Primitives::ISelector,
        impl::base<Selector, llm::OS::UI::Xaml::Controls::ItemsControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Selector, llm::OS::UI::Xaml::Controls::IItemsControl, llm::OS::UI::Xaml::Controls::IItemsControl2, llm::OS::UI::Xaml::Controls::IItemsControl3, llm::OS::UI::Xaml::Controls::IItemsControlOverrides, llm::OS::UI::Xaml::Controls::IItemContainerMapping, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Selector(std::nullptr_t) noexcept {}
        Selector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ISelector(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto SelectedIndexProperty();
        [[nodiscard]] static auto SelectedItemProperty();
        [[nodiscard]] static auto SelectedValueProperty();
        [[nodiscard]] static auto SelectedValuePathProperty();
        [[nodiscard]] static auto IsSynchronizedWithCurrentItemProperty();
        static auto GetIsSelectionActive(llm::OS::UI::Xaml::DependencyObject const& element);
    };
    struct __declspec(empty_bases) SelectorItem : llm::OS::UI::Xaml::Controls::Primitives::ISelectorItem,
        impl::base<SelectorItem, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SelectorItem, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SelectorItem(std::nullptr_t) noexcept {}
        SelectorItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ISelectorItem(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto IsSelectedProperty();
    };
    struct __declspec(empty_bases) SettingsFlyoutTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings,
        impl::base<SettingsFlyoutTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SettingsFlyoutTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SettingsFlyoutTemplateSettings(std::nullptr_t) noexcept {}
        SettingsFlyoutTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SplitViewTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings,
        impl::base<SplitViewTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SplitViewTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SplitViewTemplateSettings(std::nullptr_t) noexcept {}
        SplitViewTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Thumb : llm::OS::UI::Xaml::Controls::Primitives::IThumb,
        impl::base<Thumb, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Thumb, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Thumb(std::nullptr_t) noexcept {}
        Thumb(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IThumb(ptr, take_ownership_from_abi) {}
        Thumb();
        [[nodiscard]] static auto IsDraggingProperty();
    };
    struct __declspec(empty_bases) TickBar : llm::OS::UI::Xaml::Controls::Primitives::ITickBar,
        impl::base<TickBar, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<TickBar, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        TickBar(std::nullptr_t) noexcept {}
        TickBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::ITickBar(ptr, take_ownership_from_abi) {}
        TickBar();
        [[nodiscard]] static auto FillProperty();
    };
    struct __declspec(empty_bases) ToggleButton : llm::OS::UI::Xaml::Controls::Primitives::IToggleButton,
        impl::base<ToggleButton, llm::OS::UI::Xaml::Controls::Primitives::ButtonBase, llm::OS::UI::Xaml::Controls::ContentControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ToggleButton, llm::OS::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, llm::OS::UI::Xaml::Controls::Primitives::IButtonBase, llm::OS::UI::Xaml::Controls::IContentControl, llm::OS::UI::Xaml::Controls::IContentControl2, llm::OS::UI::Xaml::Controls::IContentControlOverrides, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ToggleButton(std::nullptr_t) noexcept {}
        ToggleButton(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IToggleButton(ptr, take_ownership_from_abi) {}
        ToggleButton();
        [[nodiscard]] static auto IsCheckedProperty();
        [[nodiscard]] static auto IsThreeStateProperty();
    };
    struct __declspec(empty_bases) ToggleSwitchTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings,
        impl::base<ToggleSwitchTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ToggleSwitchTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ToggleSwitchTemplateSettings(std::nullptr_t) noexcept {}
        ToggleSwitchTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToolTipTemplateSettings : llm::OS::UI::Xaml::Controls::Primitives::IToolTipTemplateSettings,
        impl::base<ToolTipTemplateSettings, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ToolTipTemplateSettings, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ToolTipTemplateSettings(std::nullptr_t) noexcept {}
        ToolTipTemplateSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Primitives::IToolTipTemplateSettings(ptr, take_ownership_from_abi) {}
    };
    template <typename D>
    class IFlyoutBaseOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IFlyoutBaseOverrides = llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Controls::Control) CreatePresenter() const;
    };
    template <typename D>
    class IFlyoutBaseOverrides4T
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IFlyoutBaseOverrides4 = llm::OS::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides4;
        LLM_IMPL_AUTO(void) OnProcessKeyboardAccelerators(llm::OS::UI::Xaml::Input::ProcessKeyboardAcceleratorEventArgs const& args) const;
    };
    template <typename D>
    class IPickerFlyoutBaseOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IPickerFlyoutBaseOverrides = llm::OS::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides;
        LLM_IMPL_AUTO(void) OnConfirmed() const;
        LLM_IMPL_AUTO(bool) ShouldShowConfirmationButtons() const;
    };
    template <typename D>
    class IRangeBaseOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IRangeBaseOverrides = llm::OS::UI::Xaml::Controls::Primitives::IRangeBaseOverrides;
        LLM_IMPL_AUTO(void) OnMinimumChanged(double oldMinimum, double newMinimum) const;
        LLM_IMPL_AUTO(void) OnMaximumChanged(double oldMaximum, double newMaximum) const;
        LLM_IMPL_AUTO(void) OnValueChanged(double oldValue, double newValue) const;
    };
    template <typename D>
    class IToggleButtonOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IToggleButtonOverrides = llm::OS::UI::Xaml::Controls::Primitives::IToggleButtonOverrides;
        LLM_IMPL_AUTO(void) OnToggle() const;
    };
}
#endif
