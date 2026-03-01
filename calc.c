#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: calc <expression>\n");
        printf("Example: calc \"2 + 3\"\n");
        return 1;
    }
    double a, b;
    char op;
    if (sscanf(argv[1], "%lf %c %lf", &a, &op, &b) != 3) {
        fprintf(stderr, "Invalid expression: %s\n", argv[1]);
        return 1;
    }
    double result;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) { fprintf(stderr, "Division by zero\n"); return 1; }
            result = a / b; break;
        default:
            fprintf(stderr, "Unknown operator: %c\n", op);
            return 1;
    }
    printf("%.2f\n", result);
    return 0;
}
