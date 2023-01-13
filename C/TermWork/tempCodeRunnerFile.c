#include <stdio.h>

void print(int a[], int n) {
  if (n == 0) {
    return;
  }
  printf("%d\n", a[n - 1]);
  print(a, n - 1);
}

int main() {
  // printf("%d", fact(5));
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(a, sizeof(a) / sizeof(a[0]));
}