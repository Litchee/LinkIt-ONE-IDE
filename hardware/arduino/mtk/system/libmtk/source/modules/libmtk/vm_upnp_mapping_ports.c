#include "vmsys.h"
#include "vmnat.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_upnp_mapping_ports_t)(VMUINT8  request_id, vm_upnp_result_cb cb, vm_upnp_map_info* request_data, void* user_data);
_vm_upnp_mapping_ports_t _vm_upnp_mapping_ports = NULL;

VMINT vm_upnp_mapping_ports(VMUINT8  request_id, vm_upnp_result_cb cb, vm_upnp_map_info* request_data, void* user_data)
{
    if (NULL == _vm_upnp_mapping_ports)
        _vm_upnp_mapping_ports = (_vm_upnp_mapping_ports_t)vm_get_sym_entry("vm_upnp_mapping_ports");
    if (NULL != _vm_upnp_mapping_ports)
        return _vm_upnp_mapping_ports(request_id,cb,request_data,user_data);
    return (VMINT)-1;
}