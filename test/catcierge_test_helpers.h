
#ifndef __CATCIERGE_TEST_HELPERS_H__
#define __CATCIERGE_TEST_HELPERS_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "catcierge_color.h"

int catcierge_test_verbose();
int catcierge_test_log_on();
void catcierge_test_nocolor(int nocolor);
int catcierge_test_parse_cmdline(int argc, char **argv);
int catcierge_test_init(int argc, char **argv);

void catcierge_test_vprintf(FILE *target,
		enum catcierge_color_e test_color,
		const char *fmt, va_list args);

void catcierge_test_printf(FILE *target,
		enum catcierge_color_e test_color,
		const char *fmt, ...);

void catcierge_test_SUCCESS(const char *fmt, ...);
void catcierge_test_FAILURE(const char *fmt, ...);
void catcierge_test_STATUS(const char *fmt, ...);
void catcierge_test_STATUS_ex(const char *fmt, ...);
void catcierge_test_SKIPPED(const char *fmt, ...);
void catcierge_test_HEADLINE(const char *headline);

void catcierge_test_set_malloc_fail_count(int count);
void *catcierge_test_malloc(size_t sz);
void catcierge_test_set_realloc_fail_count(int count);
void *catcierge_test_realloc(void *ptr, size_t sz);

#endif // __CATCIERGE_TEST_HELPERS_H__
