#include <stdio.h>

int main() {
    int width = 120;
    int height = 40;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int r = (255 * x) / width;         // left → right (black → red)
            int g = (255 * (width - x)) / width; // right → left (green fade)
            int b = (128 + x) % 255;           // slow blue shift

            printf("\033[48;2;%d;%d;%dm ", r, g, b);
        }
        printf("\n");
    }
    printf("\033[0m");
}
