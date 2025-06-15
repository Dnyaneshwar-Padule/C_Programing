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

        if ( fprintf(file, "%s,%d,%.2f", student.name, student.roll_no, student.per) ){
            printf("Data is written successfully !\n");
            Student s;
            
            rewind(file);

            if (  fscanf(file, "%31[^,],%d,%f", s.name, &s.roll_no, &s.per)  ){
                printf("Data is read successfully !\n");
                printf("Student Data\n");
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