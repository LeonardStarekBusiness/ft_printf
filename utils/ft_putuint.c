/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:11:05 by lstarek           #+#    #+#             */
/*   Updated: 2025/10/20 18:47:48 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putuint(unsigned int n)
{
	char	*map;
	int	i;

	i = 0;
	map = "0123456789";
	if (n > 9)
	{
		i += ft_putuint(n / 10);
		i += write(1, &map[n % 10], 1);
	}
	else
	{
		i += write(1, &map[n], 1);
	}
	return (i);
}
