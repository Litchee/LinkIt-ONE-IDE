#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_mre_version_t)(void);
_vm_get_mre_version_t _vm_get_mre_version = NULL;

VMUINT vm_get_mre_version(void)
{
    if (NULL == _vm_get_mre_version)
        _vm_get_mre_version = (_vm_get_mre_version_t)vm_get_sym_entry("vm_get_mre_version");

    if (NULL != _vm_get_mre_version)
        return _vm_get_mre_version();

    return (VMUINT )0;
}
