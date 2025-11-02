/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:57:09 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/02 22:34:02 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Helper function: handles secondary format specifiers
** %c -> character
** %x / %X -> hexadecimal (lower/upper)
** %u -> unsigned int
** %p -> pointer (calls ft_putptr)
** %% -> percent sign
*/
static int	format2(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_x(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'u')
		return (ft_putnbr_x(va_arg(args, unsigned int), 'u'));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return (0);
}

/*
** Helper function: handles main format specifiers
** %d / %i -> integer
** %s -> string
** forwards all other specifiers to format2()

  return (ft_putstr_fd("(null)", 1)); // handle null strings

*/
static int	format(va_list args, const char format)
{
	char	*str;

	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (ft_putstr_fd("(null)", 1));
		else
			return (ft_putstr_fd(str, 1));
	}
	else
		return (format2(args, format));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] && ft_strchr("%dcsuixpX", s[i + 1]) != NULL)
		{
			count += format(args, s[i + 1]);
			i++;
		}
		else if (s[i] == '%' && s[i + 1] == '\0')
			break ;
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
