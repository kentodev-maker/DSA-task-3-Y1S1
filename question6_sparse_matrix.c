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
    Term sparse[MAX_TERMS + 1];
    int rows;
    int columns;
    int term_count = 0;
    int row;
    int column;
    int index;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &columns);
    if (rows < 1 || rows > MAX_ROWS || columns < 1 || columns > MAX_COLUMNS) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (row = 0; row < rows; row++) {
        for (column = 0; column < columns; column++) {
            scanf("%d", &matrix[row][column]);
            if (matrix[row][column] != 0) {
                term_count++;
                sparse[term_count].row = row;
                sparse[term_count].column = column;
                sparse[term_count].value = matrix[row][column];
            }
        }
    }

    sparse[0].row = rows;
    sparse[0].column = columns;
    sparse[0].value = term_count;

    printf("\nTriplet representation (row column value):\n");
    for (index = 0; index <= term_count; index++) {
        printf("%d %d %d\n", sparse[index].row, sparse[index].column,
               sparse[index].value);
    }

    return 0;
}
