#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef char* (*_vm_inet_ntoa_t)(IN_ADDR in);
_vm_inet_ntoa_t _vm_inet_ntoa = NULL;

char* vm_inet_ntoa(IN_ADDR in)
{
    if (NULL == _vm_inet_ntoa)
        _vm_inet_ntoa = (_vm_inet_ntoa_t)vm_get_sym_entry("vm_inet_ntoa");
    if (NULL != _vm_inet_ntoa)
        return _vm_inet_ntoa(in);
    return (char*)NULL;
}