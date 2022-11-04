#include <stdio.h>

int main() {
    unsigned int x, r;
    printf("Enter a positive decimal integer:\n");
    scanf("%d", &x);
    printf("The entered integer in binary format is:\n\t\t\t\t\t\t\t\t\t\t\t");
    while (x != 0) {
        printf("\b\b%d", x % 2);
        x /= 2;
    }
}