#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_reg_sysevt_callback_t)(void (*f)(VMINT message, VMINT param));
_vm_reg_sysevt_callback_t _vm_reg_sysevt_callback = NULL;

void vm_reg_sysevt_callback(void (*f)(VMINT message, VMINT param))
{
    if (NULL == _vm_reg_sysevt_callback)
        _vm_reg_sysevt_callback = (_vm_reg_sysevt_callback_t)vm_get_sym_entry("vm_reg_sysevt_callback");

    if (NULL != _vm_reg_sysevt_callback)
        _vm_reg_sysevt_callback(f);

    
}
