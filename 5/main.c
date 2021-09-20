#include <stdio.h>
int main() {
    // задание 1
  int a[3][3] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
  printf("%d %d %d\n", a[0][0], a[0][1], a[0][2] );
  printf("%d %d %d\n", a[1][0], a[1][1], a[1][2] );
  printf("%d %d %d\n", a[2][0], a[2][1], a[2][2] );
  printf("_________\n");
  //задание 2
  int MatrixA[2][2] = {1, 1, 1, 4};
  int MatrixB[2][2] = {1, 2, 4, 1};
  int result[2][2] = {0, 0, 0, 0};

  printf("Matrix A:\n");
  printf("%d %d\n", MatrixA[0][0], MatrixA[0][1]);
  printf("%d %d\n\n", MatrixA[1][0], MatrixA[1][1]);

  printf("Matrix B:\n");
  printf("%d %d\n", MatrixB[0][0], MatrixB[0][1]);
  printf("%d %d\n\n", MatrixB[1][0], MatrixB[1][1]);

  result [0][0] = MatrixA[0][0] * MatrixB[0][0] + MatrixA[0][1] * MatrixB[1][0];
  result [0][1] = MatrixA[0][0] * MatrixB[0][1] + MatrixA[0][1] * MatrixB[1][1];
  result [1][0] = MatrixA[1][0] * MatrixB[0][0] + MatrixA[1][1] * MatrixB[1][0];
  result [1][1] = MatrixA[1][0] * MatrixB[0][1] + MatrixA[1][1] * MatrixB[1][1];

  printf("Matrix A * Matrix B:\n");
  printf("%d %d\n", result[0][0], result[0][1]);
  printf("%d %d\n", result[1][0], result[1][1]);

    return 0;
}
