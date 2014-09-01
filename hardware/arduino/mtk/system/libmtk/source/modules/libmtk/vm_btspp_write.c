#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_write_t)(VMUINT conn_id, void * buf, VMUINT size);
_vm_btspp_write_t _vm_btspp_write = NULL;
VMINT vm_btspp_write(VMUINT conn_id, void * buf, VMUINT size)
{
    if (NULL == _vm_btspp_write)
        _vm_btspp_write = (_vm_btspp_write_t)vm_get_sym_entry("vm_btspp_write");

    if (NULL != _vm_btspp_write)
        return _vm_btspp_write(conn_id,buf,size);

    return (VMINT)-1;
}
