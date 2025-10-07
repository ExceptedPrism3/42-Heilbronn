/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:15:05 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 01:42:50 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_and_check_last(int *combo, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = combo[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (combo[0] == 10 - n)
	{
		return (1);
	}
	write(1, ", ", 2);
	return (0);
}

void	get_next_combo(int *combo, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0 && combo[i] == 9 - (n - 1 - i))
	{
		i--;
	}
	combo[i]++;
	while (++i < n)
	{
		combo[i] = combo[i - 1] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	combo[10];
	int	i;
	int	is_finished;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		combo[i] = i;
		i++;
	}
	is_finished = 0;
	while (!is_finished)
	{
		is_finished = print_and_check_last(combo, n);
		if (!is_finished)
		{
			get_next_combo(combo, n);
		}
	}
}
