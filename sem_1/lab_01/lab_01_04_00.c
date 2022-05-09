#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
	int pennies;
	int bottles;

	printf("Enter number of pennies:\n");
	scanf("%d", &pennies);
	bottles = (pennies - 20) / 25;
	printf("Number of bottles: %d\n", bottles);
	return EXIT_SUCCESS;
}
