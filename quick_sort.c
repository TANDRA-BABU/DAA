#include <stdio.h>

void sort_array(int arr[], int n);
void print_array(int arr[], int n);

int main() 
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    print_array(arr, n);
    sort_array(arr, n);
    printf("Sorted array: ");
    print_array(arr, n);
    return 0;
}

void sort_array(int arr[], int n) 
{
    for (int i = n - 2; i >= 0; i--) 
    {
        for (int j = n - 1; j >= i + 1; j--) 
        {
            if (arr[j] < arr[i]) 
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void print_array(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

