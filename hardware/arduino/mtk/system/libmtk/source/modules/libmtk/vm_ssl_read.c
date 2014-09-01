#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_read_t)(VMINT handle, VMUINT8 *buf, VMINT len);
_vm_ssl_read_t _vm_ssl_read = NULL;

VMINT vm_ssl_read(VMINT handle, VMUINT8 *buf, VMINT len)
{
    if (NULL == _vm_ssl_read)
        _vm_ssl_read = (_vm_ssl_read_t)vm_get_sym_entry("vm_ssl_read");
    if (NULL != _vm_ssl_read)
        return _vm_ssl_read(handle,buf,len);
    return (VMINT)-1;
}