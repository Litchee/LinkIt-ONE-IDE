#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUSTR (*_vm_get_current_lang_country_code_t)(void);
_vm_get_current_lang_country_code_t _vm_get_current_lang_country_code = NULL;

VMUSTR vm_get_current_lang_country_code(void)
{
    if (NULL == _vm_get_current_lang_country_code)
        _vm_get_current_lang_country_code = (_vm_get_current_lang_country_code_t)vm_get_sym_entry("vm_get_current_lang_country_code");

    if (NULL != _vm_get_current_lang_country_code)
        return _vm_get_current_lang_country_code();

    return (VMUSTR)NULL;
}
