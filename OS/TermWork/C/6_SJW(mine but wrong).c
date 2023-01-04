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
  for (int i = 0; i < num_processes; i++) {
    printf("Enter id, arrival time, and burst time for process %d: ", i + 1);
    scanf("%d%d%d", &processes[i].id, &processes[i].arrival_time,
          &processes[i].burst_time);
    processes[i].completed = 0;
  }
  for (int i = 0; i < num_processes - 1; i++) {
    int min_ind = i;
    for (int j = i + 1; j < num_processes; j++) {
      if (processes[j].arrival_time < processes[min_ind].arrival_time)
        min_ind = j;
    }
    struct Process temp = processes[i];
    processes[i] = processes[min_ind];
    processes[min_ind] = temp;
  }
  double avg_TAT = 0, avg_WT = 0;
  printf(
      "\nProcess ID\tArrival Time\tBurst Time\tStart Time\tCompletion "
      "Time\tTurnaround Time\tWaiting Time\n");
  int current_time = 0;
  int total_completed = 0;
  while (total_completed != num_processes) {
    for (int i = 0; i < num_processes; i++) {
      if (processes[i].completed == 1) {
        continue;
      }
      current_time = current_time > processes[i].arrival_time
                         ? current_time
                         : processes[i].arrival_time;
      int to_work_ID = i;
      int min_burst = INT_MAX;
      for (int j = 0; j < num_processes; j++) {
        if (processes[j].completed == 0 &&
            processes[j].arrival_time <= current_time &&
            processes[j].burst_time < min_burst) {
          to_work_ID = j;
          min_burst = processes[j].burst_time;
        }
      }
      processes[to_work_ID].start_time = current_time;
      processes[to_work_ID].completion_time =
          current_time + processes[to_work_ID].burst_time;
      processes[to_work_ID].turnaround_time =
          processes[to_work_ID].completion_time -
          processes[to_work_ID].arrival_time;
      processes[to_work_ID].waiting_time =
          processes[to_work_ID].start_time - processes[to_work_ID].arrival_time;
      current_time += processes[to_work_ID].burst_time;
      processes[to_work_ID].completed = 1;
      total_completed++;
      if (processes[to_work_ID].completed == 0 &&
          processes[to_work_ID].id != processes[i].id) {
        i--;
      } else {
        i = 0;
      }
      avg_TAT += processes[to_work_ID].turnaround_time;
      avg_WT += processes[to_work_ID].waiting_time;
      printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
             processes[to_work_ID].id, processes[to_work_ID].arrival_time,
             processes[to_work_ID].burst_time, processes[to_work_ID].start_time,
             processes[to_work_ID].completion_time,
             processes[to_work_ID].turnaround_time,
             processes[to_work_ID].waiting_time);
    }
  }
  printf("\nAverage Turnaround Time is: %f\nAverage Waiting Time is: %f",
         avg_TAT / num_processes, avg_WT / num_processes);
}