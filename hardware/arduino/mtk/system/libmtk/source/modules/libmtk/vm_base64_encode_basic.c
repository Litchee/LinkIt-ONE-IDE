#include "vmsys.h"
#include "vmbase64.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_base64_encode_basic_t)(const VMCHAR *src, VMINT32 srcl, VMCHAR *dst,VMINT32 dstl,VMBOOL auto_line_wrap);
_vm_base64_encode_basic_t _vm_base64_encode_basic = NULL;

VMINT32 vm_base64_encode_basic(const VMCHAR *src, VMINT32 srcl, VMCHAR *dst,VMINT32 dstl,VMBOOL auto_line_wrap)
{
    if (NULL == _vm_base64_encode_basic)
      _vm_base64_encode_basic = (_vm_base64_encode_basic_t)vm_get_sym_entry("vm_base64_encode_basic");

    if (NULL != _vm_base64_encode_basic)
      return _vm_base64_encode_basic(src, srcl, dst, dstl, auto_line_wrap);
    else
    	return -255;
}
