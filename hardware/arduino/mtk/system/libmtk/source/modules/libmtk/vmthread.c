#include "vmsys.h"
#include "vmthread.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_SIGNAL_ID (*_vm_signal_init_t)(void);
_vm_signal_init_t _vm_signal_init = NULL;
VM_SIGNAL_ID vm_signal_init(void)
{
    if (NULL == _vm_signal_init)
        _vm_signal_init = (_vm_signal_init_t)vm_get_sym_entry("vm_signal_init");

    if (NULL != _vm_signal_init)
        return _vm_signal_init();

    return 0;
}

typedef void (*_vm_signal_clean_t)(VM_SIGNAL_ID s_id);
_vm_signal_clean_t _vm_signal_clean = NULL;
void vm_signal_clean(VM_SIGNAL_ID s_id)
{
    if (NULL == _vm_signal_clean)
        _vm_signal_clean = (_vm_signal_clean_t)vm_get_sym_entry("vm_signal_clean");

    if (NULL != _vm_signal_clean)
        _vm_signal_clean(s_id);
}

typedef void (*_vm_signal_post_t)(VM_SIGNAL_ID s_id);
_vm_signal_post_t _vm_signal_post = NULL;
void vm_signal_post(VM_SIGNAL_ID s_id)
{
    if (NULL == _vm_signal_post)
        _vm_signal_post = (_vm_signal_post_t)vm_get_sym_entry("vm_signal_post");

    if (NULL != _vm_signal_post)
        _vm_signal_post(s_id);
}

typedef VMINT32 (*_vm_signal_wait_t)(VM_SIGNAL_ID s_id);
_vm_signal_wait_t _vm_signal_wait = NULL;
VMINT32 vm_signal_wait(VM_SIGNAL_ID s_id)
{
    if (NULL == _vm_signal_wait)
        _vm_signal_wait = (_vm_signal_wait_t)vm_get_sym_entry("vm_signal_wait");

    if (NULL != _vm_signal_wait)
        return _vm_signal_wait(s_id);

    return (VMINT )-1;
}

typedef VMINT32 (*_vm_signal_timedwait_t)(VM_SIGNAL_ID s_id, VMUINT32 time_count);
_vm_signal_timedwait_t _vm_signal_timedwait = NULL;
VMINT32 vm_signal_timedwait(VM_SIGNAL_ID s_id, VMUINT32 time_count)
{
    if (NULL == _vm_signal_timedwait)
        _vm_signal_timedwait = (_vm_signal_timedwait_t)vm_get_sym_entry("vm_signal_timedwait");

    if (NULL != _vm_signal_timedwait)
        return _vm_signal_timedwait(s_id, time_count);

    return (VMINT )0;
}

typedef void (*_vm_signal_deinit_t)(VM_SIGNAL_ID s_id);
_vm_signal_deinit_t _vm_signal_deinit = NULL;
void vm_signal_deinit(VM_SIGNAL_ID s_id)
{
    if (NULL == _vm_signal_deinit)
        _vm_signal_deinit = (_vm_signal_deinit_t)vm_get_sym_entry("vm_signal_deinit");

    if (NULL != _vm_signal_deinit)
        _vm_signal_deinit(s_id);
}


typedef void (*_vm_mutex_create_t)(vm_thread_mutex_struct *mutex);
_vm_mutex_create_t _vm_mutex_create = NULL;
void vm_mutex_create(vm_thread_mutex_struct *mutex)
{
    if (NULL == _vm_mutex_create)
        _vm_mutex_create = (_vm_mutex_create_t)vm_get_sym_entry("vm_mutex_create");

    if (NULL != _vm_mutex_create)
        _vm_mutex_create(mutex);
}

typedef void (*_vm_mutex_lock_t)(vm_thread_mutex_struct *mutex);
_vm_mutex_lock_t _vm_mutex_lock = NULL;
void vm_mutex_lock(vm_thread_mutex_struct *mutex)
{
    if (NULL == _vm_mutex_lock)
        _vm_mutex_lock = (_vm_mutex_lock_t)vm_get_sym_entry("vm_mutex_lock");

    if (NULL != _vm_mutex_lock)
        _vm_mutex_lock(mutex);
}

typedef void (*_vm_mutex_unlock_t)(vm_thread_mutex_struct *mutex);
_vm_mutex_unlock_t _vm_mutex_unlock = NULL;
void vm_mutex_unlock(vm_thread_mutex_struct *mutex)
{
    if (NULL == _vm_mutex_unlock)
        _vm_mutex_unlock = (_vm_mutex_unlock_t)vm_get_sym_entry("vm_mutex_unlock");

    if (NULL != _vm_mutex_unlock)
        _vm_mutex_unlock(mutex);
}

typedef void (*_vm_thread_sleep_t)(VMUINT32 timeout);
_vm_thread_sleep_t _vm_thread_sleep = NULL;
void vm_thread_sleep(VMUINT32 timeout)
{
    if (NULL == _vm_thread_sleep)
        _vm_thread_sleep = (_vm_thread_sleep_t)vm_get_sym_entry("vm_thread_sleep");

    if (NULL != _vm_thread_sleep)
        _vm_thread_sleep(timeout);
}

typedef void (*_vm_thread_change_priority_t)(VM_THREAD_HANDLE thread_handle, VMUINT32 new_priority);
_vm_thread_change_priority_t _vm_thread_change_priority = NULL;
void vm_thread_change_priority(VM_THREAD_HANDLE thread_handle, VMUINT32 new_priority)
{
    if (NULL == _vm_thread_change_priority)
        _vm_thread_change_priority = (_vm_thread_change_priority_t)vm_get_sym_entry("vm_thread_change_priority");

    if (NULL != _vm_thread_change_priority)
        _vm_thread_change_priority(thread_handle, new_priority);
}

