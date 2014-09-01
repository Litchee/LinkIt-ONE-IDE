#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_record_start_t)(VMSTR drv_name, VMSTR dir_name, VMSTR rec_name, VMUINT8 format, VMWSTR full_rec_file_wname, vm_recorder_callback vm_record_cb);
_vm_record_start_t _vm_record_start = NULL;

VMINT vm_record_start(VMSTR drv_name, VMSTR dir_name, VMSTR rec_name, VMUINT8 format, VMWSTR full_rec_file_wname, vm_recorder_callback vm_record_cb)
{
    if (NULL == _vm_record_start)
        _vm_record_start = (_vm_record_start_t)vm_get_sym_entry("vm_record_start");

    if (NULL != _vm_record_start)
        return _vm_record_start(drv_name,dir_name,rec_name,format,full_rec_file_wname,vm_record_cb);

    return (VMINT )-1;
}
