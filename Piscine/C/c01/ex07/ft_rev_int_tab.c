/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 05:08:56 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 00:28:35 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start_index;
	int	end_index;
	int	temp;

	start_index = 0;
	end_index = size - 1;
	while (start_index < end_index)
	{
		temp = tab[start_index];
		tab[start_index] = tab[end_index];
		tab[end_index] = temp;
		start_index++;
		end_index--;
	}
}

/*int	main(void)
{
	int	my_array[] = {1, 2, 3, 4, 5, 6, 7};
	int	size = 7;
	int	i;

	printf("Original array: ");
	for(i = 0; i < size; i++)
	{
		printf("%d ", my_array[i]);
	}
	printf("\n");

	ft_rev_int_tab(my_array, size);

	printf("Reversed array: ");
	for(i = 0; i < size; i++) printf("%d ", my_array[i]);
	printf("\n");
	return (0);
}*/