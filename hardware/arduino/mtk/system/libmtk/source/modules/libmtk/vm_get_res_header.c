#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_res_header_t)(void);
_vm_get_res_header_t _vm_get_res_header = NULL;

VMINT vm_get_res_header(void)
{
    if (NULL == _vm_get_res_header)
        _vm_get_res_header = (_vm_get_res_header_t)vm_get_sym_entry("vm_get_res_header");

    if (NULL != _vm_get_res_header)
       return _vm_get_res_header();
    return 0;
}
