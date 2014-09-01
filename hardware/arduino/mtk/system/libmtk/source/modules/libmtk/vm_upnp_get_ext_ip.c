#include "vmsys.h"
#include "vmnat.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_upnp_get_ext_ip_t)(VMUINT8  request_id, vm_upnp_result_cb cb, void *user_data);
_vm_upnp_get_ext_ip_t _vm_upnp_get_ext_ip = NULL;

VMINT vm_upnp_get_ext_ip(VMUINT8  request_id, vm_upnp_result_cb cb, void *user_data)
{
    if (NULL == _vm_upnp_get_ext_ip)
        _vm_upnp_get_ext_ip = (_vm_upnp_get_ext_ip_t)vm_get_sym_entry("vm_upnp_get_ext_ip");
    if (NULL != _vm_upnp_get_ext_ip)
        return _vm_upnp_get_ext_ip(request_id,cb,user_data);
    return (VMINT)-1;
}