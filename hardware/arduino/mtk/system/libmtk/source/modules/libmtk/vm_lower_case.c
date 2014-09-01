#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_lower_case_t)(char* dst, char* src);
_vm_lower_case_t _vm_lower_case = NULL;

void vm_lower_case(char* dst, char* src)
{
    if (NULL == _vm_lower_case)
        _vm_lower_case = (_vm_lower_case_t)vm_get_sym_entry("vm_lower_case");

    if (NULL != _vm_lower_case)
        _vm_lower_case(dst,src);

    
}
