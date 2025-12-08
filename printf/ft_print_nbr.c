/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_print_nbr.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 22:00:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

/* Helper to update the structure with prototype definitions */
static int	ft_num_len_base(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int	ft_putnbr_dec(unsigned long long n)
{
	int		count;
	char	buffer[25];
	int		i;

	if (n == 0)
		return (ft_putchar_fd('0', 1));
	count = 0;
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		count += ft_putchar_fd(buffer[i], 1);
	return (count);
}

static char	ft_get_sign(t_format *f, long n)
{
	if (n < 0 && f->spec != 'u')
		return ('-');
	if (f->plus && f->spec != 'u')
		return ('+');
	if (f->space && f->spec != 'u')
		return (' ');
	return (0);
}

int	ft_print_nbr(t_format f, va_list args)
{
	long				val;
	unsigned long long	n;
	int					len;
	char				sign;
	int					count;

	if (f.spec == 'u')
		val = va_arg(args, unsigned int);
	else
		val = va_arg(args, int);
	sign = ft_get_sign(&f, val);
	if (val < 0 && f.spec != 'u')
		n = -val;
	else
		n = val;
	len = ft_num_len_base(n, 10);
	if (n == 0 && f.dot && f.prec == 0)
		len = 0;
	if (f.dot)
		f.zero = 0;
	if (sign)
		f.width--;
	if (f.prec < len)
		f.prec = len;
	count = 0;
	if (!f.minus && !f.zero)
		count += ft_pad(f.width, f.prec, 0);
	if (sign)
		count += ft_putchar_fd(sign, 1);
	if (!f.minus && f.zero)
		count += ft_pad(f.width, f.prec, 1);
	count += ft_pad(f.prec, len, 1);
	if (len > 0)
		count += ft_putnbr_dec(n);
	if (f.minus)
		count += ft_pad(f.width, f.prec, 0);
	return (count);
}