#include <stdio.h>

int main() {
    int n;

    printf("Enter number of statements: ");
    scanf("%d", &n);

    char lhs[10];

    printf("Enter left side variables:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &lhs[i]);
    }

    printf("\nStatement\tGEN\tKILL\n");

    for (int i = 0; i < n; i++) {
        printf("d%d (%c=...)\t{d%d}\t{ ", i+1, lhs[i], i+1);

        // Kill previous definitions of same variable
        for (int j = 0; j < n; j++) {
            if (j != i && lhs[j] == lhs[i]) {
                printf("d%d ", j+1);
            }
        }
        printf("}\n");
    }

    return 0;
}