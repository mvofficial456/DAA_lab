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
int Binary_Search(int arr[], int target, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return 1;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
int check_k_sum(int arr[], int n, int T, int k, int depth, int current_sum, int start)
{
    if (depth == k - 1)
    {
        int needed = T - current_sum;
        return Binary_Search(arr, needed, start, n - 1);
    }
    for (int i = start; i < n; i++)
    {
        if (check_k_sum(arr, n, T, k, depth + 1, current_sum + arr[i], i + 1))
            return 1;
    }
    return 0;
}
int main()
{
    int n;
    printf("enter size of set:");
    scanf("%d", &n);

    int S[n];
    printf("enter elements into S:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    int k, T;
    printf("enter value of k:");
    scanf("%d", &k);
    printf("enter target T:");
    scanf("%d", &T);
    sort(S, 0, n - 1);
    int found = check_k_sum(S, n, T, k, 0, 0, 0);
    printf("Result: %d\n", found);
    return 0;
}