/*
        First-Come-First-Serve Process Scheduling
        Non-Preemptive
*/
#include "stdio.h"
#include "stdlib.h"
struct process {
  int process_id;
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turn_around_time;
};
int main() {
  int n, i;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  struct process proc[n];
  for (i = 0; i < n; i++) {
    printf("\n");
    printf("Enter process ID: ");
    scanf("%d", &proc[i].process_id);
    printf("Enter arrival time for process%d: ", proc[i].process_id);
    scanf("%d", &proc[i].arrival_time);
    printf("Enter burst time for process%d: ", proc[i].process_id);
    scanf("%d", &proc[i].burst_time);
  }

  for (int i = 0; i < n - 1; i++) {
    int min_ind = i;
    for (int j = i + 1; j < n; j++) {
      if (proc[j].arrival_time < proc[min_ind].arrival_time) {
        min_ind = j;
      }
    }
    struct process temp = proc[i];
    proc[i] = proc[min_ind];
    proc[min_ind] = temp;
  }

  int service_time[n];
  service_time[0] = 0;
  proc[0].waiting_time = 0;

  for (i = 1; i < n; i++) {
    service_time[i] = service_time[i - 1] + proc[i - 1].burst_time;
    proc[i].waiting_time = service_time[i] - proc[i].arrival_time;

    if (proc[i].waiting_time < 0) proc[i].waiting_time = 0;
  }

  for (i = 0; i < n; i++) {
    proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
  }
  printf("\n\n");
  printf(
      "Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around "
      "Time\tCompletion Time\n");
  int total_waiting_time = 0, total_turn_around_time = 0;
  for (i = 0; i < n; i++) {
    total_waiting_time += proc[i].waiting_time;
    total_turn_around_time += proc[i].turn_around_time;

    int completion_time = proc[i].turn_around_time + proc[i].arrival_time;

    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].process_id,
           proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time,
           proc[i].turn_around_time, completion_time);
  }
  printf("Average waiting time: %f\n", (float)total_waiting_time / n);
  printf("Average turn around time: %f\n", (float)total_turn_around_time / n);
}