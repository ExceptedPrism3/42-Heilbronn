/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:24:10 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 02:52:38 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned char c)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex_digits[c / 16], 1);
	write(1, &hex_digits[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			ft_print_hex((unsigned char)str[i]);
		}
		i++;
	}
}
