#include "vmsys.h"
#include "vmuart.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT16 (*_vm_read_from_uart_t)(VMINT32 handle, VMUINT8 *buffer, VMUINT16 length);
 _vm_read_from_uart_t _vm_read_from_uart = NULL;

VMUINT16 vm_read_from_uart(VMINT32 handle, VMUINT8 *buffer, VMUINT16 length)
{
    if (NULL == _vm_read_from_uart)
        _vm_read_from_uart = (_vm_read_from_uart_t)vm_get_sym_entry("vm_read_from_uart");

    if (NULL != _vm_read_from_uart)
        _vm_read_from_uart(handle, buffer, length);
}