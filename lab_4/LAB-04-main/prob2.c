#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[1000];
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        sort(arr, low, mid);
        sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int Binary_Search(int arr[],int target,int n)
{
    int low = 0;
    int high = n-1;
    int mid = low +((high-low)/2);
    while (low <= mid && mid <= high)
    {
        mid = low +((high-low)/2);
        if (arr[mid] > target)
        {
            high = mid;
        }
        else if  (arr[mid] < target)
        {
            low = mid;
        }
        else if (arr[mid] == target)
        {
            return 1;
        }
        return 0;
    }
}
int main()
{
    int n;
    printf("enter size of both sets");
    scanf("%d",&n);
    int S1[n],S2[n];
    printf("enter elements into S1");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&S1[i]);
    }
    printf("enter elements into S2");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&S2[i]);
    }
    int x;
    printf("enter target element:");
    scanf("%d",&x);
    sort(S1,0,n-1);
    int found_pair = 0;
    for(int i = 0;i<n;i++)
    {
        if(Binary_Search(S1,x-S1[i],n))
        {
            found_pair = 1;
        }
    }
    printf("%d",found_pair);
    return 0;
}