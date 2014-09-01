#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_string_equals_ignore_case_t)(const char *s1, const char *s2);
_vm_string_equals_ignore_case_t _vm_string_equals_ignore_case = NULL;

VMINT vm_string_equals_ignore_case(const char *s1, const char *s2)
{
    if (NULL == _vm_string_equals_ignore_case)
        _vm_string_equals_ignore_case = (_vm_string_equals_ignore_case_t)vm_get_sym_entry("vm_string_equals_ignore_case");

    if (NULL != _vm_string_equals_ignore_case)
        return _vm_string_equals_ignore_case(s1,s2);

    return (VMINT )-1;
}
