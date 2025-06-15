#include<stdio.h>

enum traffic_light { RED, GREEN, YELLOW };

void show_light(enum traffic_light light){
    switch (light){
    case RED: printf("It's Red !\n"); break;
    case GREEN: printf("It's Green !\n"); break;
    case YELLOW: printf("It's Yellow !\n"); break;
    default: printf("Invalid light !\n");
    }
}

int main(){
    show_light(RED);
    return 0;
}