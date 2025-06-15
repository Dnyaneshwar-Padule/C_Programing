#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int main()
{
    int i,j;
    int *P;
    int r,col;

    printf("Enter the number of rows : ");
    scanf("%d",&r);

    printf("Enter the number of Columns : ");
    scanf("%d",&col);

    P = (int*) malloc((r*col)*sizeof(int));

    if(P == NULL)
    {
        printf("Unable to allocate memory !!\n");
        exit(0);
    }

    printf("\n\nEnter the elements at .\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("Row No.%d & Column No.%d :-> ",i+1,j+1);
            scanf("%d",&P[i*col+j]);
        }

    }
    printf("\n\nYour array is like :->\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%3d",P[i*col+j]);
        }
        printf("\n");
    }
    

    free(P);
    return 0;
}