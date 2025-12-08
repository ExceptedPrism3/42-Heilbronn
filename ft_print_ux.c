/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:10:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/08 15:10:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar_fd((n % 10) + '0', 1);
	return (count);
}

static int	print_hex_prefix(t_flags flags)
{
	if (flags.spec == 'X')
		ft_putstr_fd("0X", 1);
	else
		ft_putstr_fd("0x", 1);
	return (2);
}

static int	print_generic_hex(t_flags flags, unsigned long long n, int is_ptr)
{
	int	c;
	int	d;
	int	z;
	int	len;

	d = ft_get_hex_len(n);
	if (n == 0 && flags.precision == 0)
		d = 0;
	z = 0;
	if (flags.precision > d)
		z = flags.precision - d;
	len = d + z + ft_hex_prefix_len(flags, n, is_ptr);
	c = 0;
	if (!flags.left)
		c += ft_print_padding(ft_calc_spaces(flags, len), 0);
	if (is_ptr || (flags.hash && n != 0))
		c += print_hex_prefix(flags);
	c += ft_print_padding(ft_calc_w_z(flags, len), 1);
	c += ft_print_padding(z, 1);
	if (d > 0)
		c += ft_puthex(n, flags.spec == 'X');
	if (flags.left)
		c += ft_print_padding(ft_calc_spaces(flags, len), 0);
	return (c);
}

static int	print_unsigned_full(t_flags flags, unsigned int n)
{
	int	c;
	int	d;
	int	z;
	int	len;

	d = ft_unsigned_len(n, flags);
	z = 0;
	if (flags.precision > d)
		z = flags.precision - d;
	len = d + z;
	c = 0;
	if (!flags.left)
		c += ft_print_padding(ft_calc_spaces(flags, len), 0);
	c += ft_print_padding(ft_calc_w_z(flags, len), 1);
	c += ft_print_padding(z, 1);
	if (d > 0)
		c += ft_putunsigned(n);
	if (flags.left)
		c += ft_print_padding(ft_calc_spaces(flags, len), 0);
	return (c);
}

int	ft_print_ux_dispatch(t_flags flags, va_list *args)
{
	if (flags.spec == 'u')
		return (print_unsigned_full(flags, va_arg(*args, unsigned int)));
	else if (flags.spec == 'x' || flags.spec == 'X')
		return (print_generic_hex(flags, va_arg(*args, unsigned int), 0));
	else if (flags.spec == 'p')
		return (print_generic_hex(flags, (unsigned long long)va_arg(*args,
					void *), 1));
	return (0);
}
