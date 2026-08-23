#include <stdio.h>
void merge(int arr[][2], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[1000][2];
    while(i <= mid && j <= high)
    {
        if(arr[i][0] < arr[j][0])
        {
            temp[k][0] = arr[i][0];
            temp[k][1] = arr[i][1];
            i++;
            k++;
        }
        else
        {
            temp[k][0] = arr[j][0];
            temp[k][1] = arr[j][1];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        temp[k][0] = arr[i][0];
        temp[k][1] = arr[i][1];
        i++;
        k++;
    }
    while(j <= high)
    {
        temp[k][0] = arr[j][0];
        temp[k][1] = arr[j][1];
        j++;
        k++;
    }
    for(i = low, k = 0; i <= high; i++, k++)
    {
        arr[i][0] = temp[k][0];
        arr[i][1] = temp[k][1];
    }
}

void sort(int arr[][2], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        sort(arr, low, mid);
        sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int n;
    printf("enter number of intervals:");
    scanf("%d", &n);

    int intervals[n][2];
    printf("enter intervals (start and end pairs):\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }
    sort(intervals, 0, n - 1);
    int cur_start = intervals[0][0];
    int cur_end = intervals[0][1];
    printf("Merged intervals:\n");
    for(int i = 1; i < n; i++)
    {
        if(intervals[i][0] <= cur_end)
        {
            if(intervals[i][1] > cur_end)
            {
                cur_end = intervals[i][1];
            }
        }
        else
        {
            printf("(%d, %d) ", cur_start, cur_end);
            cur_start = intervals[i][0];
            cur_end = intervals[i][1];
        }
    }
    printf("(%d, %d)\n", cur_start, cur_end);
    return 0;
}