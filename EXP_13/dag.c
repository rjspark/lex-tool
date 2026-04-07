#include <stdio.h>
#include <string.h>

struct node {
    char op;
    char left;
    char right;
} dag[10];

int main() {
    char a, b, c, op;

    printf("Enter expression (e.g. a=b+c): ");
    scanf(" %c=%c%c%c", &a, &b, &op, &c);

    // Create DAG node
    dag[0].op = op;
    dag[0].left = b;
    dag[0].right = c;

    printf("\nDAG Representation:\n");
    printf("   %c\n", dag[0].op);
    printf("  / \\\n");
    printf(" %c   %c\n", dag[0].left, dag[0].right);

    printf("\nOptimized Code:\n");
    printf("t1 = %c %c %c\n", b, op, c);
    printf("%c = t1\n", a);

    return 0;
}