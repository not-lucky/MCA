#include <stdio.h>

int rever(int num) {
  static int bin = 0;
  if (num == 0) return bin;
  bin = bin * 10 + num % 2;
  return rever(num / 2);
}

int main(int argc, char *argv[]) {
  printf("%d", rever(21));
}