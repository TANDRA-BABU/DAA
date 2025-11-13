#include <stdio.h>

void print(int arr[], int n);
void sort(int arr[], int n);

int main()
{
    printf("-----INSERTION SORT-----\n");
    int n;
    printf("Enter the no of elements to be sorted:\n");
    scanf("%d",&n);
    int arr[n];//need to allocate dynamically
    printf("Enter the elements:\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The unsorted array is:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\nThe sorted array is:\n");
    sort(arr,n);
    for (int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    print(arr, n);
    sort(arr, n);
    return 0;
    
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    print(arr, n);
}