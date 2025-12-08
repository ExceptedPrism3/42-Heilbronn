/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:50:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/08 12:50:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(t_flags flags, int c)
{
	int	count;
	int	spaces;

	count = 0;
	spaces = 0;
	if (flags.width > 1)
		spaces = flags.width - 1;
	if (!flags.left)
		count += ft_print_padding(spaces, 0);
	ft_putchar_fd(c, 1);
	count++;
	if (flags.left)
		count += ft_print_padding(spaces, 0);
	return (count);
}

static int	print_str(t_flags flags, char *s)
{
	int	count;
	int	len;
	int	spaces;

	count = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags.precision >= 0 && flags.precision < len)
		len = flags.precision;
	spaces = 0;
	if (flags.width > len)
		spaces = flags.width - len;
	if (!flags.left)
		count += ft_print_padding(spaces, 0);
	write(1, s, len);
	count += len;
	if (flags.left)
		count += ft_print_padding(spaces, 0);
	return (count);
}

int	ft_print_cs_dispatch(t_flags flags, va_list *args)
{
	if (flags.spec == 'c')
		return (print_char(flags, va_arg(*args, int)));
	else if (flags.spec == 's')
		return (print_str(flags, va_arg(*args, char *)));
	return (0);
}
