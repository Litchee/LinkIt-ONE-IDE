#include "vmsys.h"
#include "vmche.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_che_key_action_t)(vm_stche *che_context_p, vm_che_key_action_type type, VMUINT8 *key, VMINT key_len);
_vm_che_key_action_t _vm_che_key_action = NULL;

void vm_che_key_action(vm_stche *che_context_p, vm_che_key_action_type type, VMUINT8 *key, VMINT key_len)
{
    if (NULL == _vm_che_key_action)
        _vm_che_key_action = (_vm_che_key_action_t)vm_get_sym_entry("vm_che_key_action");

    if (NULL != _vm_che_key_action)
        _vm_che_key_action(che_context_p,type,key,key_len);

}
