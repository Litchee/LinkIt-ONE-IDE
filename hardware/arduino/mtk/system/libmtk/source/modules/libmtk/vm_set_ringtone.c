#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_set_ringtone_t)(VMWSTR filepath);
_vm_set_ringtone_t _vm_set_ringtone = NULL;

VMINT vm_set_ringtone(VMWSTR filepath)
{
    if (NULL == _vm_set_ringtone)
        _vm_set_ringtone = (_vm_set_ringtone_t)vm_get_sym_entry("vm_set_ringtone");

    if (NULL != _vm_set_ringtone)
        return _vm_set_ringtone(filepath);

    return (VMINT )-1;
}
