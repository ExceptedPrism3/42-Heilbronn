/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:59:23 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:39:30 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	intoverflow(int s);

int	main(void)
{
	int	nb;

	nb = 0;
	ft_putnbr(nb);
}

void	ft_putnbr(int nb)
{
	char	c_output;
	int		i_space;
	int		icont;

	c_output = '!';
	icont = 1000000000;
	intoverflow(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (icont > 0)
	{
		i_space = nb / icont;
		nb = (nb % icont);
		icont = icont / 10;
		if (i_space > 0 || c_output != '!')
		{
			c_output = (char)(i_space + 48);
			write(1, &c_output, 1);
		}
	}
}

void	intoverflow(int s)
{
	if (s == -2147483648)
	{
		write(1, "2147483648", 10);
	}
	if (s == 0)
	{
		write(1, "0", 1);
	}
}
