#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Reverse string
void reverse(char exp[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    char rev[MAX], postfix[MAX];

    strcpy(rev, infix);
    reverse(rev);

    // Swap brackets
    for (int i = 0; rev[i]; i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    // Convert to postfix
    top = -1;
    infixToPostfix(rev, postfix);

    // Reverse postfix to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    top = -1;
    infixToPostfix(infix, postfix);

    infixToPrefix(infix, prefix);

    printf("\nPostfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);

    return 0;
}