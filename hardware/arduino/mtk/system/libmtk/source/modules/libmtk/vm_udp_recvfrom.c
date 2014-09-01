#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_udp_recvfrom_t)(VMINT hdl, void * buf, VMINT32 len, vm_sockaddr_struct * addr);
_vm_udp_recvfrom_t _vm_udp_recvfrom = NULL;

VMINT vm_udp_recvfrom(VMINT hdl, void * buf, VMINT32 len, vm_sockaddr_struct * addr)
{
    if (NULL == _vm_udp_recvfrom)
        _vm_udp_recvfrom = (_vm_udp_recvfrom_t)vm_get_sym_entry("vm_udp_recvfrom");

    if (NULL != _vm_udp_recvfrom)
        return _vm_udp_recvfrom(hdl, buf, len, addr);

    return (VMINT )-1;
}
