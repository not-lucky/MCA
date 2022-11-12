#include <stdio.h>

void time_format_print(int h, int m, int s, char pos[]) {
  if (s > 59) {
    m += s / 60;
    s %= 60;
  }
  if (m > 59) {
    h += m / 60;
    m %= 60;
  }
  printf("%s time is: %0d:%02d:%02d\n", pos, h, m, s);
}

int main() {
  int fh, fm, fs, sh, sm, ss;
  // char first[] = "First", second[] = "Second", added[] = "Added";
  printf("Input first time's hours, minutes and seconds: \n");
  scanf("%d%d%d", &fh, &fm, &fs);

  printf("Input second time's hours, minutes and seconds: \n");
  scanf("%d%d%d", &sh, &sm, &ss);

  time_format_print(fh, fm, fs, "First");
  time_format_print(sh, sm, ss, "Second");
  time_format_print(fh + sh, fm + sm, fs + ss, "Added");
}