/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_print_nbr.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 20:00:00 by aben-cad         ###   ########.fr       */
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

int	ft_print_nbr(t_format f, va_list args)
{
	long	n;
	int		len;
	int		pad_len;

	if (f.spec == 'u')
		n = va_arg(args, unsigned int);
	else
		n = va_arg(args, int);
	len = ft_nbr_len(n);
	if (n == 0 && f.dot && f.prec == 0) // Case: %.0d with 0 prints nothing
		len = 0;
	if (n < 0 || (f.plus || f.space)) // Add space for sign
		if (f.spec != 'u')
			f.width--;
	if (f.prec > len)
		pad_len = f.prec;
	else
		pad_len = len;
	// Logic: If precision exists, '0' flag is ignored
	if (f.dot)
		f.zero = 0;
	
	int count = 0;
	// 1. Left Padding (if not minus)
	if (!f.minus)
		count += ft_pad(f.width, pad_len, f.zero);
	// 2. Sign
	if (n < 0 && f.spec != 'u')
		count += ft_putchar_fd('-', 1);
	else if (f.plus && f.spec != 'u')
		count += ft_putchar_fd('+', 1);
	else if (f.space && f.spec != 'u')
		count += ft_putchar_fd(' ', 1);
	// 3. Precision Zeros
	count += ft_pad(f.prec, len, 1);
	// 4. Number
	if (!(n == 0 && f.dot && f.prec == 0))
		ft_put_abs(n);
	count += len;
	// 5. Right Padding (if minus)
	if (f.minus)
		count += ft_pad(f.width, pad_len, 0);
	return (count);
}