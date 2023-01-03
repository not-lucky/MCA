// Here is a C program that implements the First-Come, First-Served (FCFS) CPU
// scheduling algorithm and calculates the start time, completion time,
// turnaround time, and waiting time for each process:

#include <stdio.h>

#define MAX_PROCESSES 100

struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int start_time;
  int completion_time;
  int turnaround_time;
  int waiting_time;
};

int main() {
  int num_processes;

  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  // Read the process information
  struct Process processes[MAX_PROCESSES];
  for (int i = 0; i < num_processes; i++) {
    printf("Enter id, arrival time, and burst time for process %d: ", i + 1);
    scanf("%d%d%d", &processes[i].id, &processes[i].arrival_time,
          &processes[i].burst_time);
  }

  for (int i = 0; i < num_processes - 1; i++) {
    int min_ind = i;
    for (int j = i + 1; j < num_processes; j++) {
      if (processes[j].arrival_time < processes[min_ind].arrival_time) {
        min_ind = j;
      }
    }
    struct Process temp = processes[i];
    processes[i] = processes[min_ind];
    processes[min_ind] = temp;
  }

  // Schedule the processes using FCFS
  printf(
      "\nProcess\tArrival Time\tBurst Time\tStart Time\tCompletion "
      "Time\tTurnaround Time\tWaiting Time\n");
  int current_time = 0;
  for (int i = 0; i < num_processes; i++) {
    // Wait for the current process to arrive
    current_time = current_time > processes[i].arrival_time
                       ? current_time
                       : processes[i].arrival_time;
    // Set the start time and completion time for the current process
    processes[i].start_time = current_time;
    processes[i].completion_time = current_time + processes[i].burst_time;
    // Calculate the turnaround time and waiting time for the current process
    processes[i].turnaround_time =
        processes[i].completion_time - processes[i].arrival_time;
    processes[i].waiting_time =
        processes[i].start_time - processes[i].arrival_time;
    // Update the current time
    current_time += processes[i].burst_time;
    // Print the process information
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id,
           processes[i].arrival_time, processes[i].burst_time,
           processes[i].start_time, processes[i].completion_time,
           processes[i].turnaround_time, processes[i].waiting_time);
  }

  return 0;
}