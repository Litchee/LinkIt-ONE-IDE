#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_write_t)(VMINT handle, const VMUINT8 *buf, VMINT len);
_vm_ssl_write_t _vm_ssl_write = NULL;

VMINT vm_ssl_write(VMINT handle, const VMUINT8 *buf, VMINT len)
{
    if (NULL == _vm_ssl_write)
        _vm_ssl_write = (_vm_ssl_write_t)vm_get_sym_entry("vm_ssl_write");
    if (NULL != _vm_ssl_write)
        return _vm_ssl_write(handle,buf,len);
    return (VMINT)-1;
}