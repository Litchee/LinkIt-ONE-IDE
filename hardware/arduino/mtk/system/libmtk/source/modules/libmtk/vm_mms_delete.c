#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_delete_t)(VMUINT* msg_id_list, VMUINT msg_num, vm_mms_folder_enum folder, vm_mms_delete_callback callback,void* user_data);
_vm_mms_delete_t _vm_mms_delete = NULL;

VMINT vm_mms_delete(VMUINT* msg_id_list, VMUINT msg_num, vm_mms_folder_enum folder, vm_mms_delete_callback callback,void* user_data)
{
    if (NULL == _vm_mms_delete)
        _vm_mms_delete = (_vm_mms_delete_t)vm_get_sym_entry("vm_mms_delete");

    if (NULL != _vm_mms_delete)
        return _vm_mms_delete(msg_id_list,msg_num,folder,callback,user_data);
    return -1;
}
