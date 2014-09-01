#include "vmsys.h"
#include "vmdcl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;


typedef VMUINT32 (*_vm_save_irq_mask_t)(void);
_vm_save_irq_mask_t _vm_save_irq_mask = NULL;
VMUINT32 vm_save_irq_mask(void)
{
    if (NULL == _vm_save_irq_mask)
        _vm_save_irq_mask = (_vm_save_irq_mask_t)vm_get_sym_entry("vm_save_irq_mask");

    if (NULL != _vm_save_irq_mask)
        return _vm_save_irq_mask();

    return (VMUINT32)0;
}
