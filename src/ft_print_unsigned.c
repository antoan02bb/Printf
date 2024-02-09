/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:46:56 by aantonie          #+#    #+#             */
/*   Updated: 2024/02/09 15:53:12 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_unsigned_length(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		length++;
		num = num / 10;
	}
	return (length);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		length;

	length = ft_unsigned_length(n);
	num = (char *)malloc(sizeof(char) * (length + 1));
	while (num[length] != '\0')
	{
		num[length] = n % 10 + 48;
		n = n / 10;
		length--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*num;
	int		length;

	length = 0;
	if (num == 0)
		length = length + (write(1, "0", 1));
	else
	{
		num = ft_uitoa(n);
		length += ft_printstr(num);
		free(num);
	}
	return (length);
}
