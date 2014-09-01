#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_cancel_download_t)(VMINT msg_id);
_vm_mms_cancel_download_t _vm_mms_cancel_download = NULL;

void vm_mms_cancel_download(VMINT msg_id)
{
    if (NULL == _vm_mms_cancel_download)
        _vm_mms_cancel_download = (_vm_mms_cancel_download_t)vm_get_sym_entry("vm_mms_cancel_download");

    if (NULL != _vm_mms_cancel_download)
        _vm_mms_cancel_download(msg_id);
}
