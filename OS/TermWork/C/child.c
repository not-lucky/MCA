#include <stdio.h>

#define MAX_REQUESTS 100

int main() {
  int num_requests;
  int requests[MAX_REQUESTS];
  int head_position;
  int direction;

  printf("Enter the number of disk requests: ");
  scanf("%d", &num_requests);

  printf("Enter the disk requests: ");
  for (int i = 0; i < num_requests; i++) {
    scanf("%d", &requests[i]);
  }

  printf("Enter the current head position: ");
  scanf("%d", &head_position);

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

  // Schedule the requests using SCAN
  printf("\nScheduled requests: ");
  if (direction == 0) {
    // Move left first
    for (int i = num_requests - 1; i >= 0; i--) {
      if (requests[i] <= head_position) {
        printf("%d ", requests[i]);
      }
    }
    // Move right
    for (int i = 0; i < num_requests; i++) {
      if (requests[i] > head_position) {
        printf("%d ", requests[i]);
      }
    }
  } else {
    // Move right first
    for (int i = 0; i < num_requests; i++) {
      if (requests[i] >= head_position) {
        printf("%d ", requests[i]);
      }
    }
    // Move left
    for (int i = num_requests - 1; i >= 0; i--) {
      if (requests[i] < head_position) {
        printf("%d ", requests[i]);
      }
    }
  }
  printf("\n");

  return 0;
}