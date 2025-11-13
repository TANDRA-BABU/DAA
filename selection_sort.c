#include <stdio.h>


void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int indexofmin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[indexofmin] > arr[j])
            {
                indexofmin = j;
            }
        }
        int temp = arr[indexofmin];
        arr[indexofmin] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {3, 2, 4, 1, 7, 0, 6};
    int size = sizeof(arr) / sizeof(int);
    print(arr, size);
    sort(arr, size);
    print(arr, size);
}