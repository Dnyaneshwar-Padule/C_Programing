#include<stdio.h>

void say_hello(){
    printf("Hello !\n");
}

void execute(void (*function_ptr)()){
    printf("Inside execute()\n");
    function_ptr();
}

int main(){
    printf("Inside main()\n");
    execute(say_hello);
    return 0;
}