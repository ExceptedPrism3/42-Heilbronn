/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_printf.c                                        :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/10/28 19:57:09 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/09 16:00:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(t_format f, va_list args)
{
	if (f.spec == 'c')
		return (ft_print_char(f, args));
	if (f.spec == 's')
		return (ft_print_str(f, args));
	if (f.spec == 'd' || f.spec == 'i' || f.spec == 'u')
		return (ft_print_nbr(f, args));
	if (f.spec == 'x' || f.spec == 'X')
		return (ft_print_hex(f, args));
	if (f.spec == 'p')
		return (ft_print_ptr(f, args));
	if (f.spec == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

static void	ft_parse_flags(const char **s, t_format *f)
{
	while (**s && (**s == '-' || **s == '+' || **s == ' '
			|| **s == '#' || **s == '0'))
	{
		if (**s == '-')
			f->minus = 1;
		else if (**s == '+')
			f->plus = 1;
		else if (**s == ' ')
			f->space = 1;
		else if (**s == '#')
			f->hash = 1;
		else if (**s == '0')
			f->zero = 1;
		(*s)++;
	}
}

const char	*ft_parse_format(const char *s, t_format *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->dot = 0;
	f->width = 0;
	f->prec = 0;
	f->spec = 0;
	ft_parse_flags(&s, f);
	while (ft_isdigit(*s))
		f->width = (f->width * 10) + (*s++ - '0');
	if (*s == '.')
	{
		f->dot = 1;
		s++;
		while (ft_isdigit(*s))
			f->prec = (f->prec * 10) + (*s++ - '0');
	}
	f->spec = *s;
	return (s);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_format	f;
	int			count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			s = ft_parse_format(s, &f);
			if (f.spec)
				count += ft_dispatch(f, args);
		}
		else
			count += ft_putchar_fd(*s, 1);
		if (*s)
			s++;
	}
	va_end(args);
	return (count);
}