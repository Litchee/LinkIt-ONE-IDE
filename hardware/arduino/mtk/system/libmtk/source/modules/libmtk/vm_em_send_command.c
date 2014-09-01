#include "vmsys.h"
#include "vmemcmd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_emcmd_enum (*_vm_em_send_command_t)(VMCHAR *atCmdStr, VM_EM_CMD_CB atcmd_cb);
_vm_em_send_command_t _vm_em_send_command = NULL;

vm_emcmd_enum vm_em_send_command(VMCHAR *atCmdStr, VM_EM_CMD_CB atcmd_cb)
{
    if (NULL == _vm_em_send_command)
        _vm_em_send_command = (_vm_em_send_command_t)vm_get_sym_entry("vm_em_send_command");

    if (NULL != _vm_em_send_command)
        return _vm_em_send_command(atCmdStr, atcmd_cb);
        
    return (vm_emcmd_enum)-1;
}