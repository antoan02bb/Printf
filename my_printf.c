#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
	va_list ap;
	int count_args;

	va_start(ap, format);
	count_args = 0;
	while (*format != '0')
	{
		// If the pointer is equal to a percent sign
		if (*format == '%')
			printFormat(*(++format), ap);
		else
			write(1, format, 1);
		++format;
	va_end(ap);
	return count_args;
	}
}



// for (int i = 0; i < format; i++)
	// {
	// 	count_args = count_args + va_arg(ap, int);
	// }
	// va_end(ap);




int main()
{
	int count_args;

	int count_args1;

	count_args = my_printf("Hello %s\n", "Antoan");
	my_printf("The chars written are: %d\n", count_args);

	count_args1 = printf("Hello %s\n", "Antoan");
}