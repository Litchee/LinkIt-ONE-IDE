#include "vmsys.h"
#include "vmpwr.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_shutdown_normal_start_t)(VMUINT16 trigger_man_app_id);
_vm_shutdown_normal_start_t _vm_shutdown_normal_start = NULL;

void vm_shutdown_normal_start(VMUINT16 trigger_man_app_id)
{
    if (NULL == _vm_shutdown_normal_start)
        _vm_shutdown_normal_start = (_vm_shutdown_normal_start_t)vm_get_sym_entry("vm_shutdown_normal_start");

    if (NULL != _vm_shutdown_normal_start)
        _vm_shutdown_normal_start(trigger_man_app_id);
}
