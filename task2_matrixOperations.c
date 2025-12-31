#include <stdio.h>

void inputMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void displayMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int r, int c) {
    int i, j, sum[10][10];
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    displayMatrix(sum, r, c);
}

void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int i, j, k, mul[10][10];
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for (k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    displayMatrix(mul, r1, c2);
}

void transposeMatrix(int a[10][10], int r, int c) {
    int i, j, t[10][10];
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }
    displayMatrix(t, c, r);
}

int main() {
    int a[10][10], b[10][10];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(a, r1, c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(b, r2, c2);

    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose of First Matrix\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (r1 == r2 && c1 == c2)
                addMatrix(a, b, r1, c1);
            else
                printf("Addition not possible\n");
            break;

        case 2:
            if (c1 == r2)
                multiplyMatrix(a, b, r1, c1, c2);
            else
                printf("Multiplication not possible\n");
            break;

        case 3:
            transposeMatrix(a, r1, c1);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
