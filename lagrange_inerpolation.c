#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20], X, P = 0, Li;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    printf("Enter value of X to interpolate: ");
    scanf("%f", &X);

    for (i = 0; i < n; i++) {
        Li = 1;
        for (j = 0; j < n; j++) {
            if (j != i) {
                Li = Li * (X - x[j]) / (x[i] - x[j]);
            }
        }
        P = P + Li * y[i];
    }

    printf("\nInterpolated value at X = %.3f is: %.5f\n", X, P);

    return 0;
}
