#include <stdio.h>
struct student {
  char name[50];
  char subject[50];
  int roll;
  int sid;
  float marks;
};
int main() {
  struct student s;
  printf("Enter name: ");
  scanf("%s", s.name);
  printf("Enter subject: ");
  scanf("%s", s.subject);
  printf("Enter roll: ");
  scanf("%d", &s.roll);
  printf("Enter SID: ");
  scanf("%d", &s.sid);
  printf("Enter marks: ");
  scanf("%f", &s.marks);
  printf("\nName: %s\nSubject: %s\nRoll: %d\nSID: %d\nMarks:%f\n", s.name,
         s.subject, s.roll, s.sid, s.marks);
  scanf("%s", s.subject);
  printf("%s", s.subject);
}