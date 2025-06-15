#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(){
    char file_path[] = "resources/new_file.txt";
    char mode[] = "a";
    FILE *file = fopen(file_path, mode);

    if (! file){
        perror("Unable to create file");
        printf("Error code : %d\n", errno);
        printf("Error message : %s\n", strerror(errno));
    }
    else{
        char ch = '@';
        if ( fputc(ch, file) )
            printf("Data is appended successfully !\n");
        else
            perror("Unable to append data");
    }
    
    fclose(file);
    return 0;
}