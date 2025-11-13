#include<stdio.h>
#include<stdlib.h>

int bubble(int a[],int n);

int main()
{
    printf("-----BUBBLE SORT-----\n");
    int n;
    printf("Enter the no of elements to be sorted:\n");
    scanf("%d",&n);
    int a[n];//need to allocate dynamically
    printf("Enter the elements:\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted array is:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nThe sorted array is:\n");
    bubble(a,n);
    for (int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

//bubble sort
int bubble(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
