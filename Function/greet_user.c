#include<stdio.h>
#define SUCCESS 0

void greet_user();

int main()
{
    greet_user();
    return SUCCESS;
}

void greet_user()
{
    printf("Hello user!\n");
}