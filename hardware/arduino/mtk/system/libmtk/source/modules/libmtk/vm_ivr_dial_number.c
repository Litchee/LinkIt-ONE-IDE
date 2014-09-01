#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ivr_dial_number_t)(VMCHAR number);
_vm_ivr_dial_number_t _vm_ivr_dial_number = NULL;

VMINT vm_ivr_dial_number(VMCHAR number)
{
    if (NULL == _vm_ivr_dial_number)
        _vm_ivr_dial_number = (_vm_ivr_dial_number_t)vm_get_sym_entry("vm_ivr_dial_number");

    if (NULL != _vm_ivr_dial_number)
        return _vm_ivr_dial_number(number);

    return (VMINT )-1;
}
