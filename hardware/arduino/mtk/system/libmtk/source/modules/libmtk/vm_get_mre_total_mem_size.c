#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_mre_total_mem_size_t)(void);
_vm_get_mre_total_mem_size_t _vm_get_mre_total_mem_size = NULL;

VMUINT vm_get_mre_total_mem_size(void)
{
    if (NULL == _vm_get_mre_total_mem_size)
        _vm_get_mre_total_mem_size = (_vm_get_mre_total_mem_size_t)vm_get_sym_entry("vm_get_mre_total_mem_size");

    if (NULL != _vm_get_mre_total_mem_size)
        return _vm_get_mre_total_mem_size();

    return (VMUINT )0;
}
