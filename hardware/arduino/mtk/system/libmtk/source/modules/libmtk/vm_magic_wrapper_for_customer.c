#include "vmsys.h"
#include "vmmagic.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_magic_wrapper_for_customer_t)(VMINT index, void* param, void* reserve);
_vm_magic_wrapper_for_customer_t _vm_magic_wrapper_for_customer = NULL;

VMINT vm_magic_wrapper_for_customer(VMINT index, void* param, void* reserve)
{
    if (NULL == _vm_magic_wrapper_for_customer)
        _vm_magic_wrapper_for_customer = (_vm_magic_wrapper_for_customer_t)vm_get_sym_entry("vm_magic_wrapper_for_customer");
    if (NULL != _vm_magic_wrapper_for_customer)
        return _vm_magic_wrapper_for_customer(index,param,reserve);
    return (VMINT)-1;
}