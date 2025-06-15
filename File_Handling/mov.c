#include<stdio.h>
#include<stdlib.h>

void copy_file(FILE *,FILE *);

void copy_file(FILE *file_source,FILE *file_target)
{   
    char read_ch[120];
    while ( fgets(read_ch , sizeof(read_ch),file_source) )
    {
        fprintf(file_target, "%s" , read_ch);
    }
    
}

int main(int argc,char *argv[]) // Taking file name and their paths as command line arguments
{
    FILE *file_source,*file_target;


    if(argc != 3)
    {
        printf("Invalid number of arguments !!\n");
        exit(0);
    }

    file_source = fopen(argv[1],"r");
    if (file_source == NULL)
    {
        printf("Unable to open [%s] !\n",argv[1]);
        exit(0);
    }

    file_target = fopen(argv[2],"w");

    if (file_target == NULL)
    {
        printf("Unable to open [%s]\n",argv[2]);
        exit(0);
    }
    
    copy_file(file_source,file_target);
    
    fclose(file_source);
    fclose(file_target);
    remove(argv[1]);  // Deleting the file 

    printf("[%s] is SUCCESSFULLY moved into [%s] !!\n",argv[1],argv[2]);

    return 0;
}