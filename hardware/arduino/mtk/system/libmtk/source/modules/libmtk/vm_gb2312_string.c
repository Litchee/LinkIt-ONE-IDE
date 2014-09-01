#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef char *(*_vm_gb2312_string_t)(VMWSTR s);
_vm_gb2312_string_t _vm_gb2312_string = NULL;

char *vm_gb2312_string(VMWSTR s)
{
    if (NULL == _vm_gb2312_string)
        _vm_gb2312_string = (_vm_gb2312_string_t)vm_get_sym_entry("vm_gb2312_string");

    if (NULL != _vm_gb2312_string)
        return _vm_gb2312_string(s);

    return (char *)-1;
}
