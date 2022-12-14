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
    printf("Process %d \nEnter the Arrival time and Burst time : ", i + 1);
    scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    processNumber[i] = i + 1;
    completed[i] = false;
    printf("\n");
  }

  // Sort the processes in ascending order of burst time
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

  // Select the first process to run
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

  // Print the details of the first process
  printf(
      "Process %d || Start Time %d  || END Time %d || Waiting Time %d || "
      "TurnAround Time %d\n",
      processNumber[earliestArrivalTimeIndex],
      arrivalTime[earliestArrivalTimeIndex], currentTime, 0,
      burstTime[earliestArrivalTimeIndex]);

  // Run the remaining processes
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
