#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_base64_decode_t)(VMBYTE *dst, VMINT *dlen, VMBYTE *src, VMINT  slen);
_vm_ssl_base64_decode_t _vm_ssl_base64_decode = NULL;

VMINT vm_ssl_base64_decode(VMBYTE *dst, VMINT *dlen, VMBYTE *src, VMINT  slen)
{
    if (NULL == _vm_ssl_base64_decode)
        _vm_ssl_base64_decode = (_vm_ssl_base64_decode_t)vm_get_sym_entry("vm_ssl_base64_decode");
    if (NULL != _vm_ssl_base64_decode)
        return _vm_ssl_base64_decode(dst,dlen,src,slen);
    return (VMINT)-1;
}