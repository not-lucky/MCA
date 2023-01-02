#include <stdio.h>

struct Process {
  int arrival_time;
  int burst_time;
};

int main() {
  int num_processes;

  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  // Read the arrival time and burst time for each process
  struct Process processes[num_processes];
  for (int i = 0; i < num_processes; i++) {
    printf("Enter arrival time and burst time for process %d: ", i + 1);
    scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
  }

  for (int i = 0; i < num_processes - 1; i++) {
    int ind = i;
    for (int j = i + 1; j < num_processes; j++) {
      int ind = i;
      if (processes[j].arrival_time < processes[ind].arrival_time) {
        ind = j;
      }

      struct Process temp = processes[i];
      processes[i] = processes[ind];
      processes[ind] = temp;
    }
  }

  // Schedule the processes using FCFS
  int current_time = 0;
  printf(
      "\nProcess\tArrival Time\tBurst Time\tStart Time\tCompletion "
      "Time\tTurnaround Time\tWaiting Time\n");
  for (int i = 0; i < num_processes; i++) {
    int start_time = current_time;
    current_time += processes[i].burst_time;
    int turnaround_time = current_time - processes[i].arrival_time;
    int waiting_time = start_time - processes[i].arrival_time;
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", i + 1,
           processes[i].arrival_time, processes[i].burst_time, start_time,
           current_time, turnaround_time, waiting_time);
  }

  return 0;
}