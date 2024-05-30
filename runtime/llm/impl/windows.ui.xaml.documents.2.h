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
#ifndef LLM_OS_UI_Xaml_Documents_2_H
#define LLM_OS_UI_Xaml_Documents_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Documents.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Documents
{
    struct TextRange
    {
        int32_t StartIndex;
        int32_t Length;
    };
    inline bool operator==(TextRange const& left, TextRange const& right) noexcept
    {
        return left.StartIndex == right.StartIndex && left.Length == right.Length;
    }
    inline bool operator!=(TextRange const& left, TextRange const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) Block : llm::OS::UI::Xaml::Documents::IBlock,
        impl::base<Block, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Block, llm::OS::UI::Xaml::Documents::IBlock2, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Block(std::nullptr_t) noexcept {}
        Block(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IBlock(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto TextAlignmentProperty();
        [[nodiscard]] static auto LineHeightProperty();
        [[nodiscard]] static auto LineStackingStrategyProperty();
        [[nodiscard]] static auto MarginProperty();
        [[nodiscard]] static auto HorizontalTextAlignmentProperty();
    };
    struct __declspec(empty_bases) BlockCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Documents::Block>
    {
        BlockCollection(std::nullptr_t) noexcept {}
        BlockCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Documents::Block>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Bold : llm::OS::UI::Xaml::Documents::IBold,
        impl::base<Bold, llm::OS::UI::Xaml::Documents::Span, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Bold, llm::OS::UI::Xaml::Documents::ISpan, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Bold(std::nullptr_t) noexcept {}
        Bold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IBold(ptr, take_ownership_from_abi) {}
        Bold();
    };
    struct __declspec(empty_bases) ContactContentLinkProvider : llm::OS::UI::Xaml::Documents::IContactContentLinkProvider,
        impl::base<ContactContentLinkProvider, llm::OS::UI::Xaml::Documents::ContentLinkProvider, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ContactContentLinkProvider, llm::OS::UI::Xaml::Documents::IContentLinkProvider, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ContactContentLinkProvider(std::nullptr_t) noexcept {}
        ContactContentLinkProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IContactContentLinkProvider(ptr, take_ownership_from_abi) {}
        ContactContentLinkProvider();
    };
    struct __declspec(empty_bases) ContentLink : llm::OS::UI::Xaml::Documents::IContentLink,
        impl::base<ContentLink, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ContentLink, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ContentLink(std::nullptr_t) noexcept {}
        ContentLink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IContentLink(ptr, take_ownership_from_abi) {}
        ContentLink();
        [[nodiscard]] static auto BackgroundProperty();
        [[nodiscard]] static auto CursorProperty();
        [[nodiscard]] static auto XYFocusLeftProperty();
        [[nodiscard]] static auto XYFocusRightProperty();
        [[nodiscard]] static auto XYFocusUpProperty();
        [[nodiscard]] static auto XYFocusDownProperty();
        [[nodiscard]] static auto ElementSoundModeProperty();
        [[nodiscard]] static auto FocusStateProperty();
        [[nodiscard]] static auto XYFocusUpNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusDownNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusLeftNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusRightNavigationStrategyProperty();
        [[nodiscard]] static auto IsTabStopProperty();
        [[nodiscard]] static auto TabIndexProperty();
    };
    struct __declspec(empty_bases) ContentLinkInvokedEventArgs : llm::OS::UI::Xaml::Documents::IContentLinkInvokedEventArgs
    {
        ContentLinkInvokedEventArgs(std::nullptr_t) noexcept {}
        ContentLinkInvokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IContentLinkInvokedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContentLinkProvider : llm::OS::UI::Xaml::Documents::IContentLinkProvider,
        impl::base<ContentLinkProvider, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ContentLinkProvider, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ContentLinkProvider(std::nullptr_t) noexcept {}
        ContentLinkProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IContentLinkProvider(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContentLinkProviderCollection : llm::OS::UI::Xaml::Documents::IContentLinkProviderCollection,
        impl::require<ContentLinkProviderCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Documents::ContentLinkProvider>, llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Documents::ContentLinkProvider>>
    {
        ContentLinkProviderCollection(std::nullptr_t) noexcept {}
        ContentLinkProviderCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IContentLinkProviderCollection(ptr, take_ownership_from_abi) {}
        ContentLinkProviderCollection();
    };
    struct __declspec(empty_bases) Glyphs : llm::OS::UI::Xaml::Documents::IGlyphs,
        impl::base<Glyphs, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Glyphs, llm::OS::UI::Xaml::Documents::IGlyphs2, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Glyphs(std::nullptr_t) noexcept {}
        Glyphs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IGlyphs(ptr, take_ownership_from_abi) {}
        Glyphs();
        [[nodiscard]] static auto UnicodeStringProperty();
        [[nodiscard]] static auto IndicesProperty();
        [[nodiscard]] static auto FontUriProperty();
        [[nodiscard]] static auto StyleSimulationsProperty();
        [[nodiscard]] static auto FontRenderingEmSizeProperty();
        [[nodiscard]] static auto OriginXProperty();
        [[nodiscard]] static auto OriginYProperty();
        [[nodiscard]] static auto FillProperty();
        [[nodiscard]] static auto IsColorFontEnabledProperty();
        [[nodiscard]] static auto ColorFontPaletteIndexProperty();
    };
    struct __declspec(empty_bases) Hyperlink : llm::OS::UI::Xaml::Documents::IHyperlink,
        impl::base<Hyperlink, llm::OS::UI::Xaml::Documents::Span, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Hyperlink, llm::OS::UI::Xaml::Documents::IHyperlink2, llm::OS::UI::Xaml::Documents::IHyperlink3, llm::OS::UI::Xaml::Documents::IHyperlink4, llm::OS::UI::Xaml::Documents::IHyperlink5, llm::OS::UI::Xaml::Documents::ISpan, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Hyperlink(std::nullptr_t) noexcept {}
        Hyperlink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IHyperlink(ptr, take_ownership_from_abi) {}
        Hyperlink();
        [[nodiscard]] static auto NavigateUriProperty();
        [[nodiscard]] static auto UnderlineStyleProperty();
        [[nodiscard]] static auto XYFocusLeftProperty();
        [[nodiscard]] static auto XYFocusRightProperty();
        [[nodiscard]] static auto XYFocusUpProperty();
        [[nodiscard]] static auto XYFocusDownProperty();
        [[nodiscard]] static auto ElementSoundModeProperty();
        [[nodiscard]] static auto FocusStateProperty();
        [[nodiscard]] static auto XYFocusUpNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusDownNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusLeftNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusRightNavigationStrategyProperty();
        [[nodiscard]] static auto IsTabStopProperty();
        [[nodiscard]] static auto TabIndexProperty();
    };
    struct __declspec(empty_bases) HyperlinkClickEventArgs : llm::OS::UI::Xaml::Documents::IHyperlinkClickEventArgs,
        impl::base<HyperlinkClickEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<HyperlinkClickEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        HyperlinkClickEventArgs(std::nullptr_t) noexcept {}
        HyperlinkClickEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IHyperlinkClickEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Inline : llm::OS::UI::Xaml::Documents::IInline,
        impl::base<Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Inline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Inline(std::nullptr_t) noexcept {}
        Inline(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IInline(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InlineCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Documents::Inline>
    {
        InlineCollection(std::nullptr_t) noexcept {}
        InlineCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Documents::Inline>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InlineUIContainer : llm::OS::UI::Xaml::Documents::IInlineUIContainer,
        impl::base<InlineUIContainer, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<InlineUIContainer, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        InlineUIContainer(std::nullptr_t) noexcept {}
        InlineUIContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IInlineUIContainer(ptr, take_ownership_from_abi) {}
        InlineUIContainer();
    };
    struct __declspec(empty_bases) Italic : llm::OS::UI::Xaml::Documents::IItalic,
        impl::base<Italic, llm::OS::UI::Xaml::Documents::Span, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Italic, llm::OS::UI::Xaml::Documents::ISpan, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Italic(std::nullptr_t) noexcept {}
        Italic(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IItalic(ptr, take_ownership_from_abi) {}
        Italic();
    };
    struct __declspec(empty_bases) LineBreak : llm::OS::UI::Xaml::Documents::ILineBreak,
        impl::base<LineBreak, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LineBreak, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LineBreak(std::nullptr_t) noexcept {}
        LineBreak(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::ILineBreak(ptr, take_ownership_from_abi) {}
        LineBreak();
    };
    struct __declspec(empty_bases) Paragraph : llm::OS::UI::Xaml::Documents::IParagraph,
        impl::base<Paragraph, llm::OS::UI::Xaml::Documents::Block, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Paragraph, llm::OS::UI::Xaml::Documents::IBlock, llm::OS::UI::Xaml::Documents::IBlock2, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Paragraph(std::nullptr_t) noexcept {}
        Paragraph(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IParagraph(ptr, take_ownership_from_abi) {}
        Paragraph();
        [[nodiscard]] static auto TextIndentProperty();
    };
    struct __declspec(empty_bases) PlaceContentLinkProvider : llm::OS::UI::Xaml::Documents::IPlaceContentLinkProvider,
        impl::base<PlaceContentLinkProvider, llm::OS::UI::Xaml::Documents::ContentLinkProvider, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PlaceContentLinkProvider, llm::OS::UI::Xaml::Documents::IContentLinkProvider, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PlaceContentLinkProvider(std::nullptr_t) noexcept {}
        PlaceContentLinkProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IPlaceContentLinkProvider(ptr, take_ownership_from_abi) {}
        PlaceContentLinkProvider();
    };
    struct __declspec(empty_bases) Run : llm::OS::UI::Xaml::Documents::IRun,
        impl::base<Run, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Run, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Run(std::nullptr_t) noexcept {}
        Run(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IRun(ptr, take_ownership_from_abi) {}
        Run();
        [[nodiscard]] static auto FlowDirectionProperty();
    };
    struct __declspec(empty_bases) Span : llm::OS::UI::Xaml::Documents::ISpan,
        impl::base<Span, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Span, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Span(std::nullptr_t) noexcept {}
        Span(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::ISpan(ptr, take_ownership_from_abi) {}
        Span();
    };
    struct __declspec(empty_bases) TextElement : llm::OS::UI::Xaml::Documents::ITextElement,
        impl::base<TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<TextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        TextElement(std::nullptr_t) noexcept {}
        TextElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::ITextElement(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto FontSizeProperty();
        [[nodiscard]] static auto FontFamilyProperty();
        [[nodiscard]] static auto FontWeightProperty();
        [[nodiscard]] static auto FontStyleProperty();
        [[nodiscard]] static auto FontStretchProperty();
        [[nodiscard]] static auto CharacterSpacingProperty();
        [[nodiscard]] static auto ForegroundProperty();
        [[nodiscard]] static auto LanguageProperty();
        [[nodiscard]] static auto IsTextScaleFactorEnabledProperty();
        [[nodiscard]] static auto AllowFocusOnInteractionProperty();
        [[nodiscard]] static auto AccessKeyProperty();
        [[nodiscard]] static auto ExitDisplayModeOnAccessKeyInvokedProperty();
        [[nodiscard]] static auto TextDecorationsProperty();
        [[nodiscard]] static auto IsAccessKeyScopeProperty();
        [[nodiscard]] static auto AccessKeyScopeOwnerProperty();
        [[nodiscard]] static auto KeyTipPlacementModeProperty();
        [[nodiscard]] static auto KeyTipHorizontalOffsetProperty();
        [[nodiscard]] static auto KeyTipVerticalOffsetProperty();
    };
    struct __declspec(empty_bases) TextHighlighter : llm::OS::UI::Xaml::Documents::ITextHighlighter
    {
        TextHighlighter(std::nullptr_t) noexcept {}
        TextHighlighter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::ITextHighlighter(ptr, take_ownership_from_abi) {}
        TextHighlighter();
        [[nodiscard]] static auto ForegroundProperty();
        [[nodiscard]] static auto BackgroundProperty();
    };
    struct __declspec(empty_bases) TextHighlighterBase : llm::OS::UI::Xaml::Documents::ITextHighlighterBase,
        impl::base<TextHighlighterBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<TextHighlighterBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        TextHighlighterBase(std::nullptr_t) noexcept {}
        TextHighlighterBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::ITextHighlighterBase(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TextPointer : llm::OS::UI::Xaml::Documents::ITextPointer
    {
        TextPointer(std::nullptr_t) noexcept {}
        TextPointer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::ITextPointer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Typography : llm::OS::UI::Xaml::Documents::ITypography
    {
        Typography(std::nullptr_t) noexcept {}
        Typography(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::ITypography(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto AnnotationAlternatesProperty();
        static auto GetAnnotationAlternates(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetAnnotationAlternates(llm::OS::UI::Xaml::DependencyObject const& element, int32_t value);
        [[nodiscard]] static auto EastAsianExpertFormsProperty();
        static auto GetEastAsianExpertForms(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetEastAsianExpertForms(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto EastAsianLanguageProperty();
        static auto GetEastAsianLanguage(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetEastAsianLanguage(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FontEastAsianLanguage const& value);
        [[nodiscard]] static auto EastAsianWidthsProperty();
        static auto GetEastAsianWidths(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetEastAsianWidths(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FontEastAsianWidths const& value);
        [[nodiscard]] static auto StandardLigaturesProperty();
        static auto GetStandardLigatures(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStandardLigatures(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto ContextualLigaturesProperty();
        static auto GetContextualLigatures(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetContextualLigatures(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto DiscretionaryLigaturesProperty();
        static auto GetDiscretionaryLigatures(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetDiscretionaryLigatures(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto HistoricalLigaturesProperty();
        static auto GetHistoricalLigatures(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetHistoricalLigatures(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StandardSwashesProperty();
        static auto GetStandardSwashes(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStandardSwashes(llm::OS::UI::Xaml::DependencyObject const& element, int32_t value);
        [[nodiscard]] static auto ContextualSwashesProperty();
        static auto GetContextualSwashes(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetContextualSwashes(llm::OS::UI::Xaml::DependencyObject const& element, int32_t value);
        [[nodiscard]] static auto ContextualAlternatesProperty();
        static auto GetContextualAlternates(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetContextualAlternates(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticAlternatesProperty();
        static auto GetStylisticAlternates(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticAlternates(llm::OS::UI::Xaml::DependencyObject const& element, int32_t value);
        [[nodiscard]] static auto StylisticSet1Property();
        static auto GetStylisticSet1(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet1(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet2Property();
        static auto GetStylisticSet2(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet2(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet3Property();
        static auto GetStylisticSet3(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet3(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet4Property();
        static auto GetStylisticSet4(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet4(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet5Property();
        static auto GetStylisticSet5(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet5(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet6Property();
        static auto GetStylisticSet6(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet6(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet7Property();
        static auto GetStylisticSet7(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet7(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet8Property();
        static auto GetStylisticSet8(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet8(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet9Property();
        static auto GetStylisticSet9(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet9(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet10Property();
        static auto GetStylisticSet10(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet10(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet11Property();
        static auto GetStylisticSet11(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet11(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet12Property();
        static auto GetStylisticSet12(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet12(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet13Property();
        static auto GetStylisticSet13(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet13(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet14Property();
        static auto GetStylisticSet14(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet14(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet15Property();
        static auto GetStylisticSet15(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet15(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet16Property();
        static auto GetStylisticSet16(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet16(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet17Property();
        static auto GetStylisticSet17(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet17(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet18Property();
        static auto GetStylisticSet18(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet18(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet19Property();
        static auto GetStylisticSet19(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet19(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto StylisticSet20Property();
        static auto GetStylisticSet20(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetStylisticSet20(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto CapitalsProperty();
        static auto GetCapitals(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetCapitals(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FontCapitals const& value);
        [[nodiscard]] static auto CapitalSpacingProperty();
        static auto GetCapitalSpacing(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetCapitalSpacing(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto KerningProperty();
        static auto GetKerning(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetKerning(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto CaseSensitiveFormsProperty();
        static auto GetCaseSensitiveForms(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetCaseSensitiveForms(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto HistoricalFormsProperty();
        static auto GetHistoricalForms(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetHistoricalForms(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto FractionProperty();
        static auto GetFraction(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetFraction(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FontFraction const& value);
        [[nodiscard]] static auto NumeralStyleProperty();
        static auto GetNumeralStyle(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetNumeralStyle(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FontNumeralStyle const& value);
        [[nodiscard]] static auto NumeralAlignmentProperty();
        static auto GetNumeralAlignment(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetNumeralAlignment(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FontNumeralAlignment const& value);
        [[nodiscard]] static auto SlashedZeroProperty();
        static auto GetSlashedZero(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetSlashedZero(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto MathematicalGreekProperty();
        static auto GetMathematicalGreek(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetMathematicalGreek(llm::OS::UI::Xaml::DependencyObject const& element, bool value);
        [[nodiscard]] static auto VariantsProperty();
        static auto GetVariants(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetVariants(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::FontVariants const& value);
    };
    struct __declspec(empty_bases) Underline : llm::OS::UI::Xaml::Documents::IUnderline,
        impl::base<Underline, llm::OS::UI::Xaml::Documents::Span, llm::OS::UI::Xaml::Documents::Inline, llm::OS::UI::Xaml::Documents::TextElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Underline, llm::OS::UI::Xaml::Documents::ISpan, llm::OS::UI::Xaml::Documents::IInline, llm::OS::UI::Xaml::Documents::ITextElement, llm::OS::UI::Xaml::Documents::ITextElement2, llm::OS::UI::Xaml::Documents::ITextElement3, llm::OS::UI::Xaml::Documents::ITextElement4, llm::OS::UI::Xaml::Documents::ITextElement5, llm::OS::UI::Xaml::Documents::ITextElementOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Underline(std::nullptr_t) noexcept {}
        Underline(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Documents::IUnderline(ptr, take_ownership_from_abi) {}
        Underline();
    };
    template <typename D>
    class ITextElementOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using ITextElementOverrides = llm::OS::UI::Xaml::Documents::ITextElementOverrides;
        WINRT_IMPL_AUTO(void) OnDisconnectVisualChildren() const;
    };
}
#endif
