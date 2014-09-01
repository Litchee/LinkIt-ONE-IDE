#include "vmsys.h"
#include "vmdcl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;


typedef VM_DCL_HANDLE (*_vm_dcl_open_t)(VM_DCL_DEV dev, VM_DCL_FLAGS flags);
_vm_dcl_open_t _vm_dcl_open = NULL;
VM_DCL_HANDLE vm_dcl_open(VM_DCL_DEV dev, VM_DCL_FLAGS flags)
{
    if (NULL == _vm_dcl_open)
        _vm_dcl_open = (_vm_dcl_open_t)vm_get_sym_entry("vm_dcl_open");

    if (NULL != _vm_dcl_open)
        return _vm_dcl_open(dev, flags);

    return (VMINT )VM_DCL_HANDLE_INVALID;
}

typedef VM_DCL_STATUS (*_vm_dcl_control_t)(VM_DCL_HANDLE device_handle,VM_DCL_CTRL_CMD cmd,  void* arg);
_vm_dcl_control_t _vm_dcl_control = NULL;
VM_DCL_STATUS vm_dcl_control(VM_DCL_HANDLE device_handle,VM_DCL_CTRL_CMD cmd,  void* arg)
{
    if (NULL == _vm_dcl_control)
        _vm_dcl_control = (_vm_dcl_control_t)vm_get_sym_entry("vm_dcl_control");

    if (NULL != _vm_dcl_control)
        return _vm_dcl_control(device_handle, cmd, arg);

    return (VMINT )VM_DCL_STATUS_FAIL;
}

typedef VM_DCL_STATUS (*_vm_dcl_close_t)(VM_DCL_HANDLE device_handle);
_vm_dcl_close_t _vm_dcl_close = NULL;
VM_DCL_STATUS vm_dcl_close(VM_DCL_HANDLE device_handle)
{
    if (NULL == _vm_dcl_close)
        _vm_dcl_close = (_vm_dcl_close_t)vm_get_sym_entry("vm_dcl_close");

    if (NULL != _vm_dcl_close)
        return _vm_dcl_close(device_handle);

    return (VMINT )VM_DCL_STATUS_FAIL;
}

typedef VM_DCL_STATUS (*_vm_dcl_registercallback_t)(VM_DCL_HANDLE device_handle,VM_DCL_EVENT event, VM_DCL_CALLBACK callback,void* user_data);
_vm_dcl_registercallback_t _vm_dcl_registercallback = NULL;
VM_DCL_STATUS vm_dcl_registercallback(VM_DCL_HANDLE device_handle,VM_DCL_EVENT event, VM_DCL_CALLBACK callback,void* user_data)
{
    if (NULL == _vm_dcl_registercallback)
        _vm_dcl_registercallback = (_vm_dcl_registercallback_t)vm_get_sym_entry("vm_dcl_registercallback");

    if (NULL != _vm_dcl_registercallback)
        return _vm_dcl_registercallback(device_handle,event, callback, user_data);

    return (VMINT )VM_DCL_STATUS_FAIL;
}

typedef VM_DCL_STATUS (*_vm_dcl_addlistenevent_t)(VM_DCL_HANDLE device_handle,VM_DCL_EVENT event, void* user_data);
_vm_dcl_addlistenevent_t _vm_dcl_addlistenevent = NULL;
VM_DCL_STATUS vm_dcl_addlistenevent(VM_DCL_HANDLE device_handle,VM_DCL_EVENT event, void* user_data)
{
    if (NULL == _vm_dcl_addlistenevent)
        _vm_dcl_addlistenevent = (_vm_dcl_addlistenevent_t)vm_get_sym_entry("vm_dcl_addlistenevent");

    if (NULL != _vm_dcl_addlistenevent)
        return _vm_dcl_addlistenevent(device_handle,event, user_data);

    return (VMINT )VM_DCL_STATUS_FAIL;
}

typedef VM_DCL_STATUS (*_vm_dcl_read_t)(VM_DCL_HANDLE device_handle, VM_DCL_BUFF* buf, VM_DCL_BUFF_LEN buf_len, VM_DCL_BUFF_LEN* returned_len,VM_DCL_OPTIONS options);
_vm_dcl_read_t _vm_dcl_read = NULL;
VM_DCL_STATUS vm_dcl_read(VM_DCL_HANDLE device_handle, VM_DCL_BUFF* buf, VM_DCL_BUFF_LEN buf_len, VM_DCL_BUFF_LEN* returned_len,VM_DCL_OPTIONS options)
{
    if (NULL == _vm_dcl_read)
        _vm_dcl_read = (_vm_dcl_read_t)vm_get_sym_entry("vm_dcl_read");

    if (NULL != _vm_dcl_read)
        return _vm_dcl_read(device_handle, buf, buf_len, returned_len, options);

    return (VMINT )VM_DCL_STATUS_FAIL;
}

typedef VM_DCL_STATUS (*_vm_dcl_write_t)(VM_DCL_HANDLE device_handle,VM_DCL_BUFF* buf, VM_DCL_BUFF_LEN buf_len, VM_DCL_BUFF_LEN* writed_len,VM_DCL_OPTIONS options);
_vm_dcl_write_t _vm_dcl_write = NULL;
VM_DCL_STATUS vm_dcl_write(VM_DCL_HANDLE device_handle,VM_DCL_BUFF* buf, VM_DCL_BUFF_LEN buf_len, VM_DCL_BUFF_LEN* writed_len,VM_DCL_OPTIONS options)
{
    if (NULL == _vm_dcl_write)
        _vm_dcl_write = (_vm_dcl_write_t)vm_get_sym_entry("vm_dcl_write");

    if (NULL != _vm_dcl_write)
        return _vm_dcl_write(device_handle,buf, buf_len, writed_len, options);

    return (VMINT )VM_DCL_STATUS_FAIL;
}

typedef VM_DCL_MODULE_TYPE_T (*_vm_dcl_get_ownerid_t)();
_vm_dcl_get_ownerid_t _vm_dcl_get_ownerid = NULL;
VM_DCL_MODULE_TYPE_T vm_dcl_get_ownerid()
{
    if (NULL == _vm_dcl_get_ownerid)
        _vm_dcl_get_ownerid = (_vm_dcl_get_ownerid_t)vm_get_sym_entry("vm_dcl_get_ownerid");

    if (NULL != _vm_dcl_get_ownerid)
        return _vm_dcl_get_ownerid();

    return 0;
}

typedef VMUINT32 (*_vm_irq_mask_t)();
_vm_irq_mask_t _vm_irq_mask = NULL;
VMUINT32 vm_irq_mask()
{
    if (NULL == _vm_irq_mask)
        _vm_irq_mask = (_vm_irq_mask_t)vm_get_sym_entry("vm_irq_mask");

    if (NULL != _vm_irq_mask)
        return _vm_irq_mask();

    return 0;	
}

typedef void (*_vm_irq_restore_t)();
_vm_irq_restore_t _vm_irq_restore = NULL;
void vm_irq_restore(VMUINT32 mask)
{
    if (NULL == _vm_irq_restore)
        _vm_irq_restore = (_vm_irq_restore_t)vm_get_sym_entry("vm_irq_restore");

    if (NULL != _vm_irq_restore)
        _vm_irq_restore(mask);
}
