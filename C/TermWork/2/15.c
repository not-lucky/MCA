#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char buffer[1000];
  int count = 0;
  if (argc != 3) {
    printf("Invalid number of arguments\n");
    return 0;
  }
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("File not found\n");
    return 0;
  }
  while (fgets(buffer, 1000, fp)) {
    for (int i = 0; i < strlen(buffer); i++) {
      if (strncmp(&buffer[i], argv[2], strlen(argv[2]))) {
        count++;
      }
    }
  }
  printf("%s occurs %d times in %s\n", argv[2], count, argv[1]);
  fclose(fp);
  return 0;
}