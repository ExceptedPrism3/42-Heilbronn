/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:47:57 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/30 22:40:48 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(unsigned long long nbr, char c)
{
	char	*base;
	int		base_len;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long long)base_len)
		count += ft_putnbr_x(nbr / base_len, c);
	count += write(1, &base[nbr % base_len], 1);
	return (count);
}
