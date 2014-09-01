#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_exit_t)(VMINT res_hd);
_vm_btcm_exit_t _vm_btcm_exit = NULL;
VMINT vm_btcm_exit(VMINT res_hd)
{
    if (NULL == _vm_btcm_exit)
        _vm_btcm_exit = (_vm_btcm_exit_t)vm_get_sym_entry("vm_btcm_exit");

    if (NULL != _vm_btcm_exit)
        return _vm_btcm_exit(res_hd);

    return (VMINT)-1;
}
