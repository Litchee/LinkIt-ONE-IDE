#include "vmsys.h"
#include "vmhttps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 (*_vm_https_send_set_channel_req_t)(
                                       VMUINT16 req_id,
                                       VMUINT8 use_proxy,
                                       VMUINT8 prx_ip[4],
                                       VMUINT16 prx_port,
                                       VMUINT8 *username,
                                       VMUINT8 username_len,
                                       VMUINT8 *password,
                                       VMUINT8 password_len,
                                       VMUINT8 *server_auth_username,
                                       VMUINT8 server_auth_username_len,
                                       VMUINT8 *server_auth_password,
                                       VMUINT8 server_auth_password_len,
                                       VMUINT32 static_header_len,
                                       VMUINT8 *static_header );
_vm_https_send_set_channel_req_t _vm_https_send_set_channel_req = NULL;	

VMUINT8 vm_https_send_set_channel_req(VMUINT16 req_id,
                                       VMUINT8 use_proxy,
                                       VMUINT8 prx_ip[4],
                                       VMUINT16 prx_port,
                                       VMUINT8 *username,
                                       VMUINT8 username_len,
                                       VMUINT8 *password,
                                       VMUINT8 password_len,
                                       VMUINT8 *server_auth_username,
                                       VMUINT8 server_auth_username_len,
                                       VMUINT8 *server_auth_password,
                                       VMUINT8 server_auth_password_len,
                                       VMUINT32 static_header_len,
                                       VMUINT8 *static_header)
{
	if (_vm_https_send_set_channel_req == NULL) {										
		_vm_https_send_set_channel_req = (_vm_https_send_set_channel_req_t)vm_get_sym_entry("vm_https_send_set_channel_req");	
	}																
	if (_vm_https_send_set_channel_req != NULL) {										
		return _vm_https_send_set_channel_req( 
                                        req_id,
                                        use_proxy,
                                        prx_ip,
                                        prx_port,
                                        username,
                                        username_len,
                                        password,
                                        password_len,
                                        server_auth_username,
                                        server_auth_username_len,
                                        server_auth_password,
                                        server_auth_password_len,
                                        static_header_len,
                                        static_header);									
	}			
	return 0;	
}
