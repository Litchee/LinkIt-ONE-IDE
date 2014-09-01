#include "vmsys.h"
#include "vmche.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 (*_vm_che_process_t)(vm_stche *che_context_p,vm_che_type type,vm_che_operation_mode mode,
						vm_che_action act, VMUINT8 *source,VMUINT8 *dest,VMUINT source_length,VMUINT8 last_block);
_vm_che_process_t _vm_che_process = NULL;

VMUINT8 vm_che_process(vm_stche *che_context_p,vm_che_type type,vm_che_operation_mode mode,
						vm_che_action act, VMUINT8 *source,VMUINT8 *dest,VMUINT source_length,VMUINT8 last_block)
{
    if (NULL == _vm_che_process)
        _vm_che_process = (_vm_che_process_t)vm_get_sym_entry("vm_che_process");

    if (NULL != _vm_che_process)
        return _vm_che_process(che_context_p,type,mode,act,source,dest,source_length,last_block);

    return (VMUINT8 )-1;
}
