#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // 8 MiB array, stride = 64B (cache-line-ish) => streaming / memory-bound.
    const size_t bytes = 8 * 1024 * 1024;
    const size_t N = bytes / sizeof(uint32_t);
    const size_t stride = 16; // 16 * 4B = 64B

    uint32_t *a = aligned_alloc(64, bytes);
    if (!a) {
        perror("aligned_alloc failed");
        return 1;
    }

    for (size_t i = 0; i < N; i++) a[i] = (uint32_t)i;

    volatile uint32_t sum = 0;
    while (1) {
        for (size_t i = 0; i < N; i += stride) {
            sum += a[i];
        }
    }

    printf("%u\n", sum);
    free(a);
    return 0;
}
