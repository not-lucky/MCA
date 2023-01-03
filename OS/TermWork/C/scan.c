#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int main() {
  int num_requests;
  int requests[MAX_REQUESTS] = {0};
  int head_position;
  int direction;
  int total_seek_operations;
  int disk_size;

  printf("Enter the number of disk requests: ");
  scanf("%d", &num_requests);

  printf("Enter the disk size: ");
  scanf("%d", &disk_size);

  printf("Enter the disk requests: ");
  for (int i = 0; i < num_requests; i++) {
    scanf("%d", &requests[i]);
  }

  printf("Enter the current head position: ");
  scanf("%d", &head_position);
  int temp_head_position = head_position;

  printf("Enter the direction (0 for left, 1 for right): ");
  scanf("%d", &direction);

  for (int i = 0; i < num_requests - 1; i++) {
    int min_ind = i;
    for (int j = i + 1; j < num_requests; j++) {
      if (requests[j] < requests[min_ind]) {
        min_ind = j;
      }
    }
    int temp = requests[i];
    requests[i] = requests[min_ind];
    requests[min_ind] = temp;
  }

  total_seek_operations = 0;

  // Schedule the requests using SCAN
  printf("\nScheduled requests: ");
  if (direction == 0) {
    // Move left first
    for (int i = num_requests - 1; i >= 0; i--) {
      if (requests[i] <= head_position) {
        printf("%d ", requests[i]);
        total_seek_operations += abs(requests[i] - temp_head_position);
        temp_head_position = requests[i];
      }
    }
    // Move right
    total_seek_operations += temp_head_position - 0;
    temp_head_position = 0;
    printf("%d ", temp_head_position);
    for (int i = 0; i < num_requests; i++) {
      if (requests[i] > head_position) {
        printf("%d ", requests[i]);
        total_seek_operations += abs(requests[i] - temp_head_position);
        temp_head_position = requests[i];
      }
    }
  } else {
    // Move right first
    for (int i = 0; i < num_requests; i++) {
      if (requests[i] >= head_position) {
        printf("%d ", requests[i]);
        total_seek_operations += abs(requests[i] - temp_head_position);
        temp_head_position = requests[i];
      }
    }
    // Move left
    total_seek_operations += disk_size - temp_head_position;
    temp_head_position = disk_size;
    printf("%d ", temp_head_position);

    for (int i = num_requests - 1; i >= 0; i--) {
      if (requests[i] < head_position) {
        printf("%d ", requests[i]);
        total_seek_operations += abs(requests[i] - temp_head_position);
        temp_head_position = requests[i];
      }
    }
  }
  printf("\n");

  printf("Total seek operations: %d\n", total_seek_operations);

  return 0;
}