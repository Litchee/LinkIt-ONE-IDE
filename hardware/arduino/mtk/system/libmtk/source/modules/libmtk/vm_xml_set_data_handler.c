#include "vmsys.h"
#include "vmxml.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_xml_set_data_handler_t)(VM_XML_PARSER_STRUCT *parser, XML_data_hdlr data_hdlr);
_vm_xml_set_data_handler_t _vm_xml_set_data_handler = NULL;

void vm_xml_set_data_handler(VM_XML_PARSER_STRUCT *parser, XML_data_hdlr data_hdlr)
{
    if (NULL == _vm_xml_set_data_handler)
        _vm_xml_set_data_handler = (_vm_xml_set_data_handler_t)vm_get_sym_entry("vm_xml_set_data_handler");

    if (NULL != _vm_xml_set_data_handler)
        _vm_xml_set_data_handler(parser,data_hdlr);

    
}
