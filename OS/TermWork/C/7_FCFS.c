#include <stdio.h>

int main() {
  int num_frames;
  int num_references;
  int page_faults;

  printf("Enter the number of frames: ");
  scanf("%d", &num_frames);
  printf("Enter the number of references: ");
  scanf("%d", &num_references);

  int frames[num_frames];
  int references[num_references];
  printf("Enter the reference string: ");
  for (int i = 0; i < num_references; i++) {
    scanf("%d", &references[i]);
  }
  for (int i = 0; i < num_frames; i++) {
    frames[i] = -1;
  }

  page_faults = 0;
  for (int i = 0; i < num_references; i++) {
    int found = 0;
    for (int j = 0; j < num_frames; j++) {
      if (frames[j] == references[i]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      frames[page_faults % num_frames] = references[i];
      page_faults++;
    }
    printf("[");
    for (int i = 0; i < num_frames; i++) {
      printf("%d, ", frames[i]);
    }
    printf("]\n");
  }
  printf("Total page faults: %d\n", page_faults);
}