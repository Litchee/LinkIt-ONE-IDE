#include "vmsys.h"
#include "vmatcmd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_command_close_port_t)(VMUINT16 port);
_vm_command_close_port_t _vm_command_close_port = NULL;

void vm_command_close_port(VMUINT16 port)
{
    if (NULL == _vm_command_close_port)
        _vm_command_close_port = (_vm_command_close_port_t)vm_get_sym_entry("vm_command_close_port");
    if (NULL != _vm_command_close_port)
        _vm_command_close_port(port);
}