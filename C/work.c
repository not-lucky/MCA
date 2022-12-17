#include <stdio.h>
static pre_empl = 0;
static int z;
struct employee {
  int empid;
  int age;
  int salary;
  char name[30];
};
static struct employee emp[10];

int main() {
  int sel;
  int exit;
  while (sel != 0) {
    printf("\n\n\n");
    printf("EMPLOYEE DATA MANAGEMENT\n\n\n");
    printf("ADD EMPLOYEE: 1\n\n");
    printf("REMOVE EMPLOYEE: 2\n\n");
    printf("SHOW EMPLOYEE: 3\n\n");
    printf("SORT EMPLOYEE: 4\n\n");
    printf("SEARCH EMPLOYEE : 5\n\n");
    printf("EXIT: 0\n\n\n");
    printf("ENTER : ");
    scanf("%d", &sel);
    printf("\n\n");

    switch (sel) {
      case 1:
        add();
        break;
      case 2:
        remov();
        break;
      case 3:
        show();
        break;
      case 4:
        printf("SORT ON THE BASIS OF:\n\n");
        printf("AGE : 1 ||Salary : 2 ||Employee id : 3||Name : 4\n");
        printf("ENTER : ");
        scanf("%d", &z);
        sort(z);
        show();
        sleep(3);
        break;
      case 0:
        break;
      case 5:
        break;
    }
  }
}
add() {
  int i;
  printf("ENTER THE NUMBER OF EMPLOYEE YOU WANT TO ADD  :  ");
  scanf("%d", &i);
  printf("\n\nENTER THE DETAILS\n\n");
  while (i > 0) {
    char a[30];

    printf("NAME: ");
    scanf("%s", &a);
    strcpy(emp[i - 1].name, a);
    printf(" AGE: ");
    scanf("%d", &emp[i - 1].age);
    printf("EMPLOYEE ID: ");
    scanf("%d", &emp[i - 1].empid);
    printf("Salary: ");
    scanf("%d", &emp[i - 1].salary);
    printf("\nSuccess\n");
    --i;
    ++pre_empl;
  }
  printf("EMPLOYEES ADDED SUCCESSFULLY\n");
}

sort(int z) {
  if (z == 1) {
    for (int i = 0; i < pre_empl - 1; ++i) {
      for (int k = i + 1; k < pre_empl; ++k) {
        if (emp[i].age > emp[k].age) {
          struct employee temp = emp[k];
          emp[k] = emp[i];
          emp[i] = temp;
        }
      }
    }
  }
  if (z == 2) {
    for (int i = 0; i < pre_empl - 1; ++i) {
      for (int k = i + 1; k < pre_empl; ++k) {
        if (emp[i].salary > emp[k].salary) {
          struct employee temp = emp[k];
          emp[k] = emp[i];
          emp[i] = temp;
        }
      }
    }
  }
  if (z == 3) {
    for (int i = 0; i < pre_empl - 1; ++i) {
      for (int k = i + 1; k < pre_empl; ++k) {
        if (emp[i].empid > emp[k].empid) {
          struct employee temp = emp[k];
          emp[k] = emp[i];
          emp[i] = temp;
        }
      }
    }
  }
  if (z == 4) {
    int pp = 0;
    for (int i = 0; i < pre_empl - 1; ++i) {
      for (int k = i + 1; k < pre_empl; ++k) {
        while (pp == 0) {
          int m = 0;
          if (emp[i].name[m] > emp[k].name[m]) {
            struct employee temp = emp[k];
            emp[k] = emp[i];
            emp[i] = temp;
            break;
          } else if (emp[i].name[m] == emp[k].name[m]) {
            ++m;
          } else {
            ++pp;
          }
        }
      }
    }
  }
}

show() {
  for (int i = 0; i < pre_empl; ++i) {
    printf("%d -> NAME : %s|| AGE : %d ||SALARY : %d ||EMPLOYEE ID : %d\n\n",
           i + 1, emp[i].name, emp[i].age, emp[i].salary, emp[i].empid);
  }
}
remov() {
  printf("Enter the employee ID You Want To remove  :");
  int rem;
  scanf("%d", &rem);

  if (pre_empl == 0) {
    printf("NO EMPLOYEE PRESENT");
  } else {
    for (int i = 0; i < pre_empl; ++i) {
      if (emp[i].empid == rem) {
        while (i < pre_empl) {
          emp[i] = emp[i + 1];
          ++i;
        }
        --pre_empl;
        break;
      }
    }
  }
}
