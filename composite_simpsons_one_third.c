#include <stdio.h>
#include <math.h>

#define f(x) (1.0f / (1 + (x)))    // safer macro

int main() 
{ 
    float a, h, x0, xn, fx0, fxn, v, term; 
    int k, i;

    printf("Enter lower and upper limit:\n"); 
    scanf("%f %f", &x0, &xn); 

    printf("Enter number of segments (must be even):\n"); 
    scanf("%d", &k); 

    if (k % 2 != 0) {
        printf("Error: Number of segments must be EVEN for Simpson 1/3 rule.\n");
        return 0;
    }

    h = (xn - x0) / k; 
    printf("h = %f\n", h); 

    fx0 = f(x0); 
    fxn = f(xn); 
    term = fx0 + fxn; 

    // sum of odd terms
    for (i = 1; i <= k - 1; i += 2) {
        a = x0 + i * h; 
        term = term + 4 * f(a); 
    }  

    // sum of even terms
    for (i = 2; i <= k - 2; i += 2) { 
        a = x0 + i * h; 
        term = term + 2 * f(a); 
    } 

    v = (h / 3) * term; 

    printf("Value of integration = %f\n", v);  

    return 0; 
}
