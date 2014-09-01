#include "vmsys.h"
#include "vmwdt.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_assert_t)(VMSTR file, VMINT line);
_vm_assert_t _vm_assert = NULL;

void vm_assert(VMSTR file, VMINT line)
{
    if (NULL == _vm_assert)
        _vm_assert = (_vm_assert_t)vm_get_sym_entry("vm_assert");

    if (NULL != _vm_assert)
        _vm_assert(file,line);
}
