#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_base64_encode_t)(VMBYTE *dst, VMINT *dlen, VMBYTE *src, VMINT slen);
_vm_ssl_base64_encode_t _vm_ssl_base64_encode = NULL;

VMINT vm_ssl_base64_encode(VMBYTE *dst, VMINT *dlen, VMBYTE *src, VMINT slen)
{
    if (NULL == _vm_ssl_base64_encode)
        _vm_ssl_base64_encode = (_vm_ssl_base64_encode_t)vm_get_sym_entry("vm_ssl_base64_encode");
    if (NULL != _vm_ssl_base64_encode)
        return _vm_ssl_base64_encode(dst,dlen,src,slen);
    return (VMINT)-1;
}