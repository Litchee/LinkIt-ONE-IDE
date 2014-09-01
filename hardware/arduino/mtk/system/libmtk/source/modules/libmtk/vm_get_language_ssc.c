#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_get_language_ssc_t)(VMINT8 *ssc);
_vm_get_language_ssc_t _vm_get_language_ssc = NULL;

VMINT32 vm_get_language_ssc(VMINT8 *ssc)
{
    if (NULL == _vm_get_language_ssc)
        _vm_get_language_ssc = (_vm_get_language_ssc_t)vm_get_sym_entry("vm_get_language_ssc");

    if (NULL != _vm_get_language_ssc)
        return _vm_get_language_ssc(ssc);

    return (VMINT32 )-1;
}
