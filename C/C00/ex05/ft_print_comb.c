/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 04:38:56 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/05 03:04:27 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** This helper function prints the three digits and the separator ", ",
** unless it is the final combination "789".
*/
void	ft_print_digits(char d1, char d2, char d3)
{
	write(1, &d1, 1);
	write(1, &d2, 1);
	write(1, &d3, 1);
	if (d1 != '7' || d2 != '8' || d3 != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	d1;
	char	d2;
	char	d3;

	d1 = '0';
	while (d1 <= '7')
	{
		d2 = d1 + 1;
		while (d2 <= '8')
		{
			d3 = d2 + 1;
			while (d3 <= '9')
			{
				ft_print_digits(d1, d2, d3);
				d3++;
			}
			d2++;
		}
		d1++;
	}
}
