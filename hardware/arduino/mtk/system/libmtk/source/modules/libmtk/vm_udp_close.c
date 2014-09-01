#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_udp_close_t)(VMINT hdl);
_vm_udp_close_t _vm_udp_close = NULL;

VMINT vm_udp_close(VMINT hdl)
{
    if (NULL == _vm_udp_close)
        _vm_udp_close = (_vm_udp_close_t)vm_get_sym_entry("vm_udp_close");

    if (NULL != _vm_udp_close)
        return _vm_udp_close(hdl);

    return (VMINT )-1;
}
