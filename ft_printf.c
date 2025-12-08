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

int	ft_print_format(t_flags flags, va_list *args)
{
	int	count;

	count = 0;
	if (flags.spec == 'c' || flags.spec == 's')
		count = ft_print_cs_dispatch(flags, args);
	else if (flags.spec == 'd' || flags.spec == 'i')
		count = ft_print_id_dispatch(flags, args);
	else if (flags.spec == 'u' || flags.spec == 'x' || flags.spec == 'X'
		|| flags.spec == 'p')
		count = ft_print_ux_dispatch(flags, args);
	else if (flags.spec == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

static void	ft_init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->left = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

static const char	*handle_specifier(const char *s, int *count, va_list *args)
{
	t_flags	flags;

	s++;
	ft_init_flags(&flags);
	s = ft_parse_flags(s, &flags);
	if (flags.spec)
	{
		*count += ft_print_format(flags, args);
		s++;
	}
	return (s);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
			s = handle_specifier(s, &count, &args);
		else
		{
			count += ft_putchar_fd(*s, 1);
			s++;
		}
	}
	va_end(args);
	return (count);
}
