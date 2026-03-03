#include <stdio.h>
#include <ctype.h>
#include <string.h>

char production[10][10];
char first[10], follow[10];
int n;

void findFirst(char c);
void findFollow(char c);

int main() {
    int i;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR):\n");
    for(i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    printf("\nFIRST sets:\n");
    for(i = 0; i < n; i++) {
        c = production[i][0];
        printf("FIRST(%c) = { ", c);
        findFirst(c);
        printf("}\n");
    }

    printf("\nFOLLOW sets:\n");
    for(i = 0; i < n; i++) {
        c = production[i][0];
        printf("FOLLOW(%c) = { ", c);
        findFollow(c);
        printf("}\n");
    }

    return 0;
}

void findFirst(char c) {
    int i;
    if(!isupper(c)) {
        printf("%c ", c);
        return;
    }

    for(i = 0; i < n; i++) {
        if(production[i][0] == c) {
            if(production[i][2] == '#')
                printf("# ");
            else
                findFirst(production[i][2]);
        }
    }
}

void findFollow(char c) {
    int i, j;

    if(production[0][0] == c)
        printf("$ ");

    for(i = 0; i < n; i++) {
        for(j = 2; j < strlen(production[i]); j++) {
            if(production[i][j] == c) {
                if(production[i][j+1] != '\0')
                    findFirst(production[i][j+1]);
                else if(c != production[i][0])
                    findFollow(production[i][0]);
            }
        }
    }
}
