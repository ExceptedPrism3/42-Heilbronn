/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:34:50 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:34:52 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	*duplicate_and_sort(int *arr, int size)
{
	int	*copy;
	int	i;
	int	j;
	int	tmp;

	if (size <= 0)
		return (NULL);
	copy = malloc(sizeof(int) * size);
	if (!copy)
		error_exit();
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (copy[i] > copy[j])
			{
				tmp = copy[i];
				copy[i] = copy[j];
				copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (copy);
}

int	find_index(int *sorted, int size, int value)
{
	int	i;

	if (!sorted || size <= 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}
