// Performance analysis of bubble sort: Using C, implement two different versions of bubble sort simulation for randomised data sequences as follows: (i) Bubble sort that terminates if the array is sorted before the (n − 1)th pass. (ii) Bubble sort that always completes the (n − 1)th pass. Plot the number of comparisons in both cases to analyse their efficiency.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long optimized_bubble(int a[], int n) {
    long long comp = 0;
    int temp, swapped;

    for(int i = 0; i < n - 1; i++) {
        swapped = 0;

        for(int j = 0; j < n - i - 1; j++) {
            comp++;

            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

        if(!swapped)
            break;
    }

    return comp;
}

long long normal_bubble(int a[], int n) {
    long long comp = 0;
    int temp;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comp++;

            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    return comp;
}

int main() {
    srand(time(NULL));

    for(int n = 10; n <= 100; n += 10) {
        int a[100], b[100];

        for(int i = 0; i < n; i++) {
            a[i] = rand() % 1000;
            b[i] = a[i];
        }

        printf("n=%d  Optimized=%lld  Normal=%lld\n",
               n,
               optimized_bubble(a, n),
               normal_bubble(b, n));
    }

    return 0;
}