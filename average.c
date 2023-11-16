#include <stdio.h>
#include <stdarg.h>

float average(int num, ...)
{
	int total_args;
	va_list ap;

	total_args = 0;
	va_start(ap, num);
	for (int i = 0; i < num; i++)
	{
		total_args += va_arg(ap, int);
	}
	va_end(ap);
	return ((float)total_args / num);
}

int main()
{
	printf("The average value is %.2f\n",
			average(5, 				12, 33, 24, 72, 11));
			printf("Hello %s, today is %d!\n", "Antoan", 20);
			// Prototype
			int printf(const char *, ...);
}