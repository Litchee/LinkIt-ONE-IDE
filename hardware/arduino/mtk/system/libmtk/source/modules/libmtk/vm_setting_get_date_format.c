#include "vmsys.h"
#include "vmsettings.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_setting_get_date_format_t)(void);
_vm_setting_get_date_format_t _vm_setting_get_date_format = NULL;

VMINT vm_setting_get_date_format(void)
{
    if (NULL == _vm_setting_get_date_format)
        _vm_setting_get_date_format = (_vm_setting_get_date_format_t)vm_get_sym_entry("vm_setting_get_date_format");

    if (NULL != _vm_setting_get_date_format)
        return _vm_setting_get_date_format();

    return (VMINT )-1;
}
