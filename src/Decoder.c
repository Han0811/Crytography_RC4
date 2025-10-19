#include <stdio.h>
#include <string.h>
#include "..\include\RC4.h"

#define MAX_CIPHER_SIZE 1024

int main() {
    const uint8_t key[] = "DaihocBachKhoaHaNoi";
    uint8_t ciphertext[MAX_CIPHER_SIZE];
    size_t cipher_len = 0;

    FILE *f = fopen("ciphertext.txt", "r");
    if (!f) {
        perror("Không thể mở file");
        return 1;
    }
    while (fscanf(f, " 0x%2hhX", &ciphertext[cipher_len]) == 1) {
        cipher_len++;
        if (cipher_len >= MAX_CIPHER_SIZE) break;
    }
    fclose(f);

    if (cipher_len == 0) {
        printf("Không có dữ liệu nào được đọc từ file.\n");
        return 1;
    }

    uint8_t decrypted[MAX_CIPHER_SIZE + 1];
    RC4_CTX ctx;
    RC4_init(&ctx, key, strlen((const char *)key));
    RC4_crypt(&ctx, ciphertext, decrypted, cipher_len);

    decrypted[cipher_len] = '\0';

    printf("\n\n\nDecrypted text: %s\n", decrypted);

    return 0;
}
