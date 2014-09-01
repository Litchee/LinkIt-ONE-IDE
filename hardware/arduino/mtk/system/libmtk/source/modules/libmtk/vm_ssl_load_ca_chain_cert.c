#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_load_ca_chain_cert_t)(VMINT handle, const void *cert_buf, VMINT buf_len);
_vm_ssl_load_ca_chain_cert_t _vm_ssl_load_ca_chain_cert = NULL;

VMINT vm_ssl_load_ca_chain_cert(VMINT handle, const void *cert_buf, VMINT buf_len)
{
    if (NULL == _vm_ssl_load_ca_chain_cert)
        _vm_ssl_load_ca_chain_cert = (_vm_ssl_load_ca_chain_cert_t)vm_get_sym_entry("vm_ssl_load_ca_chain_cert");
    if (NULL != _vm_ssl_load_ca_chain_cert)
        return _vm_ssl_load_ca_chain_cert(handle,cert_buf,buf_len);
    return (VMINT)-1;
}