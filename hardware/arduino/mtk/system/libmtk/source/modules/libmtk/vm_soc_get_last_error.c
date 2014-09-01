#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_get_last_error_t)(void);
_vm_soc_get_last_error_t _vm_soc_get_last_error = NULL;

VMINT vm_soc_get_last_error(void)
{
    if (NULL == _vm_soc_get_last_error)
        _vm_soc_get_last_error = (_vm_soc_get_last_error_t)vm_get_sym_entry("vm_soc_get_last_error");
    if (NULL != _vm_soc_get_last_error)
        return _vm_soc_get_last_error();
    return (VMINT)-100;
}