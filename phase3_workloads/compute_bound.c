#include <stdint.h>
#include <stdio.h>

int main(void) {
    volatile uint32_t x = 1;

    // Compute-bound loop (little memory traffic). We rely on gem5 -I maxinsts to stop.
    while (1) {
        x = x * 1664525u + 1013904223u;   // LCG
        x ^= (x >> 16);
        x += (x << 5) + (x >> 3);
    }

    // Unreachable, but keeps compiler honest if anything changes.
    printf("%u\n", x);
    return 0;
}
