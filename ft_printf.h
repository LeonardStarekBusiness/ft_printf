/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:40:00 by lstarek           #+#    #+#             */
/*   Updated: 2025/11/04 14:40:02 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef long unsigned int t_lui;

int	ft_printf(const char *s, ...);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putptr(void *ptr);
int	ft_put_low_hex(t_lui address);
int	ft_put_upper_hex(t_lui address);
int	ft_putuint(unsigned int n);
