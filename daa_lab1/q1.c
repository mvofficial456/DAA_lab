// Q1. Put them in Order
// Using implementation in C, place the following functions in a list
// by increasing order of growth for sufficiently large values of n.


#include <stdio.h>
#include <string.h>

struct Function {
    char name[50];
    double order;
};

int main() {

    struct Function f[] = {
        {"1/n", -1},
        {"log2 n", 0},
        {"12*sqrt(n)", 0.5},
        {"50*n^0.5", 0.5},
        {"n^0.51", 0.51},
        {"n*log2 n", 1.1},
        {"n^(log2 n)", 1.5},
        {"100*n^2 + 6n", 2},
        {"n^2 - 324", 2},
        {"2*n^3", 3},
        {"3^n", 10},
        {"2^(32n)", 20}
    };

    int n = sizeof(f) / sizeof(f[0]);

    // Sort by increasing growth order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (f[j].order > f[j + 1].order) {
                struct Function temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }

    printf("Functions in increasing order of growth:\n\n");

    for (int i = 0; i < n; i++) {
        printf("%2d. %s\n", i + 1, f[i].name);
    }

    return 0;
}













