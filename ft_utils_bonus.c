/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:45:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/08 14:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_padding(int len, int is_zero)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		if (is_zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
		len--;
	}
	return (count);
}

int	ft_get_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned long long n, int is_upper)
{
	char	*base;
	int		count;

	count = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, is_upper);
	count += ft_putchar_fd(base[n % 16], 1);
	return (count);
}

int	ft_calc_spaces(t_flags flags, int len)
{
	if (flags.zero && flags.precision == -1 && !flags.left)
		return (0);
	if (flags.width > len)
		return (flags.width - len);
	return (0);
}

int	ft_calc_w_z(t_flags flags, int len)
{
	if (flags.zero && flags.precision == -1 && !flags.left && flags.width > len)
		return (flags.width - len);
	return (0);
}
