#include "vmsys.h"
#include "vmsettings.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_setting_get_date_seperator_t)(void);
_vm_setting_get_date_seperator_t _vm_setting_get_date_seperator = NULL;

VMINT vm_setting_get_date_seperator(void)
{
    if (NULL == _vm_setting_get_date_seperator)
        _vm_setting_get_date_seperator = (_vm_setting_get_date_seperator_t)vm_get_sym_entry("vm_setting_get_date_seperator");

    if (NULL != _vm_setting_get_date_seperator)
        return _vm_setting_get_date_seperator();

    return (VMINT )-1;
}
