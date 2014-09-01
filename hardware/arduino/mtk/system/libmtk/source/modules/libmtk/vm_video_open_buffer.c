#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_open_buffer_t)( const VMUSTR buffer, const VMUINT buffer_len, vm_video_info_struct *info);
_vm_video_open_buffer_t _vm_video_open_buffer = NULL;

VMINT vm_video_open_buffer( const VMUSTR buffer, const VMUINT buffer_len, vm_video_info_struct *info)
{
    if (NULL == _vm_video_open_buffer)
        _vm_video_open_buffer = (_vm_video_open_buffer_t)vm_get_sym_entry("vm_video_open_buffer");

    if (NULL != _vm_video_open_buffer)
        return _vm_video_open_buffer(buffer,buffer_len,info);

    return (VMINT )-1;
}
