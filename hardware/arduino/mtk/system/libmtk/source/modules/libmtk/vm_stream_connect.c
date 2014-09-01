#include "vmsys.h"
#include "vmstream.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_stream_connect_t)(vm_stream_connect_struct connect_info);
_vm_stream_connect_t _vm_stream_connect = NULL;

VMINT vm_stream_connect(vm_stream_connect_struct connect_info)
{
    if (NULL == _vm_stream_connect)
        _vm_stream_connect = (_vm_stream_connect_t)vm_get_sym_entry("vm_stream_connect");

    if (NULL != _vm_stream_connect)
        return _vm_stream_connect(connect_info);

    return -1;
}
