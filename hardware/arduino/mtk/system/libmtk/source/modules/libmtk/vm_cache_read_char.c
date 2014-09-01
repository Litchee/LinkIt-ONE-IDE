#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_cache_read_char_t)(vm_cache_t *cache, char *ch);
_vm_cache_read_char_t _vm_cache_read_char = NULL;

VMINT vm_cache_read_char(vm_cache_t *cache, char *ch)
{
    if (NULL == _vm_cache_read_char)
        _vm_cache_read_char = (_vm_cache_read_char_t)vm_get_sym_entry("vm_cache_read_char");

    if (NULL != _vm_cache_read_char)
        return _vm_cache_read_char(cache,ch);

    return (VMINT )-1;
}
