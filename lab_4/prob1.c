#include <stdio.h>
#define MAX 100
int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d",&n);
    int red[MAX], blue[MAX], yellow[MAX];
    int r = 0, b = 0, y = 0;
    printf("Enter %d pairs (Number Color) [0=Red, 1=Blue, 2=Yellow]:\n", n);
    printf("Note: Inputs MUST be entered in ascending number order of numbers only.\n");
    for (int i = 0; i < n; i++) {
        int num, color;
        scanf("%d %d", &num, &color);
        if (color == 0)      red[r++] = num;
        else if (color == 1) blue[b++] = num;
        else if (color == 2) yellow[y++] = num;
    }
    printf("\nSorted Result (Red -> Blue -> Yellow):\n");
    for (int i = 0; i < r; i++) printf("(%d, Red) ", red[i]);
    for (int i = 0; i < b; i++) printf("(%d, Blue) ", blue[i]);
    for (int i = 0; i < y; i++) printf("(%d, Yellow) ", yellow[i]);
    printf("\n");
    return 0;
}