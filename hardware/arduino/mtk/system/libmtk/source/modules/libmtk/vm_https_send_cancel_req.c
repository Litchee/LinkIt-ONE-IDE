#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 (*_vm_https_send_cancel_req_t)(VMUINT16 request_id);		
	_vm_https_send_cancel_req_t _vm_https_send_cancel_req = NULL;	
VMUINT8 vm_https_send_cancel_req(VMUINT16 request_id)
{
	if (_vm_https_send_cancel_req == NULL) {										
		_vm_https_send_cancel_req = (_vm_https_send_cancel_req_t)vm_get_sym_entry("vm_https_send_cancel_req");	
	}																
	if (_vm_https_send_cancel_req != NULL) {										
		return _vm_https_send_cancel_req(request_id);									
	}			
	return 0;	
}
