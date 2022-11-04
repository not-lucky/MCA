#include <stdio.h>

int main() {
  int h, m, s;
  printf("Input hours, minutes and seconds: ");
  scanf("%d%d%d", &h, &m, &s);

  if (s > 59) {
    m += s / 60;
    s %= 60;
  }

  if (m > 59) {
    h += m / 60;
    m %= 60;
  }

  printf("First time is: %d:%02d:%02d", h, m, s);
}