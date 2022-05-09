#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPS 0.0000001

int main(void)
{
    double ax, ay;
    double bx, by;
    double cx, cy;
    double dx, dy;
    double a, b, c;
    
    printf("Enter the coordinates (x, y) of vertex A(separated by a space): ");
    if (scanf("%lf%lf", &ax, &ay) != 2)
    {
        printf("Error: vertex A coordinates are the numbers.\n");
        return EXIT_FAILURE;
    }
    printf("Enter the coordinates (x, y) of vertex B(separated by a space): ");
    if (scanf("%lf%lf", &bx, &by) != 2)
    {
        printf("Error: vertex B coordinates are the numbers\n");
        return EXIT_FAILURE;
    }
    printf("Enter the coordinates (x, y) of vertex C(separated by a space): ");
    if (scanf("%lf%lf", &cx, &cy) != 2)
    {
        printf("Error: vertex C coordinates are the numbers\n");
        return EXIT_FAILURE;
    }
    printf("Enter the coordinates (x, y) of point D(separated by a space): ");
    if (scanf("%lf%lf", &dx, &dy) != 2)
    {
        printf("Error: point D coordinates are the numbers\n");
        return EXIT_FAILURE;
    }
    if (fabs((cx - ax) * (by - ay) - (bx - ax) * (cy - ay)) < EPS)
    {
        printf("Triangle does not exist.\n");
        return EXIT_FAILURE;
    }
    a = (ax - dx) * (by - ay) - (bx - ax) * (ay - dy);
    b = (bx - dx) * (cy - by) - (cx - bx) * (by - dy);
    c = (cx - dx) * (ay - cy) - (ax - cx) * (cy - dy);
    printf("Type: ");
    if (a > 0.0)
    {
        if (b >= 0.0 && c >= 0.0)
        {
            if (b < EPS || c < EPS)
                printf("1\n");
            else
                printf("0\n");
        }
        else
            printf("2\n");
    }
    else
    {
        if (a < 0.0)
        {
            if (b <= 0.0 && c <= 0.0)
            {
                if (fabs(b) < EPS || fabs(c) < EPS)
                    printf("1\n");
                else
                    printf("0\n");
            }
            else
                printf("2\n");
        }
        else
        {
            if ((b >= 0.0 && c >= 0.0) || (b <= 0.0 && c <= 0.0))
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return EXIT_SUCCESS;
}
