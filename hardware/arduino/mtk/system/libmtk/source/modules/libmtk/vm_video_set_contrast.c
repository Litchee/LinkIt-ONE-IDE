#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_set_contrast_t)(VMUINT16 contrast);
_vm_video_set_contrast_t _vm_video_set_contrast = NULL;

VMINT vm_video_set_contrast(VMUINT16 contrast)
{
    if (NULL == _vm_video_set_contrast)
        _vm_video_set_contrast = (_vm_video_set_contrast_t)vm_get_sym_entry("vm_video_set_contrast");

    if (NULL != _vm_video_set_contrast)
        return _vm_video_set_contrast(contrast);

    return (VMINT )-1;
}
