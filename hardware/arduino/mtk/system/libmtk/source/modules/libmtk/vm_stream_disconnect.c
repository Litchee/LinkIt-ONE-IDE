#include "vmsys.h"
#include "vmstream.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_stream_disconnect_t)(VMUINT8 session_id);
_vm_stream_disconnect_t _vm_stream_disconnect = NULL;

VMINT vm_stream_disconnect(VMUINT8 session_id)
{
    if (NULL == _vm_stream_disconnect)
        _vm_stream_disconnect = (_vm_stream_disconnect_t)vm_get_sym_entry("vm_stream_disconnect");

    if (NULL != _vm_stream_disconnect)
        return _vm_stream_disconnect(session_id);

    return -1;
}
