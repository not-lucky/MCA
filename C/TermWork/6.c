#include <stdio.h>

int main() {
  int P = 100, c = 1;
  for (int i = 2; c <= P; i++) {
    int prime = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
      printf("%d: %d is prime.\n", c, i);
      c++;
    }
  }
}