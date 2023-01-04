// Here is a C program that implements the First-Come, First-Served (FCFS) CPU
// scheduling algorithm and calculates the start time, completion time,
// turnaround time, and waiting time for each process:

#include <limits.h>
#include <stdio.h>

struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int start_time;
  int completion_time;
  int turnaround_time;
  int waiting_time;
  int completed;
};

int main() {
  int num_processes;

  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  struct Process processes[num_processes];

  // Read the process information
  for (int i = 0; i < num_processes; i++) {
    printf("Enter id, arrival time, and burst time for process %d: ", i + 1);
    scanf("%d%d%d", &processes[i].id, &processes[i].arrival_time,
          &processes[i].burst_time);
    processes[i].completed = 0;
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

  printf(
      "\nProcess\tArrival Time\tBurst Time\tStart Time\tCompletion "
      "Time\tTurnaround Time\tWaiting Time\n");

  here:
  int current_time = 0;
  for (int i = 0; i < num_processes; i++) {
    if (processes[i].completed) {
      continue;
    }

    current_time = current_time > processes[i].arrival_time
                       ? current_time
                       : processes[i].arrival_time;

    struct Process to_work = processes[i];
    int min_burst = INT_MAX;

    for (int j = i + 1; j < num_processes; j++) {
      if (processes[j].completed == 0 &&
          processes[j].arrival_time <= current_time) {
        if (processes[j].burst_time < min_burst) {
          to_work = processes[j];
        }
      }
    }

    to_work.start_time = current_time;
    to_work.completion_time = current_time + to_work.burst_time;
    to_work.turnaround_time = to_work.completion_time - to_work.arrival_time;
    to_work.waiting_time = to_work.start_time - to_work.arrival_time;
    // Update the current time
    current_time += to_work.burst_time;
    to_work.completed = 1;
    if (to_work.id != processes[i].id) {
        i--;
    }
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", to_work.id,
           to_work.arrival_time, to_work.burst_time, to_work.start_time,
           to_work.completion_time, to_work.turnaround_time,
           to_work.waiting_time);
  }

  goto here;

  return 0;
}