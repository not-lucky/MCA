#include <stdio.h>

void sort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_ind = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min_ind]) {
        min_ind = j;
      }
    }
    int temp = a[i];
    a[i] = a[min_ind];
    a[min_ind] = temp;
  }
}

void rearrange(int *a, int n) {
  sort(a, n);
  int temp[n];
  int p = 0, q = n - 1;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      temp[i] = a[q--];
    else
      temp[i] = a[p++];
  }

  for (int i = 0; i < n; i++) a[i] = temp[i];
}

int main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  rearrange(a, n);

  printf("Rearranged array is:\n");
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
}