// Find the partition point: Consider an array A with n elements containing a run of 0’s followed by a run of 1’s. Implement a method to find out the exact point of transition between them.

#include <stdio.h>

int find_partition(int a[], int n) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(a[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main() {
    int a[] = {0,0,0,0,1,1,1,1};
    int n = sizeof(a) / sizeof(a[0]);

    int pos = find_partition(a, n);

    printf("Transition point = %d\n", pos);

    return 0;
}