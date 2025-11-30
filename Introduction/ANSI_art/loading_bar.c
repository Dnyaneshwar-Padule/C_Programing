#include <stdio.h>
#include <unistd.h>

int main() {

    int width = 50;

    for (int i = 0; i <= width; i++) {

        // Clear line
        printf("\033[2K\r");

        // Dynamic RGB based on progress
        int r = (i * 5) % 255;
        int g = (i * 11) % 255;
        int b = (i * 17) % 255;

        // Print opening bracket
        printf("[");

        // Filled part
        for (int j = 0; j < i; j++)
            printf("\033[48;2;%d;%d;%dm \033[0m", r, g, b);

        // Empty part
        for (int j = i; j < width; j++)
            printf(" ");

        // Closing bracket + percentage
        printf("] %3d%%", (i * 100) / width);

        fflush(stdout);
        usleep(50000);  // adjust speed (50 ms)
    }

    printf("\nLoading Complete!\n");
    return 0;
}
