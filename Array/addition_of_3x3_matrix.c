#include<stdio.h>
#define SUCCESS 0
#define ARRAY_SIZE 3
#define TRUE 1
#define FALSE 0

void clear_buffer();
int take_input(int*, int, int);
void display_array(int[][ARRAY_SIZE], int);
int accept_array(int[][ARRAY_SIZE], int);
void add(int[][ARRAY_SIZE], int[][ARRAY_SIZE], int[][ARRAY_SIZE], int); 

int main()
{
    int matrix_one[ARRAY_SIZE][ARRAY_SIZE] = {{0}};
    int matrix_two[ARRAY_SIZE][ARRAY_SIZE] = {{0}};
    int result_matrix[ARRAY_SIZE][ARRAY_SIZE] = {{0}};

    printf("\nEnter the elements of first matrix.\n");
    if (!accept_array(matrix_one, ARRAY_SIZE)){
        printf("Invalid input !\n");
        clear_buffer();
        return SUCCESS;
    }
    
    printf("\nEnter the elements of second matrix.\n");
    if (!accept_array(matrix_two, ARRAY_SIZE)){
        printf("Invalid input !\n");
        clear_buffer();
        return SUCCESS;
    }
    
    add(matrix_one, matrix_two, result_matrix, ARRAY_SIZE);
    
    printf("\nResult : \n");
    display_array(result_matrix, ARRAY_SIZE);

    return SUCCESS;
}

void add(int matrix_one[][ARRAY_SIZE], int matrix_two[][ARRAY_SIZE], int result_matrix[][ARRAY_SIZE], int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            result_matrix[i][j] = matrix_one[i][j] + matrix_two[i][j];
        }
    }
}

void clear_buffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int take_input(int *num, int i, int j){
    printf("Enter a number at row:%d, column:%d: ", i, j);
    return scanf("%d", num);
}

void display_array(int arr[][ARRAY_SIZE], int len){
    printf("\n+--      --+\n");

    for (int i = 0; i < len; i++){
        printf("|");
        for (int j = 0; j < len; j++){
            printf("%3d", arr[i][j]);
        }
        printf(" |\n");
    }
    printf("+--      --+\n");
}

int accept_array(int arr[][ARRAY_SIZE], int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            if (!take_input(&arr[i][j], i, j)){
                return FALSE;
            }
        }
    }
    return TRUE;
}
