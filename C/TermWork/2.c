#include <stdio.h>

int main() {
  int side1, side2, side3;

  printf("Enter length of three sides of the triangle\n");
  scanf("%d %d %d", &side1, &side2, &side3);

  if ((side1 + side2 > side3) && (side2 + side3 > side1) &&
      (side3 + side1 > side2)) {
    printf("It is a valid triangle\n");
  } else {
    printf("It is an invalid triangle");
  }
}