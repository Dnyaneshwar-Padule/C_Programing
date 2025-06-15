#include<stdio.h>
#include<string.h>

#define SUCCESS 0
#define TRUE 1

struct employee{
    char name[32];
    int id;
    int salary;
};

typedef struct employee Employee;

void clear_buffer(){
    char ch;
    while ( (ch = getchar()) != '\n' && ch != EOF );
    
}

int main(){
    Employee employees[50];
    int i = 0;
    int choice = 0;

    while (TRUE){
        printf("\nEnter '1' to enter a record : ");
        if (! scanf("%d", &choice)){
            printf("Invalid input !\n");
            break;
        }
        clear_buffer();
        if (choice == 1){
            printf("Enter  the name of  employee : ");
            fgets(employees[i].name, 32, stdin);
            employees[i].name[strlen(employees[i].name) - 1] = '\0';
            
            printf("Enter  the  id  of  employee : ");
            scanf("%d", &employees[i].id);
            
            printf("Enter the salary of employee : ");
            scanf("%d", &employees[i].salary);
            i++;
        }
        else{
            printf("Invalid input !\n");
            break;
        }
    }

    if (i) {
        printf("\n+----------------+--------+---------+\n");
        printf("|      Name      |   ID   | Salary  |\n");
        printf("+----------------+--------+---------+\n");
        while (i--){
            printf("| %-14s | %-6d | %-7d |\n", employees[i].name, employees[i].id, employees[i].salary);
        }
        printf("+----------------+--------+---------+\n");
    }
    else{
        printf("No student record !\n");
    }
    

    return SUCCESS;
    
}