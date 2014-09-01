#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_download_t)(VMUINT msg_id, vm_mms_sim_id_enum sim, vm_mms_msg_storage_type_enum storage_type);
_vm_mms_download_t _vm_mms_download = NULL;

VMINT vm_mms_download(VMUINT msg_id, vm_mms_sim_id_enum sim, vm_mms_msg_storage_type_enum storage_type)
{
    if (NULL == _vm_mms_download)
        _vm_mms_download = (_vm_mms_download_t)vm_get_sym_entry("vm_mms_download");

    if (NULL != _vm_mms_download)
        return _vm_mms_download(msg_id,sim,storage_type );

    return (VMINT )-1;
}
