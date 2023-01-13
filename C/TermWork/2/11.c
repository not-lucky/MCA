#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10

struct student {
  char name[20];
  char subject[20];
  int roll;
  int sid;
  int marks;
} typedef student;

student s[n];
int filled[n];

void insert() {
  int i = 0;
  while (filled[i] == 1 && i < n) i++;
  if (i == n) {
    printf("No position left!!! Delete an entry!!!");
    return;
  }
  printf("\nEnter the name of student %d: ", i + 1);
  scanf("%s", s[i].name);
  printf("\nEnter the subject of student %d: ", i + 1);
  scanf("%s", s[i].subject);
  printf("\nEnter the roll no. of student %d: ", i + 1);
  scanf("%d", &s[i].roll);
  printf("\nEnter the sid of student %d: ", i + 1);
  scanf("%d", &s[i].sid);
  printf("\nEnter the marks of student %d: ", i + 1);
  scanf("%d", &s[i].marks);
  filled[i] = 1;
}

void display() {
  int i;
  for (i = 0; i < n; i++) {
    if (filled[i] == 0) continue;
    printf("\nName of student %d: %s", i + 1, s[i].name);
    printf("\nSubject of student %d: %s", i + 1, s[i].subject);
    printf("\nRoll no. of student %d: %d", i + 1, s[i].roll);
    printf("\nSid of student %d: %d", i + 1, s[i].sid);
    printf("\nMarks of student %d: %d", i + 1, s[i].marks);
  }
}

void delete() {
  int i, j, k;
  int id;
  int deleted = 0;
  printf("\nEnter the id of student to be deleted: ");
  scanf("%d", &id);
  for (i = 0; i < n; i++) {
    if (filled[i] == 0) continue;
    if (id == s[i].sid) {
      filled[i] = 0;
      deleted = 1;
    }
  }
  if (!deleted) {
    printf("\nStudent not found");
  } else {
    printf("\nStudent deleted");
  }
}

void search() {
  int i, j, k;
  int id;
  printf("\nEnter the name of ID to be searched: ");
  scanf("%d", &id);
  for (i = 0; i < n; i++) {
    if (filled[i] == 0) continue;
    if (s[i].sid == id) {
      printf("\nName of student %d: %s", i + 1, s[i].name);
      printf("\nSubject of student %d: %s", i + 1, s[i].subject);
      printf("\nRoll no. of student %d: %d", i + 1, s[i].roll);
      printf("\nSid of student %d: %d", i + 1, s[i].sid);
      printf("\nMarks of student %d: %d", i + 1, s[i].marks);
      break;
    }
  }
  if (i == n) {
    printf("\nStudent not found");
  }
}

int main() {
  int i, j, k, ch;
  for (int i = 0; i < n; i++) filled[i] = 0;

  while (1) {
    printf(
        "\n1. Insert\n2. Display\n3. Delete\n4. Search\n5. Exit\nEnter your "
        "choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        insert();
        break;
      case 2:
        display();
        break;
      case 3:
        delete ();
        break;
      case 4:
        search();
        break;
      case 5:
        return 0;
      default:
        printf("\nInvalid choice");
    }
  }
}