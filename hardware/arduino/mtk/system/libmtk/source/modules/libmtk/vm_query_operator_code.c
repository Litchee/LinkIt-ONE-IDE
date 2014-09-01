#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_query_operator_code_t)(VMCHAR *buffer, VMUINT buffer_size);
_vm_query_operator_code_t _vm_query_operator_code = NULL;

VMINT vm_query_operator_code(VMCHAR *buffer, VMUINT buffer_size)
{
    if (NULL == _vm_query_operator_code)
        _vm_query_operator_code = (_vm_query_operator_code_t)vm_get_sym_entry("vm_query_operator_code");

    if (NULL != _vm_query_operator_code)
        return _vm_query_operator_code(buffer,buffer_size);

    return (VMINT )-1;
}
