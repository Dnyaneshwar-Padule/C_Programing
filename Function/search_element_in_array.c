#include<stdio.h>
#define SUCCESS 0
#define NOT_FOUND -1

int search(int*, int, int);

int main()
{
    int arr[] = {1,2,3,0,9,8,7,6,5,4};
    int len = 10;
    //int key = 6;
    int key = 16;
    int pos =  search(arr, len, key);
    
    if (pos > 0)
    {
        printf("%d is found in array at %d position.\n", key, pos);
    }
    else
    {
        printf("%d is not found in array.\n", key);
    }
    return SUCCESS;
}

int search(int *arr, int len, int key)
{

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return NOT_FOUND;
}

