#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_get_msg_id_list_t)(vm_mms_folder_enum folder, vm_mms_get_msg_id_list_callback_type callback, void* user_data);
_vm_mms_get_msg_id_list_t _vm_mms_get_msg_id_list = NULL;

VMINT vm_mms_get_msg_id_list(vm_mms_folder_enum folder, vm_mms_get_msg_id_list_callback_type callback, void* user_data)
{
    if (NULL == _vm_mms_get_msg_id_list)
        _vm_mms_get_msg_id_list = (_vm_mms_get_msg_id_list_t)vm_get_sym_entry("vm_mms_get_msg_id_list");

    if (NULL != _vm_mms_get_msg_id_list)
        return _vm_mms_get_msg_id_list(folder,callback, user_data);

    return (VMINT)-1;
}

