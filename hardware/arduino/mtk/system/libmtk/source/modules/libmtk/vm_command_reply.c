#include "vmsys.h"
#include "vmatcmd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_command_reply_t)(char* reply_buf, VMUINT32 buf_size, VMUINT32 reply_type);
_vm_command_reply_t _vm_command_reply = NULL;
void vm_command_reply(char* reply_buf, VMUINT32 buf_size, VMUINT32 reply_type)
{
    if (NULL == _vm_command_reply)
        _vm_command_reply = (_vm_command_reply_t)vm_get_sym_entry("vm_command_reply");

    if (NULL != _vm_command_reply)
        _vm_command_reply(reply_buf, buf_size, reply_type);
}


