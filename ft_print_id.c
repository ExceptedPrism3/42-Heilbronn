/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/08 15:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_recursive(n / 10);
	count += ft_putchar_fd((n % 10) + '0', 1);
	return (count);
}

static int	print_prefix(int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n < 0)
		count += ft_putchar_fd('-', 1);
	else if (flags.plus)
		count += ft_putchar_fd('+', 1);
	else if (flags.space)
		count += ft_putchar_fd(' ', 1);
	return (count);
}

static int	ft_int_len(long n, t_flags flags)
{
	int		digits;
	long	temp;

	if (n == 0 && flags.precision == 0)
		digits = 0;
	else if (n == 0)
		digits = 1;
	else
	{
		digits = 0;
		temp = n;
		while (temp)
		{
			temp /= 10;
			digits++;
		}
	}
	return (digits);
}

int	print_int(t_flags flags, int n)
{
	long	ln;
	int		c;
	int		d;
	int		z;
	int		ext;

	ln = n;
	if (n < 0)
		ln = -ln;
	d = ft_int_len(ln, flags);
	z = 0;
	if (flags.precision > d)
		z = flags.precision - d;
	c = 0;
	ext = (n < 0 || flags.plus || flags.space);
	if (!flags.left)
		c += ft_print_padding(ft_calc_spaces(flags, d + z + ext), 0);
	c += print_prefix(n, flags);
	c += ft_print_padding(ft_calc_w_z(flags, d + z + ext), 1);
	c += ft_print_padding(z, 1);
	if (d > 0)
		c += ft_putnbr_recursive(ln);
	if (flags.left)
		c += ft_print_padding(ft_calc_spaces(flags, d + z + ext), 0);
	return (c);
}

int	ft_print_id_dispatch(t_flags flags, va_list *args)
{
	return (print_int(flags, va_arg(*args, int)));
}
