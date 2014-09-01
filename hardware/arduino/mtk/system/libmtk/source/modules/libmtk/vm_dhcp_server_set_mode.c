#include "vmsys.h"
#include "vmdhcp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dhcp_server_set_mode_t)(VMUINT32 mode);
_vm_dhcp_server_set_mode_t _vm_dhcp_server_set_mode = NULL;
VMINT vm_dhcp_server_set_mode(VMUINT32 mode)
{
    if (NULL == _vm_dhcp_server_set_mode)
        _vm_dhcp_server_set_mode = (_vm_dhcp_server_set_mode_t)vm_get_sym_entry("vm_dhcp_server_set_mode");

    if (NULL != _vm_dhcp_server_set_mode)
        return _vm_dhcp_server_set_mode(mode);

    return -1;

}


