#include <stdio.h>
#include <stdlib.h>

int main() {
  int row, col;

  printf("Enter the number of rows: ");
  scanf("%d", &row);

  printf("Enter the number of columns: ");
  scanf("%d", &col);

  int matrix[row][col];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) printf("%d ", matrix[i][j]);
    printf("\n");
  }

  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) scanf("%d", &matrix[i][j]);
  }

  printf("\nOriginal matrix:\n");

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) printf("%d ", matrix[i][j]);
    printf("\n");
  }

  printf("\nMirror matrix:\n");

  for (int i = 0; i < row; i++) {
    for (int j = col - 1; j >= 0; j--) printf("%d ", matrix[i][j]);
    printf("\n");
  }

  printf("\nTranspose matrix:\n");

  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) printf("%d ", matrix[j][i]);
    printf("\n");
  }
}
