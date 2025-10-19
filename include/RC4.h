#ifndef RC4_H
#define RC4_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t S[256];
    uint8_t i;
    uint8_t j;
} RC4_CTX;

void RC4_init(RC4_CTX *ctx, const uint8_t *key, size_t keylen);
void RC4_crypt(RC4_CTX *ctx, const uint8_t *in, uint8_t *out, size_t len);
void byte_to_bits(uint8_t byte, char *str);

#endif