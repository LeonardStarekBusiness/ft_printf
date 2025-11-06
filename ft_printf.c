/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:14:22 by lstarek           #+#    #+#             */
/*   Updated: 2025/11/04 14:38:56 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	substitute(char c, va_list args)
{
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_put_low_hex(va_arg(args, t_lui)));
	else if (c == 'X')
		return (ft_put_upper_hex(va_arg(args, t_lui)));
	if (c == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	else
		return (0);
	/*
	%i
	%u (unsigned int)
	%x (low hex)
	%X (upper hex) */
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	size_t		bytes_printed;

	bytes_printed = 0;
	va_start(args, s);
	while (*s != 0)
	{
		if (*s != '%')
			bytes_printed += write(1, s, 1);
		else if (*(s+1) == '%')
		{
			bytes_printed += write(1, "%", 1);
			s++;
		}
		else
		{
			s++;
			bytes_printed += substitute(s[0], args);
		}
		s++;
	}
	va_end(args);
	return (bytes_printed);
}

/*
#include <stdio.h>
int main(void){
int x = ft_printf("one: %u two: %% three: %d%s ptr: %p  %X,%x\n", -42, 33333, "hihuha", (char *)"hi", 420, 420);
int y = printf("one: %u two: %% three: %d%s ptr: %p  %X,%x\n", -42, 33333, "hihuha", (char *)"hi", 420, 420);
printf("%d ?= %d \n", x, y);
} */
