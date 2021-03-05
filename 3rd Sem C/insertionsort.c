#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Input array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");

    for (int  i = 1; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            arr[j]=key;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
    return EXIT_SUCCESS;
}