#include "functions.h"
#include <stdio.h>

double explicit_euler(double (*f)(double, double, double), double t, double y, double alpha, double beta, char v)
{
    int n = alpha / beta;

    if (v)
    {
        printf("%12s%12s%12s", "STEP (k)", "t_k", "y_k");
        printf("%12d%12f%12f", 0, t, y);
    }

    for (int k = 0; k < n; k++)
    {
        if (v)
        {
            printf("%12d%12f%12f", k, t, y);
        }
        y += f(y, alpha, beta) * beta;
        t += beta;
    }

    return y;
}