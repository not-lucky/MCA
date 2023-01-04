#include <stdio.h>

void selectionSort(int a[], int N) {
  for (int i = 0; i < N - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < N; j++) {
        if (a[j] < a[min_index]) {
            min_index = j;
        }
    }
    int temp = a[i];
    a[i] = a[min_index];
    a[min_index] = temp;
  }
}

void insertionSort(int a[], int N) {
  for (int i = 1; i < N; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

int main() {
  int N;
  printf("Enter the size of array: ");
  scanf("%d", &N);

  int a[N];
  printf("Enter %d numbers: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  selectionSort(a, N);
//   insertionSort(a, N);

  printf("\nSorted numbers: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
