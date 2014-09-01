#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_is_support_wifi_t)(void);
_vm_is_support_wifi_t _vm_is_support_wifi = NULL;

VMINT vm_is_support_wifi(void)
{
    if (NULL == _vm_is_support_wifi)
        _vm_is_support_wifi = (_vm_is_support_wifi_t)vm_get_sym_entry("vm_is_support_wifi");

    if (NULL != _vm_is_support_wifi)
        return _vm_is_support_wifi();

    return (VMINT )-1;
}
