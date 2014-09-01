#include "vmsys.h"
#include "vmbase64.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_base64_part_decode_finish_t)(vm_base64_part_context* cntx,VMBOOL* illegal_format);
_vm_base64_part_decode_finish_t _vm_base64_part_decode_finish = NULL;

VMINT32 vm_base64_part_decode_finish(vm_base64_part_context* cntx,VMBOOL* illegal_format)
{
    if (NULL == _vm_base64_part_decode_finish)
      _vm_base64_part_decode_finish = (_vm_base64_part_decode_finish_t)vm_get_sym_entry("vm_base64_part_decode_finish");

    if (NULL != _vm_base64_part_decode_finish)
      return _vm_base64_part_decode_finish(cntx, illegal_format);
    else
    	return -255;
}
