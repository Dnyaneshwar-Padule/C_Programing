#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct Student
{
    int r_no;
    char name[20];
    float per;
};

void display_namewise(struct Student*,int,char[]);

void display_namewise(struct Student *P, int n,char name[10])
{
    int i,j=1;

    printf("The list of students with name %s:\n",name);
    printf("------------------------------------------------------------\n");
    printf("|Sr.No     | NAME \t        Roll No. \t Percentage |\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (strstr(P[i].name,name))
        {
            printf("|Student %d | %s \t %d \t\t %.2f      |\n", j, P[i].name, P[i].r_no, P[i].per);
            j++;
        }
    }

    printf("------------------------------------------------------------\n");
}

int main()
{
    int students = 5;
    struct Student *P;

    P = (struct Student*) malloc(students * sizeof(struct Student));

    if (P == NULL)
    {
        printf("Unable to allocate memory!!\n");
        exit(0);
    }

    P[0].r_no = 1;
    strcpy(P[0].name, "Prasad Kadam");
    P[0].per = 79;

    P[1].r_no = 2;
    strcpy(P[1].name, "Rohan");
    P[1].per = 69;

    P[2].r_no = 3;
    strcpy(P[2].name, "Prasad Shinde");
    P[2].per = 95;

    P[3].r_no = 4;
    strcpy(P[3].name, "Prasad Paul");
    P[3].per = 95;

    P[4].r_no = 5;
    strcpy(P[4].name, "Shubham");
    P[4].per = 55;

  
    display_namewise(P,students,"Prasad");

    free(P);
    return 0;
}