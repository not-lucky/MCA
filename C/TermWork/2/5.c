#include <stdio.h>

int main() {
  int a[] = {2, 3, 4, 5, 4, 3, 1, 7, 8, 9, 8, 5, 1, 4, 5, 258};
  int n = sizeof(a) / sizeof(a[0]);

  printf("Original array: ");
  for (int i = 0; i < n; i++) printf("%d, ", a[i]);
  printf("\n");

  // create an array to store the frequency of each element
  int freq[n];
  for (int i = 0; i < n; i++) freq[i] = 0;

  // count the frequency of each element
  for (int i = 0; i < n; i++) freq[a[i]]++;

  printf("\nFrequency of each element:\n");
  for (int i = 0; i < n; i++) {
    if (freq[i] > 0) printf("%d\t: %d\n", i, freq[i]);
  }

  return 0;
}
