#include "vmsys.h"
#include "vmbridge.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_bridge_create_t)(vm_bridge_info *firPeer, vm_bridge_info *secPeer);
_vm_bridge_create_t _vm_bridge_create = NULL;

VMINT vm_bridge_create(vm_bridge_info *firPeer, vm_bridge_info *secPeer)
{
    if (NULL == _vm_bridge_create)
        _vm_bridge_create = (_vm_bridge_create_t)vm_get_sym_entry("vm_bridge_create");

    if (NULL != _vm_bridge_create)
        return _vm_bridge_create(firPeer,secPeer);
        
    return (VMINT )-1;
}
