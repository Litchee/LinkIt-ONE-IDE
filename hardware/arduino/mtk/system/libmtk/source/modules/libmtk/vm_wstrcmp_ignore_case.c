#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wstrcmp_ignore_case_t)(VMWSTR str_1, VMWSTR str_2);
_vm_wstrcmp_ignore_case_t _vm_wstrcmp_ignore_case = NULL;

VMINT vm_wstrcmp_ignore_case(VMWSTR str_1, VMWSTR str_2)
{
    if (NULL == _vm_wstrcmp_ignore_case)
        _vm_wstrcmp_ignore_case = (_vm_wstrcmp_ignore_case_t)vm_get_sym_entry("vm_wstrcmp_ignore_case");

    if (NULL != _vm_wstrcmp_ignore_case)
        return _vm_wstrcmp_ignore_case(str_1,str_2);

    return (VMINT )-1;
}
