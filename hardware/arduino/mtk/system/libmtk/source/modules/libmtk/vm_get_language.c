#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_language_t (*_vm_get_language_t)(void);
_vm_get_language_t _vm_get_language = NULL;

vm_language_t vm_get_language(void)
{
    vm_language_t  ret = {-1};
    if (NULL == _vm_get_language)
        _vm_get_language = (_vm_get_language_t)vm_get_sym_entry("vm_get_language");

    if (NULL != _vm_get_language)
        return _vm_get_language();

    return ret;
}
