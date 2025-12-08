/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_printf_utils.c                                  :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 20:00:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* ** The master padder:
** Prints 'width - len' characters. 
** Uses '0' if zero-flag is ON, otherwise spaces.
*/
int	ft_pad(int width, int len, int zero)
{
	int	count;

	count = 0;
	while (len < width)
	{
		if (zero)
			count += ft_putchar_fd('0', 1);
		else
			count += ft_putchar_fd(' ', 1);
		len++;
	}
	return (count);
}