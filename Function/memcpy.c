
/*
    If you know, how this program works behind the scene, ................

    memcpy(void *destination, const void* source, size_t size);

    memcpy copied data from source to destination,
    it copies specific (size) bits from source to destination

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

struct person{
    int age;
    char name[16];
};

struct student{
    int age;
    char name[16];
    int roll_no;
};

int main(){
    
struct student s = {16, "Athrva", 38};
void *ptr = malloc(sizeof(struct person));
memcpy(ptr, &s, sizeof(struct person));
printf("%d | %s\n", ((struct person*)ptr)->age, ((struct person*)ptr)->name );
free(ptr);
return 0;
}

*/

typedef struct{
    char ch1;
    char ch2;
    char ch3;
    char ch4;
}chars;

typedef struct{
    int i;
}integer;

int main(){
    chars c = {'a', 'b', 'c', 'd'};
    // integer i = {1684234849 };
    // void *ptr = malloc(sizeof(chars));
    void *ptr = malloc(sizeof(integer));
    // memcpy(ptr, &i, sizeof(chars) );
    memcpy(ptr, &c, sizeof(integer) );
    printf("%c | %c | %c | %c \n", ((chars*)ptr)->ch1, ((chars*)ptr)->ch2, ((chars*)ptr)->ch3, ((chars*)ptr)->ch4 );
    printf("%d \n", ((integer*)ptr)->i);
    free(ptr);
    return 0;
}