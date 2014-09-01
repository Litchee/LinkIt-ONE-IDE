#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_cancel_all_http_sessions_t)(void);
_vm_cancel_all_http_sessions_t _vm_cancel_all_http_sessions = NULL;

void vm_cancel_all_http_sessions(void)
{
    if (NULL == _vm_cancel_all_http_sessions)
        _vm_cancel_all_http_sessions = (_vm_cancel_all_http_sessions_t)vm_get_sym_entry("vm_cancel_all_http_sessions");

    if (NULL != _vm_cancel_all_http_sessions)
        _vm_cancel_all_http_sessions();

    
}
