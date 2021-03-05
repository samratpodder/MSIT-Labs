#include<stdio.h>
#include<stdlib.h>
void swap(int* arr,int i,int j)
{
    int temp = *arr+i;
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[],int l,int h)
{
    int pivot = arr[l];//Always taking low as the pivot
    int i = l+1;
    for (int j = i; j <= h; j++)
    {
        if (arr[j]<pivot)
        {
            swap(arr,i,j);i++;
        }
        
    }
    swap(arr,l,i-1);
    return i-1;
    
}
void qs(int arr[],int l,int h)
{
    if (l>h)
    {
        return;
    }
    int pi=partition(arr,l,h);
    // printf("%d\n",pi);
    // for (int i = 0; i < h; i++)
    // {
    //     printf("%d ",*(arr+i));
    // }
    // printf("\n");
    qs(arr,l,pi-1);
    qs(arr,pi+1,h);
}
int main()
{
    int arr[] = {1,6,5,4,2,3},n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
    qs(arr,0,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
    return EXIT_SUCCESS;
}