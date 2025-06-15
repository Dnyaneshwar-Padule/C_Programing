#include<stdio.h>
#include<stdlib.h>

int main(int argc ,char *argv[] )
{
    FILE *source_file;
    unsigned long int char_cnt=0 ,word_cnt = 0 ,cap_char_cnt = 0,small_char_cnt = 0,num_cnt = 0;
    unsigned long int line_cnt = 0;
    char ch;

    if (argc != 2)
    {
        printf("Invalid number of arguments !\n");
        exit(0);
    }
    
   source_file = fopen(argv[1],"r");
    if (source_file == 0)
    {
        printf("Unable to open file !\n");
        exit(0);
    }
    line_cnt = 0;
    while (1)
    {
        ch = fgetc(source_file);

        if (ch == EOF)
        {
            break;
        }
        char_cnt++;

        if (ch == ' ' || ch == '\t')
        {
            word_cnt ++;
        }
        if (ch >= 'A' && ch <='Z')
        {
            cap_char_cnt ++;
        }
        if (ch >= 'a' && ch <='z')
        {
            small_char_cnt ++;
        }
        if (ch >= '0' && ch <='9')
        {
            num_cnt ++;
        }
        if(ch == '\n')
        {
            word_cnt ++;
            line_cnt ++;
        }
 
    }
    

    printf("\n*****  YOUR FILE CONTAINS  *****\n");
    printf("%lu Lines \n%lu Characters :[%lu] Small characters ,[%lu]Capital characters & [%lu]Digits\n%lu Words \n",line_cnt,char_cnt,small_char_cnt,cap_char_cnt,num_cnt,word_cnt);

    fclose(source_file);
    return 0;
}