#include <stdio.h>
#include <stdlib.h>

char func(char i) { printf("%c ", i); }

int main() {
  int* ar = (int*) malloc(10*4);
  char* st = (char*) malloc(10*1);
  double* dr = (double*) malloc(10*(sizeof(double)));

  int* arc = (int*) calloc(10, 4);
  char* stc = (char*) calloc(10, 1);
  double* drc = (double*) calloc(10, sizeof(double));

  for (int i = 0; i< 10; i++) {
    printf("%d, %c, %lf\t%d, %d, %lf\n", ar[i], st[i], dr[i], arc[i], stc[i], drc[i]);
  }

}