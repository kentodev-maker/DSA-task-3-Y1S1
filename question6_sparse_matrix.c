#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define MAX_TERMS (MAX_ROWS * MAX_COLUMNS)

typedef struct {
    int row;
    int column;
    int value;
} Term;

int main(void) {
    int matrix[MAX_ROWS][MAX_COLUMNS];
    Term sparse[MAX_TERMS];
    int rows;
    int columns;
    int term_count = 0;
    int row;
    int column;

    printf("Enter number of rows and columns (maximum 10 each): ");
    scanf("%d %d", &rows, &columns);
    if (rows < 1 || rows > MAX_ROWS || columns < 1 || columns > MAX_COLUMNS) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter the matrix values:\n");
    for (row = 0; row < rows; row++) {
        for (column = 0; column < columns; column++) {
            scanf("%d", &matrix[row][column]);
            if (matrix[row][column] != 0) {
                sparse[term_count].row = row;
                sparse[term_count].column = column;
                sparse[term_count].value = matrix[row][column];
                term_count++;
            }
        }
    }

    printf("\nTriplet representation\n");
    printf("Row Column Value\n");
    for (row = 0; row < term_count; row++) {
        printf("%3d %6d %5d\n", sparse[row].row, sparse[row].column,
               sparse[row].value);
    }
    printf("Non-zero elements: %d\n", term_count);
    return 0;
}
