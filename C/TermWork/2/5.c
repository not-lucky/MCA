#include <stdio.h>

void countFreq(int arr[], int n) {
  int count[n];
  for (int i = 0; i < n; i++) {
    count[i] = -1;
  }

  for (int i = 0; i < n - 1; i++) {
    if (count[i] == 0) continue;
    int c = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        count[j] = 0;
        c++;
      }
    }
    count[i] = c;
  }
  printf("\nUnique Elements are:\n");
  for (int i = 0; i < n; i++) {
    if (count[i] == 1) printf("%d, ", arr[i]);
  }
  printf("\nDuplicate Elements are:\n");
  for (int i = 0; i < n; i++) {
    if (count[i] > 1) printf("%d, ", arr[i]);
  }
  printf("\nOccurence are each numbers are:\n");
  for (int i = 0; i < n; i++) {
    if (count[i] != 0) printf("%d: %d\n", arr[i], count[i]);
  }
}

int main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter elements of array: \n");
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  countFreq(arr, n);
}