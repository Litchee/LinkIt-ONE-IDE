#include "vmsys.h"
#include "vmsettings.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_setting_srv_command_t)(VMUINT16 type, 
								VMUINT16 operation, 
								void *in, 
								void *out, 
								vm_setting_srv_result_callback cb,
								void *user_data);
_vm_setting_srv_command_t _vm_setting_srv_command = NULL;

VMINT32 vm_setting_srv_command(VMUINT16 type, 
								VMUINT16 operation, 
								void *in, 
								void *out, 
								vm_setting_srv_result_callback cb,
								void *user_data)
{
    if (NULL == _vm_setting_srv_command)
        _vm_setting_srv_command = (_vm_setting_srv_command_t)vm_get_sym_entry("vm_setting_srv_command");

    if (NULL != _vm_setting_srv_command)
        return _vm_setting_srv_command(type, operation, in, out, cb, user_data);

    return (VMINT )-1;
}
