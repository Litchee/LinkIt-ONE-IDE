#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_https_send_req_ext_t)(VMUINT16 request_id, 
                                                VMUINT8 method, 
                                                VMUINT32 option, 
                                                VMUINT8 reply_type, 
                                                VMUINT32 reply_segment_len,
                                                VMBYTE more_post,
                                                VMUINT8 post_type,
                                                const vm_wps_http_req_var_struct * req,
                                                wps_post_ind_cb cb);
_vm_https_send_req_ext_t _vm_https_send_req_ext = NULL;	
VMINT vm_https_send_req_ext(VMUINT16 request_id, 
                                                VMUINT8 method, 
                                                VMUINT32 option, 
                                                VMUINT8 reply_type, 
                                                VMUINT32 reply_segment_len,
                                                VMBYTE more_post,
                                                VMUINT8 post_type,
                                                const vm_wps_http_req_var_struct * req,
                                                wps_post_ind_cb cb)
{
	if (_vm_https_send_req_ext == NULL) {										
		_vm_https_send_req_ext = (_vm_https_send_req_ext_t)vm_get_sym_entry("vm_https_send_req_ext");	
	}																
	if (_vm_https_send_req_ext != NULL) {										
		return _vm_https_send_req_ext(request_id, 
                                                   method, 
                                                   option, 
                                                   reply_type, 
                                                   reply_segment_len,
                                                   more_post,
                                                   post_type,
                                                   req,
                                                   cb);									
	}			
	return -1;	
}


