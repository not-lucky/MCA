#include <stdbool.h>
#include <stdio.h>
void main() {
  printf("Enter the number of process: ");
  int n;
  scanf("%d", &n);
  int cpu[n];
  int at[n];
  int temp;
  int pro[n];
  bool ar[n];
  for (int i = 0; i < n; ++i) {
    printf("Process %d \nEnter the Arrival time : ", i + 1);
    scanf("%d", &at[i]);
    printf("Enter the CPU BURST time : ");
    scanf("%d", &cpu[i]);
    pro[i] = i + 1;
    ar[i] = false;
    printf("\n");
  }
  for (int i = 0; i < n; ++i) {
    for (int k = i + 1; k < n; ++k) {
      if (cpu[i] > cpu[k]) {
        temp = cpu[i];
        cpu[i] = cpu[k];
        cpu[k] = temp;
        temp = at[i];
        at[i] = at[k];
        at[k] = temp;
        temp = pro[i];
        pro[i] = pro[k];
        pro[k] = temp;
      } else if (cpu[i] == cpu[k]) {
        if (at[i] > at[k]) {
          temp = cpu[i];
          cpu[i] = cpu[k];
          cpu[k] = temp;
          temp = at[i];
          at[i] = at[k];
          at[k] = temp;
          temp = pro[i];
          pro[i] = pro[k];
          pro[k] = temp;
        }
      }
    }
  }

  int mi = at[0];
  int ii;
  for (int i = 0; i < n; ++i) {
    if (mi > at[i]) {
      mi = at[i];
      ii = i;
    }
  }
  ar[ii] = true;
  int tt = cpu[ii] + at[ii];

  for (int k = 0; k < n; ++k) {
    printf("Process %d  Arrival time %d : CPU BURST %d \n", pro[k], at[k],
           cpu[k]);
  }
  printf("\n");
  printf(
      "process %d || Start Time %d || END Time %d ||Waiting Time %d|| "
      "TurnAround Time %d\n",
      pro[ii], at[ii], tt, 0, cpu[ii]);

  for (int i = 0; i < n; ++i) {
    for (int p = 0; p < n; ++p) {
      if (ar[p] == true) {
        continue;
      } else if (tt >= at[p]) {
        ar[p] = true;
        printf(
            "process %d || Start Time %d || END Time %d ||Waiting Time %d || "
            "TurnAround time %d \n",
            pro[p], tt, tt + cpu[p], tt - at[p], tt - at[p] + cpu[p]);
        tt = tt + cpu[p];
        break;
      }
    }
  }
}
