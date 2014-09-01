#include "vmsys.h"
#include "vmappcomm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_appcomm_init_t)(void);
_vm_appcomm_init_t _vm_appcomm_init = NULL;

void vm_appcomm_init(void)
{
    if (NULL == _vm_appcomm_init)
        _vm_appcomm_init = (_vm_appcomm_init_t)vm_get_sym_entry("vm_appcomm_init");

    if (NULL != _vm_appcomm_init)
        _vm_appcomm_init();

    
}
