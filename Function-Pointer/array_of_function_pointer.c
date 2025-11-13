#include<stdio.h>
#include<string.h>

typedef enum{STR_CPY, STR_CMP, STR_CAT} type_t;

typedef struct{
    type_t t;
    void *fn;
}wrapper;

typedef int   (*cmp_fn)(const char*, const char*);
typedef char* (*str_fn)(char*, const char*);

void dispatch(wrapper w, char *dest, char* src1, char* src2){
   switch (w.t){
        case STR_CAT:{
            str_fn fn = (str_fn)w.fn;
            printf("Concatenation : %s\n", fn(dest, src1));
        }
        break;

        case STR_CMP:{
            cmp_fn fn = (cmp_fn)w.fn;
            int status = fn(dest, src1);
            printf("Comparison : %d\n", status);
        }
        break;

        case STR_CPY:{
            str_fn fn = (str_fn)w.fn;
            printf("Copy : %s\n", fn(dest, src1));
        }
        break;
    } 
}

int main(){

    wrapper w[] = {
        {STR_CPY, strcpy},
        {STR_CMP, strcmp},
        {STR_CAT, strcat},
    };

    char buffer[60] = "ABC";

    dispatch(w[STR_CMP], buffer, "XYZ", "ABC" );
    dispatch(w[STR_CPY], buffer, "PQR",NULL );
    dispatch(w[STR_CAT], buffer, "LMN",NULL );

    return 0;
}