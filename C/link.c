#include <stdio.h>
#include <stdlib.h>

int* sort(int arr[], int n) {
  static int new[4];
  for (int i = 0; i < n; i += 2) {
    new[i] = arr[i];
  }
  return new;
}

int main() {
  int ar[] = {16, 9, 1, 2, 4, 8, 4};
  int* x;
  x = sort(ar, 7);
  for (size_t i = 0; i < 2; i++) {
    printf("%d", x[i]);
  }
}