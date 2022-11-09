#include <stdio.h>

int main() {
  int P, c = 1, prime = 1;
  printf("Enter a positive number: ");
  scanf("%d", &P);
  printf("Prime numbers between 1 and %d are:\n", P);
  for (int i = 2; c <= P; i++) {
    prime = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
      printf("%d\n", i);
      c++;
    }
  }
}