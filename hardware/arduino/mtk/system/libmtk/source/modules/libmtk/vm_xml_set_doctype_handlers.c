#include "vmsys.h"
#include "vmxml.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_xml_set_doctype_handlers_t)( VM_XML_PARSER_STRUCT *parser, XML_start_doctype_hdlr start_hdlr, XML_end_doctype_hdlr end_hdlr);
_vm_xml_set_doctype_handlers_t _vm_xml_set_doctype_handlers = NULL;

void vm_xml_set_doctype_handlers( VM_XML_PARSER_STRUCT *parser, XML_start_doctype_hdlr start_hdlr, XML_end_doctype_hdlr end_hdlr)
{
    if (NULL == _vm_xml_set_doctype_handlers)
        _vm_xml_set_doctype_handlers = (_vm_xml_set_doctype_handlers_t)vm_get_sym_entry("vm_xml_set_doctype_handlers");

    if (NULL != _vm_xml_set_doctype_handlers)
        _vm_xml_set_doctype_handlers(parser,start_hdlr,end_hdlr);

    
}
