#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void accept_matrix(int*,int,int);
void read_matrix(int*,int,int);
void addition_matix(int*,int*,int*,int,int);

void accept_matrix(int* mat, int r,int col)
{

    int i,j;
    
    printf("\n\nEnter the elements at .\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("Row No.%d & Column No.%d :-> ",i+1,j+1);
            scanf("%d",&mat[i*col+j]);
        }

    }

}
void read_matrix(int* mat,int r,int col)
{
    int i,j;
    

    for(i=0; i<r; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%3d",mat[i*col+j]);
        }
        printf("\n");
    }
    printf("___________________________");

}

void addition_matrix(int* add_mat,int* mat1,int* mat2,int r,int col)
{
    int i,j;
    
     for(i=0; i<r; i++)
    {
        for(j=0; j<col; j++)
        {
            add_mat[i*col+j]=mat1[i*col+j] + mat2[i*col+j];
        }
        
    }
    
}
int main()
{
    int i,j;
    int *mat1;
    int *mat2;
    int *add_mat;
    int r,col;

    printf("Enter the number of rows : ");
    scanf("%d",&r);

    printf("Enter the number of Columns : ");
    scanf("%d",&col);

     mat1 = (int*) malloc((r*col)*sizeof(int));
     
     mat2 = (int*) malloc((r*col)*sizeof(int));
    
     add_mat = (int*) calloc((r*col),sizeof(int));
    if(mat1 == NULL && mat2 == NULL && add_mat == NULL)
    {
        printf("Unable to allocate memory !!\n");
        exit(0);
    }
    printf("\nFor first matrix... ");
    
    accept_matrix(mat1,r,col);
    
    printf("\nYour first matrix...:->\n"); 
     read_matrix(mat1,r,col);
    
    printf("\n For second matrix...");
    accept_matrix(mat2,r,col);
    
   printf("\nYour second matrix...:->\n");
    read_matrix(mat2,r,col);
    
    printf("\nAddition of both matrices is :\n");
    
    addition_matrix(add_mat,mat1,mat2,r,col);
    
    printf("\nMatrix of Answer.....\n");
    read_matrix(add_mat,r,col);
    
    free(mat1);
    free(mat2);
    free(add_mat);
    return 0;
}