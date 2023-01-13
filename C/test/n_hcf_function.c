#include <stdio.h>

int hcf_r(int x, int y) {
  if (x % y != 0) {
    return hcf_r(y, x % y);
  }
  return y;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int hcf = arr[0];

  for (int i = 1; i < n; i++) {
    hcf = hcf_r(hcf, arr[i]);
  }
  printf("%d", hcf);
}