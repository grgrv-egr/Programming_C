#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 3

void print(int **matrix, int rows, int cols) { 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void zero(int **matrix, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int zeroCount = 0;
        
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
        
        for (int i = 0; i < rows; i++) {
            if (zeroCount > 0) {
                matrix[i][j] += zeroCount;
            }
        }
    }
}

int **transpose(int **original, int rows, int cols) {
    int **transposed = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transposed[i] = (int *)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }

    return transposed;
}

void replace(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int temp = matrix[i][0];
        matrix[i][0] = matrix[i][cols - 1];
        matrix[i][cols - 1] = temp;
    }
}

int main() {
    int **matrix = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
    }

    int m[ROWS][COLS] = {
        {1, 0, 3},
        {0, 5, 0},
        {9, 0, 11},
        {4, 6, 7},
        {6, 1, 2}
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = m[i][j];
        }
    }

    printf("Исходная матрица:\n");
    print(matrix, ROWS, COLS);
    
    zero(matrix, ROWS, COLS);
    printf("\nМатрица после увеличения элементов столбцов:\n");
    print(matrix, ROWS, COLS);
    
    int **transposed = transpose(matrix, ROWS, COLS);
    printf("\nТранспонированная матрица:\n");
    print(transposed, COLS, ROWS);
    
    replace(transposed, COLS, ROWS);
    printf("\nМатрица после замены первого и последнего столбца:\n");
    print(transposed, COLS, ROWS);

    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    for (int i = 0; i < COLS; i++) {
        free(transposed[i]);
    }
    free(transposed);

    return 0;
}
