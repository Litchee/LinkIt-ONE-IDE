#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_write_cache_t)(vm_cache_t *cache, void *buf, VMINT buf_len);
_vm_write_cache_t _vm_write_cache = NULL;

VMINT vm_write_cache(vm_cache_t *cache, void *buf, VMINT buf_len)
{
    if (NULL == _vm_write_cache)
        _vm_write_cache = (_vm_write_cache_t)vm_get_sym_entry("vm_write_cache");

    if (NULL != _vm_write_cache)
        return _vm_write_cache(cache,buf,buf_len);

    return (VMINT )-1;
}
