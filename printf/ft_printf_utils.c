/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_printf_utils.c                                  :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 21:30:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

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

/* ** Iterative number printer to prevent recursion issues.
** Handles base 10 and 16.
*/
int	ft_putnbr_base(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	base_len;
	char				buffer[25]; // Buffer to store digits reversed
	int					i;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n == 0)
		return (ft_putchar_fd(base[0], 1));
	i = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % base_len];
		n /= base_len;
	}
	while (--i >= 0)
		count += ft_putchar_fd(buffer[i], 1);
	return (count);
}