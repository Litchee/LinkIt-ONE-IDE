#include "vmsys.h"
#include "vmxml.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_xml_set_element_handlers_t)( VM_XML_PARSER_STRUCT *parser, XML_start_elem_hdlr start_hdlr, XML_end_elem_hdlr end_hdlr);
_vm_xml_set_element_handlers_t _vm_xml_set_element_handlers = NULL;

void vm_xml_set_element_handlers( VM_XML_PARSER_STRUCT *parser, XML_start_elem_hdlr start_hdlr, XML_end_elem_hdlr end_hdlr)
{
    if (NULL == _vm_xml_set_element_handlers)
        _vm_xml_set_element_handlers = (_vm_xml_set_element_handlers_t)vm_get_sym_entry("vm_xml_set_element_handlers");

    if (NULL != _vm_xml_set_element_handlers)
        _vm_xml_set_element_handlers(parser,start_hdlr,end_hdlr);

    
}
