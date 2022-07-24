#include <stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int i;
    int l=mid-low+1;
    int r=high-mid;
    int L[l];
    int R[r];
    
    for(i=0;i<l;i++)
    L[i]=a[low+i];
    for(i=0;i<r;i++)
    R[i]=a[mid+1+i];
    i=0;
    int j=0;
    int k=low;
    while(i<l&&j<r)
    {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            k++;
            i++;
        }    
        else
        {
            a[k]=R[j];
            k++;
            j++;
        }
    }
    while(i<l)
    {
        a[k]=L[i];
            k++;
            i++;
    }
    while(j<r)
    {
        a[k]=R[j];
            k++;
            j++;
    }
}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
    int mid=(low+high-1)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
    }
}
void main()
{
    printf("Enter size of array you wish to sort\n");
    int i=0;
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    printf("%d",a[i]);
}