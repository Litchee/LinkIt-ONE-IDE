#include "vmsys.h"
#include "vm4res.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_res_init_t)(void);
_vm_res_init_t _vm_res_init = NULL;
VMINT32 vm_res_init(void)
{
    if (NULL == _vm_res_init)
        _vm_res_init = (_vm_res_init_t)vm_get_sym_entry("vm_res_init");

    if (NULL != _vm_res_init)
        return _vm_res_init();

    return (VMINT32 )-1;
}

typedef VMINT32 (*_vm_res_init_with_language_t)(VMUINT32 language);
_vm_res_init_with_language_t _vm_res_init_with_language = NULL;
VMINT32 vm_res_init_with_language(VMUINT32 language)
{
    if (NULL == _vm_res_init_with_language)
        _vm_res_init_with_language = (_vm_res_init_with_language_t)vm_get_sym_entry("vm_res_init_with_language");

    if (NULL != _vm_res_init_with_language)
        return _vm_res_init_with_language(language);

    return (VMINT32 )-1;
}

typedef VMINT32 (*_vm_res_deinit_t)(void);
_vm_res_deinit_t _vm_res_deinit = NULL;
VMINT32 vm_res_deinit(void)
{
    if (NULL == _vm_res_deinit)
        _vm_res_deinit = (_vm_res_deinit_t)vm_get_sym_entry("vm_res_deinit");

    if (NULL != _vm_res_deinit)
        return _vm_res_deinit();

    return (VMINT32 )-1;
}

typedef VMUINT8 * (*_vm_res_get_string_t)(VMUINT32 string_id);
_vm_res_get_string_t _vm_res_get_string = NULL;
VMUINT8 *vm_res_get_string(VMUINT32 string_id)
{
    if (NULL == _vm_res_get_string)
        _vm_res_get_string = (_vm_res_get_string_t)vm_get_sym_entry("vm_res_get_string");

    if (NULL != _vm_res_get_string)
        return _vm_res_get_string(string_id);

    return NULL;
}

typedef VMINT32 (*_vm_res_load_image_start_t)(void);
_vm_res_load_image_start_t _vm_res_load_image_start = NULL;
VMINT32 vm_res_load_image_start(void)
{
    if (NULL == _vm_res_load_image_start)
        _vm_res_load_image_start = (_vm_res_load_image_start_t)vm_get_sym_entry("vm_res_load_image_start");

    if (NULL != _vm_res_load_image_start)
        return _vm_res_load_image_start();

    return (VMINT32 )-1;
}

typedef VMINT32 (*_vm_res_load_image_end_t)(void);
_vm_res_load_image_end_t _vm_res_load_image_end = NULL;
VMINT32 vm_res_load_image_end(void)
{
    if (NULL == _vm_res_load_image_end)
        _vm_res_load_image_end = (_vm_res_load_image_end_t)vm_get_sym_entry("vm_res_load_image_end");

    if (NULL != _vm_res_load_image_end)
        return _vm_res_load_image_end();

    return (VMINT32 )-1; 
}

typedef VMINT (*_vm_res_get_image_and_size_from_file_t)(VMWSTR filename, VMUINT32 image_id, void* buff, VMUINT32 *size);
_vm_res_get_image_and_size_from_file_t _vm_res_get_image_and_size_from_file = NULL;
VMINT vm_res_get_image_and_size_from_file(VMWSTR filename, VMUINT32 image_id, void* buff, VMUINT32 *size)
{
    if (NULL == _vm_res_get_image_and_size_from_file)
        _vm_res_get_image_and_size_from_file = (_vm_res_get_image_and_size_from_file_t)vm_get_sym_entry("vm_res_get_image_and_size_from_file");

    if (NULL != _vm_res_get_image_and_size_from_file)
        return _vm_res_get_image_and_size_from_file(filename, image_id, buff, size);

    return (VMINT )-1;
}

typedef VMINT (*_vm_res_get_audio_and_size_from_file_t)(VMWSTR filename, VMUINT32 audio_id, void* buff, VMUINT32 *size);
_vm_res_get_audio_and_size_from_file_t _vm_res_get_audio_and_size_from_file = NULL;
VMINT vm_res_get_audio_and_size_from_file(VMWSTR filename, VMUINT32 audio_id, void* buff, VMUINT32 *size)
{
    if (NULL == _vm_res_get_audio_and_size_from_file)
        _vm_res_get_audio_and_size_from_file = (_vm_res_get_image_and_size_from_file_t)vm_get_sym_entry("vm_res_get_audio_and_size_from_file");

    if (NULL != _vm_res_get_audio_and_size_from_file)
        return _vm_res_get_audio_and_size_from_file(filename, audio_id, buff, size);

    return (VMINT )-1;
}

typedef VMINT (*_vm_res_get_string_and_size_from_file_t)(VMWSTR filename, VMUINT32 string_id, void* buff, VMUINT32 *size);
_vm_res_get_string_and_size_from_file_t _vm_res_get_string_and_size_from_file = NULL;
VMINT vm_res_get_string_and_size_from_file(VMWSTR filename, VMUINT32 string_id, void* buff, VMUINT32 *size)
{
    if (NULL == _vm_res_get_string_and_size_from_file)
        _vm_res_get_string_and_size_from_file = (_vm_res_get_string_and_size_from_file_t)vm_get_sym_entry("vm_res_get_string_and_size_from_file");

    if (NULL != _vm_res_get_string_and_size_from_file)
        return _vm_res_get_string_and_size_from_file(filename, string_id, buff, size);

    return (VMINT )-1;
}

typedef VMINT (*_vm_res_get_image_and_size_from_rom_t)(VMWSTR filename, VMUINT32 image_id, void** buff, VMUINT32 *size);
_vm_res_get_image_and_size_from_rom_t _vm_res_get_image_and_size_from_rom = NULL;
VMINT vm_res_get_image_and_size_from_rom(VMWSTR filename, VMUINT32 image_id, void** buff, VMUINT32 *size)
{
    if (NULL == _vm_res_get_image_and_size_from_rom)
        _vm_res_get_image_and_size_from_rom = (_vm_res_get_image_and_size_from_rom_t)vm_get_sym_entry("vm_res_get_image_and_size_from_rom");

    if (NULL != _vm_res_get_image_and_size_from_rom)
        return _vm_res_get_image_and_size_from_rom(filename, image_id, buff, size);

    return (VMINT )-1;
}

typedef VMINT (*_vm_res_get_audio_and_size_from_rom_t)(VMWSTR filename, VMUINT32 audio_id, void** buff, VMUINT32 *size);
_vm_res_get_audio_and_size_from_rom_t _vm_res_get_audio_and_size_from_rom = NULL;
VMINT vm_res_get_audio_and_size_from_rom(VMWSTR filename, VMUINT32 audio_id, void** buff, VMUINT32 *size)
{
    if (NULL == _vm_res_get_audio_and_size_from_rom)
        _vm_res_get_audio_and_size_from_rom = (_vm_res_get_audio_and_size_from_rom_t)vm_get_sym_entry("vm_res_get_audio_and_size_from_rom");

    if (NULL != _vm_res_get_audio_and_size_from_rom)
        return _vm_res_get_audio_and_size_from_rom(filename, audio_id, buff, size);

    return (VMINT )-1;
}

typedef VMINT (*_vm_res_get_string_and_size_from_rom_t)(VMWSTR filename, VMUINT32 string_id, void** buff, VMUINT32 *size);
_vm_res_get_string_and_size_from_rom_t _vm_res_get_string_and_size_from_rom = NULL;
VMINT vm_res_get_string_and_size_from_rom(VMWSTR filename, VMUINT32 string_id, void** buff, VMUINT32 *size)
{
    if (NULL == _vm_res_get_string_and_size_from_rom)
        _vm_res_get_string_and_size_from_rom = (_vm_res_get_string_and_size_from_rom_t)vm_get_sym_entry("vm_res_get_string_and_size_from_rom");

    if (NULL != _vm_res_get_string_and_size_from_rom)
        return _vm_res_get_string_and_size_from_rom(filename, string_id, buff, size);

    return (VMINT )-1;
}

typedef VMUINT8 * (*_vm_res_get_image_and_size_t)(VMUINT32 image_id, VMUINT32 *size);
_vm_res_get_image_and_size_t _vm_res_get_image_and_size = NULL;
VMUINT8 *vm_res_get_image_and_size(VMUINT32 image_id, VMUINT32 *size)
{
    if (NULL == _vm_res_get_image_and_size)
        _vm_res_get_image_and_size = (_vm_res_get_image_and_size_t)vm_get_sym_entry("vm_res_get_image_and_size");

    if (NULL != _vm_res_get_image_and_size)
        return _vm_res_get_image_and_size(image_id,size);

    return NULL;
}

typedef VMUINT8 * (*_vm_res_get_image_t)(VMUINT32 image_id);
_vm_res_get_image_t _vm_res_get_image = NULL;
VMUINT8 *vm_res_get_image(VMUINT32 image_id)
{
    if (NULL == _vm_res_get_image)
        _vm_res_get_image = (_vm_res_get_image_t)vm_get_sym_entry("vm_res_get_image");

    if (NULL != _vm_res_get_image)
        return _vm_res_get_image(image_id);

    return NULL;
}

typedef VMUINT8 * (*_vm_res_get_image_with_header_t)(VMUINT32 image_id);
_vm_res_get_image_with_header_t _vm_res_get_image_with_header = NULL;
VMUINT8 *vm_res_get_image_with_header(VMUINT32 image_id)
{
    if (NULL == _vm_res_get_image_with_header)
        _vm_res_get_image_with_header = (_vm_res_get_image_with_header_t)vm_get_sym_entry("vm_res_get_image_with_header");

    if (NULL != _vm_res_get_image_with_header)
        return _vm_res_get_image_with_header(image_id);

    return NULL;
}

typedef VMUINT8 * (*_vm_res_get_image_and_size_with_header_t)(VMUINT32 image_id, VMUINT32 *size);
_vm_res_get_image_and_size_with_header_t _vm_res_get_image_and_size_with_header = NULL;
VMUINT8 *vm_res_get_image_and_size_with_header(VMUINT32 image_id, VMUINT32 *size)
{
    if (NULL == _vm_res_get_image_and_size_with_header)
        _vm_res_get_image_and_size_with_header = (_vm_res_get_image_and_size_with_header_t)vm_get_sym_entry("vm_res_get_image_and_size_with_header");

    if (NULL != _vm_res_get_image_and_size_with_header)
        return _vm_res_get_image_and_size_with_header(image_id, size);

    return NULL;
}

typedef VMUINT8 * (*_vm_res_get_audio_t)(VMUINT32 audio_id);
_vm_res_get_audio_t _vm_res_get_audio = NULL;
VMUINT8 *vm_res_get_audio(VMUINT32 audio_id)
{
    if (NULL == _vm_res_get_audio)
        _vm_res_get_audio = (_vm_res_get_audio_t)vm_get_sym_entry("vm_res_get_audio");

    if (NULL != _vm_res_get_audio)
        return _vm_res_get_audio(audio_id);

    return NULL;
}

typedef VMINT32 (*_vm_res_delete_t)(VMUINT32 id);
_vm_res_delete_t _vm_res_delete = NULL;
VMINT32 vm_res_delete(VMUINT32 id)
{
    if (NULL == _vm_res_delete)
        _vm_res_delete = (_vm_res_delete_t)vm_get_sym_entry("vm_res_delete");

    if (NULL != _vm_res_delete)
        return _vm_res_delete(id);

    return (VMINT32 )-1;
}

typedef VMUINT8 * (*_vm_res_get_virtual_image_t)(VMUINT32 image_id);
_vm_res_get_virtual_image_t _vm_res_get_virtual_image = NULL;
VMUINT8 *vm_res_get_virtual_image(VMUINT32 image_id)
{
    if (NULL == _vm_res_get_virtual_image)
        _vm_res_get_virtual_image = (_vm_res_get_virtual_image_t)vm_get_sym_entry("vm_res_get_virtual_image");

    if (NULL != _vm_res_get_virtual_image)
        return _vm_res_get_virtual_image(image_id);

    return NULL;
}
