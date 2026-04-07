#include <stdio.h>
#include <string.h>

int main() {
    char exp[20];
    char op1, op2, op;

    printf("Enter expression (e.g. a=b+c): ");
    scanf("%s", exp);

    // Extract parts
    char lhs = exp[0];
    op1 = exp[2];
    op = exp[3];
    op2 = exp[4];

    printf("\nGenerated Code:\n");

    printf("MOV %c, R0\n", op1);

    switch(op) {
        case '+':
            printf("ADD %c, R0\n", op2);
            break;
        case '-':
            printf("SUB %c, R0\n", op2);
            break;
        case '*':
            printf("MUL %c, R0\n", op2);
            break;
        case '/':
            printf("DIV %c, R0\n", op2);
            break;
    }

    printf("MOV R0, %c\n", lhs);

    return 0;
}