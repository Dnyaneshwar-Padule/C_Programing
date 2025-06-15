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
        char line[128] = {'\0'};
        int line_cnt = 1;
        while ( (fgets(line, sizeof(line), file) ) )
            printf("Line %d: %s", line_cnt++, line);
    }
 
    fclose(file);
    return 0;
}