/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmantz <mmantz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:38:24 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 14:36:57 by mmantz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
int		shutbeprinted(int num, int n);
int		tentothepowerof(int n);
void	ft_putnbr(int nb, int icont, int nb2, int ocont);

int	main(void)
{
	ft_print_combn(6);
}

void	ft_print_combn(int n)
{
	int	z;
	int	conter;
	int	ok;
	int	number;

	conter = n;
	number = 0;
	ok = n + 1;
	while (conter--)
	{
		number += ((10 - (conter + 1)) * tentothepowerof(conter));
	}
	while (conter < number)
	{
		conter++;
		ok = shutbeprinted(conter, n);
		if (ok == 0)
		{
			z = tentothepowerof(n - 1);
			ft_putnbr(conter, z, number, conter);
		}
	}
}

int	shutbeprinted(int num, int n)
{
	int	zwischenspeicher;
	int	zw2;
	int	ret;

	ret = 0;
	zwischenspeicher = (-1);
	while (n > 0)
	{
		n--;
		zw2 = (num / tentothepowerof(n) % 10);
		if (zwischenspeicher >= zw2)
		{
			ret = 1;
		}
		zwischenspeicher = zw2;
		if (zwischenspeicher == -1)
		{
			zwischenspeicher = 0;
		}
	}
	return (ret);
}

int	tentothepowerof(int n)
{
	int	res;

	res = 1;
	while (n-- > 0)
		res *= 10;
	return (res);
}

void	ft_putnbr(int nb, int icont, int nb2, int ocont)
{
	char	c_output;
	int		i_space;

	while (icont > 0)
	{
		i_space = nb / icont;
		nb = (nb % icont);
		icont = icont / 10;
		if (i_space >= 0)
		{
			c_output = (char)(i_space + 48);
			write(1, &c_output, 1);
		}
	}
	if (nb2 != ocont)
	{
		c_output = ',';
		write(1, &c_output, 1);
		c_output = ' ';
		write(1, &c_output, 1);
	}
}
