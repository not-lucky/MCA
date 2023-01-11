#include <stdio.h>

int main() {
  // Open the file
  FILE* fp = fopen("ab.txt", "r");

  // Declare a variable to hold the integer that is read
  char i;

  // Read integers from the file until the end is reached
  while (fscanf(fp, "%c", &i) == 1) {
    // Print the integer that was read
    printf("%c", i);
  }
  printf("\n");
    fseek(fp, 0, SEEK_SET);

  while (fscanf(fp, "%c", &i) == 1) {
    // Print the integer that was read
    printf("%ld", ftell(fp));
  }

  // Close the file
  fclose(fp);

  return 0;
}