#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_record_resume_t)(void);
_vm_record_resume_t _vm_record_resume = NULL;

VMINT vm_record_resume(void)
{
    if (NULL == _vm_record_resume)
        _vm_record_resume = (_vm_record_resume_t)vm_get_sym_entry("vm_record_resume");

    if (NULL != _vm_record_resume)
        return _vm_record_resume();

    return (VMINT )-1;
}
