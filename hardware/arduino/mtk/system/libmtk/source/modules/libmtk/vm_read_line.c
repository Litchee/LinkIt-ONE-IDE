#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_read_line_t)(char* line, VMINT size, vm_cache_t* cache);
_vm_read_line_t _vm_read_line = NULL;

VMINT vm_read_line(char* line, VMINT size, vm_cache_t* cache)
{
    if (NULL == _vm_read_line)
        _vm_read_line = (_vm_read_line_t)vm_get_sym_entry("vm_read_line");

    if (NULL != _vm_read_line)
        return _vm_read_line(line,size,cache);

    return (VMINT )-1;
}
