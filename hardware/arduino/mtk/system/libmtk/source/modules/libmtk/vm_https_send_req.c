#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8(*_vm_https_send_req_t)(
                            VMUINT16 request_id,
                            VMUINT8 method,
                            VMUINT32 option,
                            VMUINT8 reply_type,
                            VMUINT32 reply_segment_len,
                            VMUINT32 request_url_len,
                            VMUINT8 *request_url,
                            VMUINT32 request_header_len,
                            VMUINT8 *request_header,
                            VMUINT32 post_segment_len,
                            VMUINT8 *post_segment);		
_vm_https_send_req_t _vm_https_send_req = NULL;	

VMUINT8 vm_https_send_req(
                            VMUINT16 request_id,
                            VMUINT8 method,
                            VMUINT32 option,
                            VMUINT8 reply_type,
                            VMUINT32 reply_segment_len,
                            VMUINT32 request_url_len,
                            VMUINT8 *request_url,
                            VMUINT32 request_header_len,
                            VMUINT8 *request_header,
                            VMUINT32 post_segment_len,
                            VMUINT8 *post_segment)
{
	if (_vm_https_send_req == NULL) {										
		_vm_https_send_req = (_vm_https_send_req_t)vm_get_sym_entry("vm_https_send_req");	
	}																
	if (_vm_https_send_req != NULL) {										
		return _vm_https_send_req(
                             request_id,
                             method,
                             option,
                             reply_type,
                             reply_segment_len,
                             request_url_len,
                             request_url,
                             request_header_len,
                             request_header,
                             post_segment_len,
                             post_segment);									
	}			
	return 0;	
}
