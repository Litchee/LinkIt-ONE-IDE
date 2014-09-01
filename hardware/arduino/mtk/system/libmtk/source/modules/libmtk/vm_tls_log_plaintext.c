#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_log_plaintext_t)(VMINT onoff);
_vm_tls_log_plaintext_t _vm_tls_log_plaintext = NULL;

VMINT vm_tls_log_plaintext(VMINT onoff)
{
    if (NULL == _vm_tls_log_plaintext)
        _vm_tls_log_plaintext = (_vm_tls_log_plaintext_t)vm_get_sym_entry("vm_tls_log_plaintext");

    if (NULL != _vm_tls_log_plaintext)
        return _vm_tls_log_plaintext(onoff);

    return (VMINT)-1;
}