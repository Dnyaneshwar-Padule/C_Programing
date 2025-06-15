#include<stdio.h>
#include<string.h>

#define SUCCESS 0
#define TRUE 1

struct product{
    int id;
    char name[32];
    float price;
};

typedef struct product Product;

void clear_buffer(){
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF );
    
}

int main(){

    Product products[50];
    int choice = 0;
    int n = 0;

    while (TRUE){
        printf("\nEnter '1' to enter a record : ");
        if (! scanf("%d", &choice)){
            printf("Invalid input !\n");
            break;
        }

        if (choice == 1 ){
            printf("Enter  the  product  ID : ");
            scanf("%d", &products[n].id);
            
            clear_buffer();
            printf("Enter the  product name : ");
            fgets(products[n].name, 32, stdin);
            products[n].name[ strlen(products[n].name) - 1] = '\0';

            printf("Enter the product price : ");
            scanf("%f", &products[n].price);
            n++;
        }
        else{
            printf("Invalid input !\n");
            break;
        }         
    }

    if (n) {
        printf("\n+=================================+\n");
        printf("|          Product Details        |\n");
        printf("+=================================+\n");
        printf("|     Name     |   ID   |  Price  |\n");
        printf("+--------------+--------+---------+\n");
        while (n--) 
            printf("| %-12s | %-6d | %-7.2f |\n", products[n].name, products[n].id, products[n].price);
        printf("+--------------+--------+---------+\n");
        
    }
    else{
        printf("No records\n");
    }
    
    return SUCCESS;
}