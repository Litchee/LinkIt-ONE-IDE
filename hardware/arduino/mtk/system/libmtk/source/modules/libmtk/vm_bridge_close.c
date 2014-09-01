#include "vmsys.h"
#include "vmbridge.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_bridge_close_t)(vm_bridge_info *firPeer, vm_bridge_info *secPeer);
_vm_bridge_close_t _vm_bridge_close = NULL;

VMINT vm_bridge_close(vm_bridge_info *firPeer, vm_bridge_info *secPeer)
{
    if (NULL == _vm_bridge_close)
        _vm_bridge_close = (_vm_bridge_close_t)vm_get_sym_entry("vm_bridge_close");

    if (NULL != _vm_bridge_close)
        return _vm_bridge_close(firPeer,secPeer);
        
    return (VMINT )-1;
}
