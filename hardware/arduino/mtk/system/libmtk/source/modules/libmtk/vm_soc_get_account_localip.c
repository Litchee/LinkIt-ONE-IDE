#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_get_account_localip_t)(VMINT8 sock, VMUINT8 *local_ip);
_vm_soc_get_account_localip_t _vm_soc_get_account_localip = NULL;

VMINT vm_soc_get_account_localip(VMINT8 sock, VMUINT8 *local_ip)
{
    if (NULL == _vm_soc_get_account_localip)
        _vm_soc_get_account_localip = (_vm_soc_get_account_localip_t)vm_get_sym_entry("vm_soc_get_account_localip");
    if (NULL != _vm_soc_get_account_localip)
        return _vm_soc_get_account_localip(sock,local_ip);
    return (VMINT)-100;
}