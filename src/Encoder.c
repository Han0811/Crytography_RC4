#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "..\include\RC4.h"

int main() {
    const uint8_t key[] = "DaihocBachKhoaHaNoi";
    uint8_t plaintext[] = "Hanoi University of Science and Technology";

    RC4_CTX ctx;
    RC4_init(&ctx, key, strlen((const char *)key));
    RC4_crypt(&ctx, plaintext, plaintext, strlen((const char *)plaintext));

    size_t len = strlen((const char *)plaintext);

    FILE *f_hex = fopen("ciphertext.txt", "w");
    if (!f_hex) {
        perror("Không thể mở file hexa");
        return 1;
    }
    for (size_t i = 0; i < len; i++) {
        fprintf(f_hex, "0x%02X\t", plaintext[i]);
    }
    fprintf(f_hex, "\n");
    fclose(f_hex);
    printf("Ciphertext đã được ghi vào file ciphertext.txt (hexa)\n");

    FILE *f_bit = fopen("ciphertext_bits.txt", "w");
    if (!f_bit) {
        perror("Không thể mở file bit");
        return 1;
    }

    char bits[9];
    for (size_t i = 0; i < len; i++) {
        byte_to_bits(plaintext[i], bits);
        fprintf(f_bit, "%s", bits);
    }
    fprintf(f_bit, "\n");
    fclose(f_bit);
    printf("Ciphertext đã được ghi vào file ciphertext_bits.txt\n");

    return 0;
}
