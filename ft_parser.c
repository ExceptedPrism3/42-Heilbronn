/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:40:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/08 12:40:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in(int c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static const char	*parse_precision(const char *format, t_flags *flags)
{
	int	prec;

	prec = 0;
	if (*format == '.')
	{
		format++;
		while (*format >= '0' && *format <= '9')
		{
			prec = prec * 10 + (*format - '0');
			format++;
		}
		flags->precision = prec;
	}
	else
		flags->precision = -1;
	return (format);
}

const char	*ft_parse_flags(const char *format, t_flags *flags)
{
	while (ft_is_in(*format, "-0# +"))
	{
		if (*format == '-')
			flags->left = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (*format == '#')
			flags->hash = 1;
		else if (*format == ' ')
			flags->space = 1;
		else if (*format == '+')
			flags->plus = 1;
		format++;
	}
	while (*format >= '0' && *format <= '9')
	{
		flags->width = flags->width * 10 + (*format - '0');
		format++;
	}
	format = parse_precision(format, flags);
	flags->spec = *format;
	return (format);
}

int	ft_unsigned_len(unsigned int n, t_flags flags)
{
	int				digits;
	unsigned int	temp;

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

int	ft_hex_prefix_len(t_flags flags, unsigned long long n, int is_ptr)
{
	if (is_ptr)
		return (2);
	if (flags.hash && n != 0)
		return (2);
	return (0);
}
