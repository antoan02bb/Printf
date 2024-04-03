/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:27:01 by aantonie          #+#    #+#             */
/*   Updated: 2024/02/15 14:30:14 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s)
{
	if (!s)
		write(1, "null", 6);
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(long n, int fd)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		length++;
	}
	if (n >= 10)
	{
		length += ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((char)(n % 10 + '0'), fd);
	length++;
	return (length);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
