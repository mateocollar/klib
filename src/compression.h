#ifndef KLIB_COMPRESSION_H
#define KLIB_COMPRESSION_H

#include "klib.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  KLIB_FORMAT_ZLIB = 0,
  KLIB_FORMAT_GZIP = 1,
  KLIB_FORMAT_RAW = 2
} klib_compression_format_t;

#define KLIB_LEVEL_DEFAULT -1
#define KLIB_LEVEL_FASTEST 1
#define KLIB_LEVEL_BEST 9
#define KLIB_LEVEL_NONE 0

klib_error_t klib_compress(const uint8_t *input, size_t input_len,
                           uint8_t *output, size_t *output_len,
                           klib_compression_format_t format, int level);

klib_error_t klib_decompress(const uint8_t *input, size_t input_len,
                             uint8_t *output, size_t *output_len,
                             size_t max_output_len,
                             klib_compression_format_t format);

size_t klib_compress_bound(size_t input_len, klib_compression_format_t format);
bool klib_is_compressed(const uint8_t *data, size_t len,
                        klib_compression_format_t format);

klib_error_t klib_compress_chunk(const uint8_t *input, size_t input_len,
                                 uint8_t *output, size_t *output_len);

#ifdef __cplusplus
}
#endif

#endif
