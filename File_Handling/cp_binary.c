#include<stdio.h>
#include<stdlib.h>

void copy_file(FILE *,FILE *);


void copy_file(FILE *file_target,FILE *file_source)
{
    int n;
    char read[120]; 

    while ( 1 )
    {
        n = fread(read, sizeof(read), 120 ,file_source);

        if (n == 0)
        {
            break;
        }
        
        fwrite(read,sizeof(read), n , file_target);
    }

}

int main(int argc,char *argv[])
{
    FILE *file_source,*file_target;

    char read;
    int n;
    if(argc != 3)
    {
        printf("Invalid number of arguments !!\n");
        exit(0);
    }

    file_source = fopen(argv[1],"rb");
    if (file_source == NULL)
    {
        printf("Unable to open [%s] !\n",argv[1]);
        exit(0);
    }

    file_target = fopen(argv[2],"wb");

    if (file_target == NULL)
    {
        printf("Unable to open [%s]\n",argv[2]);
        exit(0);
    }
    
    copy_file(file_target,file_source);
    
    fclose(file_source);
    fclose(file_target);

    printf("[%s] is SUCCESSFULLY copied into [%s] !!\n",argv[1],argv[2]);

    return 0;
}