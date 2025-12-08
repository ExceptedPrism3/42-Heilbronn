/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_printf_utils.c                                  :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/09 14:00:00 by aben-cad         ###   ########.fr       */
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

int	ft_putstr_case(const char *s, char spec)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (spec == 'X' && s[i] >= 'a' && s[i] <= 'z')
			ft_putchar_fd(s[i] - 32, 1);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long long n, char spec)
{
	int			count;
	const char	*base;
	char		buffer[25];
	int			i;

	if (spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	count = 0;
	i = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		count += ft_putchar_fd(buffer[i], 1);
	return (count);
}

int	ft_putnbr_ptr(unsigned long long n)
{
	int			count;
	const char	*base;
	char		buffer[25];
	int			i;

	base = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	count = 0;
	i = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		count += ft_putchar_fd(buffer[i], 1);
	return (count);
}