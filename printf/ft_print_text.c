/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_print_text.c                                    :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 20:00:00 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 21:15:00 by aben-cad         ###   ########.fr       */
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

int	ft_print_str(t_format f, va_list args)
{
	char	*s;
	int		len;
	int		count;
	int		i;

	if (f.spec == 's')
		s = va_arg(args, char *);
	else
		s = "(nil)"; // Handling redirect from ptr
	
	if (!s)
		s = "(null)";
	
	len = ft_strlen(s);
	if (f.dot && f.prec < len)
		len = f.prec;
	
	count = 0;
	if (!f.minus)
		count += ft_pad(f.width, len, 0); // Strings ignore zero flag generally
	i = 0;
	while (i < len)
		ft_putchar_fd(s[i++], 1);
	count += len;
	if (f.minus)
		count += ft_pad(f.width, len, 0);
	return (count);
}