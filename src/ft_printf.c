/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:46:43 by aantonie          #+#    #+#             */
/*   Updated: 2024/02/09 15:53:05 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar_fd(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		length += ft_putnbr_fd(va_arg(args, int));
	else if (format == 's')
		length += ft_putstr_fd(va_arg(args, char *));
	else if (format == 'p')
		length += ft_print_unsigned(va_arg(args, unsigned long long));
	else if (format == 'x' || format == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		length += ft_print_ptr(va_arg(args, unsigned int));
	else if (format == '%')
        length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *form_str, ...)
{
	va_list ap;

	va_start(ap, form_str);

	int i;
	i = 0;

	int format_len;
	format_len = 0;

	while (form_str[i] != '\0')
	{
		if (i == '%')
		{
			format_len += ft_formats(ap, form_str[i + 1]);
			i++;
		}
	}

	//  Why use i + 1?
		-> to check the character following the '%' character in the format string
	while (form_str[i] != '\0')
	{
		if (i == '%')
		{
			format_len += ft_formats(ap, form_str[i + 1]);
			i++;
		}
		else
			format_len = +ft_putchar(form_str[i]);
		i++;
	}
	va_end(ap);
	return (format_len);
}