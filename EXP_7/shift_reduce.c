#include <stdio.h>
#include <string.h>

char stack[20];
char input[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop(int n) {
    top -= n;
    stack[top + 1] = '\0';
}

int main() {
    int i = 0;
    
    printf("Enter input string: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while (1) {
        // SHIFT
        push(input[i]);
        printf("%s\t%s\tShift\n", stack, input + i + 1);
        i++;

        // REDUCE: E → E+E
        if (strstr(stack, "E+E")) {
            pop(3);
            push('E');
            printf("%s\t%s\tReduce E->E+E\n", stack, input + i);
        }

        // REDUCE: E → id
        if (strstr(stack, "id")) {
            pop(2);
            push('E');
            printf("%s\t%s\tReduce E->id\n", stack, input + i);
        }

        if (i == strlen(input)) break;
    }

    if (strcmp(stack, "E") == 0)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}