/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_printf.h                                        :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/10/27 10:23:14 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/08 20:50:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		dot;
	int		width;
	int		prec;
	int		total_len;
	char	spec;
}	t_format;

int			ft_printf(const char *s, ...);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);

/* Parsing & Utils */
/* UPDATED LINE BELOW: removed va_list args */
const char	*ft_parse_format(const char *s, t_format *f);
int			ft_isdigit(int c);
int			ft_pad(int width, int len, int zero);

/* Printers */
int			ft_print_char(t_format f, va_list args);
int			ft_print_str(t_format f, va_list args);
int			ft_print_nbr(t_format f, va_list args);
int			ft_print_hex(t_format f, va_list args);
int			ft_print_ptr(t_format f, va_list args);

#endif