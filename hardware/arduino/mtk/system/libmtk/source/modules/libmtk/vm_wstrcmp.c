#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wstrcmp_t)(VMWSTR str_1, VMWSTR str_2);
_vm_wstrcmp_t _vm_wstrcmp = NULL;

VMINT vm_wstrcmp(VMWSTR str_1, VMWSTR str_2)
{
    if (NULL == _vm_wstrcmp)
        _vm_wstrcmp = (_vm_wstrcmp_t)vm_get_sym_entry("vm_wstrcmp");

    if (NULL != _vm_wstrcmp)
        return _vm_wstrcmp(str_1,str_2);

    return (VMINT )-1;
}
