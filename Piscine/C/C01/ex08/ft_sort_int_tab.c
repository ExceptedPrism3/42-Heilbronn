/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 05:17:40 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 00:29:36 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int    main(void)
{
    int    my_array[] = {5, 2, 8, -1, 9, 0, 7};
    int    size = 7;
    int i;

    printf("Unsorted array: ");
    for(i = 0; i < size; i++) printf("%d ", my_array[i]);
    printf("\n");

    ft_sort_int_tab(my_array, size);

    printf("Sorted array:   ");
    for(i = 0; i < size; i++) printf("%d ", my_array[i]);
    printf("\n");
    return (0);
}
