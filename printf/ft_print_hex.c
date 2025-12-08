/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_print_hex.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/09 11:00:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_print_nil(t_format f, int *count)
{
	const char	*s;
	int			len;

	s = "(nil)";
	len = 5;
	if (!f.minus)
		*count += ft_pad(f.width, len, 0);
	*count += ft_putstr_fd(s, 1);
	if (f.minus)
		*count += ft_pad(f.width, len, 0);
}

int	ft_print_hex(t_format f, va_list args)
{
	unsigned int	n;
	int				len;
	int				count;

	n = va_arg(args, unsigned int);
	len = ft_hex_len(n);
	if (n == 0 && f.dot && f.prec == 0)
		len = 0;
	if (f.hash && n != 0)
		f.width -= 2;
	if (f.dot)
		f.zero = 0;
	if (f.prec < len)
		f.prec = len;
	count = 0;
	if (!f.minus)
		count += ft_pad(f.width, f.prec, f.zero);
	if (f.hash && n != 0)
		count += ft_putstr_case("0x", f.spec);
	count += ft_pad(f.prec, len, 1);
	if (len > 0)
		count += ft_putnbr_base(n, f.spec);
	if (f.minus)
		count += ft_pad(f.width, f.prec, 0);
	return (count);
}

int	ft_print_ptr(t_format f, va_list args)
{
	unsigned long long	p;
	int					len;
	int					count;

	p = (unsigned long long)va_arg(args, void *);
	count = 0;
	if (!p)
	{
		ft_print_nil(f, &count);
		return (count);
	}
	len = ft_hex_len(p) + 2;
	if (!f.minus)
		count += ft_pad(f.width, len, 0);
	count += ft_putstr_fd("0x", 1);
	count += ft_putnbr_ptr(p);
	if (f.minus)
		count += ft_pad(f.width, len, 0);
	return (count);
}