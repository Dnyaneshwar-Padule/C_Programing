#include<stdio.h>
#include<errno.h>
#include<string.h>

#define BUFFER_SIZE 256

int main(){
    char file_path[] = "resources/new_file.txt";
    char mode[] = "rb";
    FILE *file = fopen(file_path, mode);

    if (! file){
        perror("Unable to create file");
        printf("Error code : %d\n", errno);
        printf("Error message : %s\n", strerror(errno));
    }
    else{
        char buffer[BUFFER_SIZE] = {'\0'};
        while (fread(buffer, sizeof(char), sizeof(buffer), file))
            printf("%s", buffer); // Should not be printed
    }
    
    fclose(file);
    return 0;
}