
#include "vmlog.h"
#include "vmio.h"
#include "vmsys.h"
#include "vmchset.h"

#include "vmstdlib.h"

#define MAX_APP_NAME_LEN					(260)

static char * _cache_file_ = NULL;
static int _lineNo = 0;
static char g_log_buffer[MAX_APP_NAME_LEN];

static void log_it(VMINT level, char* fmt, va_list ap);


int _vm_log_module(const char* __file__, const int __line__)
{
	_lineNo = __line__;	
	_cache_file_ = (char*)__file__;	
	return 1;
}

void vm_log_init(char* filename, int log_level) 
{
	return ;
}

void _vm_log_debug(char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	log_it(VM_DEBUG_LEVEL, fmt, ap);
	va_end(ap);
}

void _vm_log_info(char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	log_it(VM_INFO_LEVEL, fmt, ap);
	va_end(ap);
}

void _vm_log_warn(char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	log_it(VM_WARN_LEVEL, fmt, ap);
	va_end(ap);
}

void _vm_log_error(char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	log_it(VM_ERROR_LEVEL, fmt, ap);
	va_end(ap);
}

void _vm_log_fatal(char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	log_it(VM_FATAL_LEVEL, fmt, ap);
	va_end(ap);
}

void log_it(VMINT level, char* fmt, va_list ap) {
	vm_time_t tm;
	int len;
	int i = 0;
	char text[MAX_APP_NAME_LEN];

	memset(text, 0x00, sizeof(text));
		
	vm_get_time(&tm);

	len = strlen(_cache_file_);
	
	while (len>0)
	{
		if (_cache_file_[len-1] != '\\' && _cache_file_[len-1] != '/')
		{
			len--;
		}
		else
		{
			break;
		}
	}
	
	strncpy(g_log_buffer, (char*)&_cache_file_[len], 10);
	
	sprintf(text, "%d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d\t%d\t%s:%d\t", tm.year, tm.mon, tm.day, tm.hour,
		tm.min, tm.sec, level, g_log_buffer ,_lineNo);
	
	vsprintf(text + strlen(text), fmt, ap);
	strcat(text, "\r\n");
	vm_app_log(text);
}

void vm_log_close(void) 
{
	return ;
}

void vm_set_log_level(int log_level)
{
	return;
}



