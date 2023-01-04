#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_requests;
  int head_position;
  int total_seek_distance = 0;
  printf("Enter the number of disk requests: ");
  scanf("%d", &num_requests);
  int requests[num_requests];

  printf("Enter the disk requests: ");
  for (int i = 0; i < num_requests; i++) {
    scanf("%d", &requests[i]);
  }
  printf("Enter the current head position: ");
  scanf("%d", &head_position);

  printf("\nSeek Sequence is: ");
  while (num_requests > 0) {
    int min_seek_time = INT_MAX;
    int min_seek_time_index = -1;
    for (int i = 0; i < num_requests; i++) {
      int seek_time = abs(requests[i] - head_position);
      if (seek_time < min_seek_time) {
        min_seek_time = seek_time;
        min_seek_time_index = i;
      }
    }
    printf("%d ", requests[min_seek_time_index]);
    head_position = requests[min_seek_time_index];
    for (int i = min_seek_time_index; i < num_requests - 1; i++) {
      requests[i] = requests[i + 1];
    }
    num_requests--;
    total_seek_distance += min_seek_time;
  }
  printf("\nTotal Head Movements: %d", total_seek_distance);
}