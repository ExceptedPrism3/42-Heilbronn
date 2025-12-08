/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_print_text.c                                    :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/09 00:00:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format f, va_list args)
{
	char	c;
	int		count;

	c = va_arg(args, int);
	count = 0;
	if (!f.minus)
		count += ft_pad(f.width, 1, 0);
	count += ft_putchar_fd(c, 1);
	if (f.minus)
		count += ft_pad(f.width, 1, 0);
	return (count);
}

/* ** Fix for the 7 failures:
** If s is NULL:
** 1. Default to "(null)"
** 2. BUT, if precision is set (dot) and is < 6, return empty string ""
*/
static const char	*ft_get_str_safe(char *arg, t_format f)
{
	if (!arg)
	{
		if (f.dot && f.prec < 6)
			return ("");
		return ("(null)");
	}
	return (arg);
}

int	ft_print_str(t_format f, va_list args)
{
	char		*arg;
	const char	*s;
	int			len;
	int			count;
	int			i;

	arg = va_arg(args, char *);
	s = ft_get_str_safe(arg, f);
	len = ft_strlen(s);
	if (f.dot && f.prec < len)
		len = f.prec;
	count = 0;
	if (!f.minus)
		count += ft_pad(f.width, len, 0);
	i = 0;
	while (i < len)
		ft_putchar_fd((char)s[i++], 1);
	count += len;
	if (f.minus)
		count += ft_pad(f.width, len, 0);
	return (count);
}