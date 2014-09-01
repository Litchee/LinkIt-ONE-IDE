#include "vmsys.h"
#include "vmsettings.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_settings_set_wallpaper_t)(vm_setttings_wallpaper_enum type, VMWCHAR* path,vm_settings_set_wallpaper_callback callback, void* user_data);
_vm_settings_set_wallpaper_t _vm_settings_set_wallpaper = NULL;

VMINT vm_settings_set_wallpaper(vm_setttings_wallpaper_enum type, VMWCHAR* path,vm_settings_set_wallpaper_callback callback, void* user_data)
{
    if (NULL == _vm_settings_set_wallpaper)
        _vm_settings_set_wallpaper = (_vm_settings_set_wallpaper_t)vm_get_sym_entry("vm_settings_set_wallpaper");

    if (NULL != _vm_settings_set_wallpaper)
        return _vm_settings_set_wallpaper(type,path,callback,user_data);

    return (VMINT )-1;
}
