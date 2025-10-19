#include "..\include\RC4.h"

void RC4_init(RC4_CTX *ctx, const uint8_t *key, size_t keylen) {
    for (size_t i = 0; i < 256; i++) {
        ctx->S[i] = (uint8_t)i;
    }
    ctx->i = 0;
    ctx->j = 0;

    uint8_t j = 0;
    for (size_t i = 0; i < 256; i++) {
        j = j + ctx->S[i] + key[i % keylen];
        uint8_t temp = ctx->S[i];
        ctx->S[i] = ctx->S[j];
        ctx->S[j] = temp;
    }
}

void RC4_crypt(RC4_CTX *ctx, const uint8_t *in, uint8_t *out, size_t len) {
    for (size_t k = 0; k < len; k++) {
        ctx->i = ctx->i + 1;
        ctx->j = ctx->j + ctx->S[ctx->i];

        uint8_t temp = ctx->S[ctx->i];
        ctx->S[ctx->i] = ctx->S[ctx->j];
        ctx->S[ctx->j] = temp;

        uint8_t K = ctx->S[(ctx->S[ctx->i] + ctx->S[ctx->j]) & 0xFF];
        out[k] = in[k] ^ K;
    }
}

void byte_to_bits(uint8_t byte, char *str) {
    for (int i = 7; i >= 0; i--) {
        str[7 - i] = (byte & (1 << i)) ? '1' : '0';
    }
    str[8] = '\0';
}