#include "vmsys.h"
#include "vmgettag.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_vm_tag_t)(short* filename,int tag_num, void* buf ,int* buf_size);
_vm_get_vm_tag_t _vm_get_vm_tag = NULL;

VMINT vm_get_vm_tag(short* filename,int tag_num, void* buf ,int* buf_size)
{
    if (NULL == _vm_get_vm_tag)
        _vm_get_vm_tag = (_vm_get_vm_tag_t)vm_get_sym_entry("vm_get_vm_tag");

    if (NULL != _vm_get_vm_tag)
        return _vm_get_vm_tag(filename,tag_num,buf ,buf_size);

    return (VMINT )-1;
}
