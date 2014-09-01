#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_set_badge_t)(VMINT32 badege_number);
_vm_pn_set_badge_t _vm_pn_set_badge = NULL;

VMINT vm_pn_set_badge(VMINT32 badege_number)
{
    if (NULL == _vm_pn_set_badge)
        _vm_pn_set_badge = (_vm_pn_set_badge_t)vm_get_sym_entry("vm_pn_set_badge");

    if (NULL != _vm_pn_set_badge)
        return _vm_pn_set_badge(badege_number);

    return (VMINT)-1;
}