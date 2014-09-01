#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_set_host_name_t)(VMUINT8 * name);
_vm_btcm_set_host_name_t _vm_btcm_set_host_name = NULL;
VMINT vm_btcm_set_host_name(VMUINT8 * name)
{
    if (NULL == _vm_btcm_set_host_name)
        _vm_btcm_set_host_name = (_vm_btcm_set_host_name_t)vm_get_sym_entry("vm_btcm_set_host_name");

    if (NULL != _vm_btcm_set_host_name)
        return _vm_btcm_set_host_name(name);

    return (VMINT)-1;
}
