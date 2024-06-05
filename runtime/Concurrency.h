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
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:

// File: Concurrency.h
// Purpose: Runtime interface for concurrency

// Date: Wednesday, June 6, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)

// Description: 
// The runtime interface for concurrency.

#ifndef CODE_RUNTIME_CONCURRENCY_H
#define CODE_RUNTIME_CONCURRENCY_H

#include "code/ABI/AsyncLet.h"
#include "code/ABI/Task.h"
#include "code/ABI/TaskGroup.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"

// Does the runtime use a cooperative global executor?
#if defined(CODE_STDLIB_SINGLE_THREADED_CONCURRENCY)
#define CODE_CONCURRENCY_COOPERATIVE_GLOBAL_EXECUTOR 1
#else
#define CODE_CONCURRENCY_COOPERATIVE_GLOBAL_EXECUTOR 0
#endif

// Does the runtime use a task-thread model?
#if defined(CODE_STDLIB_TASK_TO_THREAD_MODEL_CONCURRENCY)
#define CODE_CONCURRENCY_TASK_TO_THREAD_MODEL 1
#else
#define CODE_CONCURRENCY_TASK_TO_THREAD_MODEL 0
#endif

// Does the runtime integrate with libdispatch?
#if defined(CODE_CONCURRENCY_USES_DISPATCH)
#define CODE_CONCURRENCY_ENABLE_DISPATCH CODE_CONCURRENCY_USES_DISPATCH
#else
#define CODE_CONCURRENCY_ENABLE_DISPATCH 0
#endif

// Does the runtime provide priority escalation support?
#ifndef CODE_CONCURRENCY_ENABLE_PRIORITY_ESCALATION
#if CODE_CONCURRENCY_ENABLE_DISPATCH && \
    __has_include(<dispatch/code_concurrency_private.h>) && __APPLE__ && \
    (defined(__arm64__) || defined(__x86_64__))
#define CODE_CONCURRENCY_ENABLE_PRIORITY_ESCALATION 1
#else
#define CODE_CONCURRENCY_ENABLE_PRIORITY_ESCALATION 0
#endif
#endif /* CODE_CONCURRENCY_ENABLE_PRIORITY_ESCALATION */

namespace code {
class DefaultActor;
class TaskOptionRecord;

struct CodeError;

struct AsyncTaskAndContext {
  AsyncTask *Task;
  AsyncContext *InitialContext;
};

/// Create a task object.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
AsyncTaskAndContext code_task_create(
    size_t taskCreateFlags,
    TaskOptionRecord *options,
    const Metadata *futureResultType,
    void *closureEntry, HeapObject *closureContext);

/// Caution: not all future-initializing functions actually throw, so
/// this signature may be incorrect.
using FutureAsyncSignature =
  AsyncSignature<void(void*), /*throws*/ true>;

/// Create a task object.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
AsyncTaskAndContext code_task_create_common(
    size_t taskCreateFlags,
    TaskOptionRecord *options,
    const Metadata *futureResultType,
    TaskContinuationFunction *function, void *closureContext,
    size_t initialContextSize);

#if CODE_CONCURRENCY_TASK_TO_THREAD_MODEL
#define CODE_TASK_RUN_INLINE_INITIAL_CONTEXT_BYTES 4096
/// Begin an async context in the current sync context and run the indicated
/// closure in it.
///
/// This is only supported under the task-to-thread concurrency model and
/// relies on a synchronous implementation of task blocking in order to work.
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code)
void code_task_run_inline(OpaqueValue *result, void *closureAFP,
                           OpaqueValue *closureContext,
                           const Metadata *futureResultType);
#endif

/// Allocate memory in a task.
///
/// This must be called synchronously with the task.
///
/// All allocations will be rounded to a multiple of MAX_ALIGNMENT.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void *code_task_alloc(size_t size);

/// Deallocate memory in a task.
///
/// The pointer provided must be the last pointer allocated on
/// this task that has not yet been deallocated; that is, memory
/// must be allocated and deallocated in a strict stack discipline.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_dealloc(void *ptr);

/// Cancel a task and all of its child tasks.
///
/// This can be called from any thread.
///
/// This has no effect if the task is already cancelled.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_cancel(AsyncTask *task);

/// Cancel all the child tasks that belong to the `group`.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_cancel_group_child_tasks(TaskGroup *group);

/// Escalate the priority of a task and all of its child tasks.
///
/// This can be called from any thread.
///
/// This has no effect if the task already has at least the given priority.
/// Returns the priority of the task.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
JobPriority
code_task_escalate(AsyncTask *task, JobPriority newPriority);

// TODO: "async let wait" and "async let destroy" would be expressed
//       similar to like TaskFutureWait;

/// Wait for a non-throwing future task to complete.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_task_future_wait(on task: _owned Builtin.NativeObject) async
///     -> Success
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_task_future_wait(OpaqueValue *,
         CODE_ASYNC_CONTEXT AsyncContext *, AsyncTask *,
         TaskContinuationFunction *,
         AsyncContext *);

/// Wait for a potentially-throwing future task to complete.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_task_future_wait_throwing(on task: _owned Builtin.NativeObject)
///    async throws -> Success
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_task_future_wait_throwing(
  OpaqueValue *,
  CODE_ASYNC_CONTEXT AsyncContext *,
  AsyncTask *,
  ThrowingTaskFutureWaitContinuationFunction *,
  AsyncContext *);

/// Wait for a readyQueue of a Channel to become non empty.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_taskGroup_wait_next_throwing(
///     waitingTask: Builtin.NativeObject, // current task
///     group: Builtin.RawPointer
/// ) async throws -> T
/// \endcode
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(codeasync)
void code_taskGroup_wait_next_throwing(
    OpaqueValue *resultPointer,
    CODE_ASYNC_CONTEXT AsyncContext *callerContext,
    TaskGroup *group,
    ThrowingTaskFutureWaitContinuationFunction *resumeFn,
    AsyncContext *callContext);

/// Initialize a `TaskGroup` in the passed `group` memory location.
/// The caller is responsible for retaining and managing the group's lifecycle.
///
/// Its Code signature is
///
/// \code
/// func code_taskGroup_initialize(group: Builtin.RawPointer)
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_taskGroup_initialize(TaskGroup *group, const Metadata *T);

/// Initialize a `TaskGroup` in the passed `group` memory location.
/// The caller is responsible for retaining and managing the group's lifecycle.
///
/// Its Code signature is
///
/// \code
/// func code_taskGroup_initialize(flags: Int, group: Builtin.RawPointer)
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_taskGroup_initializeWithFlags(size_t flags, TaskGroup *group, const Metadata *T);

/// Attach a child task to the parent task's task group record.
///
/// This function MUST be called from the AsyncTask running the task group.
///
/// Since the group (or rather, its record) is inserted in the parent task at
/// creation we do not need the parent task here, the group already is attached
/// to it.
/// Its Code signature is
///
/// \code
/// func code_taskGroup_attachChild(
///     group: Builtin.RawPointer,
///     child: Builtin.NativeObject
/// )
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_taskGroup_attachChild(TaskGroup *group, AsyncTask *child);

/// Its Code signature is
///
/// This function MUST be called from the AsyncTask running the task group.
///
/// \code
/// func code_taskGroup_destroy(_ group: Builtin.RawPointer)
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_taskGroup_destroy(TaskGroup *group);

/// Before starting a task group child task, inform the group that there is one
/// more 'pending' child to account for.
///
/// This function SHOULD be called from the AsyncTask running the task group,
/// however is generally thread-safe as it only works with the group status.
///
/// Its Code signature is
///
/// \code
/// func code_taskGroup_addPending(
///     group: Builtin.RawPointer,
///     unconditionally: Bool
/// ) -> Bool
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_taskGroup_addPending(TaskGroup *group, bool unconditionally);

/// Cancel all tasks in the group.
/// This also prevents new tasks from being added.
///
/// This can be called from any thread.
///
/// Its Code signature is
///
/// \code
/// func code_taskGroup_cancelAll(group: Builtin.RawPointer)
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_taskGroup_cancelAll(TaskGroup *group);

/// Check ONLY if the group was explicitly cancelled, e.g. by `cancelAll`.
///
/// This check DOES NOT take into account the task in which the group is running
/// being cancelled or not.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_taskGroup_isCancelled(group: Builtin.RawPointer)
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_taskGroup_isCancelled(TaskGroup *group);

/// Wait until all pending tasks from the task group have completed.
/// If this task group is accumulating results, this also discards all those results.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_taskGroup_waitAll(
///     waitingTask: Builtin.NativeObject, // current task
///     group: Builtin.RawPointer,
///     bodyError: Code.Error?
/// ) async throws
/// \endcode
  CODE_EXPORT_FROM(code_Concurrency)
  CODE_CC(codeasync)
  void code_taskGroup_waitAll(
      OpaqueValue *resultPointer,
      CODE_ASYNC_CONTEXT AsyncContext *callerContext,
      TaskGroup *group,
      CodeError *bodyError,
      ThrowingTaskFutureWaitContinuationFunction *resumeFn,
      AsyncContext *callContext);

/// Check the readyQueue of a task group, return true if it has no pending tasks.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_taskGroup_isEmpty(
///     _ group: Builtin.RawPointer
/// ) -> Bool
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_taskGroup_isEmpty(TaskGroup *group);

/// DEPRECATED. code_asyncLet_begin is used instead.
/// Its Code signature is
///
/// \code
/// func code_asyncLet_start<T>(
///     asyncLet: Builtin.RawPointer,
///     options: Builtin.RawPointer?,
///     operation: __owned @Sendable () async throws -> T
/// )
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_asyncLet_start(AsyncLet *alet,
                          TaskOptionRecord *options,
                          const Metadata *futureResultType,
                          void *closureEntryPoint, HeapObject *closureContext);

/// Begin an async let child task.
/// Its Code signature is
///
/// \code
/// func code_asyncLet_start<T>(
///     asyncLet: Builtin.RawPointer,
///     options: Builtin.RawPointer?,
///     operation: __owned @Sendable () async throws -> T,
///     resultBuffer: Builtin.RawPointer
/// )
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_asyncLet_begin(AsyncLet *alet,
                          TaskOptionRecord *options,
                          const Metadata *futureResultType,
                          void *closureEntryPoint, HeapObject *closureContext,
                          void *resultBuffer);

/// This matches the ABI of a closure `<T>(Builtin.RawPointer) async -> T`
using AsyncLetWaitSignature =
    CODE_CC(codeasync)
    void(OpaqueValue *,
         CODE_ASYNC_CONTEXT AsyncContext *, AsyncTask *, Metadata *);

/// DEPRECATED. code_asyncLet_get is used instead.
/// Wait for a non-throwing async-let to complete.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_asyncLet_wait(
///     _ asyncLet: _owned Builtin.RawPointer
/// ) async -> Success
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_asyncLet_wait(OpaqueValue *,
                         CODE_ASYNC_CONTEXT AsyncContext *,
                         AsyncLet *, TaskContinuationFunction *,
                         AsyncContext *);

/// DEPRECATED. code_asyncLet_get_throwing is used instead.
/// Wait for a potentially-throwing async-let to complete.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_asyncLet_wait_throwing(
///     _ asyncLet: _owned Builtin.RawPointer
/// ) async throws -> Success
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_asyncLet_wait_throwing(OpaqueValue *,
                                  CODE_ASYNC_CONTEXT AsyncContext *,
                                  AsyncLet *,
                                  ThrowingTaskFutureWaitContinuationFunction *,
                                  AsyncContext *);

/// DEPRECATED. code_asyncLet_finish is used instead.
/// Its Code signature is
///
/// \code
/// func code_asyncLet_end(_ alet: Builtin.RawPointer)
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_asyncLet_end(AsyncLet *alet);

/// Get the value of a non-throwing async-let, awaiting the result if necessary.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_asyncLet_get(
///     _ asyncLet: Builtin.RawPointer,
///     _ resultBuffer: Builtin.RawPointer
/// ) async
/// \endcode
///
/// \c result points at the variable storage for the binding. It is
/// uninitialized until the first call to \c code_asyncLet_get or
/// \c code_asyncLet_get_throwing. That first call initializes the storage
/// with the result of the child task. Subsequent calls do nothing and leave
/// the value in place.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_asyncLet_get(CODE_ASYNC_CONTEXT AsyncContext *,
                        AsyncLet *,
                        void *,
                        TaskContinuationFunction *,
                        AsyncContext *);

/// Get the value of a throwing async-let, awaiting the result if necessary.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_asyncLet_get_throwing(
///     _ asyncLet: Builtin.RawPointer,
///     _ resultBuffer: Builtin.RawPointer
/// ) async throws
/// \endcode
///
/// \c result points at the variable storage for the binding. It is
/// uninitialized until the first call to \c code_asyncLet_get or
/// \c code_asyncLet_get_throwing. That first call initializes the storage
/// with the result of the child task. Subsequent calls do nothing and leave
/// the value in place. A pointer to the storage inside the child task is
/// returned if the task completes successfully, otherwise the error from the
/// child task is thrown.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_asyncLet_get_throwing(CODE_ASYNC_CONTEXT AsyncContext *,
                                 AsyncLet *,
                                 void *,
                                 ThrowingTaskFutureWaitContinuationFunction *,
                                 AsyncContext *);

/// Exit the scope of an async-let binding. If the task is still running, it
/// is cancelled, and we await its completion; otherwise, we destroy the
/// value in the variable storage.
///
/// Its Code signature is
///
/// \code
/// func code_asyncLet_finish(_ asyncLet: Builtin.RawPointer,
///                            _ resultBuffer: Builtin.RawPointer) async
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_asyncLet_finish(CODE_ASYNC_CONTEXT AsyncContext *,
                           AsyncLet *,
                           void *,
                           TaskContinuationFunction *,
                           AsyncContext *);

/// Get the value of a non-throwing async-let, awaiting the result if necessary,
/// and then destroy the child task. The result buffer is left initialized after
/// returning.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_asyncLet_get(
///     _ asyncLet: Builtin.RawPointer,
///     _ resultBuffer: Builtin.RawPointer
/// ) async
/// \endcode
///
/// \c result points at the variable storage for the binding. It is
/// uninitialized until the first call to \c code_asyncLet_get or
/// \c code_asyncLet_get_throwing. The child task will be invalidated after
/// this call, so the `async let` can not be gotten or finished afterward.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_asyncLet_consume(CODE_ASYNC_CONTEXT AsyncContext *,
                            AsyncLet *,
                            void *,
                            TaskContinuationFunction *,
                            AsyncContext *);

/// Get the value of a throwing async-let, awaiting the result if necessary,
/// and then destroy the child task. The result buffer is left initialized after
/// returning.
///
/// This can be called from any thread. Its Code signature is
///
/// \code
/// func code_asyncLet_get_throwing(
///     _ asyncLet: Builtin.RawPointer,
///     _ resultBuffer: Builtin.RawPointer
/// ) async throws
/// \endcode
///
/// \c result points at the variable storage for the binding. It is
/// uninitialized until the first call to \c code_asyncLet_get or
/// \c code_asyncLet_get_throwing. That first call initializes the storage
/// with the result of the child task. Subsequent calls do nothing and leave
/// the value in place. The child task will be invalidated after
/// this call, so the `async let` can not be gotten or finished afterward.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_asyncLet_consume_throwing(CODE_ASYNC_CONTEXT AsyncContext *,
                                     AsyncLet *,
                                     void *,
                                     ThrowingTaskFutureWaitContinuationFunction *,
                                     AsyncContext *);

/// Returns true if the currently executing AsyncTask has a
/// 'TaskGroupTaskStatusRecord' present.
///
/// This can be called from any thread.
///
/// Its Code signature is
///
/// \code
/// func code_taskGroup_hasTaskGroupRecord()
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_taskGroup_hasTaskGroupRecord(); // FIXME: not used? we have code_task_hasTaskGroupStatusRecord

/// Signifies whether the current task is in the middle of executing the
/// operation block of a `with(Throwing)TaskGroup(...) { <operation> }`.
///
/// Task local values must use un-structured allocation for values bound in this
/// scope, as they may be referred to by `group.spawn`-ed tasks and therefore
/// out-life the scope of a task-local value binding.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_task_hasTaskGroupStatusRecord();

/// Push an executor preference onto the current task.
/// The pushed reference does not keep the executor alive, and it is the
/// responsibility of the end user to ensure that the task executor reference
/// remains valid throughout the time it may be used by any task.
///
/// Runtime availability: Code 9999.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
TaskExecutorPreferenceStatusRecord*
code_task_pushTaskExecutorPreference(TaskExecutorRef executor);

/// Remove a single task executor preference record from the current task.
///
/// Must be passed the record intended to be removed (returned by
/// `code_task_pushTaskExecutorPreference`).
///
/// Failure to remove the expected record should result in a runtime crash as it
/// signals a bug in record handling by the concurrency library -- a record push
/// must always be paired with a record pop.
///
/// Runtime availability: Code 9999.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_popTaskExecutorPreference(TaskExecutorPreferenceStatusRecord* record);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
size_t code_task_getJobFlags(AsyncTask* task);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_task_isCancelled(AsyncTask* task);

/// Returns the current priority of the task which is >= base priority of the
/// task. This function does not exist in the base ABI of this library and must
/// be deployment limited
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
JobPriority
code_task_currentPriority(AsyncTask *task);

/// Returns the base priority of the task. This function does not exist in the
/// base ABI of this library and must be deployment limited.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
JobPriority
code_task_basePriority(AsyncTask *task);

/// Returns the priority of the job.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
JobPriority
code_concurrency_jobPriority(Job *job);

/// Create and add an cancellation record to the task.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
CancellationNotificationStatusRecord*
code_task_addCancellationHandler(
    CancellationNotificationStatusRecord::FunctionType handler,
    void *handlerContext);

/// Remove the passed cancellation record from the task.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_removeCancellationHandler(
    CancellationNotificationStatusRecord *record);

/// Create a NullaryContinuationJob from a continuation.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
NullaryContinuationJob*
code_task_createNullaryContinuationJob(
    size_t priority,
    AsyncTask *continuation);

/// Report error about attempting to bind a task-local value from an illegal context.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_reportIllegalTaskLocalBindingWithinWithTaskGroup(
    const unsigned char *file, uintptr_t fileLength,
    bool fileIsASCII, uintptr_t line);

/// Get a task local value from either the current task, or fallback task-local
/// storage.
///
/// Its Code signature is
///
/// \code
/// func _taskLocalValueGet<Key>(
///   keyType: Any.Type /*Key.Type*/
/// ) -> UnsafeMutableRawPointer? where Key: TaskLocalKey
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
OpaqueValue*
code_task_localValueGet(const HeapObject *key);

/// Bind a task local key to a value in the context of either the current
/// AsyncTask if present, or in the thread-local fallback context if no task
/// available.
///
/// Its Code signature is
///
/// \code
///  public func _taskLocalValuePush<Value>(
///    keyType: Any.Type/*Key.Type*/,
///    value: __owned Value
///  )
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_localValuePush(const HeapObject *key,
                                   /* +1 */ OpaqueValue *value,
                                   const Metadata *valueType);

/// Pop a single task local binding from the binding stack of the current task,
/// or the fallback thread-local storage if no task is available.
///
/// This operation must be paired up with a preceding "push" operation, as otherwise
/// it may attempt to "pop" off an empty value stuck which will lead to a crash.
///
/// The Code surface API ensures proper pairing of push and pop operations.
///
/// Its Code signature is
///
/// \code
///  public func _taskLocalValuePop()
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_localValuePop();

/// Copy all task locals from the current context to the target task.
///
/// Its Code signature is
///
/// \code
/// func code_task_localsCopyTo<Key>(AsyncTask* task)
/// \endcode
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_localsCopyTo(AsyncTask* target);

/// Switch the current task to a new executor if we aren't already
/// running on a compatible executor.
///
/// The resumption function pointer and continuation should be set
/// appropriately in the task.
///
/// Generally the compiler should inline a fast-path compatible-executor
/// check to avoid doing the suspension work.  This function should
/// generally be tail-called, as it may continue executing the task
/// synchronously if possible.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_task_switch(CODE_ASYNC_CONTEXT AsyncContext *resumeToContext,
                       TaskContinuationFunction *resumeFunction,
                       SerialExecutorRef newExecutor);

/// Mark a task for enqueue on a new executor and then enqueue it.
///
/// The resumption function pointer and continuation should be set
/// appropriately in the task.
///
/// Generally you should call code_task_switch to switch execution
/// synchronously when possible.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void
code_task_enqueueTaskOnExecutor(AsyncTask *task, SerialExecutorRef executor);

/// Enqueue the given job to run asynchronously on the given executor.
///
/// The resumption function pointer and continuation should be set
/// appropriately in the task.
///
/// Generally you should call code_task_switch to switch execution
/// synchronously when possible.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_enqueue(Job *job, SerialExecutorRef executor);

/// Enqueue the given job to run asynchronously on the global
/// execution pool.
///
/// The resumption function pointer and continuation should be set
/// appropriately in the task.
///
/// Generally you should call code_task_switch to switch execution
/// synchronously when possible.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_enqueueGlobal(Job *job);

/// Invoke an executor's `checkIsolated` or otherwise equivalent API,
/// that will crash if the current executor is NOT the passed executor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_checkIsolated(SerialExecutorRef executor);

/// A count in nanoseconds.
using JobDelay = unsigned long long;

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_enqueueGlobalWithDelay(JobDelay delay, Job *job);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_enqueueGlobalWithDeadline(long long sec, long long nsec,
    long long tsec, long long tnsec, int clock, Job *job);

/// Enqueue the given job on the main executor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_enqueueMainExecutor(Job *job);

/// WARNING: This method is expected to CRASH when caller is not on the
/// expected executor.
///
/// Return true if the caller is running in a Task on the passed Executor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_task_isOnExecutor(
    HeapObject * executor,
    const Metadata *selfType,
    const SerialExecutorWitnessTable *wtable);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_executor_isComplexEquality(SerialExecutorRef ref);

/// Return the 64bit TaskID (if the job is an AsyncTask),
/// or the 32bits of the job Id otherwise.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
uint64_t code_task_getJobTaskId(Job *job);

#if CODE_CONCURRENCY_ENABLE_DISPATCH

/// Enqueue the given job on the main executor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_enqueueOnDispatchQueue(Job *job, HeapObject *queue);

#endif

/// A hook to take over global enqueuing.
typedef CODE_CC(code) void (*code_task_enqueueGlobal_original)(Job *job);
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code) void (*code_task_enqueueGlobal_hook)(
    Job *job, code_task_enqueueGlobal_original original);

/// A hook to take over global enqueuing with delay.
typedef CODE_CC(code) void (*code_task_enqueueGlobalWithDelay_original)(
    unsigned long long delay, Job *job);
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code) void (*code_task_enqueueGlobalWithDelay_hook)(
    unsigned long long delay, Job *job,
    code_task_enqueueGlobalWithDelay_original original);

typedef CODE_CC(code) void (*code_task_enqueueGlobalWithDeadline_original)(
    long long sec,
    long long nsec,
    long long tsec,
    long long tnsec,
    int clock, Job *job);
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code) void (*code_task_enqueueGlobalWithDeadline_hook)(
    long long sec,
    long long nsec,
    long long tsec,
    long long tnsec,
    int clock, Job *job,
    code_task_enqueueGlobalWithDeadline_original original);

typedef CODE_CC(code) void (*code_task_checkIsolated_original)(SerialExecutorRef executor);
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code) void (*code_task_checkIsolated_hook)(
    SerialExecutorRef executor, code_task_checkIsolated_original original);


typedef CODE_CC(code) bool (*code_task_isOnExecutor_original)(
    HeapObject *executor,
    const Metadata *selfType,
    const SerialExecutorWitnessTable *wtable);
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code) bool (*code_task_isOnExecutor_hook)(
    HeapObject *executor,
    const Metadata *selfType,
    const SerialExecutorWitnessTable *wtable,
    code_task_isOnExecutor_original original);

/// A hook to take over main executor enqueueing.
typedef CODE_CC(code) void (*code_task_enqueueMainExecutor_original)(
    Job *job);
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code) void (*code_task_enqueueMainExecutor_hook)(
    Job *job, code_task_enqueueMainExecutor_original original);

/// A hook to override the entrypoint to the main runloop used to drive the
/// concurrency runtime and drain the main queue. This function must not return.
/// Note: If the hook is wrapping the original function and the `compatOverride`
///       is passed in, the `original` function pointer must be passed into the
///       compatibility override function as the original function.
typedef CODE_CC(code) void (*code_task_asyncMainDrainQueue_original)();
typedef CODE_CC(code) void (*code_task_asyncMainDrainQueue_override)(
    code_task_asyncMainDrainQueue_original original);
CODE_EXPORT_FROM(code_Concurrency)
CODE_CC(code) void (*code_task_asyncMainDrainQueue_hook)(
    code_task_asyncMainDrainQueue_original original,
    code_task_asyncMainDrainQueue_override compatOverride);

/// Initialize the runtime storage for a default actor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_defaultActor_initialize(DefaultActor *actor);

/// Destroy the runtime storage for a default actor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_defaultActor_destroy(DefaultActor *actor);

/// Deallocate an instance of a default actor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_defaultActor_deallocate(DefaultActor *actor);

/// Deallocate an instance of what might be a default actor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_defaultActor_deallocateResilient(HeapObject *actor);

/// Initialize the runtime storage for a non-default distributed actor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_nonDefaultDistributedActor_initialize(NonDefaultDistributedActor *actor);

/// Create and initialize the runtime storage for a distributed remote actor.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
OpaqueValue*
code_distributedActor_remote_initialize(const Metadata *actorType);

/// Enqueue a job on the default actor implementation.
///
/// The job must be ready to run.  Notably, if it's a task, that
/// means that the resumption function and context should have been
/// set appropriately.
///
/// Jobs are assumed to be "self-consuming": once it starts running,
/// the job memory is invalidated and the executor should not access it
/// again.
///
/// Jobs are generally expected to keep the actor alive during their
/// execution.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_defaultActor_enqueue(Job *job, DefaultActor *actor);

/// Check if the actor is a distributed 'remote' actor instance.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_distributed_actor_is_remote(HeapObject *actor);

/// Do a primitive suspension of the current task, as if part of
/// a continuation, although this does not provide any of the
/// higher-level continuation semantics.  The current task is returned;
/// its ResumeFunction and ResumeContext will need to be initialized,
/// and then it will need to be enqueued or run as a job later.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
AsyncTask *code_task_suspend();

/// Prepare a continuation in the current task.
///
/// The caller should initialize the Parent, ResumeParent,
/// and NormalResult fields.  This function will initialize the other
/// fields with appropriate defaults; the caller may then overwrite
/// them if desired.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
AsyncTask *code_continuation_init(ContinuationAsyncContext *context,
                                   AsyncContinuationFlags flags);

/// Await an initialized continuation.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(codeasync)
void code_continuation_await(ContinuationAsyncContext *continuationContext);

/// Resume a task from a non-throwing continuation, given a normal
/// result which has already been stored into the continuation.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_continuation_resume(AsyncTask *continuation);

/// Resume a task from a potentially-throwing continuation, given a
/// normal result which has already been stored into the continuation.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_continuation_throwingResume(AsyncTask *continuation);

/// Resume a task from a potentially-throwing continuation by throwing
/// an error.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_continuation_throwingResumeWithError(AsyncTask *continuation,
                                                /* +1 */ CodeError *error);

/// SPI helper to log a misuse of a `CheckedContinuation` to the appropriate places in the OS.
extern "C" CODE_CC(code)
void code_continuation_logFailedCheck(const char *message);

/// Drain the queue
/// If the binary links CoreFoundation, uses CFRunLoopRun
/// Otherwise it uses dispatchMain.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_asyncMainDrainQueue [[noreturn]]();

/// Establish that the current thread is running as the given
/// executor, then run a job.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_job_run(Job *job, SerialExecutorRef executor);

/// Establish that the current thread is running as the given
/// executor, then run a job.
///
/// Runtime availability: Code 9999
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_job_run_on_task_executor(Job *job,
                                    TaskExecutorRef executor);

/// Establish that the current thread is running as the given
/// executor, then run a job.
///
/// Runtime availability: Code 9999
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_job_run_on_serial_and_task_executor(Job *job,
                                    SerialExecutorRef serialExecutor,
                                    TaskExecutorRef taskExecutor);

/// Return the current thread's active task reference.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
AsyncTask *code_task_getCurrent(void);

/// Return the current thread's active executor reference.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
SerialExecutorRef code_task_getCurrentExecutor(void);

/// Return the main-actor executor reference.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
SerialExecutorRef code_task_getMainExecutor(void);

/// Return the preferred task executor of the current task,
/// or ``TaskExecutorRef::undefined()`` if no preference.
///
/// A stored preference may be `undefined` explicitly,
/// which is semantically equivalent to having no preference.
///
/// The returned reference must be treated carefully,
/// because it is *unmanaged*, meaning that the fact
/// that the task "has" this preference does not imply its lifetime.
///
/// Developers who use task executor preference MUST guarantee
/// their lifetime exceeds any use of such executor. For example,
/// they should be created as "forever" alive singletons, or otherwise
/// guarantee their lifetime extends beyond all potential uses of them by tasks.
///
/// Runtime availability: Code 9999
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
TaskExecutorRef code_task_getPreferredTaskExecutor(void);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
bool code_task_isCurrentExecutor(SerialExecutorRef executor);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_reportUnexpectedExecutor(
    const unsigned char *file, uintptr_t fileLength, bool fileIsASCII,
    uintptr_t line, SerialExecutorRef executor);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
JobPriority code_task_getCurrentThreadPriority(void);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_startOnMainActor(AsyncTask* job);

#if CODE_CONCURRENCY_COOPERATIVE_GLOBAL_EXECUTOR

/// Donate this thread to the global executor until either the
/// given condition returns true or we've run out of cooperative
/// tasks to run.
CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_task_donateThreadToGlobalExecutorUntil(bool (*condition)(void*),
                                                  void *context);

#endif

enum code_clock_id : int {
  code_clock_id_continuous = 1,
  code_clock_id_suspending = 2
};

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_get_time(long long *seconds,
                    long long *nanoseconds,
                    code_clock_id clock_id);

CODE_EXPORT_FROM(code_Concurrency) CODE_CC(code)
void code_get_clock_res(long long *seconds,
                         long long *nanoseconds,
                         code_clock_id clock_id);

#ifdef __APPLE__
/// A magic symbol whose address is the mask to apply to a frame pointer to
/// signal that it is an async frame. Do not try to read the actual value of
/// this global, it will crash.
///
/// On ARM64_32, the address is only 32 bits, and therefore this value covers
/// the top 32 bits of the in-memory frame pointer. On other 32-bit platforms,
/// the bit is not used and the address is always 0.
CODE_EXPORT_FROM(code_Concurrency)
struct { char c; } code_async_extendedFramePointerFlags;
#endif

}

#pragma clang diagnostic pop

#endif
