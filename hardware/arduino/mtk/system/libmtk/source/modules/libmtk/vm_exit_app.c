#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_exit_app_t)(void);
_vm_exit_app_t _vm_exit_app = NULL;

void vm_exit_app(void)
{
    if (NULL == _vm_exit_app)
        _vm_exit_app = (_vm_exit_app_t)vm_get_sym_entry("vm_exit_app");

    if (NULL != _vm_exit_app)
        _vm_exit_app();

    
}
