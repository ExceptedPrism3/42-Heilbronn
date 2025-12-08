/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:08:33 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/02 21:46:45 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	count = 0;
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	addr = (unsigned long long)ptr;
	count += ft_putstr_fd("0x", 1);
	count += ft_putnbr_x(addr, 'x');
	return (count);
}
