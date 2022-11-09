#include <stdio.h>

int power(int num, int exponent) {
  int powered_num = num;
  for (int i = 1; i < exponent; i++) {
    powered_num = powered_num * num;
  }
  return powered_num;
}

int main() {
  int N;
  scanf("%d", &N);

  double fac = 1, sum = 0;
  for (int i = 1; i <= N; i++) {
    fac *= i;
    sum += fac;
  }
  printf("%d\n", sum);

  sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += power(i, i);
  }
  printf("%d\n", sum);

  for (int i = 1; i <= N; i++) {
    fac *= i;
    sum += i / fac;
  }
  printf("%f", sum);

  for (int i = 1; i <= N; i++) {
    fac *= i;
    sum += power(i, i) / fac;
  }
  printf("%f", sum);

  for (int i = 1; i <= N; i++) {
    fac *= i;
    sum += power(i, i - 1) / fac;
  }
  printf("%f", sum);

  for (int i = 1; i <= N; i++) {
    fac *= i;
    if (i % 2 == 0)
      sum -= fac;
    else
      sum += fac;
  }
  printf("%f", sum);
}