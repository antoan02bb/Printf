/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:46:51 by aantonie          #+#    #+#             */
/*   Updated: 2024/02/15 13:00:03 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		length++;
		num = num / 16;
	}
	return (length);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length = print_length + write(1, "0x", 2);
	if (ptr == 0)
	{
		print_length += write(1, "0", 1);
	}
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}

// int main() {

// 	unsigned long long num = 200;

// 	ft_print_ptr(num);

// 	return (0);
// }

// Standard convention in C programming
// - when printing the hexadecimal representation of a pointer, such as 0,
//	the output should start with "0x" followed by the hexadecimal digits