#include <stdbool.h>
#include <stdio.h>

void main() {
  printf("Enter the number of processes: ");
  int numProcesses;
  scanf("%d", &numProcesses);

  int burstTime[numProcesses];
  int arrivalTime[numProcesses];
  int temp;
  int processNumber[numProcesses];
  bool completed[numProcesses];

  for (int i = 0; i < numProcesses; ++i) {
    printf("Process %d \nEnter the Arrival time : ", i + 1);
    scanf("%d", &arrivalTime[i]);
    printf("Enter the CPU BURST time : ");
    scanf("%d", &burstTime[i]);
    processNumber[i] = i + 1;
    completed[i] = false;
    printf("\n");
  }

  for (int i = 0; i < numProcesses; ++i) {
    for (int k = i + 1; k < numProcesses; ++k) {
      if (burstTime[i] > burstTime[k]) {
        temp = burstTime[i];
        burstTime[i] = burstTime[k];
        burstTime[k] = temp;
        temp = arrivalTime[i];
        arrivalTime[i] = arrivalTime[k];
        arrivalTime[k] = temp;
        temp = processNumber[i];
        processNumber[i] = processNumber[k];
        processNumber[k] = temp;
      } else if (burstTime[i] == burstTime[k]) {
        if (arrivalTime[i] > arrivalTime[k]) {
          temp = burstTime[i];
          burstTime[i] = burstTime[k];
          burstTime[k] = temp;
          temp = arrivalTime[i];
          arrivalTime[i] = arrivalTime[k];
          arrivalTime[k] = temp;
          temp = processNumber[i];
          processNumber[i] = processNumber[k];
          processNumber[k] = temp;
        }
      }
    }
  }

  int earliestArrivalTime = arrivalTime[0];
  int earliestArrivalTimeIndex;
  for (int i = 0; i < numProcesses; ++i) {
    if (earliestArrivalTime > arrivalTime[i]) {
      earliestArrivalTime = arrivalTime[i];
      earliestArrivalTimeIndex = i;
    }
  }
  completed[earliestArrivalTimeIndex] = true;
  int currentTime = burstTime[earliestArrivalTimeIndex] +
                    arrivalTime[earliestArrivalTimeIndex];

  for (int k = 0; k < numProcesses; ++k) {
    printf("Process %d  Arrival time %d : CPU BURST %d \n", processNumber[k],
           arrivalTime[k], burstTime[k]);
  }
  printf("\n");

  printf(
      "Process %d || Start Time %d  || END Time %d || Waiting Time %d || "
      "TurnAround Time %d\n",
      processNumber[earliestArrivalTimeIndex],
      arrivalTime[earliestArrivalTimeIndex], currentTime, 0,
      burstTime[earliestArrivalTimeIndex]);

  for (int i = 0; i < numProcesses; ++i) {
    for (int p = 0; p < numProcesses; ++p) {
      if (completed[p] == true) {
        continue;
      } else if (currentTime >= arrivalTime[p]) {
        completed[p] = true;
        printf(
            "Process %d || Start Time %d || END Time %d || Waiting Time %d || "
            "TurnAround time %d \n",
            processNumber[p], currentTime, currentTime + burstTime[p],
            currentTime - arrivalTime[p],
            currentTime - arrivalTime[p] + burstTime[p]);
        currentTime = currentTime + burstTime[p];
        break;
      }
    }
  }
}
