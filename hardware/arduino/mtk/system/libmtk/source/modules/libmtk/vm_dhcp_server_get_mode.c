#include "vmsys.h"
#include "vmdhcp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dhcp_server_get_mode_t)(void);
_vm_dhcp_server_get_mode_t _vm_dhcp_server_get_mode = NULL;
VMINT vm_dhcp_server_get_mode(void)
{
    if (NULL == _vm_dhcp_server_get_mode)
        _vm_dhcp_server_get_mode = (_vm_dhcp_server_get_mode_t)vm_get_sym_entry("vm_dhcp_server_get_mode");

    if (NULL != _vm_dhcp_server_get_mode)
        return _vm_dhcp_server_get_mode();

    return -1;

}


