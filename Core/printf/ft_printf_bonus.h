/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 02:10:23 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/02 22:50:16 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
	int width;     // e.g. %5d
	int precision; // e.g. %.3d or %.5s
	int minus;     // '-' -> left align
	int zero;      // '0' -> pad with zeros
	int dot;       // '.' -> precision is active
	int plus;      // '+' -> show + sign for positives
	int space;     // ' ' -> add space before positive numbers
	int hash;      // '#' -> 0x or 0X prefix for hex
*/
typedef struct s_flags
{
	int	width;
	int	precision;
	int	minus;
	int	zero;
	int	dot;
	int	plus;
	int	space;
	int	hash;
}		t_flags;

// Main functions
int		ft_printf(const char *s, ...);
int		ft_parse_flags(const char *s, t_flags *flags, va_list args);

// Utils (from your old version)
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_x(unsigned long long nbr, char c);
int		ft_putptr(void *ptr);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
