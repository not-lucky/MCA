#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
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


// Function to rearrange the array in the desired order
void rearrange(int *a, int n) {
  sort(a, n);  // sort the array in ascending order

  // create a temporary array to store the rearranged elements
  int temp[n];

  // index variables for the two halves of the original array
  int p = 0, q = n - 1;

  // fill the temporary array with the rearranged elements
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      temp[i] = a[p++];
    else
      temp[i] = a[q--];
  }

  // copy the elements from the temporary array back to the original array
  for (int i = 0; i < n; i++) a[i] = temp[i];
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(a) / sizeof(a[0]);

  rearrange(a, n);

  // print the rearranged array
  for (int i = 0; i < n; i++) printf("%d ", a[i]);

  return 0;
}