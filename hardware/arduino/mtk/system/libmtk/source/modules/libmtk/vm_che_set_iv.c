#include "vmsys.h"
#include "vmche.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_che_set_iv_t)(vm_stche *che_context_p, VMUINT8 *iv, VMUINT iv_len);
_vm_che_set_iv_t _vm_che_set_iv = NULL;

void vm_che_set_iv(vm_stche *che_context_p, VMUINT8 *iv, VMUINT iv_len)
{
    if (NULL == _vm_che_set_iv)
        _vm_che_set_iv = (_vm_che_set_iv_t)vm_get_sym_entry("vm_che_set_iv");

    if (NULL != _vm_che_set_iv)
        _vm_che_set_iv(che_context_p,iv,iv_len);

}
