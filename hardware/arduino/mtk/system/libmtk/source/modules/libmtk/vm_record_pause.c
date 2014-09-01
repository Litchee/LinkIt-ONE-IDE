#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_record_pause_t)(void);
_vm_record_pause_t _vm_record_pause = NULL;

VMINT vm_record_pause(void)
{
    if (NULL == _vm_record_pause)
        _vm_record_pause = (_vm_record_pause_t)vm_get_sym_entry("vm_record_pause");

    if (NULL != _vm_record_pause)
        return _vm_record_pause();

    return (VMINT )-1;
}
