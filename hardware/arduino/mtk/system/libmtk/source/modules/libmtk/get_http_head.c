#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_get_http_head_t)(http_session_t* session, const char* name, char* value);
_get_http_head_t _get_http_head = NULL;

int get_http_head(http_session_t* session, const char* name, char* value)
{
    int  ret = {-1};
    if (NULL == _get_http_head)
        _get_http_head = (_get_http_head_t)vm_get_sym_entry("get_http_head");

    if (NULL != _get_http_head)
        return _get_http_head(session,name,value);

    return ret;
}
