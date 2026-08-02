// Fair vs Biased coin: Using simulation in C, show that the probability of getting a HEAD by tossing a fair coin is about 0.5. Extend your simulation to compare fair vs biased coin-tossing experiments.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fair_coin() {
    return rand() % 2;     // 0 or 1
}

int biased_coin() {
    return (rand() % 100) < 70;   // 70% probability of HEAD
}

int main() {
    int n = 100000;
    int fair_heads = 0, biased_heads = 0;

    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        fair_heads += fair_coin();
        biased_heads += biased_coin();
    }

    printf("Fair coin probability of HEAD  = %.4f\n",
           (double)fair_heads / n);

    printf("Biased coin probability of HEAD = %.4f\n",
           (double)biased_heads / n);

    return 0;
}