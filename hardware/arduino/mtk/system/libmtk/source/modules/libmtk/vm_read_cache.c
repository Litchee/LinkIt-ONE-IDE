#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_read_cache_t)(vm_cache_t *cache, void *buf, VMINT buf_size, VMINT len);
_vm_read_cache_t _vm_read_cache = NULL;

VMINT vm_read_cache(vm_cache_t *cache, void *buf, VMINT buf_size, VMINT len)
{
    if (NULL == _vm_read_cache)
        _vm_read_cache = (_vm_read_cache_t)vm_get_sym_entry("vm_read_cache");

    if (NULL != _vm_read_cache)
        return _vm_read_cache(cache,buf,buf_size,len);

    return (VMINT )-1;
}
