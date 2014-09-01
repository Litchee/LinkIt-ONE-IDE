#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_sha1_hmac_t)(VMBYTE *key, VMINT keylen, VMBYTE *input, VMINT ilen, VMBYTE output[20]);
_vm_ssl_sha1_hmac_t _vm_ssl_sha1_hmac = NULL;

VMINT vm_ssl_sha1_hmac(VMBYTE *key, VMINT keylen, VMBYTE *input, VMINT ilen, VMBYTE output[20])
{
    if (NULL == _vm_ssl_sha1_hmac)
        _vm_ssl_sha1_hmac = (_vm_ssl_sha1_hmac_t)vm_get_sym_entry("vm_ssl_sha1_hmac");
    if (NULL != _vm_ssl_sha1_hmac)
        return _vm_ssl_sha1_hmac(key,keylen,input,ilen,output);
    return (VMINT)-1;
}