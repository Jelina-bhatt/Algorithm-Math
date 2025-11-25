#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x,y) (2*(x) + (y))

int main()
{
    float x0, y0, xp, h;
    float x, y;
    float k1, k2, k3, k4;

    printf("Enter initial values of x and y:\n");
    scanf("%f %f", &x0, &y0);

    printf("Enter x at which function is to be evaluated:\n");
    scanf("%f", &xp);

    printf("Enter the step size:\n");
    scanf("%f", &h);

    x = x0;
    y = y0;

    while (x < xp)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + 0.5*h, y + 0.5*k1);
        k3 = h * f(x + 0.5*h, y + 0.5*k2);
        k4 = h * f(x + h,     y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x = x + h;
    }

    printf("Function value at x = %f is %f\n", xp, y);

    getch();
    return 0;
}
