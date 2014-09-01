#include "vmsys.h"
#include "vmxml.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_xml_parse_t)(VM_XML_PARSER_STRUCT *parser, const VMCHAR *xmlsource, VMINT length);
_vm_xml_parse_t _vm_xml_parse = NULL;

VMINT vm_xml_parse(VM_XML_PARSER_STRUCT *parser, const VMCHAR *xmlsource, VMINT length)
{
    if (NULL == _vm_xml_parse)
        _vm_xml_parse = (_vm_xml_parse_t)vm_get_sym_entry("vm_xml_parse");

    if (NULL != _vm_xml_parse)
        return _vm_xml_parse(parser,xmlsource,length);

    return (VMINT )-1;
}
