#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void  (*_vm_custom_set_bt_pairing_method_t)(vm_bt_pairing_Type config_type);
_vm_custom_set_bt_pairing_method_t _vm_custom_set_bt_pairing_method = NULL;
void vm_custom_set_bt_pairing_method(vm_bt_pairing_Type config_type)

{
    if (NULL == _vm_custom_set_bt_pairing_method)
        _vm_custom_set_bt_pairing_method = (_vm_custom_set_bt_pairing_method_t)vm_get_sym_entry("vm_custom_set_bt_pairing_method");
    if (NULL != _vm_custom_set_bt_pairing_method)
        _vm_custom_set_bt_pairing_method(config_type);
}