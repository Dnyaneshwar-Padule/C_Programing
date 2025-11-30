#include <stdio.h>

int main() {
    int width = 120;
    int height = 40;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int k = x + y;     // diagonal direction

            int r = (k * 2) % 255;
            int g = (k * 5) % 255;
            int b = (k * 9) % 255;

            printf("\033[48;2;%d;%d;%dm ", r, g, b);
        }
        printf("\n");
    }

    printf("\033[0m");
}
