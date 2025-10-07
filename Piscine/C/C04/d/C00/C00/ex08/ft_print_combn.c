/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altaube <altaube@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:16:13 by altaube           #+#    #+#             */
/*   Updated: 2025/08/20 17:16:26 by altaube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putdigits(int *d, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar((char)(d[i] + '0'));
		i++;
	}
}

static int	ft_is_last(int *d, int n)
{
	return (d[0] == 10 - n);
}

static void	ft_increment(int *d, int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (i >= 0 && d[i] == 9 - (n - 1 - i))
		i--;
	d[i]++;
	j = i + 1;
	while (j < n)
	{
		d[j] = d[j - 1] + 1;
		j++;
	}
}

void	ft_print_combn(int n)
{
	int	d[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		d[i] = i;
		i++;
	}
	while (1)
	{
		ft_putdigits(d, n);
		if (ft_is_last(d, n))
			break ;
		ft_putchar(',');
		ft_putchar(' ');
		ft_increment(d, n);
	}
}
