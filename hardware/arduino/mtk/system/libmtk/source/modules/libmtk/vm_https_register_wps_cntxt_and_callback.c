#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;
typedef VMUINT8 (*_vm_https_register_wps_cntxt_and_callback_t)( 
                VMINT apn,
                wps_send_set_channel_rsp_cb set_channel_rsp_cb,
                wps_unset_channel_rsp_cb unset_channel_cb,
                wps_send_release_all_req_rsp_cb release_all_req_cb,
                wps_send_wps_termination_ind_cb terminal_ind_cb,
                wps_send_http_rsp_cb http_rsp_cb,
                wps_send_read_content_rsp_cb read_content_rsp_cb,
                wps_send_cancel_rsp_cb cancel_rsp_cb,
                wps_send_status_query_rsp_cb status_query_rsp_cb);
_vm_https_register_wps_cntxt_and_callback_t _vm_https_register_wps_cntxt_and_callback = NULL;	
VMUINT8 vm_https_register_wps_cntxt_and_callback(
                VMINT apn,
                wps_send_set_channel_rsp_cb set_channel_rsp_cb,
                wps_unset_channel_rsp_cb unset_channel_cb,
                wps_send_release_all_req_rsp_cb release_all_req_cb,
                wps_send_wps_termination_ind_cb terminal_ind_cb,
                wps_send_http_rsp_cb http_rsp_cb,
                wps_send_read_content_rsp_cb read_content_rsp_cb,
                wps_send_cancel_rsp_cb cancel_rsp_cb,
                wps_send_status_query_rsp_cb status_query_rsp_cb)
{
	if (_vm_https_register_wps_cntxt_and_callback == NULL) {										
		_vm_https_register_wps_cntxt_and_callback = (_vm_https_register_wps_cntxt_and_callback_t)vm_get_sym_entry("vm_https_register_wps_cntxt_and_callback");	
	}																
	if (_vm_https_register_wps_cntxt_and_callback != NULL) {										
		return _vm_https_register_wps_cntxt_and_callback(
                                                        apn,
                                                        set_channel_rsp_cb,
														unset_channel_cb,
														release_all_req_cb,
														terminal_ind_cb,
														http_rsp_cb,
														read_content_rsp_cb,
														cancel_rsp_cb,
														status_query_rsp_cb);									
	}			
	return 0;	
}
