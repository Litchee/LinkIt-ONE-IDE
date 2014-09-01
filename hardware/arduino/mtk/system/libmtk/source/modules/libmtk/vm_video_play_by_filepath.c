#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_play_by_filepath_t)(VMWSTR filename);
_vm_video_play_by_filepath_t _vm_video_play_by_filepath = NULL;

VMINT vm_video_play_by_filepath(VMWSTR filename)
{
    if (NULL == _vm_video_play_by_filepath)
        _vm_video_play_by_filepath = (_vm_video_play_by_filepath_t)vm_get_sym_entry("vm_video_play_by_filepath");

    if (NULL != _vm_video_play_by_filepath)
        return _vm_video_play_by_filepath(filename);

    return (VMINT)-1;
}