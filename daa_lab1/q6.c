// Element uniqueness:: For given n random numbers, implement a method in C to check if there are any duplicates. What can you conclude about your method for a sufficiently large value of n?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int has_duplicates(int a[], int n) {
    qsort(a, n, sizeof(int), cmp);

    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1])
            return 1;
    }

    return 0;
}

int main() {
    int n = 20;
    int a[20];

    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        a[i] = rand() % 15;
        printf("%d ", a[i]);
    }

    printf("\n");

    if(has_duplicates(a, n))
        printf("Duplicates exist\n");
    else
        printf("All elements are unique\n");

    return 0;
}







