#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(){
    char file_path[] = "resources/new_file.txt";
    char mode[] = "r";
    FILE *file = fopen(file_path, mode);

    if (! file){
        perror("Unable to create file");
        printf("Error code : %d\n", errno);
        printf("Error message : %s\n", strerror(errno));
    }
    else{
        char ch;
        while ( (ch = fgetc(file)) != EOF )
            printf("%c", ch);
    }
    
    fclose(file);
    return 0;
}