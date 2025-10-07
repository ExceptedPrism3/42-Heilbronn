/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:05:26 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/14 16:07:07 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** This new helper function checks if the base is valid.
** If valid, it returns the size of the base.
** If invalid, it returns 0.
*/
int	check_base(char *base)
{
	int	base_size;
	int	j;

	base_size = 0;
	while (base[base_size] != '\0')
	{
		if (base[base_size] == '+' || base[base_size] == '-')
			return (0);
		j = base_size + 1;
		while (base[j] != '\0')
		{
			if (base[base_size] == base[j])
				return (0);
			j++;
		}
		base_size++;
	}
	if (base_size < 2)
		return (0);
	return (base_size);
}

// The recursive printing function remains the same.
void	print_in_base(long number, char *base, int base_size)
{
	if (number >= base_size)
	{
		print_in_base(number / base_size, base, base_size);
	}
	ft_putchar(base[number % base_size]);
}

/*
** The main function is now much shorter and cleaner.
*/
void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	long	long_nbr;

	base_size = check_base(base);
	if (base_size == 0)
		return ;
	long_nbr = nbr;
	if (long_nbr < 0)
	{
		ft_putchar('-');
		long_nbr = -long_nbr;
	}
	print_in_base(long_nbr, base, base_size);
}
