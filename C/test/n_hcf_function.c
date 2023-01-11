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
  int hcf = hcf_r(arr[0], arr[1]);

  for (int i = 2; i < n; i++) {
    hcf = hcf_r(hcf, arr[i]);
  }
  printf("%d", hcf);
}