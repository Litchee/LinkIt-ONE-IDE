#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_upper_case_t)(char* dst, char* src);
_vm_upper_case_t _vm_upper_case = NULL;

void vm_upper_case(char* dst, char* src)
{
    if (NULL == _vm_upper_case)
        _vm_upper_case = (_vm_upper_case_t)vm_get_sym_entry("vm_upper_case");

    if (NULL != _vm_upper_case)
        _vm_upper_case(dst,src);

    
}
