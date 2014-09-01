#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_scan_abort_t)(VMUINT32 job_id);
_vm_wlan_scan_abort_t _vm_wlan_scan_abort = NULL;

VMINT vm_wlan_scan_abort(VMUINT32 job_id)
{
    if (NULL == _vm_wlan_scan_abort)
        _vm_wlan_scan_abort = (_vm_wlan_scan_abort_t)vm_get_sym_entry("vm_wlan_scan_abort");
    if (NULL != _vm_wlan_scan_abort)
        return _vm_wlan_scan_abort(job_id);
    return (VMINT)-1;
}