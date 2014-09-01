#include "vmsys.h"
#include "vmxml.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMCHAR *(*_vm_xml_get_error_t)(void);
_vm_xml_get_error_t _vm_xml_get_error = NULL;

VMCHAR *vm_xml_get_error(void)
{
    if (NULL == _vm_xml_get_error)
        _vm_xml_get_error = (_vm_xml_get_error_t)vm_get_sym_entry("vm_xml_get_error");

    if (NULL != _vm_xml_get_error)
        return _vm_xml_get_error();

    return (VMCHAR *)0;
}
