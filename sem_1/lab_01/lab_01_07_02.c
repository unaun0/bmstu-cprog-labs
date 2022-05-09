#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPS 1e-7

double tailor_asin(double x, double eps)
{
    double s = 0;
    double m;
    double a = x;
    double sq_x = x * x;
    int i = 2;
    while (fabs(a) > eps)
    {
        s += a;
        m = sq_x * (1.0 + 1.0 / i - 4.0 / (i + 1.0));
        i += 2;
        a *= m;
    }
    return s;
}

int main(void)
{
    double x;
    double eps;
    double function_1;
    double function_2;
    double absolute_err, relative_err;
    printf("Enter the x: ");
    if (scanf("%lf", &x) != 1)
        return EXIT_FAILURE;
    printf("Enter the eps: ");
    if (scanf("%lf", &eps) != 1)
        return EXIT_FAILURE;
    if (fabs(x) > 1)
        return EXIT_FAILURE;
    if ((eps > 1) || (eps < EPS))
        return EXIT_FAILURE;
   
    function_1 = asin(x);
    function_2 = tailor_asin(x, eps);
    absolute_err = fabs(function_1 - function_2);
    if (fabs(function_1) < EPS)
        relative_err = 0;
    else
        relative_err = absolute_err / fabs(function_1);
    
    printf("Approximate sum value: %.6lf\n", function_2);
    printf("Function value: %.6lf\n", function_1);
    printf("Absolute error: %.6lf\n", absolute_err);
    printf("Relative error: %.6lf\n", relative_err);

    return EXIT_SUCCESS;
}

