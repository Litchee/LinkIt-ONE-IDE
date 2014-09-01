#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef malloc_stat_t* (*_vm_get_malloc_stat_t)(void);
_vm_get_malloc_stat_t _vm_get_malloc_stat = NULL;

malloc_stat_t* vm_get_malloc_stat(void)
{
    if (NULL == _vm_get_malloc_stat)
        _vm_get_malloc_stat = (_vm_get_malloc_stat_t)vm_get_sym_entry("vm_get_malloc_stat");

    if (NULL != _vm_get_malloc_stat)
        return _vm_get_malloc_stat();

    return (malloc_stat_t* )-1;
}
