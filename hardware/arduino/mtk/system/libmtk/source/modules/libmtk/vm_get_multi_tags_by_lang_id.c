#include "vmsys.h"
#include "vmgettag.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_multi_tags_by_lang_id_t)( short* filename, MULTI_TAG * tag_req, int lang_id );
_vm_get_multi_tags_by_lang_id_t _vm_get_multi_tags_by_lang_id = NULL;

VMINT vm_get_multi_tags_by_lang_id( short* filename, MULTI_TAG * tag_req, int lang_id )
{
    if (NULL == _vm_get_multi_tags_by_lang_id)
        _vm_get_multi_tags_by_lang_id = (_vm_get_multi_tags_by_lang_id_t)vm_get_sym_entry("vm_get_multi_tags_by_lang_id");

    if (NULL != _vm_get_multi_tags_by_lang_id)
        return _vm_get_multi_tags_by_lang_id(filename,tag_req,lang_id);

    return (VMINT )-1;
}
