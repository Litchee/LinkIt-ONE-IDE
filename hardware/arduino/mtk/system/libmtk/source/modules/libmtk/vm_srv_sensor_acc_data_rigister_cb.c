#include "vmsys.h"
#include "vmsettings.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void  (*_vm_srv_sensor_acc_data_rigister_cb_t)(vm_srv_sensor_acc_data_cb event_hdlr);
_vm_srv_sensor_acc_data_rigister_cb_t _vm_srv_sensor_acc_data_rigister_cb = NULL;
void vm_srv_sensor_acc_data_rigister_cb(vm_srv_sensor_acc_data_cb event_hdlr)

{
    if (NULL == _vm_srv_sensor_acc_data_rigister_cb)
        _vm_srv_sensor_acc_data_rigister_cb = (_vm_srv_sensor_acc_data_rigister_cb_t)vm_get_sym_entry("vm_srv_sensor_acc_data_rigister_cb");
    if (NULL != _vm_srv_sensor_acc_data_rigister_cb)
        _vm_srv_sensor_acc_data_rigister_cb(event_hdlr);
}