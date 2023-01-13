#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char str[100];
  int alphabets = 0, digits = 0, white_space = 0, special_characters = 0,
      lines = 0;

  fp = fopen("d:\\myfile.txt", "w");

  if (fp == NULL) {
    printf("Error in opening file\n");
    exit(1);
  }

  printf("Enter data in file\n");
  do {
    fgets(str, 100, stdin);
    fputs(str, fp);
  } while (str[0] != '\n');
  fclose(fp);

  fp = fopen("d:\\myfile.txt", "r");

  if (fp == NULL) {
    printf("Error in opening file\n");
    exit(1);
  }
  printf("\nData in file is:\n");
  char ch;
  ch = fgetc(fp);
  printf("%c", ch);
  while (ch != EOF) {
    printf("%c", ch);
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      alphabets++;
    } else if (ch >= '0' && ch <= '9') {
      digits++;
    } else if (ch == ' ') {
      white_space++;
    } else if (ch == '\n') {
      lines++;
    } else {
      special_characters++;
    }
    ch = fgetc(fp);
  }

  printf("\n\nTotal alphabets: %d\n", alphabets);
  printf("Total digits: %d\n", digits);
  printf("Total white spaces: %d\n", white_space);
  printf("Total special characters: %d\n", special_characters);
  printf("Total lines: %d\n", lines);

  fclose(fp);
}