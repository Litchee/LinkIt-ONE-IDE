#include "vmsys.h"
#include "vmrtspd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_inet_rtspd_set_stream_identify_t)(VMCHAR* stream_name);
_vm_inet_rtspd_set_stream_identify_t _vm_inet_rtspd_set_stream_identify = NULL;

void vm_inet_rtspd_set_stream_identify(VMCHAR* stream_name)
{
    if (NULL == _vm_inet_rtspd_set_stream_identify)
        _vm_inet_rtspd_set_stream_identify = (_vm_inet_rtspd_set_stream_identify_t)vm_get_sym_entry("vm_inet_rtspd_set_stream_identify");

    if (NULL != _vm_inet_rtspd_set_stream_identify)
       _vm_inet_rtspd_set_stream_identify(stream_name);
        
}
