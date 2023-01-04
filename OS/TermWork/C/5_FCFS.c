#include <stdio.h>

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

  struct Process processes[num_processes];

  for (int i = 0; i < num_processes; i++) {
    printf("Enter id, arrival time, and burst time for process %d: ", i + 1);
    scanf("%d%d%d", &processes[i].id, &processes[i].arrival_time, &processes[i].burst_time);
  }

  for (int i = 0; i < num_processes - 1; i++) {
    int min_ind = i;
    for (int j = i + 1; j < num_processes; j++) {
      if (processes[j].arrival_time < processes[min_ind].arrival_time) min_ind = j;
    }
    struct Process temp = processes[i];
    processes[i] = processes[min_ind];
    processes[min_ind] = temp;
  }
  double avg_TAT = 0, avg_WT = 0;
  printf(
      "\nProcess\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
  int current_time = 0;
  for (int i = 0; i < num_processes; i++) {
    current_time = current_time > processes[i].arrival_time ? current_time : processes[i].arrival_time;

    processes[i].start_time = current_time;
    processes[i].completion_time = current_time + processes[i].burst_time;

    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    processes[i].waiting_time = processes[i].start_time - processes[i].arrival_time;

    avg_TAT += processes[i].turnaround_time;
    avg_WT += processes[i].waiting_time;

    current_time += processes[i].burst_time;

    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].start_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
  }

  printf("\nAverage Turnaround Time is: %f\nAverage Waiting Time is: %f", avg_TAT / num_processes, avg_WT / num_processes);
}