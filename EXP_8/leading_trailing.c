#include <stdio.h>
#include <ctype.h>
#include <string.h>

char productions[10][20];
char leading[26][20];
char trailing[26][20];
int n;

// Add symbol to set (avoid duplicates)
void addToSet(char *set, char symbol) {
    if (!strchr(set, symbol)) {
        int len = strlen(set);
        set[len] = symbol;
        set[len + 1] = '\0';
    }
}

// Function to compute LEADING
void findLeading(char nonTerminal) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == nonTerminal) {

            // Case 1: A → terminal...
            if (islower(productions[i][2])) {
                addToSet(leading[nonTerminal - 'A'], productions[i][2]);
            }

            // Case 2: A → B... (avoid infinite recursion)
            else if (isupper(productions[i][2]) && productions[i][2] != nonTerminal) {
                findLeading(productions[i][2]);

                // Copy LEADING(B) into LEADING(A)
                for (int j = 0; j < strlen(leading[productions[i][2] - 'A']); j++) {
                    addToSet(leading[nonTerminal - 'A'],
                             leading[productions[i][2] - 'A'][j]);
                }
            }
        }
    }
}

// Function to compute TRAILING
void findTrailing(char nonTerminal) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == nonTerminal) {

            int len = strlen(productions[i]);
            char last = productions[i][len - 1];

            // Case 1: ends with terminal
            if (islower(last)) {
                addToSet(trailing[nonTerminal - 'A'], last);
            }

            // Case 2: ends with non-terminal (avoid infinite recursion)
            else if (isupper(last) && last != nonTerminal) {
                findTrailing(last);

                // Copy TRAILING(B) into TRAILING(A)
                for (int j = 0; j < strlen(trailing[last - 'A']); j++) {
                    addToSet(trailing[nonTerminal - 'A'],
                             trailing[last - 'A'][j]);
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (E=E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    // Initialize sets
    for (int i = 0; i < 26; i++) {
        leading[i][0] = '\0';
        trailing[i][0] = '\0';
    }

    // Compute LEADING and TRAILING
    for (int i = 0; i < n; i++) {
        findLeading(productions[i][0]);
        findTrailing(productions[i][0]);
    }

    // Print LEADING
    printf("\nLEADING:\n");
    for (int i = 0; i < n; i++) {
        printf("%c : %s\n", productions[i][0],
               leading[productions[i][0] - 'A']);
    }

    // Print TRAILING
    printf("\nTRAILING:\n");
    for (int i = 0; i < n; i++) {
        printf("%c : %s\n", productions[i][0],
               trailing[productions[i][0] - 'A']);
    }

    return 0;
}