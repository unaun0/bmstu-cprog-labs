#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
	double a, b, height; 
	double perimeter;

	printf("Enter the first side 'A' of the trapezoid: ");
	scanf("%lf", &a);
	printf("Enter the second side 'B' of the trapezoid: ");
	scanf("%lf", &b);
	printf("Enter the height of the trapezoid: ");
	scanf("%lf", &height);
	if (b > a)
	{
		perimeter = sqrt((((b - a) / 2) * ((b - a) / 2)) + (height * height));
	}
	else
	{ 
		perimeter = sqrt((((a - b) / 2) * ((a - b) / 2)) + (height * height));
	}
	perimeter += perimeter;
	perimeter = perimeter + a + b;
	printf("Trapezoid perimeter: %.6lf\n", perimeter);
	return EXIT_SUCCESS;
}
