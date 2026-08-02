// Towers of Hanoi (ToH): Simulate the solution to the ToH problem using C. Plot the total number of moves required for solving the problem of n-discs. What can you conclude about your algorithm from the plot obtained?
#include <stdio.h>
#include <math.h>

long long moves = 0;

void hanoi(int n, char from, char aux, char to) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        moves++;
        return;
    }

    hanoi(n - 1, from, to, aux);

    printf("Move disk %d from %c to %c\n", n, from, to);
    moves++;

    hanoi(n - 1, aux, from, to);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    printf("\nTotal moves = %lld\n", moves);

    printf("\nData for plotting:\n");

    for(int i = 1; i <= n; i++) {
        printf("%d %lld\n", i, (long long)pow(2, i) - 1);
    }

    return 0;
}