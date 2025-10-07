/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:23:10 by mlagutin          #+#    #+#             */
/*   Updated: 2025/08/07 13:51:15 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		base_len;

	if (!ft_is_valid(base))
		return ;
	n = nbr;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
		
	write(1, &base[n % base_len], 1);
}
