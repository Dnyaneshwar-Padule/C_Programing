// #include<stdio.h>

// /*

//     Escape characters : 
//         \033
//         \x1b
//         \u001B (valid in Java)

// */


// void show_ansi_magic(){
//     int i = 0;

//     printf("\033[6m");  // blink
    
//     for(int i = 31; i <= 37; ++i)
//         printf("\033[%dm ANSI COLOR\n", i);
    
//         for(int i = 91; i <= 97; ++i)
//         printf("\033[%dm ANSI COLOR\n", i);
    
//         printf("\033[0m");  // reset

//     for(int i = 41; i <= 47; ++i)
//         printf("\033[%dm ANSI COLOR\033[0m\n", i);

//     for(int i = 0; i < 256; i++)
//         printf("\033[48;5;%dm ANSI 256-Colors BACKGROUND\033[0m\n", i);
    
//         for(int i = 0; i < 256; i++)
//         printf("\033[38;5;%dm ANSI 256-Colors Foreground\033[0m\n", i);
//     // printf("");


// }


// int main(){

//     printf("\033[42m  Hello ANSI");
//     printf("\x1b[0m\n");

//     show_ansi_magic();


//     // printf("\033[31;5mBlink\033[0m");
//     // printf("\u001B[32m Hello \u001B[0m ");
//     // printf("Hello !\n");
//     // printf("ANSI");

//     return 0;
// }


#include <stdio.h>

int main() {

    printf("\n=== NORMAL FOREGROUND COLORS (30->37) ===\n");
    for (int i = 30; i <= 37; i++)
        printf("\033[%dm FG %d \033[0m\n", i, i);

    printf("\n=== NORMAL BACKGROUND COLORS (40->47) ===\n");
    for (int i = 40; i <= 47; i++)
        printf("\033[%dm BG %d \033[0m\n", i, i);

    printf("\n=== BRIGHT FOREGROUND COLORS (90->97) ===\n");
    for (int i = 90; i <= 97; i++)
        printf("\033[%dm FG %d \033[0m\n", i, i);

    printf("\n=== BRIGHT BACKGROUND COLORS (100->107) ===\n");
    for (int i = 100; i <= 107; i++)
        printf("\033[%dm BG %d \033[0m\n", i, i);

    printf("\n=== 256-COLOR FOREGROUND (0->255) ===\n");
    for (int i = 0; i < 256; i++)
        printf("\033[38;5;%dm FG %3d \033[0m\n", i, i);

    printf("\n=== 256-COLOR BACKGROUND (0->255) ===\n");
    for (int i = 0; i < 256; i++)
        printf("\033[48;5;%dm BG %3d \033[0m\n", i, i);

    printf("\n=== TRUE COLOR (RGB) FOREGROUND ===\n");
    for (int r = 0; r <= 255; r += 51)
        for (int g = 0; g <= 255; g += 51)
            for (int b = 0; b <= 255; b += 51)
                printf("\033[38;2;%d;%d;%dm RGB(%3d,%3d,%3d) \033[0m\n", 
                       r, g, b, r, g, b);

    printf("\n=== TRUE COLOR (RGB) BACKGROUND ===\n");
    for (int r = 0; r <= 255; r += 51)
        for (int g = 0; g <= 255; g += 51)
            for (int b = 0; b <= 255; b += 51)
                printf("\033[48;2;%d;%d;%dm RGB(%3d,%3d,%3d) \033[0m\n", 
                       r, g, b, r, g, b);

    return 0;
}
