#include <stdio.h>

void ambiguity() {
    printf("\n--- Elimination of Ambiguity ---\n");
    printf("Ambiguous Grammar:\n");
    printf("E -> E + E | E * E | (E) | id\n");

    printf("\nUnambiguous Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> (E) | id\n");
}

void leftRecursion() {
    char nt;

    printf("\nEnter Non-Terminal: ");
    scanf(" %c", &nt);

    printf("\n--- Left Recursion Removal ---\n");
    printf("Given: %c -> %c + T | T\n", nt, nt);

    printf("After:\n");
    printf("%c  -> T %c'\n", nt, nt);
    printf("%c' -> + T %c' | epsilon\n", nt, nt);
}

void leftFactoring() {
    char nt;

    printf("\nEnter Non-Terminal: ");
    scanf(" %c", &nt);

    printf("\n--- Left Factoring ---\n");
    printf("Given: %c -> iEtS | iEtSeS | a\n", nt);

    printf("After:\n");
    printf("%c  -> iEtS %c' | a\n", nt, nt);
    printf("%c' -> eS | epsilon\n", nt);
}

int main() {
    int choice;

    printf("Grammar Transformation Program\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Eliminate Ambiguity\n");
        printf("2. Remove Left Recursion\n");
        printf("3. Left Factoring\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                ambiguity();
                break;
            case 2:
                leftRecursion();
                break;
            case 3:
                leftFactoring();
                break;
            case 4:
                printf("\nProgram Ended.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
