#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int x, y;
} Interval;
int cmp(const void *a, const void *b) {
    return ((Interval*)a)->x - ((Interval*)b)->x;
}
int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    Interval iv[MAX];
    printf("Enter %d intervals (x y):\n", n);
    for (int i = 0; i < n; i++) scanf("%d %d", &iv[i].x, &iv[i].y);
    qsort(iv, n, sizeof(Interval), cmp);
    Interval merged[MAX];
    int m = 0;
    merged[m++] = iv[0];
    for (int i = 1; i < n; i++) {
        if (iv[i].x <= merged[m-1].y) {
            if (iv[i].y > merged[m-1].y) merged[m-1].y = iv[i].y;
        } else {
            merged[m++] = iv[i];
        }
    }
    printf("\nMerged intervals: ");
    for (int i = 0; i < m; i++) printf("(%d,%d) ", merged[i].x, merged[i].y);
    printf("\n");
    return 0;
}