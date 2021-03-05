#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[]={10,9,8,6,7,5,4,3,2,1},n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        int min=999999;
        int idx=-1;
        for (int j = i; j < n; j++)
        {
            if (arr[j]<min) 
            {
                min=arr[j];
                idx=j;
            }
        }
        int temp=arr[i];
        arr[i]=min;
        arr[idx]=temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
    return EXIT_SUCCESS;
}