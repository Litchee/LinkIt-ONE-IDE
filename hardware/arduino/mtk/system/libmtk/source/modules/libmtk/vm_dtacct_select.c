#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dtacct_select_t)(VMINT sim_id, VMINT (*callback)(VMUINT32 dtacct));
_vm_dtacct_select_t _vm_dtacct_select = NULL;
VMINT vm_dtacct_select(VMINT sim_id, VMINT (*callback)(VMUINT32 dtacct))
{
    if (NULL == _vm_dtacct_select)
        _vm_dtacct_select = (_vm_dtacct_select_t)vm_get_sym_entry("vm_dtacct_select");

    if (NULL != _vm_dtacct_select)
        return _vm_dtacct_select(sim_id, callback);

    return -1;
}


