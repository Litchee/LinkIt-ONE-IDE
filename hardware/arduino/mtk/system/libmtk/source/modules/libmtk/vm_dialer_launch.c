#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dialer_launch_t)(VMWSTR phone_num);
_vm_dialer_launch_t _vm_dialer_launch = NULL;

VMINT vm_dialer_launch(VMWSTR phone_num)
{
    if (NULL == _vm_dialer_launch)
        _vm_dialer_launch = (_vm_dialer_launch_t)vm_get_sym_entry("vm_dialer_launch");

    if (NULL != _vm_dialer_launch)
        return _vm_dialer_launch(phone_num);

    return -1;
}
