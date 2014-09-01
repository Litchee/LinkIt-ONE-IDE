#include "vmsys.h"
#include "vmxml.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_xml_new_parser_t)(VM_XML_PARSER_STRUCT *parser);
_vm_xml_new_parser_t _vm_xml_new_parser = NULL;

VMINT vm_xml_new_parser(VM_XML_PARSER_STRUCT *parser)
{
    if (NULL == _vm_xml_new_parser)
        _vm_xml_new_parser = (_vm_xml_new_parser_t)vm_get_sym_entry("vm_xml_new_parser");

    if (NULL != _vm_xml_new_parser)
        return _vm_xml_new_parser(parser);

    return (VMINT )-1;
}
