#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(){
    char file_path[] = "resources/new_file.txt";
    char mode[] = "w";
    FILE *file = fopen(file_path, mode);

    if (! file){
        perror("Unable to create file");
        printf("Error code : %d\n", errno);
        printf("Error message : %s\n", strerror(errno));
    }
    else{
        char ch = 'A';
        if( fputc(ch, file) )
            printf("Data is written successfully !\n");
        else   
            perror("Unable to write data");
    }
    
    fclose(file);
    return 0;
}