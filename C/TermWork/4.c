#include <stdio.h>
void main() {
  int marks;
  printf("Enter your marks:");
  scanf("%d", &marks);
  if (marks < 0 || marks > 100) {
    printf("Out of range marks.");
  } else if (marks < 30) {
    printf("F");
  } else if (marks < 45) {
    printf("E");
  } else if (marks < 60) {
    printf("D");
  } else if (marks < 75) {
    printf("C");
  } else if (marks < 85) {
    printf("B");
  } else printf("A");
}