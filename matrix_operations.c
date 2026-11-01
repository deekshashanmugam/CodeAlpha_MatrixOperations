/*
 * CodeAlpha - C Programming Internship
 * Task 2: Matrix Operations
 *
 * Implements matrix addition, multiplication and transpose
 * using functions and 2D arrays.
 *
 * Compile: gcc matrix_operations.c -o matrix_operations
 * Run:     ./matrix_operations
 */

#include <stdio.h>

#define MAX 10

/* Reads an integer within [min, max]; keeps asking until valid */
int readInt(const char *prompt, int min, int max) {
    int value, c;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= min && value <= max)
            return value;
        printf("Invalid input. Enter a number between %d and %d.\n", min, max);
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

/* Reads rows x cols elements into matrix m */
void readMatrix(int m[MAX][MAX], int rows, int cols, char name) {
    int i, j, c;
    printf("Enter elements of matrix %c (%d x %d):\n", name, rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("  %c[%d][%d] = ", name, i, j);
            while (scanf("%d", &m[i][j]) != 1) {
                printf("  Invalid input. Try again: ");
                while ((c = getchar()) != '\n' && c != EOF) { }
            }
        }
    }
}

/* Prints a matrix */
void printMatrix(int m[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%6d", m[i][j]);
        printf("\n");
    }
}

/* result = a + b (same dimensions) */
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                 int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

/* result = a (r1 x c1) * b (c1 x c2) */
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                      int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

/* result = transpose of a (rows x cols) -> (cols x rows) */
void transposeMatrix(int a[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[j][i] = a[i][j];
}

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int choice, r1, c1, r2, c2;

    printf("=== Matrix Operations ===\n");

    do {
        printf("\n1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Transpose\n");
        printf("4. Exit\n");
        choice = readInt("Enter your choice (1-4): ", 1, 4);

        switch (choice) {
            case 1:
                r1 = readInt("Rows (1-10): ", 1, MAX);
                c1 = readInt("Columns (1-10): ", 1, MAX);
                readMatrix(a, r1, c1, 'A');
                readMatrix(b, r1, c1, 'B');
                addMatrices(a, b, result, r1, c1);
                printf("\nA + B =\n");
                printMatrix(result, r1, c1);
                break;

            case 2:
                r1 = readInt("Rows of A (1-10): ", 1, MAX);
                c1 = readInt("Columns of A (1-10): ", 1, MAX);
                r2 = c1; /* must match for multiplication */
                printf("Matrix B must have %d rows.\n", r2);
                c2 = readInt("Columns of B (1-10): ", 1, MAX);
                readMatrix(a, r1, c1, 'A');
                readMatrix(b, r2, c2, 'B');
                multiplyMatrices(a, b, result, r1, c1, c2);
                printf("\nA x B =\n");
                printMatrix(result, r1, c2);
                break;

            case 3:
                r1 = readInt("Rows (1-10): ", 1, MAX);
                c1 = readInt("Columns (1-10): ", 1, MAX);
                readMatrix(a, r1, c1, 'A');
                transposeMatrix(a, result, r1, c1);
                printf("\nTranspose of A =\n");
                printMatrix(result, c1, r1);
                break;

            case 4:
                printf("Goodbye!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
