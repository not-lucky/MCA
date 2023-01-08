#include <stdio.h>
#include <stdlib.h>

int main() {
  int row1, col1, row2, col2;

  printf("Enter the number of rows in matrix 1: ");
  scanf("%d", &row1);

  printf("Enter the number of columns in matrix 1: ");
  scanf("%d", &col1);

  printf("Enter the number of rows in matrix 2: ");
  scanf("%d", &row2);

  printf("Enter the number of columns in matrix 2: ");
  scanf("%d", &col2);

  if (col1 != row2) {
    printf("Matrix multiplication is not possible.\n");
    return 0;
  }

  int matrix1[row1][col1], matrix2[row2][col2], result[row1][col2];

  printf("Enter the elements of matrix 1:\n");
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) scanf("%d", &matrix1[i][j]);
  }

  printf("Enter the elements of matrix 2:\n");
  for (int i = 0; i < row2; i++) {
    for (int j = 0; j < col2; j++) scanf("%d", &matrix2[i][j]);
  }

  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < col1; k++)
        result[i][j] += matrix1[i][k] * matrix2[k][j];
    }
  }

  printf("\nResultant matrix:\n");

  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) printf("%d ", result[i][j]);
    printf("\n");
  }
}
