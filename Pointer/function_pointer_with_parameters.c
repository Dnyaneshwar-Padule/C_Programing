#include<stdio.h>

int add(int a, int b){
    return a+b;
}

int main(){
    int (*function_ptr) (int,int) = add;
    printf("2 + 5 = %d\n", function_ptr(2,5));
    return 0;
}
