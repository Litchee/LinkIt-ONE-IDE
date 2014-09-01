#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_set_brightness_t)(VMUINT16 brightness);
_vm_video_set_brightness_t _vm_video_set_brightness = NULL;

VMINT vm_video_set_brightness(VMUINT16 brightness)
{
    if (NULL == _vm_video_set_brightness)
        _vm_video_set_brightness = (_vm_video_set_brightness_t)vm_get_sym_entry("vm_video_set_brightness");

    if (NULL != _vm_video_set_brightness)
        return _vm_video_set_brightness(brightness);

    return (VMINT )-1;
}
