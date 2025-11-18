#include <stdio.h>

int main() {
    float x[20], y[20][20], X, h, u, sum;
    int n, i, j;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    // Create forward difference table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    printf("Enter value of X to interpolate: ");
    scanf("%f", &X);

    // Calculate u
    h = x[1] - x[0];
    u = (X - x[0]) / h;

    // Calculate interpolated value
    sum = y[0][0];
    float term = 1;

    for (j = 1; j < n; j++) {
        term = term * (u - (j - 1)) / j;
        sum = sum + term * y[0][j];
    }

    printf("\nInterpolated value at X = %.3f is %.5f\n", X, sum);

    return 0;
}
