#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 (*_vm_reboot_normal_start_t)(void);
_vm_reboot_normal_start_t _vm_reboot_normal_start = NULL;

void vm_reboot_normal_start(void)
{
    if (NULL == _vm_reboot_normal_start)
        _vm_reboot_normal_start = (_vm_reboot_normal_start_t)vm_get_sym_entry("vm_reboot_normal_start");

    if (NULL != _vm_reboot_normal_start)
        _vm_reboot_normal_start();
}
