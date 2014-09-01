#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_uriagent_uri_request_t)(const VMCHAR * str, VMINT confirm);
_vm_uriagent_uri_request_t _vm_uriagent_uri_request = NULL;

VMINT vm_uriagent_uri_request(const VMCHAR * str, VMINT confirm)
{
    if (NULL == _vm_uriagent_uri_request)
        _vm_uriagent_uri_request = (_vm_uriagent_uri_request_t)vm_get_sym_entry("vm_uriagent_uri_request");

    if (NULL != _vm_uriagent_uri_request)
        return _vm_uriagent_uri_request(str,confirm);

    return (VMINT)-1;
}