#include <stdio.h>

typedef struct 
{
    int idx;
    double value;
} participant;


void merge(participant arr[], int l , int m , int r)
{
    int i,j,k;
    
    int n1 = m - l  +1;

    int n2 = r - m;

    participant L[n1] , R[n2];

    k = l;
    for(i  = 0 ; i < n1 ; i++)
    {
        L[i] = arr[l + i];
    }

    for(j = 0 ; j < n2 ; j++)
    {
        R[j] = arr[m + j + 1];
    }

    i = j = 0;

    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i].value > R[j].value)
        {
            arr[k] = L[i++];
        }
        else if(L[i].value == R[j].value && L[i].idx < R[j].idx)
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
        k++;
    }

    while(i < n1)
    {
        arr[k++] = L[i++];
    }

    while(j < n2)
    {
        arr[k++] = R[j++];
    }
}


void mergeSort(participant arr[], int l , int r)
{
    if(l < r)
    {
        int m = l + (r-l) /2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}


int main()
{
    int n ,t1, t2, k;
    scanf("%d%d%d%d",&n,&t1,&t2,&k);
    participant arr[n];
    double dk = (double)k/(double)100;

    int sp1, sp2;
    for(int i = 0  ; i < n ; i++)
    {
        scanf("%d%d",&sp1,&sp2);

        double total1 =((sp1 * t1) - ((sp1 * t1) * dk)) + (sp2 * t2);

        double total2 = ((sp2 * t1)-((sp2 * t1) * dk)) + (sp1 * t2);

        arr[i].idx = i+1;
        if(total1 > total2)
        {
            arr[i].value = total1;
        }
        else
        {
            arr[i].value = total2;
        }
    }

    mergeSort(arr,0,n-1);

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d %0.2f\n",arr[i].idx,arr[i].value);
    }

    return 0;
}