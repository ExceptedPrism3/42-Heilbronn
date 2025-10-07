/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:51:30 by sabo-gla          #+#    #+#             */
/*   Updated: 2025/08/05 02:54:43 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	start_index;
	int	finish_index;

	finish_index = size - 1;
	start_index = 0;
	while (start_index < finish_index)
	{
		temp = tab[start_index];
		tab [start_index] = tab [finish_index];
		tab [finish_index] = temp;
		start_index++;
		finish_index--;
	}
}

int	main(void)
{
	int	testtab[7];
	int	testsize;

	testsize = 7;
	testtab[7] = {4, 5, 7, 38, 6, -7, 11};
	ft_rev_int_tab(testtab, testsize);
	for (int i = 0; i < testsize; i++)
	{
		printf("%d", testtab[i]);
		if (i != 6)
		{
			printf(",");
		}
	}
}