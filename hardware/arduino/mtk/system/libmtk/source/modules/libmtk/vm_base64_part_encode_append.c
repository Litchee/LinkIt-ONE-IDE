#include "vmsys.h"
#include "vmbase64.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_base64_part_encode_append_t)(vm_base64_part_context *cntx,const VMCHAR *src,VMINT32 *srcl,VMCHAR  *dst,VMINT32 dstl);
_vm_base64_part_encode_append_t _vm_base64_part_encode_append = NULL;

VMINT32 vm_base64_part_encode_append(vm_base64_part_context *cntx,const VMCHAR *src,VMINT32 *srcl,VMCHAR  *dst,VMINT32 dstl)
{
    if (NULL == _vm_base64_part_encode_append)
      _vm_base64_part_encode_append = (_vm_base64_part_encode_append_t)vm_get_sym_entry("vm_base64_part_encode_append");

    if (NULL != _vm_base64_part_encode_append)
      return _vm_base64_part_encode_append(cntx, src, srcl, dst, dstl);
    else
    	return -255;
}
