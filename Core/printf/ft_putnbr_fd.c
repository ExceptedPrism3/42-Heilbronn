/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:40:13 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/02 21:35:58 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count = count + ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		count = count + ft_putnbr_fd(num / 10, fd);
	count = count + ft_putchar_fd((num % 10) + '0', fd);
	return (count);
}
