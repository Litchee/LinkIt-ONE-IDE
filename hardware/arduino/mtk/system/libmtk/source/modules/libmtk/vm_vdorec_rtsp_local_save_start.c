#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_rtsp_local_save_start_t)(VMWSTR filepath, vm_vdorec_callback callback);
_vm_vdorec_rtsp_local_save_start_t _vm_vdorec_rtsp_local_save_start = NULL;

VMINT vm_vdorec_rtsp_local_save_start(VMWSTR filepath, vm_vdorec_callback callback)
{
    if (NULL == _vm_vdorec_rtsp_local_save_start)
        _vm_vdorec_rtsp_local_save_start = (_vm_vdorec_rtsp_local_save_start_t)vm_get_sym_entry("vm_vdorec_rtsp_local_save_start");

    if (NULL != _vm_vdorec_rtsp_local_save_start)
        return _vm_vdorec_rtsp_local_save_start(filepath,callback);
	return -1;
}
