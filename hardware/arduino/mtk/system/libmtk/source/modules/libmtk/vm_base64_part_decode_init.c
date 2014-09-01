#include "vmsys.h"
#include "vmbase64.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_base64_part_decode_init_t)(vm_base64_part_context *cntx, VMINT32 max_part_buf_size);
_vm_base64_part_decode_init_t _vm_base64_part_decode_init = NULL;

VMINT32 vm_base64_part_decode_init( vm_base64_part_context *cntx, VMINT32 max_part_buf_size)
{
    if (NULL == _vm_base64_part_decode_init)
      _vm_base64_part_decode_init = (_vm_base64_part_decode_init_t)vm_get_sym_entry("vm_base64_part_decode_init");

    if (NULL != _vm_base64_part_decode_init)
      return _vm_base64_part_decode_init(cntx, max_part_buf_size);
    else
    	return -255;
}
