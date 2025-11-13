#include<stdio.h>
#include<conio.h>

#define MAX 100

int list[MAX];
void mergesort(int, int);
void merge(int, int, int, int);
void main()
{
    int n, i, j=0;
    printf("ENTER THE NO. OF TERMS: ");
    scanf("%d",&n);
    printf("ENTER THE TERMS TO BE SORTED: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &list[i]);
    }
    mergesort(j,n-1);
    printf("THE SORTED LIST IS: \n");
    for(i=0; i<n; i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

void mergesort(int f, int l)
{
    int m;
    if(l>f)
    {
        m=(f+l)/2;
        mergesort(f,m);
        mergesort(m+1,l);
        merge(f,m,m+1,l);
    }
}

void merge(int f1, int l1, int f2, int l2)
{
    int i=f1, j=f2, temp[MAX], k=0;
    while (i<=l1 && j<=l2)
    {
        if(list[i] <= list[j])
        {
            temp[k++] = list[i++];
        }
        else
        {
            temp[k++] = list[j++];
        }
    }
    while(i<=l1)
    {
        temp[k++] = list[i++];
    }
    while(j<=l2)
    {
        temp[k] = list[j];
        k++;
        j++;
    }
    for(i=f1, k=0; i<=l2; i++, k++)
    {
        list[i] = temp[k];
    }
}