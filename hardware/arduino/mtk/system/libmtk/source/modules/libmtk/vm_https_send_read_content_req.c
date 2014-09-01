#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;


typedef VMUINT8 (*_vm_https_send_read_content_req_t)(
                                        VMUINT16 request_id,
                                        VMUINT8 seq_num,
                                        VMUINT32 read_segnemtn_len);		
_vm_https_send_read_content_req_t _vm_https_send_read_content_req = NULL;	

VMUINT8 vm_https_send_read_content_req(
                                        VMUINT16 request_id,
                                        VMUINT8 seq_num,
                                        VMUINT32 read_segnemtn_len)
{
	if (_vm_https_send_read_content_req == NULL) {										
		_vm_https_send_read_content_req = (_vm_https_send_read_content_req_t)vm_get_sym_entry("vm_https_send_read_content_req");	
	}																
	if (_vm_https_send_read_content_req != NULL) {										
		return _vm_https_send_read_content_req(
											request_id,
                                            seq_num,
                                            read_segnemtn_len);									
	}			
	return 0;	
}
