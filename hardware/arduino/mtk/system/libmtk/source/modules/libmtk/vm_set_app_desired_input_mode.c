#include "vmsys.h"
#include "vmio.h"
#include "vminput.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_set_app_desired_input_mode_t)(vm_input_mode_enum desired_input_mode);
_vm_set_app_desired_input_mode_t _vm_set_app_desired_input_mode = NULL;

void vm_set_app_desired_input_mode(vm_input_mode_enum desired_input_mode)
{
    if (NULL == _vm_set_app_desired_input_mode)
        _vm_set_app_desired_input_mode = (_vm_set_app_desired_input_mode_t)vm_get_sym_entry("vm_set_app_desired_input_mode");

    if (NULL != _vm_set_app_desired_input_mode)
        _vm_set_app_desired_input_mode(desired_input_mode);

    
}
