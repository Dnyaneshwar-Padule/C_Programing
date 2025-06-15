#include <stdio.h>
#include <stdlib.h>

struct student
{
    unsigned short int rno;
    char stdudent_name[12];
    float per;
    char class[8];
}; // NO NEED TO DECLARE STRUCTURE VARIABLE

void accept_student_data(int count, struct student *ptr)
{
    register int i;
    for (i = 0; i < count; i++)
    {
        printf("\nEnter the data of student No.%d\n", i+1);
        printf("Enter the name : ");
        scanf("%s", ptr[i].stdudent_name);

        printf("Enter the Roll No. : ");
        scanf("%hu", &ptr[i].rno);

        printf("Enter the class : ");
        getchar();
        gets(ptr[i].class);

        printf("Enter the percentage : ");
        scanf("%f", &ptr[i].per);
        getchar();
    }
}

void display_student_data(int count, struct student *ptr)
{
    register int i;

    printf("\n*** Student Data ***\n");

    printf("\n-----------------------------------------------\n");
    printf("|    Name    | Roll No. | Class  | Percentage |\n");
    printf("-----------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("| %-10s | %-8hu | %-5s  | %-10.2f |\n", ptr[i].stdudent_name, ptr[i].rno, ptr[i].class, ptr[i].per);
    }
    printf("-----------------------------------------------\n");
}

int main()
{
    unsigned int count; // Counter is never in negative.
    struct student *ptr; 

    printf("How many students : ");
    scanf("%d", &count);
    getchar();

    ptr = (struct student *)malloc(count * sizeof(struct student));
    if (ptr == NULL)
    {
        printf("Unable to allocate memory !\n");
        exit(0);
    }

    accept_student_data(count, ptr);
    display_student_data(count, ptr);

    free(ptr);

    return 0;
}
