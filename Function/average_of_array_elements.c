#include<stdio.h>
#define SUCCESS 0

double get_average(int*, int);
int get_sum(int*, int*);

int main()
{
    int arr[] = {10,20,10,20,10,20,10,20,10,20};
    //int arr[] = {12,34,35,53,13,53,65,23,76,90};
    int len = 10;

    printf("Average : %.2lf", get_average(arr, len));

    return SUCCESS;
}

double get_average(int *arr, int length)
{
    return ( (double)get_sum(arr, &length) / (double) length);
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
