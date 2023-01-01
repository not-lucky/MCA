#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
  int processId;    // Process ID
  int arrivalTime;  // Arrival time
  int cpuBurst;     // CPU burst time
  int ioBurst;      // I/O burst time
} Process;

int main() {
  // Initialize the process queue
  Process processQueue[10];
  int numProcesses = 0;

  // Read in the process data from the user
  printf("Enter the number of processes: ");
  scanf("%d", &numProcesses);

  for (int i = 0; i < numProcesses; i++) {
    printf("Enter data for process %d:\n", i + 1);
    printf("  Arrival time: ");
    scanf("%d", &processQueue[i].arrivalTime);
    printf("  CPU burst time: ");
    scanf("%d", &processQueue[i].cpuBurst);
    printf("  I/O burst time: ");
    scanf("%d", &processQueue[i].ioBurst);
    processQueue[i].processId = i + 1;
  }

  // Initialize the current time to 0
  int currentTime = processQueue[0].arrivalTime;

  // Initialize the waiting time and turnaround time for each process to 0
  int waitingTimes[10] = {0};
  int turnaroundTimes[10] = {0};

  // Iterate through the process queue
  for (int i = 0; i < numProcesses; i++) {
    // Calculate the waiting time for this process
    waitingTimes[i] = currentTime - processQueue[i].arrivalTime;

    // Calculate the turnaround time for this process
    turnaroundTimes[i] =
        waitingTimes[i] + processQueue[i].cpuBurst + processQueue[i].ioBurst;

    // Update the current time
    currentTime += processQueue[i].cpuBurst + processQueue[i].ioBurst;
  }

  // Calculate the average waiting time and turnaround time
  float avgWaitingTime = 0;
  float avgTurnaroundTime = 0;
  for (int i = 0; i < numProcesses; i++) {
    avgWaitingTime += waitingTimes[i];
    avgTurnaroundTime += turnaroundTimes[i];
  }
  avgWaitingTime /= numProcesses;

  // Print the results
  printf("\nProcess Scheduling Results (FCFS):\n");
  for (int i = 0; i < numProcesses; i++) {
    printf("Process %d:\n", processQueue[i].processId);
    printf(" Waiting time: %d\n", waitingTimes[i]);
    printf(" Turnaround time: %d\n", turnaroundTimes[i]);
  }
  printf("Average waiting time: %.2f\n", avgWaitingTime);
  printf("Average turnaround time: %.2f\n", avgTurnaroundTime);

  return 0;
}