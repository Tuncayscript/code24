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
#ifndef LLM_OS_UI_Xaml_Shapes_2_H
#define LLM_OS_UI_Xaml_Shapes_2_H
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Shapes.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Shapes
{
    struct __declspec(empty_bases) Ellipse : llm::OS::UI::Xaml::Shapes::IEllipse,
        impl::base<Ellipse, llm::OS::UI::Xaml::Shapes::Shape, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Ellipse, llm::OS::UI::Xaml::Shapes::IShape, llm::OS::UI::Xaml::Shapes::IShape2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Ellipse(std::nullptr_t) noexcept {}
        Ellipse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Shapes::IEllipse(ptr, take_ownership_from_abi) {}
        Ellipse();
    };
    struct __declspec(empty_bases) Line : llm::OS::UI::Xaml::Shapes::ILine,
        impl::base<Line, llm::OS::UI::Xaml::Shapes::Shape, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Line, llm::OS::UI::Xaml::Shapes::IShape, llm::OS::UI::Xaml::Shapes::IShape2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Line(std::nullptr_t) noexcept {}
        Line(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Shapes::ILine(ptr, take_ownership_from_abi) {}
        Line();
        [[nodiscard]] static auto X1Property();
        [[nodiscard]] static auto Y1Property();
        [[nodiscard]] static auto X2Property();
        [[nodiscard]] static auto Y2Property();
    };
    struct __declspec(empty_bases) Path : llm::OS::UI::Xaml::Shapes::IPath,
        impl::base<Path, llm::OS::UI::Xaml::Shapes::Shape, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Path, llm::OS::UI::Xaml::Shapes::IShape, llm::OS::UI::Xaml::Shapes::IShape2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Path(std::nullptr_t) noexcept {}
        Path(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Shapes::IPath(ptr, take_ownership_from_abi) {}
        Path();
        [[nodiscard]] static auto DataProperty();
    };
    struct __declspec(empty_bases) Polygon : llm::OS::UI::Xaml::Shapes::IPolygon,
        impl::base<Polygon, llm::OS::UI::Xaml::Shapes::Shape, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Polygon, llm::OS::UI::Xaml::Shapes::IShape, llm::OS::UI::Xaml::Shapes::IShape2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Polygon(std::nullptr_t) noexcept {}
        Polygon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Shapes::IPolygon(ptr, take_ownership_from_abi) {}
        Polygon();
        [[nodiscard]] static auto FillRuleProperty();
        [[nodiscard]] static auto PointsProperty();
    };
    struct __declspec(empty_bases) Polyline : llm::OS::UI::Xaml::Shapes::IPolyline,
        impl::base<Polyline, llm::OS::UI::Xaml::Shapes::Shape, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Polyline, llm::OS::UI::Xaml::Shapes::IShape, llm::OS::UI::Xaml::Shapes::IShape2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Polyline(std::nullptr_t) noexcept {}
        Polyline(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Shapes::IPolyline(ptr, take_ownership_from_abi) {}
        Polyline();
        [[nodiscard]] static auto FillRuleProperty();
        [[nodiscard]] static auto PointsProperty();
    };
    struct __declspec(empty_bases) Rectangle : llm::OS::UI::Xaml::Shapes::IRectangle,
        impl::base<Rectangle, llm::OS::UI::Xaml::Shapes::Shape, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Rectangle, llm::OS::UI::Xaml::Shapes::IShape, llm::OS::UI::Xaml::Shapes::IShape2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Rectangle(std::nullptr_t) noexcept {}
        Rectangle(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Shapes::IRectangle(ptr, take_ownership_from_abi) {}
        Rectangle();
        [[nodiscard]] static auto RadiusXProperty();
        [[nodiscard]] static auto RadiusYProperty();
    };
    struct __declspec(empty_bases) Shape : llm::OS::UI::Xaml::Shapes::IShape,
        impl::base<Shape, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Shape, llm::OS::UI::Xaml::Shapes::IShape2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Shape(std::nullptr_t) noexcept {}
        Shape(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Shapes::IShape(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto FillProperty();
        [[nodiscard]] static auto StrokeProperty();
        [[nodiscard]] static auto StrokeMiterLimitProperty();
        [[nodiscard]] static auto StrokeThicknessProperty();
        [[nodiscard]] static auto StrokeStartLineCapProperty();
        [[nodiscard]] static auto StrokeEndLineCapProperty();
        [[nodiscard]] static auto StrokeLineJoinProperty();
        [[nodiscard]] static auto StrokeDashOffsetProperty();
        [[nodiscard]] static auto StrokeDashCapProperty();
        [[nodiscard]] static auto StrokeDashArrayProperty();
        [[nodiscard]] static auto StretchProperty();
    };
}
#endif
