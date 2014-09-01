#include "vmsys.h"
#include "vmgettag.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_multi_tags_t)( short* filename, MULTI_TAG * tag_req);
_vm_get_multi_tags_t _vm_get_multi_tags = NULL;

VMINT vm_get_multi_tags( short* filename, MULTI_TAG * tag_req)
{
    if (NULL == _vm_get_multi_tags)
        _vm_get_multi_tags = (_vm_get_multi_tags_t)vm_get_sym_entry("vm_get_multi_tags");

    if (NULL != _vm_get_multi_tags)
        return _vm_get_multi_tags(filename,tag_req);

    return (VMINT )-1;
}
