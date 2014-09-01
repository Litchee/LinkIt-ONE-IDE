#include "vmsys.h"
#include "vmatcmd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT16 (*_vm_command_open_port_t)(VMUINT16 port, vm_command_callback call_back, void *user_data);
_vm_command_open_port_t _vm_command_open_port = NULL;

VMUINT16 vm_command_open_port(VMUINT16 port, vm_command_callback call_back, void *user_data)
{
    if (NULL == _vm_command_open_port)
        _vm_command_open_port = (_vm_command_open_port_t)vm_get_sym_entry("vm_command_open_port");
    if (NULL != _vm_command_open_port)
        return _vm_command_open_port(port,call_back,user_data);
    return 0;
}