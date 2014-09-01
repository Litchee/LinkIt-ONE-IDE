#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_udp_sendto_t)(VMINT hdl, const void * buf, VMINT32 len, const vm_sockaddr_struct * addr);
_vm_udp_sendto_t _vm_udp_sendto = NULL;

VMINT vm_udp_sendto(VMINT hdl, const void * buf, VMINT32 len, const vm_sockaddr_struct * addr)
{
    if (NULL == _vm_udp_sendto)
        _vm_udp_sendto = (_vm_udp_sendto_t)vm_get_sym_entry("vm_udp_sendto");

    if (NULL != _vm_udp_sendto)
        return _vm_udp_sendto(hdl, buf, len, addr);

    return (VMINT )-1;
}
