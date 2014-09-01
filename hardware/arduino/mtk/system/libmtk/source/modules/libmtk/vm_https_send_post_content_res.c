#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 (*_vm_https_send_post_content_res_t)(VMUINT16 request_id,       
                                            VMUINT8 seq_num,           
                                            VMBYTE more,               
                                            VMUINT32 post_segment_len, 
                                            VMUINT8* post_segment);		
_vm_https_send_post_content_res_t _vm_https_send_post_content_res = NULL;	
VMINT vm_https_send_post_content_res(VMUINT16 request_id,       
                                            VMUINT8 seq_num,           
                                            VMBYTE more,               
                                            VMUINT32 post_segment_len, 
                                            VMUINT8* post_segment)
{
	if (_vm_https_send_post_content_res == NULL) {										
		_vm_https_send_post_content_res = (_vm_https_send_post_content_res_t)vm_get_sym_entry("vm_https_send_post_content_res");	
	}																
	if (_vm_https_send_post_content_res != NULL) {										
		return _vm_https_send_post_content_res(request_id, 
                                            seq_num,           
                                            more,               
                                            post_segment_len, 
                                            post_segment);									
	}			
	return -1;	
}
