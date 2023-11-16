#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
	va_list ap; // pointer that points to the first argument - string format
	int count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		/* code */
	}
	
}




int main()
{
	int count;

	count = my_printf("Hello %s/n", "Antoan");
	my_printf("The chars written are %d/n", count);
}