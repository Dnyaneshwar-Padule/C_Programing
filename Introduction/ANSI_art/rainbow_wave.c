#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main() {
    float t = 0;

    while (1) {
        printf("\033[H");             // cursor top-left
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 80; x++) {

                float value = sin((x + t) * 0.2) * 5 + 10;  
                int r = (int)(sin((x*0.1)+0)*127 + 128);
                int g = (int)(sin((x*0.1)+2)*127 + 128);
                int b = (int)(sin((x*0.1)+4)*127 + 128);

                if (y == (int)value) {
                    printf("\033[38;2;%d;%d;%dm█", r, g, b);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        t += 0.3;
        usleep(30000);  // 30 ms
    }

    return 0;
}
