/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_print_nbr.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 21:15:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_put_abs(long n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_put_abs(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

static char	ft_get_sign(long n, t_format *f)
{
	if (n < 0)
	{
		if (f->spec != 'u')
			return ('-');
	}
	else if (f->plus && f->spec != 'u')
		return ('+');
	else if (f->space && f->spec != 'u')
		return (' ');
	return (0);
}

int	ft_print_nbr(t_format f, va_list args)
{
	long	n;
	int		len;
	int		count;
	char	sign;

	if (f.spec == 'u')
		n = va_arg(args, unsigned int);
	else
		n = va_arg(args, int);
	len = ft_nbr_len(n);
	if (n == 0 && f.dot && f.prec == 0)
		len = 0;
	sign = ft_get_sign(n, &f);
	if (sign)
		f.width--;
	if (f.dot)
		f.zero = 0; // Precision disables zero flag
	if (f.prec < len)
		f.prec = len;
	
	count = 0;
	// 1. If Zero flag: Sign -> Zeros -> Num
	if (f.zero)
	{
		if (sign) count += ft_putchar_fd(sign, 1);
		count += ft_pad(f.width, f.prec, 1);
		if (!(n == 0 && f.dot && f.prec == 0)) ft_put_abs(n);
	}
	// 2. Normal: Space -> Sign -> Zeros -> Num -> Space
	else
	{
		if (!f.minus) count += ft_pad(f.width, f.prec, 0);
		if (sign) count += ft_putchar_fd(sign, 1);
		count += ft_pad(f.prec, len, 1);
		if (!(n == 0 && f.dot && f.prec == 0)) ft_put_abs(n);
		if (f.minus) count += ft_pad(f.width, f.prec, 0);
	}
	return (count);
}