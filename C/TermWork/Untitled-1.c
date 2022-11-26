#include <stdio.h>
#include <string.h>

int main() {
  char arr[100];
  char ar[100] = "uello motherfuckers!!";
  gets(arr);
  char a[100] = "asasas ";
  strcat(a, arr);
  printf("%s %d", a, strlen(arr));
}