#include <stdio.h>

char marks_to_grade(float mark) {
  if (mark < 30) {
    return 'F';
  } else if (mark < 45) {
    return 'E';
  } else if (mark < 60) {
    return 'D';
  } else if (mark < 75) {
    return 'C';
  } else if (mark < 85) {
    return 'B';
  } else
    return 'A';
}

void main() {
  float marks[5];
  float sum = 0;
  printf("Enter your marks in 5 subjects:\n");
  int i = 0;
  while (i < 5) {
    scanf("%f", &marks[i]);
    if (marks[i] < 0 || 100 < marks[i]) {
      printf("Out of range marks.\nPlease enter correct marks.\n");
      continue;
    }
    printf("Your marks in this subject is: %c\n", marks_to_grade(marks[i]));
    sum += marks[i];
    i++;
  }

  printf("Your total percentage is :\n%.2f\nYou final grade is:\n%c", sum / 5,
         marks_to_grade(sum / 5));
}