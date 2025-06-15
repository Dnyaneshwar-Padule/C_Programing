#include<stdio.h>
#include<errno.h>
#include<string.h>

typedef struct {
    char name[32];
    int roll_no;
    float per;
} Student;


int main(){
    char file_path[] = "resources/data.txt";
    char mode[] = "w+";
    FILE *file = fopen(file_path, mode);

    if (! file){
        perror("Unable to create file");
        printf("Error code : %d\n", errno);
        printf("Error message : %s\n", strerror(errno));
    }
    else{
        Student student = {"Athrva", 38, 86.60};

        if ( fwrite(&student, sizeof(Student), 1, file) ){
            printf("Data is written successfully !\n");
            Student s;
            
            fseek(file, 0, SEEK_SET); // changing the file pointer at the beginning of the file

            if ( fread(&s, sizeof(Student), 1, file) ){
                printf("Data is read successfully !\n");
                printf("\nStudent Data\n");
                printf("Name       : %s\n", s.name);
                printf("Roll No    : %d\n", s.roll_no);
                printf("Percentage : %.2f\n", s.per);
            } 
            else
                perror("Unable to read data");
        }
        else
            perror("Unable to write data");
    }

    fclose(file);
    return 0;
}