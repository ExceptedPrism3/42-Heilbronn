/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:23:14 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/02 22:39:16 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	spec;
	int	width;
	int	precision;
	int	left;
	int	zero;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

size_t			ft_strlen(const char *s);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putnbr_x(unsigned long long nbr, char c);
int				ft_putptr(void *ptr);
char			*ft_strchr(const char *s, int c);
int				ft_printf(const char *s, ...);

/* Bonus Functions */
const char		*ft_parse_flags(const char *format, t_flags *flags);
int				ft_is_in(int c, char *str);
int				ft_print_format(t_flags flags, va_list *args);
int				ft_print_padding(int len, int is_zero);
int				ft_get_hex_len(unsigned long long n);
int				ft_puthex(unsigned long long n, int is_upper);
int				ft_putunsigned(unsigned int n);
int				ft_unsigned_len(unsigned int n, t_flags flags);
int				ft_hex_prefix_len(t_flags flags, unsigned long long n,
					int is_ptr);
int				ft_calc_spaces(t_flags flags, int len);
int				ft_calc_w_z(t_flags flags, int len);

/* Dispatchers */
int				ft_print_cs_dispatch(t_flags flags, va_list *args);
int				ft_print_id_dispatch(t_flags flags, va_list *args);
int				ft_print_ux_dispatch(t_flags flags, va_list *args);
#endif
