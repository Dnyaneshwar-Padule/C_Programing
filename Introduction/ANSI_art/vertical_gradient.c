#include <stdio.h>

int main() {
    for (int y = 0; y < 40; y++) {

        int r = y * 6;
        int g = 255 - (y * 6);
        int b = (y * 3) % 255;

        for (int x = 0; x < 120; x++)
            printf("\033[48;2;%d;%d;%dm ", r, g, b);

        printf("\n");
    }
    printf("\033[0m");
    return 0;
}
