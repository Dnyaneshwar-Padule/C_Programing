/*
    When a C program get's loaded into the main memory, then it becomes a process
    and every process has it's text, data and stack 

    all global, static and dynamic variables are stored in the data region
    all stacks of function are created in stack region
    and text region holds all instructions, of all functions

    a variable pointer stores address of a variable (whether the variable is on the stack or heap)
    it points either in the stack region or data region
    
    But a function pointer, which is created on the stack points to the function instruction
    which are on the text region


    To declare a function pointer, use the return type of the function as the data type
    and write the function pointer name with * in the brackets '()'
    and then write two brackets like (), which tells this is a function pointer
    the pointer name should be in the brackets, so that it won't make conflicts  with functio brackets ()

    ex. 

    void (*fun_ptr)() = function_name;

    here void is the return type of the function
    (*fun_ptr) is the function pointer name
    and () tells this is a function pointer
    function_name is the name of the actual function

    ---------------------------------------------------

    2nd example :

    int add(int a, int b){
        return a + b;
    }
    
    int (*add_ptr)(int,int) = add;

    here,
    int is the return type of the function
    (*add_ptr) is the return type of the function
    (int, int) is the parameter list for the function add
    add is the name of actual add function

    --------------------------------------------------

    3rd example,

    void greet(const char *name){
        printf("Hello %s !\n", name);
    }

    void (*greet_ptr)(const char*) = greet;

    void is return type of the function
    greet_ptr is the function pointer name
    const char * is functio parameter data type

    ---------------------------------------------

    4th example

    int* create_arr(const int len, const int initializer){
        int *arr = (int*)malloc(sizeof(int) * len);
        for(int i = 0; i < len; ++i){
            arr[i] = initializer;
        }
        return arr;
    }

    int* (*create_arr_ptr)(const int, const int) = create_arr;

    int* is the return type of the function
    *create_arr_ptr is the function pointer name
    (const int, const int) are the function parameter data types



*/


#include<stdio.h>
#include<stdlib.h>

int* create_arr(const int len, const int initializer){
    int *arr = (int*)malloc(sizeof(int) * len);
    for(int i = 0; i < len; ++i){
        arr[i] = initializer;
    }
    return arr;
}

void greet(const char *name){
    printf("Hello %s !\n", name);
}

int add(int a, int b){
    printf("Addition : %d\n", a + b);
    return a + b;
}

void say_hello(){
    printf("Hello !\n");
}

int main(){

    void (*say_hello_ptr)() = say_hello;
    int (*add_ptr)(int,int) = add;
    void (*greet_ptr)(const char*) = greet;
    int* (*create_arr_ptr)(const int, const int) = create_arr;

    int* arr;

    printf("I am in main\n");
    say_hello_ptr();
    add_ptr(4,5);
    greet_ptr("Athrva");
    arr = create_arr_ptr(5,5);

    for(int i = 0; i < 5; ++i)
        printf("%d\t", arr[i]);

    free(arr);    
    return 0;
}