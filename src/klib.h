#ifndef KLIB_H
#define KLIB_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  KLIB_OK = 0,
  KLIB_ERROR_INVALID_ARGUMENT = -1,
  KLIB_ERROR_COMPRESSION_FAILED = -2,
  KLIB_ERROR_DECOMPRESSION_FAILED = -3,
  KLIB_ERROR_OUT_OF_MEMORY = -4,
  KLIB_ERROR_BUFFER_TOO_SMALL = -5,
  KLIB_ERROR_NOT_INITIALIZED = -6,
  KLIB_ERROR_UNSUPPORTED_FORMAT = -7
} klib_error_t;

klib_error_t klib_init(void);
void klib_cleanup(void);
const char *klib_get_version(void);
const char *klib_get_module_version(const char *module_name);

#ifdef __cplusplus
}
#endif

#endif
