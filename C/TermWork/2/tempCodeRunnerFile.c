#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char buffer[1000];
  fp = fopen("S:/Emp.dat", "r");
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  long i = 0;
  fseek(fp, -1, SEEK_END);
  printf("%c", fgetc(fp));
  char ch;
  while (i < size) {
    if (ch == 10) fseek(fp, -3, SEEK_CUR);
    else fseek(fp, -2, SEEK_CUR);
    ch = fgetc(fp);
    printf("%c", ch);
    i++;
  }
}