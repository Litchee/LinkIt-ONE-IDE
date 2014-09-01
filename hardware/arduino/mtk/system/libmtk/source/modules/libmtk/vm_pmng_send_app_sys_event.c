#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_send_app_sys_event_t)(VM_PROCESS_STATUS pmng_status);
_vm_pmng_send_app_sys_event_t _vm_pmng_send_app_sys_event = NULL;

VMINT vm_pmng_send_app_sys_event(VM_PROCESS_STATUS pmng_status)
{
    if (NULL == _vm_pmng_send_app_sys_event)
        _vm_pmng_send_app_sys_event = (_vm_pmng_send_app_sys_event_t)vm_get_sym_entry("vm_pmng_send_app_sys_event");

    if (NULL != _vm_pmng_send_app_sys_event)
        return _vm_pmng_send_app_sys_event(pmng_status);

    return -1;
}
