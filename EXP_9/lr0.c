#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char productions[MAX][MAX];
char items[MAX][MAX][MAX]; // states
int n;

// Add dot at beginning
void addDot(char *dest, char *src) {
    dest[0] = src[0];
    dest[1] = '-';
    dest[2] = '>';
    dest[3] = '.';
    strcpy(dest + 4, src + 3);
}

// Closure function
void closure(int state) {
    for (int i = 0; i < MAX; i++) {
        if (items[state][i][0] == '\0') continue;

        for (int j = 0; j < strlen(items[state][i]); j++) {
            if (items[state][i][j] == '.') {
                char next = items[state][i][j + 1];

                if (isupper(next)) {
                    for (int k = 0; k < n; k++) {
                        if (productions[k][0] == next) {
                            char temp[MAX];
                            addDot(temp, productions[k]);

                            int exists = 0;
                            for (int x = 0; x < MAX; x++) {
                                if (strcmp(items[state][x], temp) == 0)
                                    exists = 1;
                            }

                            if (!exists) {
                                for (int x = 0; x < MAX; x++) {
                                    if (items[state][x][0] == '\0') {
                                        strcpy(items[state][x], temp);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// Move dot (GOTO)
void moveDot(char *dest, char *src, int pos) {
    strcpy(dest, src);
    char temp = dest[pos];
    dest[pos] = dest[pos + 1];
    dest[pos + 1] = temp;
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (E->E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    // Initialize first state
    addDot(items[0][0], productions[0]);
    closure(0);

    printf("\nLR(0) ITEMS:\n");

    for (int i = 0; i < MAX; i++) {
        if (items[0][i][0] == '\0') break;
        printf("%s\n", items[0][i]);
    }

    return 0;
}