#include<stdio.h>
#include<conio.h>

#define f(x,y) (2.0*y/x)

int main() 
{
    float x, xp, x0, y0, y, h, m1, m2;

    printf("Enter initial values of x and y:\n");
    scanf("%f%f", &x0, &y0);

    printf("Enter x at which function is to be evaluated:\n");
    scanf("%f", &xp);

    printf("Enter step size h:\n");
    scanf("%f", &h);

    x = x0;
    y = y0;

    while (x < xp)
    {
        m1 = f(x, y);
        m2 = f(x + h, y + h * m1);

        y = y + (h / 2.0) * (m1 + m2);
        x = x + h;
    }

    printf("Function value at x = %f is %f\n", xp, y);

    getch();
    return 0;
}
