#include <stdio.h>

int binary_search(int a[], int n, int x) {
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] == x) {
      return mid;
    } else if (a[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter elements of array: \n");
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  int x;
  printf("Enter a number to search for: ");
  scanf("%d", &x);

  int index = binary_search(arr, n, x);
  if (index == -1) {
    printf("Number not found\n");
  } else {
    printf("Number found at index %d\n", index);
  }
}
