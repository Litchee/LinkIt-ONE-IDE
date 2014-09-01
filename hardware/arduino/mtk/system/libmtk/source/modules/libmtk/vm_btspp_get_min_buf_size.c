#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_get_min_buf_size_t)(void);
_vm_btspp_get_min_buf_size_t _vm_btspp_get_min_buf_size = NULL;
VMINT vm_btspp_get_min_buf_size(void)
{
    if (NULL == _vm_btspp_get_min_buf_size)
        _vm_btspp_get_min_buf_size = (_vm_btspp_get_min_buf_size_t)vm_get_sym_entry("vm_btspp_get_min_buf_size");

    if (NULL != _vm_btspp_get_min_buf_size)
        return _vm_btspp_get_min_buf_size();

    return (VMINT)-1;
}
