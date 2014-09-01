#include "vmsys.h"
#include "vmda.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_da_display_download_list_t)(void);
_vm_da_display_download_list_t _vm_da_display_download_list = NULL;

VMINT vm_da_display_download_list(void)
{
    if (NULL == _vm_da_display_download_list)
        _vm_da_display_download_list = (_vm_da_display_download_list_t)vm_get_sym_entry("vm_da_display_download_list");

    if (NULL != _vm_da_display_download_list)
        return _vm_da_display_download_list();

    return (VMINT)-1;
}