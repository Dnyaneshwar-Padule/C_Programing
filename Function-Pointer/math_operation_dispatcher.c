#include<stdio.h>

typedef enum{ADD, SUB, MUL, DIV} type_t;

typedef struct 
{
    type_t t;
    void *fn;
}wrapper;

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

float div(int a, int b){
    return (float)a / (float)b;
}

//tricky
/*
    It's creating a type, not creating a alias
    complex type into a simple type
*/
typedef int (*int_fn)(int, int);    // int_fn
typedef float (*float_fn)(int, int);  // float_fn

void math_dispatch(wrapper w, int a, int b){
    switch (w.t)
    {
        case ADD:{
            int_fn fn  = (int_fn) w.fn;
            printf("Addition : %d\n", fn(a,b));
        }
        break;
        case SUB:{
            int_fn fn  = (int_fn) w.fn;
            printf("Subtraction : %d\n", fn(a,b));
        }
        break;
        case MUL:{
            int_fn fn  = (int_fn) w.fn;
            printf("Multiplication : %d\n", fn(a,b));
        }
        break;
        case DIV:{
            float_fn fn  = (float_fn) w.fn;
            printf("Division : %f\n", fn(a,b));
        }
        break;
    }
}

int main(){

    wrapper w[] = {
        {ADD, add},
        {SUB, sub},
        {MUL, mul},
        {DIV, div},
    };

    math_dispatch(w[ADD], 45, 55);
    math_dispatch(w[SUB], 55, 5);
    math_dispatch(w[MUL], 5, 55);
    math_dispatch(w[DIV], 45, 7);
    
    return 0;
}
