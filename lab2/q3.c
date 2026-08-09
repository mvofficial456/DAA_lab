
// q - . Merging k sorted arrays: Suppose you are given k sorted arrays, each with n elements, and you want to combine 
// them into a single sorted array of kn elements.

// --------------------------method 1 ----------------------

#include <stdio.h>
#include <stdlib.h>

int* merge(int a[], int m, int b[], int n) {
    int *c = malloc((m+n) * sizeof(int));

    int i=0, j=0, k=0;

    while(i<m && j<n) {
        if(a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i<m) c[k++] = a[i++];
    while(j<n) c[k++] = b[j++];

    return c;
}

int main() {
    int k = 4, n = 5;

    int arr[4][5] = {
        {1,3,5,7,9},
        {2,4,6,8,10},
        {11,13,15,17,19},
        {12,14,16,18,20}
    };

    int *result = merge(arr[0], n, arr[1], n);
    int size = 2*n;

    for(int i=2;i<k;i++) {
        int *temp = merge(result, size, arr[i], n);
        free(result);
        result = temp;
        size += n;
    }

    printf("Merged Array:\n");
    for(int i=0;i<size;i++)
        printf("%d ", result[i]);

    free(result);

    return 0;
}

// -------------------method 2 ---------------------------------

// Merge two sorted arrays

int* merge(int a[], int m, int b[], int n) {
    int *c = malloc((m + n) * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < m)
        c[k++] = a[i++];

    while (j < n)
        c[k++] = b[j++];

    return c;
}

int main() {
    int n = 5;

    int A1[] = {1,3,5,7,9};
    int A2[] = {2,4,6,8,10};
    int A3[] = {11,13,15,17,19};
    int A4[] = {12,14,16,18,20};

    // First level
    int *B1 = merge(A1, n, A2, n);
    int *B2 = merge(A3, n, A4, n);

    // Second level
    int *C = merge(B1, 2*n, B2, 2*n);

    printf("Final merged array:\n");

    for (int i = 0; i < 4*n; i++)
        printf("%d ", C[i]);

    free(B1);
    free(B2);
    free(C);

    return 0;
}