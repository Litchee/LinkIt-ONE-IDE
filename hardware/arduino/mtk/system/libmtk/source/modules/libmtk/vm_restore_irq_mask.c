#include "vmsys.h"
#include "vmdcl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_restore_irq_mask_t)(VMUINT32 mask);
_vm_restore_irq_mask_t _vm_restore_irq_mask = NULL;
void vm_restore_irq_mask(VMUINT32 mask)
{
    if (NULL == _vm_restore_irq_mask)
        _vm_restore_irq_mask = (_vm_restore_irq_mask_t)vm_get_sym_entry("vm_restore_irq_mask");

    if (NULL != _vm_restore_irq_mask)
        _vm_restore_irq_mask(mask);
}
