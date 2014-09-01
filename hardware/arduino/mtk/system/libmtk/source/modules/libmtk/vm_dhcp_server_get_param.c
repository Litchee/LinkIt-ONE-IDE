#include "vmsys.h"
#include "vmdhcp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dhcp_server_get_param_t)(vm_dhcp_server_config_struct *param);
_vm_dhcp_server_get_param_t _vm_dhcp_server_get_param = NULL;
VMINT vm_dhcp_server_get_param(vm_dhcp_server_config_struct *param)
{
    if (NULL == _vm_dhcp_server_get_param)
        _vm_dhcp_server_get_param = (_vm_dhcp_server_get_param_t)vm_get_sym_entry("vm_dhcp_server_get_param");

    if (NULL != _vm_dhcp_server_get_param)
        return _vm_dhcp_server_get_param(param);

    return -1;

}


