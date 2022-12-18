#include <stdio.h>
#include <stdlib.h>

int main() {
//   int arr[10];
  int* arr = malloc(sizeof(int) * 5);
  for (int i = 0; i < 1000; i++) {
    printf("Addr: %d, Value: %d\n", &arr[i], arr[i]);
  }
}