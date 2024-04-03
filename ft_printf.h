/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:32:38 by aantonie          #+#    #+#             */
/*   Updated: 2024/02/15 14:15:00 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char *format);
int		ft_printf_utils(void);

// print hex
int		ft_hex_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_print_hex(unsigned int num, const char format);

// print ptr
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_print_ptr(unsigned long long ptr);

// print uns
int		ft_unsigned_length(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
// int	ft_putunisugned_fd(int n, int fd);

// print utils
void	ft_putstr_fd(char *s);
int		ft_printpercent(void);
int		ft_printstr(char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(long n, int fd);

#endif