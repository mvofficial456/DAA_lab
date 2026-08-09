

#include <stdio.h>
#include <math.h>

int main() {
    FILE *fp = fopen("growth.dat", "w");

    fprintf(fp, "#n constant logn linear\n");

    for (int n = 1; n <= 1000; n += 10) {
        fprintf(fp, "%d %d %lf %d\n",
                n,
                1,
                log2((double)n),
                n);
    }

    fclose(fp);

    printf("Data written to growth.dat\n");
    printf("Use gnuplot to visualize.\n");

    return 0;
}