/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 12, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef __Foundation_h_GNUSTEP_BASE_INCLUDE
#define __Foundation_h_GNUSTEP_BASE_INCLUDE

#import	<Base/VersionMacros.h>
#import	<objc/objc.h>

#import	<Foundation/FoundationErrors.h>
#import <Foundation/FoundationLegacySwiftCompatibility.h>
#import	<ObjCRuntime.h>
#import <Base/Config.h>
#import	<Debug.h>
#import	<Object.h>

#import	<AffineTransform.h>
#import <AppleEventDescriptor.h>
#import <AppleEventManager.h>
#import <AppleScript.h>
#import	<Archiver.h>
#import	<Array.h>
#import	<AttributedString.h>
#import	<AutoreleasePool.h>
#import <BackgroundActivityScheduler.h>
#import	<Bundle.h>
#import <ByteCountFormatter.h>
#import	<ByteOrder.h>
#import	<Cache.h>
#import	<Calendar.h>
#import	<CalendarDate.h>
#import	<CharacterSet.h>
#import	<ClassDescription.h>
#import	<Coder.h>
#import	<ComparisonPredicate.h>
#import	<CompoundPredicate.h>
#import	<Connection.h>
#import	<Data.h>
#import <DateComponentsFormatter.h>
#import	<DateFormatter.h>
#import <DateInterval.h>
#import <DateIntervalFormatter.h>
#import	<Date.h>
#import	<DecimalNumber.h>
#import	<Dictionary.h>
#import	<DistantObject.h>
#import	<DistributedLock.h>
#import	<DistributedNotificationCenter.h>
#import	<EnergyFormatter.h>
#import	<Enumerator.h>
#import	<Error.h>
#import	<Exception.h>
#import	<Expression.h>
#import <ExtensionContext.h>
#import <ExtensionItem.h>
#import <ExtensionRequestHandling.h>
#import	<FileCoordinator.h>
#import	<FileHandle.h>
#import	<FileManager.h>
#import	<FilePresenter.h>
#import	<FileVersion.h>
#import <FileWrapper.h>
#import	<Formatter.h>
#import	<GarbageCollector.h>
#import	<Geometry.h>
#import	<HashTable.h>
#import <HFSFileTypes.h>
#import	<Host.h>
#import	<HTTPCookie.h>
#import	<HTTPCookieStorage.h>
#import	<IndexPath.h>
#import	<IndexSet.h>
#import	<Invocation.h>
#import <InvocationOperation.h>
#import <ISO8601DateFormatter.h>
#import <ItemProvider.h>
#import <ItemProviderReadingWriting.h>
#import	<JSONSerialization.h>
#import	<KeyedArchiver.h>
#import	<KeyValueCoding.h>
#import	<KeyValueObserving.h>
#import <LengthFormatter.h>
#import <LinguisticTagger.h>
#import	<Lock.h>
#import	<Locale.h>
#import	<MapTable.h>
#import <Measurement.h>
#import <MeasurementFormatter.h>
#import <Metadata.h>
#import <MetadataAttributes.h>
#import	<MethodSignature.h>
#import	<Notification.h>
#import	<NotificationQueue.h>
#import	<NetServices.h>
#import	<Null.h>
#import	<NumberFormatter.h>
#import <ObjectScripting.h>
#import	<Operation.h>
#import <OrderedSet.h>
#import <Orthography.h>
#import	<PathUtilities.h>
#import <PersonNameComponents.h>
#import <PersonNameComponentsFormatter.h>
#import	<PointerArray.h>
#import	<PointerFunctions.h>
#import	<PortCoder.h>
#import	<PortMessage.h>
#import	<PortNameServer.h>
#import	<Predicate.h>
#import	<ProcessInfo.h>
#import <Progress.h>
#import	<ProtocolChecker.h>
#import	<Proxy.h>
#import	<Range.h>
#import	<RegularExpression.h>
#import	<RunLoop.h>
#import	<Scanner.h>
#import <ScriptClassDescription.h>
#import <ScriptCoercionHandler.h>
#import <ScriptCommand.h>
#import <ScriptCommandDescription.h>
#import <ScriptExecutionContext.h>
#import <ScriptKeyValueCoding.h>
#import <ScriptObjectSpecifiers.h>
#import <ScriptStandardSuiteCommands.h>
#import <ScriptSuiteRegistry.h>
#import	<ScriptWhoseTests.h>
#import	<Serialization.h>
#import	<Set.h>
#import	<SortDescriptor.h>
#import	<SpellServer.h>
#import	<Stream.h>
#import	<String.h>
#import	<Task.h>
#import	<TextCheckingResult.h>
#import	<Thread.h>
#import	<Timer.h>
#import	<TimeZone.h>
#import <UbiquitousKeyValueStore.h>
#import	<UndoManager.h>
#import <Unit.h>
#import <UserActivity.h>
#import	<URLAuthenticationChallenge.h>
#import	<URLCache.h>
#import	<URLConnection.h>
#import	<URLCredential.h>
#import	<URLCredentialStorage.h>
#import	<URLDownload.h>
#import	<URLError.h>
#import	<URL.h>
#import	<URLHandle.h>
#import	<URLProtectionSpace.h>
#import	<URLProtocol.h>
#import	<URLRequest.h>
#import	<URLResponse.h>
#import	<URLSession.h>
#import	<UserDefaults.h>
#import	<UserNotification.h>
#import	<UUID.h>
#import	<Value.h>
#import	<ValueTransformer.h>
#import <XMLDocument.h>
#import <XMLDTD.h>
#import <XMLDTDNode.h>
#import <XMLElement.h>
#import <XMLNode.h>
#import <XMLNodeOptions.h>
#import	<XMLParser.h>
#import <XPCConnection.h>
#import	<Zone.h>

#ifdef __has_include
#  if __has_include(<CoreFoundation/CoreFoundation.h>)
#    include <CoreFoundation/CoreFoundation.h>
#  endif
#  if __has_include(<dispatch/dispatch.h>)
#    include <dispatch/dispatch.h>
#  endif
#endif

#endif /* __Foundation_h_GNUSTEP_BASE_INCLUDE */
