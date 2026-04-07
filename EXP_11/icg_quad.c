#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char exp[20];
    char op1, op2, op;

    printf("Enter expression (e.g. a=b+c*d): ");
    scanf("%s", exp);

    // Extract values assuming format a=b+c*d
    char lhs = exp[0];

    // First operation (* or /)
    op1 = exp[4];
    op = exp[3];
    op2 = exp[5];

    // Second operation (+ or -)
    char op3 = exp[1];
    char op4 = exp[2];

    printf("\nTHREE ADDRESS CODE:\n");
    printf("t1 = %c %c %c\n", op1, op, op2);
    printf("t2 = %c %c t1\n", op4, op3);
    printf("%c = t2\n", lhs);

    printf("\nQUADRUPLE:\n");
    printf("op\targ1\targ2\tresult\n");
    printf("%c\t%c\t%c\tt1\n", op, op1, op2);
    printf("%c\t%c\tt1\tt2\n", op3, op4);
    printf("=\tt2\t-\t%c\n", lhs);

    printf("\nTRIPLE:\n");
    printf("index\top\targ1\targ2\n");
    printf("0\t%c\t%c\t%c\n", op, op1, op2);
    printf("1\t%c\t%c\t(0)\n", op3, op4);
    printf("2\t=\t(1)\t%c\n", lhs);

    printf("\nINDIRECT TRIPLE:\n");
    printf("pointer\tvalue\n");
    printf("p0\t(0)\n");
    printf("p1\t(1)\n");
    printf("p2\t(2)\n");

    return 0;
}