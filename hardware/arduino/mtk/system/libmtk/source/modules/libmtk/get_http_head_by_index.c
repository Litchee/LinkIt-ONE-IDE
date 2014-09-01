#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_get_http_head_by_index_t)(http_session_t* session, int index, char* name, char* value);
_get_http_head_by_index_t _get_http_head_by_index = NULL;

int get_http_head_by_index(http_session_t* session, int index, char* name, char* value)
{
    int  ret = {-1};
    if (NULL == _get_http_head_by_index)
        _get_http_head_by_index = (_get_http_head_by_index_t)vm_get_sym_entry("get_http_head_by_index");

    if (NULL != _get_http_head_by_index)
        return _get_http_head_by_index(session,index,name,value);

    return ret;
}
