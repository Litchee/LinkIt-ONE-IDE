#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8(*_vm_https_send_unset_channel_req_t)(VMUINT8 channel_id);		
_vm_https_send_unset_channel_req_t _vm_https_send_unset_channel_req = NULL;
		
VMUINT8 vm_https_send_unset_channel_req(VMUINT8 channel_id)
{
	if (_vm_https_send_unset_channel_req == NULL) {										
		_vm_https_send_unset_channel_req = (_vm_https_send_unset_channel_req_t)vm_get_sym_entry("vm_https_send_unset_channel_req");	
	}																
	if (_vm_https_send_unset_channel_req != NULL) {										
		return _vm_https_send_unset_channel_req(channel_id);									
	}			
	return 0;	
}
