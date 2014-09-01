#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_read_t)(VMUINT conn_id, void * buf, VMUINT size);
_vm_btspp_read_t _vm_btspp_read = NULL;
VMINT vm_btspp_read(VMUINT conn_id, void * buf, VMUINT size)
{
    if (NULL == _vm_btspp_read)
        _vm_btspp_read = (_vm_btspp_read_t)vm_get_sym_entry("vm_btspp_read");

    if (NULL != _vm_btspp_read)
        return _vm_btspp_read(conn_id,buf,size);

    return (VMINT)-1;
}
