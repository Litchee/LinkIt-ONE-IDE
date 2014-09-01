#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_get_http_head_number_t)(http_session_t* session);
_get_http_head_number_t _get_http_head_number = NULL;

int get_http_head_number(http_session_t* session)
{
    int  ret = {-1};
    if (NULL == _get_http_head_number)
        _get_http_head_number = (_get_http_head_number_t)vm_get_sym_entry("get_http_head_number");

    if (NULL != _get_http_head_number)
        return _get_http_head_number(session);

    return ret;
}
