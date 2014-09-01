#include "vmsys.h"
#include "vmbase64.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_base64_decode_basic_t)(const VMCHAR *src, VMINT32 srcl,VMCHAR *dst,VMINT32 dstl);
_vm_base64_decode_basic_t _vm_base64_decode_basic = NULL;

VMINT32 vm_base64_decode_basic(const VMCHAR *src, VMINT32 srcl,VMCHAR *dst,VMINT32 dstl)
{
    if (NULL == _vm_base64_decode_basic)
      _vm_base64_decode_basic = (_vm_base64_decode_basic_t)vm_get_sym_entry("vm_base64_decode_basic");

    if (NULL != _vm_base64_decode_basic)
      return _vm_base64_decode_basic(src, srcl, dst, dstl);
    else
    	return -255;
}
