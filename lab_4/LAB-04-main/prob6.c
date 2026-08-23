#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int coord;
    int type;
} Event;
int cmp(const void *a, const void *b) {
    Event *e1 = (Event*)a, *e2 = (Event*)b;
    if (e1->coord != e2->coord) return e1->coord - e2->coord;
    return e1->type - e2->type;
}
int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    Event ev[2 * MAX];
    printf("Enter %d intervals (l r):\n", n);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        ev[2*i]   = (Event){l, 0};
        ev[2*i+1] = (Event){r, 1};
    }
    qsort(ev, 2*n, sizeof(Event), cmp);
    int count = 0, maxCount = 0, bestPoint = ev[0].coord;
    for (int i = 0; i < 2*n; i++) {
        if (ev[i].type == 0) {
            count++;
            if (count > maxCount) {
                maxCount = count;
                bestPoint = ev[i].coord;
            }
        } else {
            count--;
        }
    }
    printf("\nPoint %d is covered by the maximum number of intervals (%d).\n",
           bestPoint, maxCount);
    return 0;
}