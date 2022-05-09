#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
	double height, chest, weight;
	double normal;
	double bmi;

	printf("Enter the height:\n");
	scanf("%lf", &height);
	printf("Enter the chest:\n");
	scanf("%lf", &chest);
	printf("Enter the weight:\n");
	scanf("%lf", &weight);
	normal = (height * chest) / 240;
	bmi = weight / ((height / 100) * (height / 100));
	printf("Normal body weight: %0.6lf\n", normal);
	printf("BMI: %0.6lf\n", bmi);
	return EXIT_SUCCESS;
}
