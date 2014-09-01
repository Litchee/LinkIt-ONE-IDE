#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_memcpy_t)(void* dst, void* src, VMINT count);
_vm_memcpy_t _vm_memcpy = NULL;

void vm_memcpy(void* dst, void* src, VMINT count)
{
    if (NULL == _vm_memcpy)
        _vm_memcpy = (_vm_memcpy_t)vm_get_sym_entry("vm_memcpy");

    if (NULL != _vm_memcpy)
        _vm_memcpy(dst,src,count);

    
}
