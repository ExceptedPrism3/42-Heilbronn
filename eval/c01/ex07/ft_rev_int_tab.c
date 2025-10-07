/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:26:28 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/07 14:57:02 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = 0;
	while (++i < --size)
	{
		tmp = tab[i];
		tab[i] = tab[size];
		tab[size] = tmp;
	}
}

/*
#include <stdio.h>
void	print_int_arr(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		printf("%d", arr[i]);
	}

int main()
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	len = 9;

	print_int_arr(arr, len);
	ft_rev_int_tab(arr, len);
	print_int_arr(arr, len);
	}
	*/
