/* Julia DTrace provider */

provider julia {
    probe gc__begin(int collection);
    probe gc__stop_the_world();
    probe gc__mark__begin();
    probe gc__mark__end(int64_t scanned_bytes, int64_t perm_scanned_bytes);
    probe gc__sweep__begin(int full);
    probe gc__sweep__end();
    probe gc__end();
    probe gc__finalizer();

    probe rt__run__task(language_task_t *task);
    probe rt__pause__task(language_task_t *task);
    probe rt__new__task(language_task_t *parent, language_task_t *child);
    probe rt__start__task(language_task_t *task);
    probe rt__finish__task(language_task_t *task);
    probe rt__start__process__events(language_task_t *task);
    probe rt__finish__process__events(language_task_t *task);
    probe rt__taskq__insert(language_ptls_t ptls, language_task_t *task);
    probe rt__taskq__get(language_ptls_t ptls, language_task_t *task);
    probe rt__sleep__check__wake(language_ptls_t other, int8_t old_state);
    probe rt__sleep__check__wakeup(language_ptls_t ptls);
    probe rt__sleep__check__sleep(language_ptls_t ptls);
    probe rt__sleep__check__taskq__wake(language_ptls_t ptls);
    probe rt__sleep__check__task__wake(language_ptls_t ptls);
    probe rt__sleep__check__uv__wake(language_ptls_t ptls);
};

#pragma D attributes Evolving/Evolving/Common provider julia provider
#pragma D attributes Evolving/Evolving/Common provider julia module
#pragma D attributes Evolving/Evolving/Common provider julia function
#pragma D attributes Evolving/Evolving/Common provider julia name
#pragma D attributes Evolving/Evolving/Common provider julia args
