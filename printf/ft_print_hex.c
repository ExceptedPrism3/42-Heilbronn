/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_print_hex.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 21:15:00 by aben-cad         ###   ########.fr       */
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

static void	ft_puthex(unsigned long long n, char spec)
{
	char	*base;

	if (spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16, spec);
	ft_putchar_fd(base[n % 16], 1);
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
	if (f.prec < len) f.prec = len;

	count = 0;
	if (!f.minus) count += ft_pad(f.width, f.prec, f.zero);
	if (f.hash && n != 0)
	{
		if (f.spec == 'X') count += ft_putstr_fd("0X", 1);
		else count += ft_putstr_fd("0x", 1);
	}
	count += ft_pad(f.prec, len, 1);
	if (!(n == 0 && f.dot && f.prec == 0)) ft_puthex(n, f.spec);
	if (f.minus) count += ft_pad(f.width, f.prec, 0);
	return (count);
}

/* ** Fix for Pointers: 
** If NULL, print "(nil)" but respect width.
** If Valid, print "0x" + hex.
*/
int	ft_print_ptr(t_format f, va_list args)
{
	unsigned long long	p;
	int					len;
	int					count;

	p = (unsigned long long)va_arg(args, void *);
	if (!p)
	{
		f.spec = 's';
		return (ft_print_str(f, args)); // Redirect to string handler
	}
	len = ft_hex_len(p) + 2;
	count = 0;
	if (!f.minus)
		count += ft_pad(f.width, len, 0);
	count += ft_putstr_fd("0x", 1);
	ft_puthex(p, 'x');
	if (f.minus)
		count += ft_pad(f.width, len, 0);
	return (count);
}