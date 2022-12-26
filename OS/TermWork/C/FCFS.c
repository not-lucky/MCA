#include <stdio.h>

// Structure to represent a process
struct Process {
  int pid;             // Process ID
  int burstTime;       // CPU burst time
  int arrivalTime;     // Arrival time
  int ioBurstTime;     // IO burst time
  int startingTime;    // Starting time
  int completionTime;  // Completion time
  int waitingTime;     // Waiting time
  int turnaroundTime;  // Turnaround time
};

// Function to find the waiting time and turnaround time of each process
void findWaitingTimeAndTurnaroundTime(struct Process processes[], int n) {
  // Initialize waiting time of the first process to 0
  processes[0].waitingTime = 0;

  // Calculate waiting time and turnaround time of the rest of the processes
  for (int i = 1; i < n; i++) {
    // Waiting time of the current process is the sum of the completion time of
    // the previous process and the burst time and IO burst time of the previous
    // process
    processes[i].waitingTime =
        processes[i - 1].completionTime - processes[i].arrivalTime;
    // Turnaround time of the current process is the sum of the waiting time and
    // burst time of the current process
    processes[i].turnaroundTime =
        processes[i].waitingTime + processes[i].burstTime;
  }
}

// Function to find the starting time and completion time of each process
void findStartingTimeAndCompletionTime(struct Process processes[], int n) {
  // Initialize the starting time and completion time of the first process
  processes[0].startingTime = processes[0].arrivalTime;
  processes[0].completionTime =
      processes[0].startingTime + processes[0].burstTime;

  // Calculate the starting time and completion time of the rest of the
  // processes
  for (int i = 1; i < n; i++) {
    // Starting time of the current process is the sum of the completion time of
    // the previous process and the IO burst time of the previous process
    processes[i].startingTime =
        processes[i - 1].completionTime + processes[i - 1].ioBurstTime;
    // Completion time of the current process is the sum of the starting time
    // and burst time of the current process
    processes[i].completionTime =
        processes[i].startingTime + processes[i].burstTime;
  }
}

int main() {
  // Define an array of processes
  struct Process processes[] = {{1, 6, 1, 2, 0, 0, 0, 0},
                                {2, 8, 3, 1, 0, 0, 0, 0},
                                {3, 7, 0, 3, 0, 0, 0, 0},
                                {4, 3, 2, 1, 0, 0, 0, 0},
                                {5, 4, 4, 2, 0, 0, 0, 0}};

  int n = sizeof(processes) / sizeof(processes[0]);  // Number of processes

  // Find the starting time and completion time of each process
  findStartingTimeAndCompletionTime(processes, n);

  // Find the waiting time and turnaround time of each process
  findWaitingTimeAndTurnaroundTime(processes, n);

  // Print the results
  printf(
      "Process ID\tStarting Time\tCompletion Time\tTurnaround Time\tWaiting "
      "Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid,
           processes[i].startingTime, processes[i].completionTime,
           processes[i].turnaroundTime, processes[i].waitingTime);
  }

  return 0;
}
