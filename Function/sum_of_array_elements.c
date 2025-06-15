#include<stdio.h>
#define SUCCESS 0

int get_sum(int*, int*);

int main()
{
    int arr[] = {3,2,1,45,2,25,21,53,69};
    int len = 9;
    printf("Sum : %d.\n", get_sum(arr, &len));
    return SUCCESS;
}

int get_sum(int* arr, int *len)
{
    int sum = 0;

    for (int i = 0; i < *len; i++)
    {
        sum += arr[i];
    }

    return sum;
}
