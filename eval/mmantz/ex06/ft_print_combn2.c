/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:22 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:42:01 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn2(void);
void	printint(int i, int b);

int	main(void)
{
	ft_print_combn2();
}

void	ft_print_combn2(void)
{
	int	i_firstdigits;
	int	i_sekonddigit;

	i_firstdigits = -1;
	i_sekonddigit = 0;
	while (i_firstdigits++ < 99)
	{
		while (i_sekonddigit < 99)
		{
			i_sekonddigit++;
			printint(i_firstdigits, i_sekonddigit);
		}
		i_sekonddigit = i_firstdigits + 1;
	}
}

void	printint(int i, int b)
{
	char	printabil;

	printabil = (i / 10) + 48;
	write(1, &printabil, 1);
	printabil = i % 10 + 48;
	write(1, &printabil, 1);
	printabil = ' ';
	write(1, &printabil, 1);
	printabil = b / 10 + 48;
	write(1, &printabil, 1);
	printabil = b % 10 + 48;
	write(1, &printabil, 1);
	if (i + b < 197)
	{
		printabil = ',';
		write(1, &printabil, 1);
		printabil = ' ';
		write(1, &printabil, 1);
	}
}
