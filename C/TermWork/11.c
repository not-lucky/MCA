#include <stdio.h>

int main() {
  int n = 5;
  for (int i = 1; i <= n; i++) {
    for (int j = n - i; j >= 1; j--) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = n - i; j >= 1; j--) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("* ");
    } 
    printf("\n");
  }

  printf("\n\n");

  for (int i = 1; i <= n; i++) {
    for (int j = n - i; j >= 1; j--) {
      printf("  ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    for (int j = i - 1; j >= 1; j--) {
      printf("%d ", j);
    }
    printf("\n");
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = n - i; j >= 1; j--) {
      printf("  ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    for (int j = i - 1; j >= 1; j--) {
      printf("%d ", j);
    }
    printf("\n");
  }

  printf("\n\n");

  for (int i = 1; i <= n; i++) {
    for (int j = n - i; j >= 1; j--) {
      printf("  ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%c ", 65 + n - j);
    }
    for (int j = i - 1; j >= 1; j--) {
      printf("%c ", 65 + n - j);
    }
    printf("\n");
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = n - i; j >= 1; j--) {
      printf("  ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%c ", 65 + n - j);
    }
    for (int j = i - 1; j >= 1; j--) {
      printf("%c ", 65 + n - j);
    }
    printf("\n");
  }
}