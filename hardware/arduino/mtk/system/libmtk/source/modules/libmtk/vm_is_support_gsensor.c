#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_is_support_gsensor_t)(void);
_vm_is_support_gsensor_t _vm_is_support_gsensor = NULL;

VMINT vm_is_support_gsensor(void)
{
    if (NULL == _vm_is_support_gsensor)
        _vm_is_support_gsensor = (_vm_is_support_gsensor_t)vm_get_sym_entry("vm_is_support_gsensor");

    if (NULL != _vm_is_support_gsensor)
        return _vm_is_support_gsensor();

    return (VMINT )-1;
}
