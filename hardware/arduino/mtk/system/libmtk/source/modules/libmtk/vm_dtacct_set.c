#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;


typedef VMINT (*_vm_dtacct_set_t)(VMINT sim_id, VMUINT32 dtacct);
_vm_dtacct_set_t _vm_dtacct_set = NULL;
VMINT vm_dtacct_set(VMINT sim_id, VMUINT32 dtacct)
{
    if (NULL == _vm_dtacct_set)
        _vm_dtacct_set = (_vm_dtacct_set_t)vm_get_sym_entry("vm_dtacct_set");

    if (NULL != _vm_dtacct_set)
        return _vm_dtacct_set(sim_id, dtacct);

    return -1;
}


