#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int     ft_printf(const char *format, ...);
int     ft_formats(va_list args, const char format);



// utils
char *ft_printstr()

// print hex
int ft_hex_len(unsigned int num);
void ft_put_hex(unsigned int num, const char format);
int ft_print_hex(unsigned int num, const char format);

// print ptr
int ft_ptr_len(uintptr_t num);
void ft_put_ptr(uintptr_t num);
int ft_print_ptr(unsigned long long ptr);

// print uns
int ft_unsigned_length(unsigned int num);
char *ft_uitoa(unsigned int n);
int ft_print_unsigned(unsigned int n);

// print percent
int ft_print_percent(void);






#endif