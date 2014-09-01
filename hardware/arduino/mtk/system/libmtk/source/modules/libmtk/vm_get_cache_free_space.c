#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_cache_free_space_t)(vm_cache_t *cache);
_vm_get_cache_free_space_t _vm_get_cache_free_space = NULL;

VMINT vm_get_cache_free_space(vm_cache_t *cache)
{
    if (NULL == _vm_get_cache_free_space)
        _vm_get_cache_free_space = (_vm_get_cache_free_space_t)vm_get_sym_entry("vm_get_cache_free_space");

    if (NULL != _vm_get_cache_free_space)
        return _vm_get_cache_free_space(cache);

    return (VMINT )-1;
}
