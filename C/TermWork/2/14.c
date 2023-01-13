#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp {
  char name[20];
  char dept[20];
  int eid;
  float sal;
  int age;
};

void main() {
  struct emp e;
  FILE *fp;
  char ch;
  fp = fopen("S:\\emp.dat", "w");
  if (fp == NULL) {
    printf("\nFile cannot be opened");
    exit(0);
  }
  do {
    printf("\nEnter name : ");
    scanf("%s", e.name);
    printf("\nEnter department : ");
    scanf("%s", e.dept);
    printf("\nEnter employee id : ");
    scanf("%d", &e.eid);
    printf("\nEnter salary : ");
    scanf("%f", &e.sal);
    printf("\nEnter age : ");
    scanf("%d", &e.age);
    fprintf(fp, "%s %s %d %f %d\n", e.name, e.dept, e.eid, e.sal, e.age);
    printf("\nDo you want to enter more data (y/n) : ");
    ch = getche();
  } while (ch == 'y' || ch == 'Y');
  fclose(fp);
  fp = fopen("S:\\emp.dat", "r");
  if (fp == NULL) {
    printf("\nFile cannot be opened");
    exit(0);
  }
  printf("\n\nName\tDepartment\tEmployee ID\tSalary\tAge");
  while (fscanf(fp, "%s %s %d %f %d", e.name, e.dept, &e.eid, &e.sal, &e.age) !=
         EOF) {
    printf("\n%s\t%s\t\t%d\t\t%.2f\t%d", e.name, e.dept, e.eid, e.sal, e.age);
  }
  fclose(fp);
}