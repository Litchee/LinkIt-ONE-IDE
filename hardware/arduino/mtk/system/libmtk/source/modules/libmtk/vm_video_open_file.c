#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_open_file_t)( const VMWSTR filename, vm_video_open_result_callback open_result_callback);
_vm_video_open_file_t _vm_video_open_file = NULL;

VMINT vm_video_open_file( const VMWSTR filename, vm_video_open_result_callback open_result_callback)
{
    if (NULL == _vm_video_open_file)
        _vm_video_open_file = (_vm_video_open_file_t)vm_get_sym_entry("vm_video_open_file");

    if (NULL != _vm_video_open_file)
        return _vm_video_open_file(filename,open_result_callback);

    return (VMINT )-1;
}
