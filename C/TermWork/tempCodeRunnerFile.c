#include <stdio.h>

int main() {
  int x = 10000000;
  int* y = &x;
  int** z = &y;
  int*** z_address = &z;
  printf("x = %d, y = %d, z = %d , z address = %d", x, y, z, z_address);
}