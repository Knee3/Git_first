#include <stdio.h>

void quick_sort(int[],int,int);     //To sort the array
int partition(int[],int,int);       //Function to create partitions
 
int main()
{
    int a[50],n,i;
    printf("How many elements?");
    scanf("%d", &n);
    printf("\nEnter array elements:");
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);                  //Input elements
        
    quick_sort(a,0,n-1);            //quick_sort function called
    printf("\nArray after sorting:");
    
    for(i=0;i<n;i++)
        printf("%d ",a[i]);           //sorted array displayed
    
    return 0;        
}
 
void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);         //To find the index of the pivot point
        quick_sort(a,l,j-1);        //sort on the tleft of the pivot
        quick_sort(a,j+1,u);        //sort on the right of the pivot
    }
}
           
int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);        //to shift the pivot element to it's location
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];              //swap the numbers
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}