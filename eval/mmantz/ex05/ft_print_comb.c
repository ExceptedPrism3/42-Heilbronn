/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:09:40 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:36:54 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	printing(char i_first, char i_second, char i_third);

int	main(void)
{
	ft_print_comb();
	return (0);
}

void	ft_print_comb(void)
{
	char	i_first;
	char	i_second;
	char	i_third;

	i_first = '0' - 1;
	i_second = '0';
	i_third = '0';
	while (++i_first <= '7')
	{
		i_second = i_first;
		while (i_second++ <= '8')
		{
			i_third = i_second;
			while (++i_third <= '9')
			{
				printing(i_first, i_second, i_third);
			}
		}
	}
}

void	printing(char i_first, char i_second, char i_third)
{
	char	c_komler;

	write(1, &i_first, 1);
	write(1, &i_second, 1);
	write(1, &i_third, 1);
	if (!(i_first == '7' && i_second == '8' && i_third == '9'))
	{
		c_komler = ',';
		write(1, &c_komler, 1);
		c_komler = ' ';
		write(1, &c_komler, 1);
	}
}
