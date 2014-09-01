#include "vmsys.h"
#include "vmbase64.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_base64_part_encode_init_t)(vm_base64_part_context *cntx,VMINT32 max_part_buf_size,VMBOOL auto_line_wrap);
_vm_base64_part_encode_init_t _vm_base64_part_encode_init = NULL;

VMINT32 vm_base64_part_encode_init(vm_base64_part_context *cntx,VMINT32 max_part_buf_size,VMBOOL auto_line_wrap)
{
    if (NULL == _vm_base64_part_encode_init)
      _vm_base64_part_encode_init = (_vm_base64_part_encode_init_t)vm_get_sym_entry("vm_base64_part_encode_init");

    if (NULL != _vm_base64_part_encode_init)
      return _vm_base64_part_encode_init(cntx, max_part_buf_size, auto_line_wrap);
    else
    	return -255;
}
