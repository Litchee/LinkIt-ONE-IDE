#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ivr_end_t)(void);
_vm_ivr_end_t _vm_ivr_end = NULL;

VMINT vm_ivr_end(void)
{
    if (NULL == _vm_ivr_end)
        _vm_ivr_end = (_vm_ivr_end_t)vm_get_sym_entry("vm_ivr_end");

    if (NULL != _vm_ivr_end)
        return _vm_ivr_end();

    return (VMINT )-1;
}
