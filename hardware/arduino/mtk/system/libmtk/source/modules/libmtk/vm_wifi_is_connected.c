#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wifi_is_connected_t)(void);
_vm_wifi_is_connected_t _vm_wifi_is_connected = NULL;

VMINT vm_wifi_is_connected(void)
{
    if (NULL == _vm_wifi_is_connected)
        _vm_wifi_is_connected = (_vm_wifi_is_connected_t)vm_get_sym_entry("vm_wifi_is_connected");

    if (NULL != _vm_wifi_is_connected)
        return _vm_wifi_is_connected();

    return (VMINT )-1;
}
