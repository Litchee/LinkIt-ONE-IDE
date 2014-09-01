#include "vmsys.h"
#include "vmbase64.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_base64_part_encode_finish_t)(vm_base64_part_context* cntx,VMCHAR *dst,VMINT32 dstl);
_vm_base64_part_encode_finish_t _vm_base64_part_encode_finish = NULL;

VMINT32 vm_base64_part_encode_finish(vm_base64_part_context* cntx,VMCHAR *dst,VMINT32 dstl)
{
    if (NULL == _vm_base64_part_encode_finish)
      _vm_base64_part_encode_finish = (_vm_base64_part_encode_finish_t)vm_get_sym_entry("vm_base64_part_encode_finish");

    if (NULL != _vm_base64_part_encode_finish)
      return _vm_base64_part_encode_finish(cntx, dst, dstl);
    else
    	return -255;
}
