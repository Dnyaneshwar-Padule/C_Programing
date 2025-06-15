#include<stdio.h>
#define SUCCESS 0

int get_max(int*, int*);

int main()
{
    int arr[] = {3,2,1,45,2,25,21,53,69};
    int len = 9;
    printf("Max : %d.\n", get_max(arr, &len));
    return SUCCESS;
}

int get_max(int* arr, int *len)
{
    int max = arr[0];

    for (int i = 1; i < *len; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}
