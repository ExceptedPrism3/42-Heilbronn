/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:47:35 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/02 22:50:40 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_parse_flags(const char *s, t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			flags->minus = 1;
		else if (s[i] == '0' && !flags->width && !flags->dot)
			flags->zero = 1;
		else if (s[i] == '+')
			flags->plus = 1;
		else if (s[i] == ' ')
			flags->space = 1;
		else if (s[i] == '#')
			flags->hash = 1;
		else if (is_digit(s[i]) && !flags->dot)
			flags->width = (flags->width * 10) + (s[i] - '0');
		else if (s[i] == '.')
		{
			flags->dot = 1;
			i++;
			while (is_digit(s[i]))
				flags->precision = (flags->precision * 10) + (s[i++] - '0');
			i--;
		}
		else
			break ;
		i++;
	}
	return (i);
}
